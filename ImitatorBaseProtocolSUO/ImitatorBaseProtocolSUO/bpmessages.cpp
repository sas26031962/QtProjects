#include "bpmessages.h"
#include <QDebug>


//---------------------------------------------------------------------
// Конструкторы
//---------------------------------------------------------------------
BaseProtocolHandler::BaseProtocolHandler(/*quint16 listenPort, quint16 sendingPort,
                                         QString sendingIP, QObject* parent*/)
//    :QObject(parent)
{
    connect(&mSocket, SIGNAL(readyRead()), this, SLOT(incomingMessage()));
}

BaseProtocolHandler::BaseProtocolHandler(
        quint16 listenPort,
        quint16 sendingPort,
        QString sendingIP
        /*, QObject* parent*/
        )
//    :QObject(parent)
{
    setListenPort(listenPort);
    setAddress(sendingPort, sendingIP);

    connect(&mSocket, SIGNAL(readyRead()), this, SLOT(incomingMessage()));
}

//---------------------------------------------------------------------
// Отправка сообщения
//---------------------------------------------------------------------
void BaseProtocolHandler::sendMessage(QByteArray &payload, quint16 descriptor)
{
    QByteArray completeDatagram;
    QDataStream str(&completeDatagram, QIODevice::WriteOnly);
    str.setByteOrder(QDataStream::LittleEndian);

    quint16 messageNumber = 0;
    quint64 trTime = 0;

    str << descriptor;
    str << messageNumber;
    str << trTime;
    completeDatagram.append(payload);

    //qDebug() << "Data: " << completeDatagram << " Descriptor: " << descriptor;

    mSocket.writeDatagram(completeDatagram, mIP, mPort);
}


//---------------------------------------------------------------------
// Установка порта для чтения
//---------------------------------------------------------------------
void BaseProtocolHandler::setListenPort(quint16 port)
{
    mSocket.close();
    mSocket.bind(port);
}

//---------------------------------------------------------------------
// Установка адреса
//---------------------------------------------------------------------
void BaseProtocolHandler::setAddress(quint16 port, QString IP)
{
    mPort = port;
    mIP.setAddress(IP);
}

//---------------------------------------------------------------------
// Слот для обработки входящего сообщения
//---------------------------------------------------------------------
void BaseProtocolHandler::incomingMessage()
{
    QByteArray datagram;
    while(mSocket.hasPendingDatagrams())
    {
        datagram.resize(mSocket.pendingDatagramSize());
        mSocket.readDatagram(datagram.data(), datagram.size());

        parseDatagram(datagram);
    }
}

//---------------------------------------------------------------------
// Разбор входящего сообщения
//---------------------------------------------------------------------
void BaseProtocolHandler::parseDatagram(QByteArray &datagram)
{
    qDebug() << "Parse incoming datagram";

    ////Splitting the header from payload
    QDataStream inStr(&datagram, QIODevice::ReadOnly);
    inStr.setByteOrder(QDataStream::LittleEndian);

    quint16 descriptor;
    quint16 messageNumber;
    timeSpec trTime;

    inStr >> descriptor;
    inStr >> messageNumber;
    inStr >> trTime.sec;
    inStr >> trTime.nsec;

    QByteArray payload;
    quint8 payloadSize = datagram.size() - (sizeof(descriptor) + sizeof(messageNumber) + sizeof(trTime));//optimize?

    payload.resize(payloadSize);
    inStr.readRawData(payload.data(), payloadSize);


    ////Parsing the header
    ////Time Conversion
    ////Setting time sample to the received total amount of seconds(int)
    time_t timeSample = int(trTime.sec);  //received time
    //time_t timeSample = time(0);         //current system time

    ////Creating & initializing time storing object with received data & extracting the mFields
    /*struct */tm tmStruct;
    tmStruct = *localtime(&timeSample);

    QString parsedHeader;

    parsedHeader += "#" + QString::number(messageNumber) + " @";
    parsedHeader += QString::number(tmStruct.tm_hour) + ":";
    parsedHeader += QString::number(tmStruct.tm_min) + ":";
    parsedHeader += QString::number(tmStruct.tm_sec) + ".";
    parsedHeader += QString::number(quint32(trTime.nsec)) + "\n";

    QString parsedMessage;
    parsedMessage += parsedHeader;

    ////Parsing the payload
    switch(descriptor)
    {
    case 9:
    {
        BMessage9 m;
        if(payloadSize == 0)
        {
            parsedMessage += m.parse();
        }
        else
        {
            parsedMessage += "Message length[" + QString::number(payloadSize) +
                    "] doesn't match[" + QString::number(0) +
                    "]. Descriptor [" + QString::number(descriptor) + "]";
        }
    }
        break;
    case 10:
    {
        BMessage10 m;
        if(payloadSize == 0)
        {
            parsedMessage += m.parse();
        }
        else
        {
            parsedMessage += "Message length[" + QString::number(payloadSize) +
                    "] doesn't match[" + QString::number(0) +
                    "]. Descriptor [" + QString::number(descriptor) + "]";
        }
    }
        break;
    case 11:
    {
        BMessage11 m;
        m.fromBytes(&payload);
        if(payloadSize == sizeof(m))
        {
            parsedMessage += m.parse();
        }
        else
        {
            parsedMessage += "Message length[" + QString::number(payloadSize) +
                    "] doesn't match[" + QString::number(sizeof(m)) +
                    "]. Descriptor [" + QString::number(descriptor) +
                    "]";
        }
    }
        break;
    case 12:
    {
        BMessage12 m;
        m.fromBytes(&payload);
        if(payloadSize == sizeof(m))
        {
            parsedMessage += m.parse();
        }
        else
        {
            parsedMessage += "Message length[" + QString::number(payloadSize) +
                    "] doesn't match[" + QString::number(sizeof(m)) +
                    "]. Descriptor [" + QString::number(descriptor) + "]";
        }
    }
        break;
    default:
        parsedMessage += "Unknown descriptor: " + QString::number(descriptor);
        break;
    }

    emit incParsedDatagram(parsedMessage);
}

//---------------------------------------------------------------------
// Функции передачи UDP датаграмм
//---------------------------------------------------------------------
void BaseProtocolHandler::transmit1()
{
    qDebug() << "send Message_1";
    QByteArray body = "1234567890";//
    quint16 descriptor = 104;
    sendMessage(body, descriptor);
}

void BaseProtocolHandler::transmit2()
{
    qDebug() << "send Message_2";
    QByteArray payload;//empty
    sendMessage(payload, 2);
}

void BaseProtocolHandler::transmit3()
{
    qDebug() << "send Message_3";
    QByteArray payload;//empty
    sendMessage(payload, 3);
}

void BaseProtocolHandler::transmit4()
{
    qDebug() << "send Message_4";
    QByteArray payload;//empty
    sendMessage(payload, 4);
}

void BaseProtocolHandler::transmit5()
{
    qDebug() << "send Message_5";
    QByteArray payload;//empty
    sendMessage(payload, 5);
}

void BaseProtocolHandler::transmit6()
{
    qDebug() << "send Message_6";
    QByteArray payload;//empty
    sendMessage(payload, 6);
}

void BaseProtocolHandler::transmit7()
{
    qDebug() << "send Message_7";
    QByteArray payload;//empty
    sendMessage(payload, 7);
}

void BaseProtocolHandler::transmit8()
{
    qDebug() << "send Message_8";
    QByteArray payload;//empty
    sendMessage(payload, 8);
}

