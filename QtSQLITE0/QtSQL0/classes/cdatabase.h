#ifndef CDATABASE_H
#define CDATABASE_H

#include <QSqlDatabase>
#include <QtSql/QSqlResult>
#include <QStringList>
#include <QString>
#include <QTextCodec>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QList>

class cDataBase
{
public:
    //=========================================================================
    // �����������
    //=========================================================================
    cDataBase();
    //=========================================================================
    // ����������� ��������
    //=========================================================================

    //=========================================================================
    // ��������
    //=========================================================================
    QSqlDatabase db;    //���� ������ SQLite

    QList<QSqlRecord> Records;

    QString     msg;    //������ ��� ������ ���������

    QStringList Fields; //������ �����
    QStringList Values; //������ �������� �����
    QStringList Tables; //������ ������
    QStringList Types;  //������ ����� �����
    QStringList lRecords;//������ ����������� �������
    QStringList Status; //������ ��� ����������� ������� ��������

    QString TableHeaderValue;//��������� ��� �������

private:
    QString DatabasePath;

public:
    //=========================================================================
    // ������
    //=========================================================================
    static void Codec();
    void installDataBase(QString);

    void getTableList();
    void getFieldList(QString);
    int getRecordsCount(QString);
    void updateTable(QString);
    void insertRecordToTable(QString);
    void selectRecordsToStringList(QString);
    void createHeaderFromFields();
    void createHeaderFromRecords();
    void getCurrentRecord(QString, int);

    void convertRecordToString(int);

};//End of class cDataBase

#endif // CDATABASE_H
