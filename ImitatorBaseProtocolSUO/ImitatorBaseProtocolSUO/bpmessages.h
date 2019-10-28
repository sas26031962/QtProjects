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

    // ������ ��� �������� ���������
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

    //IP/���� - ����� �������, ������� ������������ ���������
    quint16 mPort;
    QHostAddress mIP;


    void parseDatagram(QByteArray& datagram);

private slots:
    // ����� ��� ��������� �������� ���������
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
        parsedMessage += "��������� ���� (9)";

        return parsedMessage;
    }
};


class BMessage10
{
public:

    QString parse()
    {
        QString parsedMessage;
        parsedMessage += "���������� ���� (10)";

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
        parsedMessage += "��������� ���� (11)";

        parsedMessage += "\n���������: ";
        switch(mNodeState)
        {
        case 1:
            parsedMessage += "������� ����";
            break;
        case 2:
            parsedMessage += "������� ���������";
            break;
        case 3:
            parsedMessage += "������� ������";
            break;
        case 4:
            parsedMessage += "�����";
            break;
        case 5:
            parsedMessage += "������";
            break;
        case 6:
            parsedMessage += "�������";
            break;
        case 7:
            parsedMessage += "����������";
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
        parsedMessage += "���������� �� ���� (12)";

        parsedMessage += "\n��� �����: " + QString::number(mUnitType);
        parsedMessage += "\n������� ���������� �����: " + QString::number(mUnitImplementation);
        parsedMessage += "\n������� ������������ �����������: " + QString::number(mSoftwareVariant);
        parsedMessage += "\n������ ������������ �����������: "
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
