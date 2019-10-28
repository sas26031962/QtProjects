#ifndef BPMESSAGES_H
#define BPMESSAGES_H

#include <QUdpSocket>
#include <time.h>

class BaseProtocolHandler: public QObject
{
    Q_OBJECT

public:
    BaseProtocolHandler();
    BaseProtocolHandler(quint16 listenPort, quint16 sendingPort, QString sendingIP/*, QObject* parent = 0*/);

    void setListenPort(quint16 port);
    void setAddress(quint16 port, QString IP);

    void sendMessage(QByteArray& payload, quint16 descriptor);

    // методы для отправки сообщений
    void transmit1();
    void transmit2();
    void transmit3();
    void transmit4();
    void transmit5();
    void transmit6();
    void transmit7();
    void transmit8();

private:
    QUdpSocket mSocket;

    //IP/порт - адрес системы, которой отправляется сообщение
    quint16 mPort;
    QHostAddress mIP;


    void parseDatagram(QByteArray& datagram);

private slots:
    // метод для обработки входящих сообщений
    void incomingMessage();//readDatagram?

signals:
    void incParsedDatagram(QString);
};


#pragma pack(push, 1)

struct timeSpec
{
    qint32 sec;
    qint32 nsec;
};


class BBaseMessage
{
public:
    virtual int getID() = 0;
    virtual int getLength() = 0;
    //sizeof

    //virtual void setData() = 0;

    //virtual void toBytes(QByteArray* payload) = 0;

    //virtual void fromBytes(QByteArray* payload) = 0;

protected:
};


class BMessage9
{
public:

    QString parse()
    {
        QString parsedMessage;
        parsedMessage += "Включение узла (9)";

        return parsedMessage;
    }
};


class BMessage10
{
public:

    QString parse()
    {
        QString parsedMessage;
        parsedMessage += "Выключение узла (10)";

        return parsedMessage;
    }
};


class BMessage11
{
public:
    void setData(quint8 rNodeState)
    {
        mNodeState = rNodeState;
    }

    void toBytes(QByteArray* payload)
    {
        QDataStream outStr(payload, QIODevice::WriteOnly);
        outStr.setByteOrder(QDataStream::LittleEndian);

        outStr << mNodeState;
    }

    void fromBytes(QByteArray* payload)
    {
        QDataStream inStr(payload, QIODevice::ReadOnly);
        inStr.setByteOrder(QDataStream::LittleEndian);

        inStr >> mNodeState;
    }

    QString parse()
    {
        QString parsedMessage;
        parsedMessage += "Состояние узла (11)";

        parsedMessage += "\nСостояние: ";
        switch(mNodeState)
        {
        case 1:
            parsedMessage += "Рестарт Узла";
            break;
        case 2:
            parsedMessage += "Рестарт Программы";
            break;
        case 3:
            parsedMessage += "Рестарт Обмена";
            break;
        case 4:
            parsedMessage += "Готов";
            break;
        case 5:
            parsedMessage += "Работа";
            break;
        case 6:
            parsedMessage += "Останов";
            break;
        case 7:
            parsedMessage += "Выключение";
            break;
        default:
            parsedMessage += "Error! Incorrect Value: " + QString::number(mNodeState);
            break;
        }

        return parsedMessage;
    }

private:
    quint8 mNodeState;
};


class BMessage12
{
public:
    void setData(quint8 rUnitType,
                 quint8 rUnitImplementation,
                 quint8 rSoftwareVariant,
                 quint8 rSoftwareVersionHigh,
                 quint8 rSoftwareVersionMid,
                 quint8 rSoftwareVersionLow)
    {
        mUnitType = rUnitType;
        mUnitImplementation = rUnitImplementation;
        mSoftwareVariant = rSoftwareVariant;
        mSoftwareVersionHigh = rSoftwareVersionHigh;
        mSoftwareVersionMid = rSoftwareVersionMid;
        mSoftwareVersionLow = rSoftwareVersionLow;;
    }

    void toBytes(QByteArray* payload)
    {
        QDataStream outStr(payload, QIODevice::WriteOnly);
        outStr.setByteOrder(QDataStream::LittleEndian);

        outStr << mUnitType;
        outStr << mUnitImplementation;
        outStr << mSoftwareVariant;
        outStr << mSoftwareVersionHigh;
        outStr << mSoftwareVersionMid;
        outStr << mSoftwareVersionLow;
    }

    void fromBytes(QByteArray* payload)
    {
        QDataStream inStr(payload, QIODevice::ReadOnly);
        inStr.setByteOrder(QDataStream::LittleEndian);

        inStr >> mUnitType;
        inStr >> mUnitImplementation;
        inStr >> mSoftwareVariant;
        inStr >> mSoftwareVersionHigh;
        inStr >> mSoftwareVersionMid;
        inStr >> mSoftwareVersionLow;
    }

    QString parse()
    {
        QString parsedMessage;
        parsedMessage += "Информация об узле (12)";

        parsedMessage += "\nТип блока: " + QString::number(mUnitType);
        parsedMessage += "\nВариант исполнения блока: " + QString::number(mUnitImplementation);
        parsedMessage += "\nВариант программного обеспечения: " + QString::number(mSoftwareVariant);
        parsedMessage += "\nВерсия программного обеспечения: "
                + QString::number(mSoftwareVersionHigh) + "."
                + QString::number(mSoftwareVersionMid) + "."
                + QString::number(mSoftwareVersionLow);

        return parsedMessage;
    }

private:
    quint8 mUnitType;
    quint8 mUnitImplementation;
    quint8 mSoftwareVariant;
    quint8 mSoftwareVersionHigh;
    quint8 mSoftwareVersionMid;
    quint8 mSoftwareVersionLow;
};

#pragma pack(pop)
#endif // BPMESSAGES_H
