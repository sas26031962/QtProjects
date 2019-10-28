/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 27. Dec 11:13:42 2016
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionView_data;
    QAction *actionInsert_data;
    QAction *actionInsert_table;
    QAction *actionInsert_field;
    QAction *actionSelect_row;
    QAction *actionUpdate_data;
    QAction *actionView_table_list;
    QAction *actionView_fields_list;
    QAction *actionInsertRelationship;
    QAction *actionUpdateRelationship;
    QAction *actionViewRelationship;
    QAction *actionViewRelationshipRecords;
    QAction *actionViewPersonRecords;
    QAction *actionViewRelationRecords;
    QAction *actionInsertEvent;
    QAction *actionUpdateEvent;
    QAction *actionViewEvent;
    QAction *actionViewEventRecords;
    QAction *actionViewEventTypeRecords;
    QAction *actionExecuteRequest;
    QAction *actionDeleteRequest;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabData;
    QGroupBox *groupBoxRecord;
    QPushButton *pushButtonInsert;
    QPushButton *pushButtonUpdate;
    QTableWidget *tableWidgetForm;
    QPushButton *pushButtonView;
    QComboBox *comboBox1;
    QComboBox *comboBox2;
    QComboBox *comboBox3;
    QComboBox *comboBox4;
    QGroupBox *groupBoxTables;
    QComboBox *comboBoxTables;
    QPushButton *pushButtonGrabTable;
    QGroupBox *groupBoxStatus;
    QListWidget *listWidgetStatus;
    QGroupBox *groupBoxData_2;
    QListWidget *listWidgetData;
    QGroupBox *groupBoxRequest;
    QLineEdit *lineEditRequest;
    QPushButton *pushButtonRequestExec;
    QListWidget *listWidgetRequest;
    QPushButton *pushButtonDeleteRequest;
    QGroupBox *groupBoxFields;
    QPushButton *pushButtonGrabField;
    QComboBox *comboBoxFields;
    QWidget *tabRelationships;
    QGroupBox *groupBoxObject;
    QTableWidget *tableWidgetObject;
    QSpinBox *spinBoxObject;
    QGroupBox *groupBoxRelation;
    QTableWidget *tableWidgetObjectRelation;
    QSpinBox *spinBoxRelation;
    QGroupBox *groupBoxSubject;
    QTableWidget *tableWidgetSubject;
    QSpinBox *spinBoxSubject;
    QSpinBox *spinBoxRelationship;
    QPushButton *pushButtonInsertRelationship;
    QPushButton *pushButtonUpdateRelationship;
    QLabel *labelRecordRelationship;
    QGroupBox *groupBoxMemo;
    QLineEdit *lineEditMemo;
    QWidget *tabEvents;
    QPushButton *pushButtonUpdateEvent;
    QGroupBox *groupBoxEventType;
    QTableWidget *tableWidgetObjectEventType;
    QSpinBox *spinBoxEventType;
    QLabel *labelRecordEvent;
    QPushButton *pushButtonInsertEvent;
    QGroupBox *groupBoxMemo_2;
    QLineEdit *lineEditMemoEvents;
    QGroupBox *groupBoxObjectEvent;
    QTableWidget *tableWidgetObjectEvent;
    QSpinBox *spinBoxObjectEvent;
    QSpinBox *spinBoxEvent;
    QGroupBox *groupBoxData;
    QLineEdit *lineEditDate;
    QPushButton *pushButtonViewtEvent;
    QGroupBox *groupBoxSubjectEvent;
    QTableWidget *tableWidgetSubjectEvent;
    QSpinBox *spinBoxSubjectEvent;
    QWidget *tab;
    QTreeWidget *treeWidgetFathers;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDatabase;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(761, 566);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionView_data = new QAction(MainWindow);
        actionView_data->setObjectName(QString::fromUtf8("actionView_data"));
        actionInsert_data = new QAction(MainWindow);
        actionInsert_data->setObjectName(QString::fromUtf8("actionInsert_data"));
        actionInsert_table = new QAction(MainWindow);
        actionInsert_table->setObjectName(QString::fromUtf8("actionInsert_table"));
        actionInsert_field = new QAction(MainWindow);
        actionInsert_field->setObjectName(QString::fromUtf8("actionInsert_field"));
        actionSelect_row = new QAction(MainWindow);
        actionSelect_row->setObjectName(QString::fromUtf8("actionSelect_row"));
        actionUpdate_data = new QAction(MainWindow);
        actionUpdate_data->setObjectName(QString::fromUtf8("actionUpdate_data"));
        actionView_table_list = new QAction(MainWindow);
        actionView_table_list->setObjectName(QString::fromUtf8("actionView_table_list"));
        actionView_fields_list = new QAction(MainWindow);
        actionView_fields_list->setObjectName(QString::fromUtf8("actionView_fields_list"));
        actionInsertRelationship = new QAction(MainWindow);
        actionInsertRelationship->setObjectName(QString::fromUtf8("actionInsertRelationship"));
        actionUpdateRelationship = new QAction(MainWindow);
        actionUpdateRelationship->setObjectName(QString::fromUtf8("actionUpdateRelationship"));
        actionViewRelationship = new QAction(MainWindow);
        actionViewRelationship->setObjectName(QString::fromUtf8("actionViewRelationship"));
        actionViewRelationshipRecords = new QAction(MainWindow);
        actionViewRelationshipRecords->setObjectName(QString::fromUtf8("actionViewRelationshipRecords"));
        actionViewPersonRecords = new QAction(MainWindow);
        actionViewPersonRecords->setObjectName(QString::fromUtf8("actionViewPersonRecords"));
        actionViewRelationRecords = new QAction(MainWindow);
        actionViewRelationRecords->setObjectName(QString::fromUtf8("actionViewRelationRecords"));
        actionInsertEvent = new QAction(MainWindow);
        actionInsertEvent->setObjectName(QString::fromUtf8("actionInsertEvent"));
        actionUpdateEvent = new QAction(MainWindow);
        actionUpdateEvent->setObjectName(QString::fromUtf8("actionUpdateEvent"));
        actionViewEvent = new QAction(MainWindow);
        actionViewEvent->setObjectName(QString::fromUtf8("actionViewEvent"));
        actionViewEventRecords = new QAction(MainWindow);
        actionViewEventRecords->setObjectName(QString::fromUtf8("actionViewEventRecords"));
        actionViewEventTypeRecords = new QAction(MainWindow);
        actionViewEventTypeRecords->setObjectName(QString::fromUtf8("actionViewEventTypeRecords"));
        actionExecuteRequest = new QAction(MainWindow);
        actionExecuteRequest->setObjectName(QString::fromUtf8("actionExecuteRequest"));
        actionDeleteRequest = new QAction(MainWindow);
        actionDeleteRequest->setObjectName(QString::fromUtf8("actionDeleteRequest"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 751, 511));
        tabData = new QWidget();
        tabData->setObjectName(QString::fromUtf8("tabData"));
        groupBoxRecord = new QGroupBox(tabData);
        groupBoxRecord->setObjectName(QString::fromUtf8("groupBoxRecord"));
        groupBoxRecord->setGeometry(QRect(400, 10, 341, 231));
        pushButtonInsert = new QPushButton(groupBoxRecord);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));
        pushButtonInsert->setGeometry(QRect(150, 200, 61, 23));
        pushButtonUpdate = new QPushButton(groupBoxRecord);
        pushButtonUpdate->setObjectName(QString::fromUtf8("pushButtonUpdate"));
        pushButtonUpdate->setGeometry(QRect(80, 200, 61, 23));
        tableWidgetForm = new QTableWidget(groupBoxRecord);
        tableWidgetForm->setObjectName(QString::fromUtf8("tableWidgetForm"));
        tableWidgetForm->setGeometry(QRect(10, 20, 201, 171));
        pushButtonView = new QPushButton(groupBoxRecord);
        pushButtonView->setObjectName(QString::fromUtf8("pushButtonView"));
        pushButtonView->setGeometry(QRect(10, 200, 61, 23));
        comboBox1 = new QComboBox(groupBoxRecord);
        comboBox1->setObjectName(QString::fromUtf8("comboBox1"));
        comboBox1->setGeometry(QRect(220, 60, 111, 22));
        comboBox2 = new QComboBox(groupBoxRecord);
        comboBox2->setObjectName(QString::fromUtf8("comboBox2"));
        comboBox2->setGeometry(QRect(220, 90, 111, 22));
        comboBox3 = new QComboBox(groupBoxRecord);
        comboBox3->setObjectName(QString::fromUtf8("comboBox3"));
        comboBox3->setGeometry(QRect(220, 120, 111, 22));
        comboBox4 = new QComboBox(groupBoxRecord);
        comboBox4->setObjectName(QString::fromUtf8("comboBox4"));
        comboBox4->setGeometry(QRect(220, 150, 111, 22));
        groupBoxTables = new QGroupBox(tabData);
        groupBoxTables->setObjectName(QString::fromUtf8("groupBoxTables"));
        groupBoxTables->setGeometry(QRect(470, 370, 211, 51));
        comboBoxTables = new QComboBox(groupBoxTables);
        comboBoxTables->setObjectName(QString::fromUtf8("comboBoxTables"));
        comboBoxTables->setGeometry(QRect(10, 20, 121, 22));
        pushButtonGrabTable = new QPushButton(groupBoxTables);
        pushButtonGrabTable->setObjectName(QString::fromUtf8("pushButtonGrabTable"));
        pushButtonGrabTable->setGeometry(QRect(140, 20, 61, 23));
        groupBoxStatus = new QGroupBox(tabData);
        groupBoxStatus->setObjectName(QString::fromUtf8("groupBoxStatus"));
        groupBoxStatus->setGeometry(QRect(10, 370, 451, 111));
        listWidgetStatus = new QListWidget(groupBoxStatus);
        listWidgetStatus->setObjectName(QString::fromUtf8("listWidgetStatus"));
        listWidgetStatus->setGeometry(QRect(10, 20, 431, 81));
        groupBoxData_2 = new QGroupBox(tabData);
        groupBoxData_2->setObjectName(QString::fromUtf8("groupBoxData_2"));
        groupBoxData_2->setGeometry(QRect(10, 10, 381, 231));
        listWidgetData = new QListWidget(groupBoxData_2);
        listWidgetData->setObjectName(QString::fromUtf8("listWidgetData"));
        listWidgetData->setGeometry(QRect(10, 20, 361, 201));
        groupBoxRequest = new QGroupBox(tabData);
        groupBoxRequest->setObjectName(QString::fromUtf8("groupBoxRequest"));
        groupBoxRequest->setGeometry(QRect(10, 250, 671, 121));
        lineEditRequest = new QLineEdit(groupBoxRequest);
        lineEditRequest->setObjectName(QString::fromUtf8("lineEditRequest"));
        lineEditRequest->setGeometry(QRect(10, 20, 571, 20));
        pushButtonRequestExec = new QPushButton(groupBoxRequest);
        pushButtonRequestExec->setObjectName(QString::fromUtf8("pushButtonRequestExec"));
        pushButtonRequestExec->setGeometry(QRect(590, 20, 71, 23));
        listWidgetRequest = new QListWidget(groupBoxRequest);
        listWidgetRequest->setObjectName(QString::fromUtf8("listWidgetRequest"));
        listWidgetRequest->setGeometry(QRect(10, 50, 571, 61));
        pushButtonDeleteRequest = new QPushButton(groupBoxRequest);
        pushButtonDeleteRequest->setObjectName(QString::fromUtf8("pushButtonDeleteRequest"));
        pushButtonDeleteRequest->setGeometry(QRect(590, 50, 71, 23));
        groupBoxFields = new QGroupBox(tabData);
        groupBoxFields->setObjectName(QString::fromUtf8("groupBoxFields"));
        groupBoxFields->setGeometry(QRect(470, 430, 211, 51));
        pushButtonGrabField = new QPushButton(groupBoxFields);
        pushButtonGrabField->setObjectName(QString::fromUtf8("pushButtonGrabField"));
        pushButtonGrabField->setGeometry(QRect(140, 20, 61, 23));
        comboBoxFields = new QComboBox(groupBoxFields);
        comboBoxFields->setObjectName(QString::fromUtf8("comboBoxFields"));
        comboBoxFields->setGeometry(QRect(10, 20, 121, 22));
        tabWidget->addTab(tabData, QString());
        tabRelationships = new QWidget();
        tabRelationships->setObjectName(QString::fromUtf8("tabRelationships"));
        groupBoxObject = new QGroupBox(tabRelationships);
        groupBoxObject->setObjectName(QString::fromUtf8("groupBoxObject"));
        groupBoxObject->setGeometry(QRect(10, 10, 191, 241));
        tableWidgetObject = new QTableWidget(groupBoxObject);
        tableWidgetObject->setObjectName(QString::fromUtf8("tableWidgetObject"));
        tableWidgetObject->setGeometry(QRect(10, 20, 171, 171));
        spinBoxObject = new QSpinBox(groupBoxObject);
        spinBoxObject->setObjectName(QString::fromUtf8("spinBoxObject"));
        spinBoxObject->setGeometry(QRect(10, 200, 71, 22));
        groupBoxRelation = new QGroupBox(tabRelationships);
        groupBoxRelation->setObjectName(QString::fromUtf8("groupBoxRelation"));
        groupBoxRelation->setGeometry(QRect(210, 10, 191, 241));
        tableWidgetObjectRelation = new QTableWidget(groupBoxRelation);
        tableWidgetObjectRelation->setObjectName(QString::fromUtf8("tableWidgetObjectRelation"));
        tableWidgetObjectRelation->setGeometry(QRect(10, 20, 171, 171));
        spinBoxRelation = new QSpinBox(groupBoxRelation);
        spinBoxRelation->setObjectName(QString::fromUtf8("spinBoxRelation"));
        spinBoxRelation->setGeometry(QRect(10, 200, 71, 22));
        groupBoxSubject = new QGroupBox(tabRelationships);
        groupBoxSubject->setObjectName(QString::fromUtf8("groupBoxSubject"));
        groupBoxSubject->setGeometry(QRect(410, 10, 191, 241));
        tableWidgetSubject = new QTableWidget(groupBoxSubject);
        tableWidgetSubject->setObjectName(QString::fromUtf8("tableWidgetSubject"));
        tableWidgetSubject->setGeometry(QRect(10, 20, 171, 171));
        spinBoxSubject = new QSpinBox(groupBoxSubject);
        spinBoxSubject->setObjectName(QString::fromUtf8("spinBoxSubject"));
        spinBoxSubject->setGeometry(QRect(10, 200, 71, 22));
        spinBoxRelationship = new QSpinBox(tabRelationships);
        spinBoxRelationship->setObjectName(QString::fromUtf8("spinBoxRelationship"));
        spinBoxRelationship->setGeometry(QRect(10, 280, 71, 22));
        pushButtonInsertRelationship = new QPushButton(tabRelationships);
        pushButtonInsertRelationship->setObjectName(QString::fromUtf8("pushButtonInsertRelationship"));
        pushButtonInsertRelationship->setGeometry(QRect(10, 310, 61, 23));
        pushButtonUpdateRelationship = new QPushButton(tabRelationships);
        pushButtonUpdateRelationship->setObjectName(QString::fromUtf8("pushButtonUpdateRelationship"));
        pushButtonUpdateRelationship->setGeometry(QRect(10, 340, 61, 23));
        labelRecordRelationship = new QLabel(tabRelationships);
        labelRecordRelationship->setObjectName(QString::fromUtf8("labelRecordRelationship"));
        labelRecordRelationship->setGeometry(QRect(10, 260, 671, 16));
        labelRecordRelationship->setFrameShape(QFrame::Panel);
        labelRecordRelationship->setFrameShadow(QFrame::Sunken);
        groupBoxMemo = new QGroupBox(tabRelationships);
        groupBoxMemo->setObjectName(QString::fromUtf8("groupBoxMemo"));
        groupBoxMemo->setGeometry(QRect(210, 280, 391, 91));
        lineEditMemo = new QLineEdit(groupBoxMemo);
        lineEditMemo->setObjectName(QString::fromUtf8("lineEditMemo"));
        lineEditMemo->setGeometry(QRect(10, 20, 371, 20));
        tabWidget->addTab(tabRelationships, QString());
        tabEvents = new QWidget();
        tabEvents->setObjectName(QString::fromUtf8("tabEvents"));
        pushButtonUpdateEvent = new QPushButton(tabEvents);
        pushButtonUpdateEvent->setObjectName(QString::fromUtf8("pushButtonUpdateEvent"));
        pushButtonUpdateEvent->setGeometry(QRect(160, 380, 61, 23));
        groupBoxEventType = new QGroupBox(tabEvents);
        groupBoxEventType->setObjectName(QString::fromUtf8("groupBoxEventType"));
        groupBoxEventType->setGeometry(QRect(210, 10, 271, 241));
        tableWidgetObjectEventType = new QTableWidget(groupBoxEventType);
        tableWidgetObjectEventType->setObjectName(QString::fromUtf8("tableWidgetObjectEventType"));
        tableWidgetObjectEventType->setGeometry(QRect(10, 20, 251, 171));
        spinBoxEventType = new QSpinBox(groupBoxEventType);
        spinBoxEventType->setObjectName(QString::fromUtf8("spinBoxEventType"));
        spinBoxEventType->setGeometry(QRect(10, 200, 71, 22));
        labelRecordEvent = new QLabel(tabEvents);
        labelRecordEvent->setObjectName(QString::fromUtf8("labelRecordEvent"));
        labelRecordEvent->setGeometry(QRect(10, 360, 671, 16));
        labelRecordEvent->setFrameShape(QFrame::Panel);
        labelRecordEvent->setFrameShadow(QFrame::Sunken);
        pushButtonInsertEvent = new QPushButton(tabEvents);
        pushButtonInsertEvent->setObjectName(QString::fromUtf8("pushButtonInsertEvent"));
        pushButtonInsertEvent->setGeometry(QRect(90, 380, 61, 23));
        groupBoxMemo_2 = new QGroupBox(tabEvents);
        groupBoxMemo_2->setObjectName(QString::fromUtf8("groupBoxMemo_2"));
        groupBoxMemo_2->setGeometry(QRect(390, 300, 291, 51));
        lineEditMemoEvents = new QLineEdit(groupBoxMemo_2);
        lineEditMemoEvents->setObjectName(QString::fromUtf8("lineEditMemoEvents"));
        lineEditMemoEvents->setGeometry(QRect(10, 20, 271, 20));
        groupBoxObjectEvent = new QGroupBox(tabEvents);
        groupBoxObjectEvent->setObjectName(QString::fromUtf8("groupBoxObjectEvent"));
        groupBoxObjectEvent->setGeometry(QRect(10, 10, 191, 241));
        tableWidgetObjectEvent = new QTableWidget(groupBoxObjectEvent);
        tableWidgetObjectEvent->setObjectName(QString::fromUtf8("tableWidgetObjectEvent"));
        tableWidgetObjectEvent->setGeometry(QRect(10, 20, 171, 171));
        spinBoxObjectEvent = new QSpinBox(groupBoxObjectEvent);
        spinBoxObjectEvent->setObjectName(QString::fromUtf8("spinBoxObjectEvent"));
        spinBoxObjectEvent->setGeometry(QRect(10, 200, 71, 22));
        spinBoxEvent = new QSpinBox(tabEvents);
        spinBoxEvent->setObjectName(QString::fromUtf8("spinBoxEvent"));
        spinBoxEvent->setGeometry(QRect(10, 380, 71, 22));
        groupBoxData = new QGroupBox(tabEvents);
        groupBoxData->setObjectName(QString::fromUtf8("groupBoxData"));
        groupBoxData->setGeometry(QRect(390, 250, 191, 51));
        lineEditDate = new QLineEdit(groupBoxData);
        lineEditDate->setObjectName(QString::fromUtf8("lineEditDate"));
        lineEditDate->setGeometry(QRect(10, 20, 113, 20));
        pushButtonViewtEvent = new QPushButton(tabEvents);
        pushButtonViewtEvent->setObjectName(QString::fromUtf8("pushButtonViewtEvent"));
        pushButtonViewtEvent->setGeometry(QRect(230, 380, 61, 23));
        groupBoxSubjectEvent = new QGroupBox(tabEvents);
        groupBoxSubjectEvent->setObjectName(QString::fromUtf8("groupBoxSubjectEvent"));
        groupBoxSubjectEvent->setGeometry(QRect(490, 10, 191, 241));
        tableWidgetSubjectEvent = new QTableWidget(groupBoxSubjectEvent);
        tableWidgetSubjectEvent->setObjectName(QString::fromUtf8("tableWidgetSubjectEvent"));
        tableWidgetSubjectEvent->setGeometry(QRect(10, 20, 171, 171));
        spinBoxSubjectEvent = new QSpinBox(groupBoxSubjectEvent);
        spinBoxSubjectEvent->setObjectName(QString::fromUtf8("spinBoxSubjectEvent"));
        spinBoxSubjectEvent->setGeometry(QRect(10, 200, 71, 22));
        tabWidget->addTab(tabEvents, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        treeWidgetFathers = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidgetFathers->setHeaderItem(__qtreewidgetitem);
        treeWidgetFathers->setObjectName(QString::fromUtf8("treeWidgetFathers"));
        treeWidgetFathers->setGeometry(QRect(10, 10, 351, 431));
        treeWidgetFathers->setAllColumnsShowFocus(false);
        treeWidgetFathers->setHeaderHidden(true);
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 761, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuDatabase = new QMenu(menuBar);
        menuDatabase->setObjectName(QString::fromUtf8("menuDatabase"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDatabase->menuAction());
        menuFile->addAction(actionExit);
        menuDatabase->addAction(actionView_data);
        menuDatabase->addAction(actionInsert_data);
        menuDatabase->addAction(actionInsert_field);
        menuDatabase->addAction(actionUpdate_data);
        menuDatabase->addAction(actionView_table_list);
        menuDatabase->addAction(actionView_fields_list);
        menuDatabase->addAction(actionInsertRelationship);
        menuDatabase->addAction(actionUpdateRelationship);
        menuDatabase->addAction(actionViewRelationship);
        menuDatabase->addAction(actionViewRelationshipRecords);
        menuDatabase->addAction(actionViewPersonRecords);
        menuDatabase->addAction(actionViewRelationRecords);
        menuDatabase->addAction(actionInsertEvent);
        menuDatabase->addAction(actionUpdateEvent);
        menuDatabase->addAction(actionViewEvent);
        menuDatabase->addAction(actionViewEventRecords);
        menuDatabase->addAction(actionViewEventTypeRecords);
        menuDatabase->addAction(actionExecuteRequest);
        menuDatabase->addAction(actionDeleteRequest);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionView_data->setText(QApplication::translate("MainWindow", "View data", 0, QApplication::UnicodeUTF8));
        actionInsert_data->setText(QApplication::translate("MainWindow", "Insert data", 0, QApplication::UnicodeUTF8));
        actionInsert_table->setText(QApplication::translate("MainWindow", "Insert table", 0, QApplication::UnicodeUTF8));
        actionInsert_field->setText(QApplication::translate("MainWindow", "Insert field", 0, QApplication::UnicodeUTF8));
        actionSelect_row->setText(QApplication::translate("MainWindow", "Select row", 0, QApplication::UnicodeUTF8));
        actionUpdate_data->setText(QApplication::translate("MainWindow", "Update data", 0, QApplication::UnicodeUTF8));
        actionView_table_list->setText(QApplication::translate("MainWindow", "View table list", 0, QApplication::UnicodeUTF8));
        actionView_fields_list->setText(QApplication::translate("MainWindow", "View fields list", 0, QApplication::UnicodeUTF8));
        actionInsertRelationship->setText(QApplication::translate("MainWindow", "InsertRelationship", 0, QApplication::UnicodeUTF8));
        actionUpdateRelationship->setText(QApplication::translate("MainWindow", "UpdateRelationship", 0, QApplication::UnicodeUTF8));
        actionViewRelationship->setText(QApplication::translate("MainWindow", "ViewRelationship", 0, QApplication::UnicodeUTF8));
        actionViewRelationshipRecords->setText(QApplication::translate("MainWindow", "ViewRelationshipRecords", 0, QApplication::UnicodeUTF8));
        actionViewPersonRecords->setText(QApplication::translate("MainWindow", "ViewPersonRecords", 0, QApplication::UnicodeUTF8));
        actionViewRelationRecords->setText(QApplication::translate("MainWindow", "ViewRelationRecords", 0, QApplication::UnicodeUTF8));
        actionInsertEvent->setText(QApplication::translate("MainWindow", "InsertEvent", 0, QApplication::UnicodeUTF8));
        actionUpdateEvent->setText(QApplication::translate("MainWindow", "UpdateEvent", 0, QApplication::UnicodeUTF8));
        actionViewEvent->setText(QApplication::translate("MainWindow", "ViewEvent", 0, QApplication::UnicodeUTF8));
        actionViewEventRecords->setText(QApplication::translate("MainWindow", "ViewEventRecords", 0, QApplication::UnicodeUTF8));
        actionViewEventTypeRecords->setText(QApplication::translate("MainWindow", "ViewEventTypeRecords", 0, QApplication::UnicodeUTF8));
        actionExecuteRequest->setText(QApplication::translate("MainWindow", "ExecuteRequest", 0, QApplication::UnicodeUTF8));
        actionDeleteRequest->setText(QApplication::translate("MainWindow", "DeleteRequest", 0, QApplication::UnicodeUTF8));
        groupBoxRecord->setTitle(QApplication::translate("MainWindow", " \320\227\320\260\320\277\320\270\321\201\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonInsert->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonUpdate->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonView->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\276\321\202\321\200\320\265\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBoxTables->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\321\213", 0, QApplication::UnicodeUTF8));
        pushButtonGrabTable->setText(QApplication::translate("MainWindow", "\320\222 \321\201\321\202\321\200\320\276\320\272\321\203", 0, QApplication::UnicodeUTF8));
        groupBoxStatus->setTitle(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", 0, QApplication::UnicodeUTF8));
        groupBoxData_2->setTitle(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        groupBoxRequest->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        pushButtonRequestExec->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonDeleteRequest->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBoxFields->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\217", 0, QApplication::UnicodeUTF8));
        pushButtonGrabField->setText(QApplication::translate("MainWindow", "\320\222 \321\201\321\202\321\200\320\276\320\272\321\203", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabData), QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        groupBoxObject->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
        groupBoxRelation->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\275\320\276\321\210\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        groupBoxSubject->setTitle(QApplication::translate("MainWindow", "\320\241\321\203\320\261\321\212\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
        pushButtonInsertRelationship->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonUpdateRelationship->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        labelRecordRelationship->setText(QApplication::translate("MainWindow", "<\320\236\320\261\321\212\320\265\320\272\321\202> for <\321\201\321\203\320\261\321\212\320\265\320\272\321\202\320\260> as <\320\276\321\202\320\275\320\276\321\210\320\265\320\275\320\270\320\265>", 0, QApplication::UnicodeUTF8));
        groupBoxMemo->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        lineEditMemo->setText(QApplication::translate("MainWindow", "memo", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabRelationships), QApplication::translate("MainWindow", "\320\236\321\202\320\275\320\276\321\210\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushButtonUpdateEvent->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBoxEventType->setTitle(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\201\320\276\320\261\321\213\321\202\320\270\321\217", 0, QApplication::UnicodeUTF8));
        labelRecordEvent->setText(QApplication::translate("MainWindow", "<\320\236\320\261\321\212\320\265\320\272\321\202> in <\321\201\320\276\320\261\321\213\321\202\320\270\320\265> at <\320\264\320\260\321\202\320\260>", 0, QApplication::UnicodeUTF8));
        pushButtonInsertEvent->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBoxMemo_2->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        lineEditMemoEvents->setText(QApplication::translate("MainWindow", "memo", 0, QApplication::UnicodeUTF8));
        groupBoxObjectEvent->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
        groupBoxData->setTitle(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", 0, QApplication::UnicodeUTF8));
        pushButtonViewtEvent->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\276\321\202\321\200\320\265\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBoxSubjectEvent->setTitle(QApplication::translate("MainWindow", "\320\241\321\203\320\261\321\212\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabEvents), QApplication::translate("MainWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\230\320\265\321\200\320\260\321\200\321\205\320\270\321\217", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuDatabase->setTitle(QApplication::translate("MainWindow", "Database", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
