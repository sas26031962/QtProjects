#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlResult>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QModelIndex>
#include <QStringList>
#include <QTextCodec>
#include <QTableWidget>
#include <QComboBox>
#include <QMessageBox>

#include "./classes/Constants.h"
#include "./classes/cDataBase.h"
#include "./classes/cIndexDataSet.h"
#include "./classes/cTreeItem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //
    // ��������� ���� ������
    //
    static const QString DatabasePath;


    cDataBase sdb;              // ���� ������

    int CurrentRow;     //������� ��� � ������

    int RelationshipsRecordsCount;
    int PersonRecordsCount;
    int RelationRecordsCount;
    int EventRecordsCount;
    int EventTypeRecordsCount;

     //
     // �������� ��������
     //
     static const QString LabelStyleString;
     static const QString TableStyleString;
     static const QString HeaderStyleString;

     //
     // ��������� �������
     //

     static const char* TableDataHeaderValue;
     static const char* TableFormHeaderValue;
     static const char* TableObjectRelationHeaderValue;
     static const char* TableEventHeaderValue;
     static const char* TableEventTypeHeaderValue;

private:
    Ui::MainWindow *ui;

    QLabel* RequestLabel;
    QLabel* ViewLabel;

    //
    // ���������� ��� ������������ �������� ������������
    //
    QList<int> PatriarchIndexList;
    QList<QString> PatriarchTextList;
    QList<QString> ChildTextList;

    QList <cTreeItem> GenealogicTree;

    //
    // ������
    //
    bool getFieldCollection(QString table, QString field, QComboBox* box);


private slots:
    // �������: �������� ������
    void viewTableList();
    void viewFieldList();
    void insertData();
    void viewData();
    void updateData();
    void selectRow();
    void clickListData(QModelIndex i);
    void executeRequest();
    void deleteRequest();
    void selectRequest();

    void grabTable();
    void grabTableField();

    void grabField1();
    void grabField2();
    void grabField3();
    void grabField4();

    // �������: ���������
    void insertRelationship();
    void updateRelationship();
    void viewRelationship();

    // �������: �������
    void viewEvents();
    void insertEvents();
    void updateEvents();

    void viewObject();
    void viewObjectEvent();
    void viewSubjectEvent();
    void viewSubject();
    void viewRelation();
    void viewEventType();

    // �������: ��������
    bool mountGenealogicTree();

    // ������ ��������
    void ViewRelationshipsRecordsCount();
    void ViewPersonRecordsCount();
    void ViewRelationRecordsCount();
    void ViewEventRecordsCount();
    void ViewEventTypeRecordsCount();
};

#endif // MAINWINDOW_H
