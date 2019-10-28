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
    // Конструктор
    //=========================================================================
    cDataBase();
    //=========================================================================
    // Статические элементы
    //=========================================================================

    //=========================================================================
    // Атрибуты
    //=========================================================================
    QSqlDatabase db;    //База данных SQLite

    QList<QSqlRecord> Records;

    QString     msg;    //Строка для вывода сообщений

    QStringList Fields; //Список полей
    QStringList Values; //Список значений полей
    QStringList Tables; //Список таблиц
    QStringList Types;  //Список типов полей
    QStringList lRecords;//Список извлечённых записей
    QStringList Status; //Список для обозначения статуса операции

    QString TableHeaderValue;//Заголовок для таблицы

private:
    QString DatabasePath;

public:
    //=========================================================================
    // Методы
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
