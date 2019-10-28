#include "mainwindow.h"
#include "ui_mainwindow.h"

//=============================================================================
//============================== ��������� ====================================
//=============================================================================
//
// ��������� ���� ������
//
const QString MainWindow::DatabasePath = "../db/test.sqlite";

//
// ��������� ������
//
const char* MainWindow::TableDataHeaderValue = "�;���;�������;�������;���";
const char* MainWindow::TableObjectRelationHeaderValue = "�;���";
const char* MainWindow::TableFormHeaderValue = "��������";
const char* MainWindow::TableEventHeaderValue = "�;���;������;����;����������";
const char* MainWindow::TableEventTypeHeaderValue = "�;��������;����������";

//=============================================================================
//============================= ����������� ===================================
//=============================================================================

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    // ������������� ���� ������
    //
    this->sdb.installDataBase(MainWindow::DatabasePath);

    //
    // ������������ ������ ���������
    //
    this->RequestLabel = new QLabel("Request");
    this->ui->statusBar->addWidget(RequestLabel);

    this->ViewLabel = new QLabel("View");
    this->ui->statusBar->addWidget(ViewLabel);

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //-------------------------------------------------------------------------
    // ������������� ������ ����������� ������
    //-------------------------------------------------------------------------
    //
    // ��������� ��������� ������������ ������
    //
    cDataBase::Codec();

    //
    // ��������� ������ �� ����� ����� � ��������
    //
    //this->ui->tableWidgetData->setRowCount(100);
    //this->ui->tableWidgetData->setColumnCount(10);
    //this->ui->tableWidgetData->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->ui->tableWidgetForm->setRowCount(TABLE_FORM_ROWS);
    this->ui->tableWidgetForm->setColumnCount(TABLE_FORM_COLUMNS);
    this->ui->tableWidgetForm->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->ui->tableWidgetObject->setRowCount(TABLE_FORM_ROWS);
    this->ui->tableWidgetObject->setColumnCount(TABLE_FORM_COLUMNS);
    this->ui->tableWidgetObject->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->ui->tableWidgetSubject->setRowCount(TABLE_FORM_ROWS);
    this->ui->tableWidgetSubject->setColumnCount(TABLE_FORM_COLUMNS);
    this->ui->tableWidgetSubject->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->ui->tableWidgetObjectRelation->setRowCount(TABLE_RELATIONS_ROWS);
    this->ui->tableWidgetObjectRelation->setColumnCount(TABLE_FORM_COLUMNS);
    this->ui->tableWidgetObjectRelation->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->ui->tableWidgetObjectEvent->setRowCount(TABLE_EVENT_ROWS);
    this->ui->tableWidgetObjectEvent->setColumnCount(TABLE_FORM_COLUMNS);
    this->ui->tableWidgetObjectEvent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->ui->tableWidgetSubjectEvent->setRowCount(TABLE_EVENT_ROWS);
    this->ui->tableWidgetSubjectEvent->setColumnCount(TABLE_FORM_COLUMNS);
    this->ui->tableWidgetSubjectEvent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->ui->tableWidgetObjectEventType->setRowCount(TABLE_EVENT_TYPE_ROWS);
    this->ui->tableWidgetObjectEventType->setColumnCount(TABLE_FORM_COLUMNS);
    this->ui->tableWidgetObjectEventType->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //
    // ������ �������������� ������
    //
    //this->ui->tableWidgetData->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //this->ui->tableWidgetForm->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //
    // ������� ��������� ����� ����� � �������
    //
    //this->ui->tableWidgetData->setSelectionBehavior(QAbstractItemView::SelectRows);
    //this->ui->tableWidgetData->setSelectionMode(QAbstractItemView::SingleSelection);

    this->ui->tableWidgetForm->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableWidgetForm->setSelectionMode(QAbstractItemView::SingleSelection);

    this->ui->tableWidgetObject->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableWidgetObject->setSelectionMode(QAbstractItemView::SingleSelection);

    this->ui->tableWidgetSubject->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableWidgetSubject->setSelectionMode(QAbstractItemView::SingleSelection);

    this->ui->tableWidgetObjectRelation->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableWidgetObjectRelation->setSelectionMode(QAbstractItemView::SingleSelection);

    this->ui->tableWidgetObjectEvent->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableWidgetObjectEvent->setSelectionMode(QAbstractItemView::SingleSelection);

    this->ui->tableWidgetSubjectEvent->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableWidgetSubjectEvent->setSelectionMode(QAbstractItemView::SingleSelection);

    this->ui->tableWidgetObjectEventType->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableWidgetObjectEventType->setSelectionMode(QAbstractItemView::SingleSelection);

    //
    // ������� ���������� ��������
    //
    //this->ui->tableWidgetData->setHorizontalHeaderLabels(QString(this->TableDataHeaderValue).split(";"));

    this->ui->tableWidgetForm->setHorizontalHeaderLabels(QString(this->TableFormHeaderValue).split(";"));
    this->ui->tableWidgetForm->setVerticalHeaderLabels(QString(this->TableDataHeaderValue).split(";"));

    this->ui->tableWidgetObject->setHorizontalHeaderLabels(QString(this->TableFormHeaderValue).split(";"));
    this->ui->tableWidgetObject->setVerticalHeaderLabels(QString(this->TableDataHeaderValue).split(";"));

    this->ui->tableWidgetSubject->setHorizontalHeaderLabels(QString(this->TableFormHeaderValue).split(";"));
    this->ui->tableWidgetSubject->setVerticalHeaderLabels(QString(this->TableDataHeaderValue).split(";"));

    this->ui->tableWidgetObjectRelation->setHorizontalHeaderLabels(QString(this->TableFormHeaderValue).split(";"));
    this->ui->tableWidgetObjectRelation->setVerticalHeaderLabels(QString(this->TableObjectRelationHeaderValue).split(";"));

    this->ui->tableWidgetObjectEvent->setHorizontalHeaderLabels(QString(this->TableFormHeaderValue).split(";"));
    this->ui->tableWidgetObjectEvent->setVerticalHeaderLabels(QString(this->TableDataHeaderValue).split(";"));

    this->ui->tableWidgetSubjectEvent->setHorizontalHeaderLabels(QString(this->TableFormHeaderValue).split(";"));
    this->ui->tableWidgetSubjectEvent->setVerticalHeaderLabels(QString(this->TableDataHeaderValue).split(";"));

    this->ui->tableWidgetObjectEventType->setHorizontalHeaderLabels(QString(this->TableFormHeaderValue).split(";"));
    this->ui->tableWidgetObjectEventType->setVerticalHeaderLabels(QString(this->TableEventTypeHeaderValue).split(";"));

    //
    // ��������� �������� ������� �������
    //
    /*
    this->ui->tableWidgetData->setStyleSheet(this->TableStyleString);
    this->ui->tableWidgetData->horizontalHeader()->setStyleSheet(this->HeaderStyleString);
    this->ui->tableWidgetData->verticalHeader()->setStyleSheet(this->HeaderStyleString);

    this->ui->tableWidgetData->setStyleSheet(this->TableStyleString);
    this->ui->tableWidgetData->horizontalHeader()->setStyleSheet(this->HeaderStyleString);
    this->ui->tableWidgetData->verticalHeader()->setStyleSheet(this->HeaderStyleString);

    this->ui->tableWidgetForm->setStyleSheet(this->TableStyleString);
    this->ui->tableWidgetForm->horizontalHeader()->setStyleSheet(this->HeaderStyleString);
    this->ui->tableWidgetForm->verticalHeader()->setStyleSheet(this->HeaderStyleString);

    this->ui->tableWidgetForm->setStyleSheet(this->TableStyleString);
    this->ui->tableWidgetForm->horizontalHeader()->setStyleSheet(this->HeaderStyleString);
    this->ui->tableWidgetForm->verticalHeader()->setStyleSheet(this->HeaderStyleString);
    */
    //
    // ��������� ������ ��������
    //
    //this->ui->tableWidgetData->horizontalHeader()->setMinimumSectionSize(20);
    //this->ui->tableWidgetData->horizontalHeader()->setStretchLastSection(true);

    this->ui->tableWidgetForm->horizontalHeader()->setMinimumSectionSize(50);
    this->ui->tableWidgetForm->horizontalHeader()->setStretchLastSection(true);

    this->ui->tableWidgetObject->horizontalHeader()->setMinimumSectionSize(50);
    this->ui->tableWidgetObject->horizontalHeader()->setStretchLastSection(true);

    this->ui->tableWidgetSubject->horizontalHeader()->setMinimumSectionSize(50);
    this->ui->tableWidgetSubject->horizontalHeader()->setStretchLastSection(true);

    this->ui->tableWidgetObjectRelation->horizontalHeader()->setMinimumSectionSize(50);
    this->ui->tableWidgetObjectRelation->horizontalHeader()->setStretchLastSection(true);

    this->ui->tableWidgetObjectEvent->horizontalHeader()->setMinimumSectionSize(50);
    this->ui->tableWidgetObjectEvent->horizontalHeader()->setStretchLastSection(true);

    this->ui->tableWidgetSubjectEvent->horizontalHeader()->setMinimumSectionSize(50);
    this->ui->tableWidgetSubjectEvent->horizontalHeader()->setStretchLastSection(true);

    this->ui->tableWidgetObjectEventType->horizontalHeader()->setMinimumSectionSize(50);
    this->ui->tableWidgetObjectEventType->horizontalHeader()->setStretchLastSection(true);

    //
    // ����������� ������ �������� �� ����������� ������ ������
    //
    //this->ui->tableWidgetData->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    this->ui->tableWidgetForm->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    this->ui->tableWidgetObject->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    this->ui->tableWidgetSubject->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    this->ui->tableWidgetObjectRelation->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    this->ui->tableWidgetObjectEvent->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    this->ui->tableWidgetSubjectEvent->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    this->ui->tableWidgetObjectEventType->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);


    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    //
    // Installation vidget parameters
    //

    this->ViewPersonRecordsCount();
    this->ViewRelationRecordsCount();
    this->ViewRelationshipsRecordsCount();
    this->ViewEventRecordsCount();
    this->ViewEventTypeRecordsCount();

    //=========================================================================
    //=================== ���������� �������� � ������ ========================
    //=========================================================================

    //#########################################################################
    // �������: �������� ������
    //#########################################################################
    QObject::connect(this->ui->actionView_table_list, SIGNAL(triggered()), this, SLOT(viewTableList()));

    QObject::connect(this->ui->actionView_fields_list, SIGNAL(triggered()), this, SLOT(viewFieldList()));
    //QObject::connect(this->ui->comboBoxTables, SIGNAL(currentIndexChanged(QString)), this, SLOT(viewFieldList()));
    QObject::connect(this->ui->comboBoxTables, SIGNAL(currentIndexChanged(QString)), this, SLOT(viewData()));

    QObject::connect(this->ui->actionView_data, SIGNAL(triggered()), this, SLOT(viewData()));
    QObject::connect(this->ui->pushButtonView, SIGNAL(clicked()), this, SLOT(viewData()));

    QObject::connect(this->ui->actionInsert_data, SIGNAL(triggered()), this, SLOT(insertData()));
    QObject::connect(this->ui->pushButtonInsert, SIGNAL(clicked()), this, SLOT(insertData()));

    QObject::connect(this->ui->actionUpdate_data, SIGNAL(triggered()), this, SLOT(updateData()));
    QObject::connect(this->ui->pushButtonUpdate, SIGNAL(clicked()), this, SLOT(updateData()));

    QObject::connect(this->ui->actionExecuteRequest, SIGNAL(triggered()), this, SLOT(executeRequest()));
    QObject::connect(this->ui->pushButtonRequestExec, SIGNAL(clicked()), this, SLOT(executeRequest()));
    //QObject::connect(this->ui->lineEditRequest, SIGNAL(editingFinished()), this, SLOT(executeRequest()));
    QObject::connect(this->ui->actionDeleteRequest, SIGNAL(triggered()), this, SLOT(deleteRequest()));
    QObject::connect(this->ui->pushButtonDeleteRequest, SIGNAL(clicked()), this, SLOT(deleteRequest()));

    QObject::connect(this->ui->listWidgetData, SIGNAL(clicked(QModelIndex)), this, SLOT(clickListData(QModelIndex)));

    QObject::connect(this->ui->listWidgetRequest, SIGNAL(clicked(QModelIndex)), this, SLOT(selectRequest()));

    //QObject::connect(this->ui->pushButtonGrabField, SIGNAL(clicked()), this, SLOT(grabField()));
    QObject::connect(this->ui->pushButtonGrabTable, SIGNAL(clicked()), this, SLOT(grabTable()));

    QObject::connect(this->ui->comboBox1, SIGNAL(currentIndexChanged(int)), this, SLOT(grabField1()));
    QObject::connect(this->ui->comboBox2, SIGNAL(currentIndexChanged(int)), this, SLOT(grabField2()));
    QObject::connect(this->ui->comboBox3, SIGNAL(currentIndexChanged(int)), this, SLOT(grabField3()));
    QObject::connect(this->ui->comboBox4, SIGNAL(currentIndexChanged(int)), this, SLOT(grabField4()));

    //#########################################################################
    // �������: ���������
    //#########################################################################

    QObject::connect(this->ui->actionViewRelationship, SIGNAL(triggered()), this, SLOT(viewRelationship()));

    QObject::connect(this->ui->actionUpdateRelationship, SIGNAL(triggered()), this, SLOT(updateRelationship()));
    QObject::connect(this->ui->pushButtonUpdateRelationship, SIGNAL(clicked()), this, SLOT(updateRelationship()));

    QObject::connect(this->ui->actionInsertRelationship, SIGNAL(triggered()), this, SLOT(insertRelationship()));
    QObject::connect(this->ui->pushButtonInsertRelationship, SIGNAL(clicked()), this, SLOT(insertRelationship()));

    QObject::connect(this->ui->spinBoxObject, SIGNAL(valueChanged(int)), this, SLOT(viewObject()));
    QObject::connect(this->ui->spinBoxSubject, SIGNAL(valueChanged(int)), this, SLOT(viewSubject()));
    QObject::connect(this->ui->spinBoxRelation, SIGNAL(valueChanged(int)), this, SLOT(viewRelation()));
    QObject::connect(this->ui->spinBoxRelationship, SIGNAL(valueChanged(int)), this, SLOT(viewRelationship()));

    //#########################################################################
    // �������: �������
    //#########################################################################

    QObject::connect(this->ui->actionInsertEvent, SIGNAL(triggered()), this, SLOT(insertEvents()));
    QObject::connect(this->ui->pushButtonInsertEvent, SIGNAL(clicked()), this, SLOT(insertEvents()));

    QObject::connect(this->ui->actionUpdateEvent, SIGNAL(triggered()), this, SLOT(updateEvents()));
    QObject::connect(this->ui->pushButtonUpdateEvent, SIGNAL(clicked()), this, SLOT(updateEvents()));

    QObject::connect(this->ui->spinBoxObjectEvent, SIGNAL(valueChanged(int)), this, SLOT(viewObjectEvent()));
    QObject::connect(this->ui->spinBoxSubjectEvent, SIGNAL(valueChanged(int)), this, SLOT(viewSubjectEvent()));
    QObject::connect(this->ui->spinBoxEvent, SIGNAL(valueChanged(int)), this, SLOT(viewEvents()));
    QObject::connect(this->ui->spinBoxEventType, SIGNAL(valueChanged(int)), this, SLOT(viewEventType()));


    //#########################################################################
    // ������ ��������
    //#########################################################################

    //QObject::connect(this->ui->actionInsert_table, SIGNAL(triggered()), this, SLOT(insertTable()));

    //QObject::connect(this->ui->actionInsert_field, SIGNAL(triggered()), this, SLOT(insertField()));

    QObject::connect(this->ui->actionViewRelationshipRecords, SIGNAL(triggered()), this, SLOT(ViewRelationshipsRecordsCount()));
    QObject::connect(this->ui->actionViewPersonRecords, SIGNAL(triggered()), this, SLOT(ViewPersonRecordsCount()));
    QObject::connect(this->ui->actionViewRelationRecords, SIGNAL(triggered()), this, SLOT(ViewRelationRecordsCount()));
    QObject::connect(this->ui->actionViewEventRecords, SIGNAL(triggered()), this, SLOT(ViewEventRecordsCount()));
    QObject::connect(this->ui->actionViewEventTypeRecords, SIGNAL(triggered()), this, SLOT(ViewEventTypeRecordsCount()));


    //
    // Default action
    //
    this->viewTableList();
    this->viewFieldList();
    this->viewData();
    this->ui->listWidgetData->setCurrentRow(0);

    //=========================================================================
    // ���������� ��������
    //=========================================================================

    //
    // ������ �����  ��������� ������
    //
    // ��������� �������� ��������� ����������
    bool x = false;
    int CountOfItems = 0;

    // ��������� ���������� �� ���� ������
    x = sdb.db.open();
    if(x)
    {
        QString str = "SELECT COUNT(*) FROM person;";

        QSqlQuery qSelect(str);
        qSelect.next();
        CountOfItems = qSelect.value(0).toInt();

        //QMessageBox::warning(this, "��������� � ���� ������", "����� !!!");
    }
    else
    {
        QMessageBox::warning(this, "Bad query", "������ ������ ����� ��������� � �������");
    }

    //
    // ������ ������ ��������� ������
    //
    this->GenealogicTree.clear();
    for(int i = 1; i < CountOfItems; i++)
    {
        cTreeItem x = cTreeItem(i);
        if(x.getChildren(this->sdb))
            this->GenealogicTree.append(x);
        else
            QMessageBox::warning(this, "Bad query", "������ ������ �������� " + QString::number(i));
    }

    //
    // ���������� �������������� ������
    //
    this->mountGenealogicTree();

    //
    // View tables records count
    //
    this->ViewEventRecordsCount();
    this->ViewEventTypeRecordsCount();
    this->ViewPersonRecordsCount();
    this->ViewRelationRecordsCount();
    this->ViewRelationshipsRecordsCount();

    //
    // View result
    //
    this->viewRelationship();
    this->viewObject();
    this->viewObjectEvent();
    this->viewSubjectEvent();
    this->viewSubject();
    this->viewRelation();
    this->viewEvents();
    this->viewEventType();

}//End of ctor

MainWindow::~MainWindow()
{
    delete ui;
    this->sdb.db.close();
}

//=============================================================================
//================================ SLOTS ======================================
//=============================================================================

//#############################################################################
// �������: �������� ������
//#############################################################################

//=============================================================================
// ������ ������ ������
//=============================================================================
void MainWindow::viewTableList()
{
    //
    // ���������� ������� � ���� ������
    //
    this->sdb.getTableList();

    //
    // �������� ����� ���������� �������
    //
    this->ui->comboBoxTables->clear();
    this->ui->comboBoxTables->addItems(this->sdb.Tables);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

}//End of void MainWindow::viewTableList()

//=============================================================================
// ������ ������ ����� �������
//=============================================================================
void MainWindow::viewFieldList()
{
    //
    // ���������� ������� � ���� ������
    //
    this->sdb.getFieldList(this->ui->comboBoxTables->currentText());
    /*
    QString str = "SELECT * FROM ";
    str += this->ui->comboBoxTables->currentText();
    str += ";";
    this->sdb.selectRecordsToStringList(str);
    */
    //
    // �������� ����� ���������� �������
    //
    this->ui->comboBoxFields->clear();//����������� ������ �����
    this->ui->comboBoxFields->addItems(this->sdb.Fields);

}//End of void MainWindow::viewFieldList()

//=============================================================================
// ���������� ������ � �������
//=============================================================================
void MainWindow::updateData()
{
    //
    // ���������� ��������� ������ �������
    //
    QString table =  this->ui->comboBoxTables->currentText();
    //������ ������ �����
    this->sdb.getFieldList(table);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    //������ ������ ��������
    this->sdb.Values.clear();
    for(int i = 0; i < this->sdb.Fields.count(); i++)
    {
        this->sdb.Values.append(this->ui->tableWidgetForm->item(0,i)->data(0).toString());
    }

    //
    // ���������� �������
    //
    this->sdb.updateTable(table);

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    this->ViewLabel->setText("");

}//End of void MainWindow::updateData()


//=============================================================================
// ���������� ������ � �������
//=============================================================================
void MainWindow::insertData()
{
    //
    // ���������� ��������� ������ �������
    //
    QString table = this->ui->comboBoxTables->currentText();

    //������ ������ �����
    this->sdb.getFieldList(table);

    //������ ������ ������
    this->sdb.Values.clear();
    for(int i = 0; i < this->sdb.Fields.count(); i++)
    {
        this->sdb.Values.append(this->ui->tableWidgetForm->item(0,i)->data(0).toString());
    }
    //
    // ���������� �������
    //
    this->sdb.insertRecordToTable(table);

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    /*
    this->ViewEventRecordsCount();
    this->ViewEventTypeRecordsCount();
    this->ViewPersonRecordsCount();
    this->ViewRelationRecordsCount();
    this->ViewRelationshipsRecordsCount();

    this->viewData();// ���������� ������ ����� ���������
    */
}//End of void MainWindow::insertData()

//=============================================================================
// �������� ������ � �������
//=============================================================================
void MainWindow::viewData()
{
    //
    // ���������� ��������� ������ �������
    //
    QString table = this->ui->comboBoxTables->currentText();

    //
    // ������������ �������
    //
    QString str = "SELECT * FROM ";
    str += table;
    str += ";";

    //
    // ���������� �������
    //
    this->sdb.selectRecordsToStringList(str);

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetData->clear();
    this->ui->listWidgetData->addItems(this->sdb.lRecords);

    this->sdb.createHeaderFromRecords();
    this->ui->tableWidgetForm->setVerticalHeaderLabels(QString(this->sdb.TableHeaderValue).split(";"));

    //
    // ����������� ������ �������� ������� ����
    //
    if(this->sdb.Records.count())
    {
        // ������ ����
        this->getFieldCollection(table, this->sdb.Records.at(0).fieldName(1),this->ui->comboBox1);

        // ������ ����
        this->getFieldCollection(table, this->sdb.Records.at(0).fieldName(2),this->ui->comboBox2);

        // ������ ����
        this->getFieldCollection(table, this->sdb.Records.at(0).fieldName(3),this->ui->comboBox3);

        // �������� ����
        this->getFieldCollection(table, this->sdb.Records.at(0).fieldName(4),this->ui->comboBox4);

    }
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    this->CurrentRow = 1;// ���������� ������ ������� ���� � ������� �����
    this->selectRow();

}//End of void MainWindow::viewData()

//=============================================================================
// ������� �� ����� ���� � ������ ������
//=============================================================================
void MainWindow::selectRow()
{
    //
    // ���������� �������
    //
    this->sdb.getCurrentRecord(
            this->ui->comboBoxTables->currentText(),
            this->CurrentRow
            );

    //
    // �������� ����� ���������� �������
    //

    // ��������� ������ ��� ����� �����
    this->sdb.createHeaderFromFields();
    this->ui->tableWidgetForm->setVerticalHeaderLabels(this->sdb.TableHeaderValue.split(";"));

    // ��������� ����� ����� �����
    int RowsCount = this->sdb.Fields.count();
    this->ui->tableWidgetForm->setRowCount(RowsCount);

    // ����� �������� � �������
    for (int i = 0; i < RowsCount; i++)
    {
        this->ui->tableWidgetForm->setItem(0, i, new QTableWidgetItem(this->sdb.Values.at(i)));//row
    }
    // ����� ���������� � ������ �������
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

}//End of void MainWindow::selectRow()

//=============================================================================
// OnClickListData
//=============================================================================
void MainWindow::clickListData(QModelIndex i)
{
    this->CurrentRow = i.row() + 1;
    QString str = "ListData is clicked on ";
    str += QString::number(this->CurrentRow);
    this->ui->listWidgetStatus->addItem(str);

    this->selectRow();

}//End of void MainWindow::clickListData(QModelIndex i)

//=============================================================================
// ���������� ������� � ���� ������ � �������� ����������
//=============================================================================
void MainWindow::executeRequest()
{
    //
    // ���������� ������� � ������
    //
    this->ui->listWidgetRequest->addItem(this->ui->lineEditRequest->text());

    //
    // ������������ �������
    //
    QString str = this->ui->lineEditRequest->text();
    str += ";";

    //
    // ���������� �������
    //
    this->sdb.selectRecordsToStringList(str);

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetData->clear();
    this->ui->listWidgetData->addItems(this->sdb.lRecords);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    this->ui->tableWidgetForm->clear();

}//End of void MainWindow::executeRequest()

//=============================================================================
// �������� ������� �� ������
//=============================================================================
void MainWindow::deleteRequest()
{
    this->ui->listWidgetRequest->takeItem(this->ui->listWidgetRequest->row(this->ui->listWidgetRequest->currentItem()));
}//End of void MainWindow::executeRequest()

//=============================================================================
// ����� ������� �� ������
//=============================================================================
void MainWindow::selectRequest()
{
    this->ui->lineEditRequest->setText(this->ui->listWidgetRequest->currentItem()->text());
}//End of void MainWindow::executeRequest()

//=============================================================================
// �������� ��� ������� �� ������ � ������ �������
//=============================================================================
void MainWindow::grabTable()
{
    QString str = this->ui->lineEditRequest->text();
    str += this->ui->comboBoxTables->currentText();
    this->ui->lineEditRequest->setText(str);
}//End of void MainWindow::grabTable()

//=============================================================================
// �������� ��� ���� �� ������ � ������ �������
//=============================================================================
void MainWindow::grabTableField()
{
    QString str = this->ui->lineEditRequest->text();
    str += this->ui->comboBoxFields->currentText();
    this->ui->lineEditRequest->setText(str);
}//End of void MainWindow::grabTableField()

//=============================================================================
// �������� ��� ���� �� ������1 � ���� 1 ����� ������
//=============================================================================
void MainWindow::grabField1()
{
    this->ui->tableWidgetForm->setItem(0, 1, new QTableWidgetItem(this->ui->comboBox1->currentText()));
}//End of void MainWindow::grabField1()

//=============================================================================
// �������� ��� ���� �� ������2 � ���� 2 ����� ������
//=============================================================================
void MainWindow::grabField2()
{
    this->ui->tableWidgetForm->setItem(0, 2, new QTableWidgetItem(this->ui->comboBox2->currentText()));
}//End of void MainWindow::grabField2()

//=============================================================================
// �������� ��� ���� �� ������3 � ���� 3 ����� ������
//=============================================================================
void MainWindow::grabField3()
{
    this->ui->tableWidgetForm->setItem(0, 3, new QTableWidgetItem(this->ui->comboBox3->currentText()));
}//End of void MainWindow::grabField3()

//=============================================================================
// �������� ��� ���� �� ������4 � ���� 4 ����� ������
//=============================================================================
void MainWindow::grabField4()
{
    this->ui->tableWidgetForm->setItem(0, 4, new QTableWidgetItem(this->ui->comboBox4->currentText()));
}//End of void MainWindow::grabField4()


//#############################################################################
// �������: ���������
//#############################################################################

//=============================================================================
// ���������� ������ � ������� relationships
//=============================================================================
void MainWindow::updateRelationship()
{

    //
    // ���������� ��������� ������ �������
    //
    QString table =  "relationships";
    //������ ������ �����
    this->sdb.getFieldList(table);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    //������ ������ ��������
    this->sdb.Values.clear();
    this->sdb.Values.append(QString::number(this->ui->spinBoxRelationship->value()));   //Id
    this->sdb.Values.append(QString::number(this->ui->spinBoxObject->value()));         //Object
    this->sdb.Values.append(QString::number(this->ui->spinBoxRelation->value()));       //Relation
    this->sdb.Values.append(QString::number(this->ui->spinBoxSubject->value()));        //Subject
    this->sdb.Values.append(this->ui->lineEditMemo->text());                            //Memo

    //
    // ���������� �������
    //
    this->sdb.updateTable(table);

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    this->ViewLabel->setText("");

}//End of void MainWindow::updateRelationship()

//=============================================================================
// ���������� ������ � ������� relationships
//=============================================================================
void MainWindow::insertRelationship()
{
    //
    // ���������� ��������� ������ �������
    //
    QString table = "relationships";

    //������ ������ �����
    this->sdb.getFieldList(table);

    //������ ������ ������
    this->sdb.Values.clear();
    this->sdb.Values.append(QString::number(this->ui->spinBoxRelationship->value()));//Id
    this->sdb.Values.append(QString::number(this->ui->spinBoxObject->value()));//Object
    this->sdb.Values.append(QString::number(this->ui->spinBoxRelation->value()));//Relation
    this->sdb.Values.append(QString::number(this->ui->spinBoxSubject->value()));//Subject
    this->sdb.Values.append(this->ui->lineEditMemo->text());//Memo

    //
    // ���������� �������
    //
    this->sdb.insertRecordToTable(table);

    // �������� ����� ���������� �������
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    this->ViewRelationshipsRecordsCount();
    this->viewRelationship();

}//End of void MainWindow::insertRelationship()

//=============================================================================
// View relationship
//=============================================================================
void MainWindow::viewRelationship()
{
    //
    // ���������� ��������� ������ �������
    //
    bool ret = true;                // result of database access
    QString table = "relationships";// table name string
    QString str = "";               // request to database string
    //cIndexDataSet IndexDataSet;     // ��������� ������� ������ � ���� ������

    //
    // ������������ �������
    //
    str += "SELECT ";
    str += "*";
    str += " FROM ";
    str += table;
    str += " WHERE Id = ";
    str += QString::number(this->ui->spinBoxRelationship->value());
    str += ";";

    this->RequestLabel->setText(str);
    this->ViewLabel->setText("viewRelationship");


    //
    // ���������� �������
    //
    this->sdb.Status.clear();   //������� ���������
    this->sdb.Records.clear();  //������� ������ �������

    if(this->sdb.db.open())
    {
        QSqlQuery qSelect(str);
        ret = qSelect.next();

        if(ret)
        {
            this->sdb.Records.append(qSelect.record());

            //��������������� �������� ����������
            this->sdb.msg = "View relationship: ";
            this->sdb.convertRecordToString(0);
            this->sdb.Status.append(this->sdb.msg);

            //�������� ���� ������
            this->sdb.db.close();

        }
        else
        {
            //��������������� ���������� ����������
            this->sdb.Status.append("view of relationship is failure");
        }
    }
    else
    {
        this->sdb.Status.append("database not open");
    }

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

    this->ui->spinBoxObject->setValue(this->sdb.Records.at(0).value(1).toInt());
    this->ui->spinBoxRelation->setValue(this->sdb.Records.at(0).value(2).toInt());
    this->ui->spinBoxSubject->setValue(this->sdb.Records.at(0).value(3).toInt());
    this->ui->lineEditMemo->setText(this->sdb.Records.at(0).value(4).toString());

    //
    // ������������ ������� ��� ����������� ���������
    //
    str = "";
    str += "SELECT DISTINCT (";
    str += "SELECT name || ' ' ||  family || ' ���' ";
    str += "FROM person WHERE Id = (SELECT object FROM relationships WHERE Id = ";
    str += QString::number(this->ui->spinBoxRelationship->value());//"1";
    str += ")) AS ' ', (SELECT name FROM relations WHERE Id = (SELECT relation FROM relationships WHERE Id = ";
    str += QString::number(this->ui->spinBoxRelationship->value());//"1";
    str += ")) AS ' ', (SELECT person.name || ' ' || person.family FROM person WHERE Id = (SELECT subject FROM relationships WHERE Id = ";
    str += QString::number(this->ui->spinBoxRelationship->value());//"1";
    str += ")) AS ' '  FROM person, relations;";

    //
    // ���������� �������
    //
    this->sdb.Status.clear();   //������� ���������
    this->sdb.Records.clear();  //������� ������ �������

    if(this->sdb.db.open())
    {
        QSqlQuery qSelect(str);
        ret = qSelect.next();

        if(ret)
        {
            this->sdb.Records.append(qSelect.record());

            //��������������� �������� ����������
            this->sdb.msg = "Decode relationship: ";
            this->sdb.convertRecordToString(0);
            this->sdb.Status.append(this->sdb.msg);

            //�������� ���� ������
            this->sdb.db.close();

        }
        else
        {
            //��������������� ���������� ����������
            this->sdb.Status.append("Decode of relationship is failure");
        }
    }
    else
    {
        this->sdb.Status.append("database not open");
    }

    this->sdb.msg = "";
    for(int i = 0; i < this->sdb.Records.at(0).count(); i++)
    {
        this->sdb.msg += this->sdb.Records.at(0).value(i).toString();
        this->sdb.msg += " ";
    }
    this->ui->labelRecordRelationship->setText(this->sdb.msg);

}//End of void MainWindow::viewRelationship()

//=============================================================================
// View object
//=============================================================================
void MainWindow::viewObject()
{

    bool ret = true;    // result of database access
    QString str = "";   // request to database string
    QString table = ""; // table name string

    if(this->sdb.db.open())
    {
        table = "person";
        int RowsCount = TABLE_FORM_ROWS;//person rows count
        str += "SELECT ";
        str += "*";
        str += " FROM ";
        str += table;
        str += " WHERE Id = ";
        str += QString::number(this->ui->spinBoxObject->value());
        str += ";";

        QSqlQuery qSelectObject(str);
        ret = ret && qSelectObject.next();

        if(ret)
        {
            for (int i = 0; i < RowsCount; i++)
                this->ui->tableWidgetObject->setItem(0, i, new QTableWidgetItem(qSelectObject.value(i).toString()));//row

            //Status set
            this->ui->listWidgetStatus->addItem("view of object is done");
        }
        else
        {
            //Status set
            this->ui->listWidgetStatus->addItem("view of object is failure");
        }

    }
    this->sdb.db.close();

}//End of void MainWindow::viewObject()


//#############################################################################
// �������: �������
//#############################################################################

//=============================================================================
// ���������� ������ � ������� Events
//=============================================================================
void MainWindow::updateEvents()
{
    //
    // ���������� ��������� ������ �������
    //
    QString table =  "events";
    //������ ������ �����
    this->sdb.getFieldList(table);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    //������ ������ ��������
    this->sdb.Values.clear();
    this->sdb.Values.append(QString::number(this->ui->spinBoxEvent->value()));      //Id
    this->sdb.Values.append(QString::number(this->ui->spinBoxEventType->value()));  //name
    this->sdb.Values.append(QString::number(this->ui->spinBoxObjectEvent->value()));//object
    this->sdb.Values.append(this->ui->lineEditDate->text());                        //date
    this->sdb.Values.append(this->ui->lineEditMemoEvents->text());                  //memo
    this->sdb.Values.append(QString::number(this->ui->spinBoxSubjectEvent->value()));//subject

    //
    // ���������� �������
    //
    this->sdb.updateTable(table);

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    this->ViewLabel->setText("");

}//End of void MainWindow::updateEvents()

//=============================================================================
// ���������� ������ � ������� evnents
//=============================================================================
void MainWindow::insertEvents()
{
    //
    // ���������� ��������� ������ �������
    //
    QString table = "events";

    //������ ������ �����
    this->sdb.getFieldList(table);

    //������ ������ ������
    this->sdb.Values.clear();
    this->sdb.Values.append(QString::number(this->ui->spinBoxEvent->value()));//Id
    this->sdb.Values.append(QString::number(this->ui->spinBoxEventType->value()));//Name
    this->sdb.Values.append(QString::number(this->ui->spinBoxObjectEvent->value()));//Object
    this->sdb.Values.append(this->ui->lineEditDate->text());//Date
    this->sdb.Values.append(this->ui->lineEditMemoEvents->text());//Memo
    this->sdb.Values.append(QString::number(this->ui->spinBoxSubjectEvent->value()));//Subject

    //
    // ���������� �������
    //
    this->sdb.insertRecordToTable(table);

    //
    // �������� ����� ���������� �������
    //
    this->ui->listWidgetStatus->addItems(this->sdb.Status);
    this->ViewEventRecordsCount();;
    this->viewEvents();

}//End of void MainWindow::insertEvents()

//=============================================================================
// �������� ������ �� ������� evnts
//=============================================================================
void MainWindow::viewEvents()
{
    //
    // ���������� ��������� ������ �������
    //
    bool ret = true;                // result of database access
    QString str = "";               // request to database string
    cIndexDataSet data;
    data.Index = this->ui->spinBoxEvent->value();

    str += "SELECT ";
    str += "*";
    str += " FROM ";
    str += "events";
    str += " WHERE Id = ";
    str += QString::number(data.Index);
    str += ";";

    this->RequestLabel->setText(str);

    //
    // ���������� �������
    //
    this->sdb.Status.clear();

    if(this->sdb.db.open())
    {
        QSqlQuery qSelect(str);
        ret = qSelect.next();

        if(ret)
        {
            data.Relation = qSelect.value(1).toInt();
            data.Object = qSelect.value(2).toInt();
            data.Date = qSelect.value(3).toString();
            data.Memo = qSelect.value(4).toString();
            data.Subject = qSelect.value(5).toInt();

            // view result of request to database string
            QString msg = "";

            msg += "View: event=";
            msg += QString::number(data.Relation);
            msg += " , object=";
            msg += QString::number(data.Object);
            msg += " , subject=";
            msg += QString::number(data.Subject);
            msg += " , date=";
            msg += data.Date;
            msg += " , memo=";
            msg += data.Memo;

            //Status set
            this->sdb.Status.append(msg);
            //this->ui->listWidgetStatus->addItem();

        }
        else
        {
            //Status set
            //this->ui->listWidgetStatus->addItem("view of events is failure");
            this->sdb.Status.append("view of events is failure");
        }
        // �������� ���� ������
        this->sdb.db.close();
    }
    else
    {
        this->sdb.Status.append("database not open");
    }
    //
    // �������� ����� ���������� �������
    //
    this->ui->spinBoxEventType->setValue(data.Relation);
    this->ui->spinBoxObjectEvent->setValue(data.Object);
    this->ui->lineEditDate->setText(data.Date);
    this->ui->lineEditMemoEvents->setText(data.Memo);
    this->ui->spinBoxSubjectEvent->setValue(data.Subject);

    //����������� ����������� �������
    this->ViewLabel->setText(this->sdb.Status.last());
    /*
    //View event content
    QString info = "";
    info += "event(";
    info += QString::number(this->ui->spinBoxObject->value());
    info += ")";
    // "<object>";//this->ui->tableWidgetObject->item(0,1)->data(0).toString();//
    info += " is ";
    info += "relation(";
    info += QString::number(this->ui->spinBoxRelation->value());
    info += ")";//<relation>";
    info += " for ";
    info += "person(";
    info += QString::number(this->ui->spinBoxSubject->value());
    info += ")";//<subject>";
    */

    this->ui->labelRecordEvent->setText(this->sdb.Status.last());

    this->ui->listWidgetStatus->addItems(this->sdb.Status);
}//End of void MainWindow::viewEvents()

//=============================================================================
// View object event
//=============================================================================
void MainWindow::viewObjectEvent()
{

    bool ret = true;    // result of database access
    QString str = "";   // request to database string
    QString table = ""; // table name string

    if(this->sdb.db.open())
    {
        table = "person";
        int RowsCount = TABLE_FORM_ROWS;//person rows count
        str += "SELECT ";
        str += "*";
        str += " FROM ";
        str += table;
        str += " WHERE Id = ";
        str += QString::number(this->ui->spinBoxObjectEvent->value());
        str += ";";

        QSqlQuery qSelectObject(str);
        ret = ret && qSelectObject.next();

        if(ret)
        {
            for (int i = 0; i < RowsCount; i++)
                this->ui->tableWidgetObjectEvent->setItem(0, i, new QTableWidgetItem(qSelectObject.value(i).toString()));//row

            //Status set
            this->ui->listWidgetStatus->addItem("view of object is done");
        }
        else
        {
            //Status set
            this->ui->listWidgetStatus->addItem("view of object is failure");
        }

    }
    this->sdb.db.close();

}//End of void MainWindow::viewObjectEvent()

//=============================================================================
// View subject event
//=============================================================================
void MainWindow::viewSubjectEvent()
{

    bool ret = true;    // result of database access
    QString str = "";   // request to database string
    QString table = ""; // table name string

    if(this->sdb.db.open())
    {
        table = "person";
        int RowsCount = TABLE_FORM_ROWS;//person rows count
        str += "SELECT ";
        str += "*";
        str += " FROM ";
        str += table;
        str += " WHERE Id = ";
        str += QString::number(this->ui->spinBoxSubjectEvent->value());
        str += ";";

        QSqlQuery qSelectSubject(str);
        ret = ret && qSelectSubject.next();

        if(ret)
        {
            for (int i = 0; i < RowsCount; i++)
                this->ui->tableWidgetSubjectEvent->setItem(0, i, new QTableWidgetItem(qSelectSubject.value(i).toString()));//row

            //Status set
            this->ui->listWidgetStatus->addItem("view of subject_event is done");
        }
        else
        {
            //Status set
            this->ui->listWidgetStatus->addItem("view of subject_event is failure");
        }
        //������� ���� ������
        this->sdb.db.close();

    }

}//End of void MainWindow::viewSubjectEvent()

//=============================================================================
// View subject
//=============================================================================
void MainWindow::viewSubject()
{

    bool ret = true;    // result of database access
    QString str = "";   // request to database string
    QString table = ""; // table name string
    int RowsCount = 0;  // table rows count

    if(this->sdb.db.open())
    {
        table = "person";
        RowsCount = TABLE_FORM_ROWS;//person rows count
        str += "SELECT ";
        str += "*";
        str += " FROM ";
        str += table;
        str += " WHERE Id = ";
        str += QString::number(this->ui->spinBoxSubject->value());
        str += ";";

        QSqlQuery qSelectSubject(str);
        ret = ret && qSelectSubject.next();

        if(ret)
        {
            for (int i = 0; i < RowsCount; i++)
                this->ui->tableWidgetSubject->setItem(0, i, new QTableWidgetItem(qSelectSubject.value(i).toString()));//row

            //Status set
            this->ui->listWidgetStatus->addItem("view of subject is done");
        }
        else
        {
            //Status set
            this->ui->listWidgetStatus->addItem("view of subject is failure");
        }

    }
    this->sdb.db.close();

}//End of void MainWindow::viewSubject()

//=============================================================================
// View relation
//=============================================================================
void MainWindow::viewRelation()
{

    bool ret = true;    // result of database access
    QString str = "";   // request to database string
    QString table = ""; // table name string

    if(this->sdb.db.open())
    {
        table = "relations";
        int RowsCount = TABLE_RELATIONS_ROWS;//person rows count
        str += "SELECT ";
        str += "*";
        str += " FROM ";
        str += table;
        str += " WHERE Id = ";
        str += QString::number(this->ui->spinBoxRelation->value());
        str += ";";

        QSqlQuery qSelectRelation(str);
        ret = ret && qSelectRelation.next();

        if(ret)
        {
            for (int i = 0; i < RowsCount; i++)
                this->ui->tableWidgetObjectRelation->setItem(0, i, new QTableWidgetItem(qSelectRelation.value(i).toString()));//row

            //Status set
            this->ui->listWidgetStatus->addItem("view of relation is done");
        }
        else
        {
            //Status set
            this->ui->listWidgetStatus->addItem("view of relation is failure");
        }

    }
    this->sdb.db.close();

}//End of void MainWindow::viewRelation()

//=============================================================================
// View event_type
//=============================================================================
void MainWindow::viewEventType()
{

    bool ret = true;    // result of database access
    QString str = "";   // request to database string
    QString table = ""; // table name string

    if(this->sdb.db.open())
    {
        table = "events_types";
        int RowsCount = TABLE_EVENT_TYPE_ROWS;//person rows count
        str += "SELECT ";
        str += "*";
        str += " FROM ";
        str += table;
        str += " WHERE Id = ";
        str += QString::number(this->ui->spinBoxEventType->value());
        str += ";";

        QSqlQuery qSelectRelation(str);
        ret = ret && qSelectRelation.next();

        if(ret)
        {
            for (int i = 0; i < RowsCount; i++)
                this->ui->tableWidgetObjectEventType->setItem(0, i, new QTableWidgetItem(qSelectRelation.value(i).toString()));//row

            //Status set
            this->ui->listWidgetStatus->addItem("view of event_type is done");
        }
        else
        {
            //Status set
            this->ui->listWidgetStatus->addItem("view of event_type is failure");
        }

    }
    this->sdb.db.close();

}//End of void MainWindow::viewEventType()

//#############################################################################
// ������ ��������
//#############################################################################

//---------------------------------------------------------------------------
// ������ ����� ������� � ������� relationships
//---------------------------------------------------------------------------
void MainWindow::ViewRelationshipsRecordsCount()
{
    this->RelationshipsRecordsCount = this->sdb.getRecordsCount("relationships");
    this->ui->spinBoxRelationship->setRange(1, this->RelationshipsRecordsCount);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

}//End of void MainWindow::ViewRelationshipsRecordsCount()

//---------------------------------------------------------------------------
// ������ ����� ������� � ������� person
//---------------------------------------------------------------------------
void MainWindow::ViewPersonRecordsCount()
{

    this->PersonRecordsCount = this->sdb.getRecordsCount("person");

    this->ui->spinBoxObject->setRange(1, this->PersonRecordsCount);
    this->ui->spinBoxSubject->setRange(1, this->PersonRecordsCount);
    this->ui->spinBoxObjectEvent->setRange(1, this->PersonRecordsCount);
    this->ui->spinBoxSubjectEvent->setRange(1, this->PersonRecordsCount);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

}//End of void MainWindow::ViewPersonRecordsCount()

//---------------------------------------------------------------------------
// ������ ����� ������� � ������� relations
//---------------------------------------------------------------------------
void MainWindow::ViewRelationRecordsCount()
{

    this->RelationRecordsCount = this->sdb.getRecordsCount("relations");
    this->ui->spinBoxRelation->setRange(1, this->RelationRecordsCount);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

}//End of void MainWindow::ViewRelationRecordsCount()

//---------------------------------------------------------------------------
// ������ ����� ������� � ������� events
//---------------------------------------------------------------------------
void MainWindow::ViewEventRecordsCount()
{

    this->EventRecordsCount = this->sdb.getRecordsCount("events");
    this->ui->spinBoxEvent->setRange(1, this->EventRecordsCount);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

}//End of void MainWindow::ViewEventRecordsCount()

//---------------------------------------------------------------------------
// ������ ����� ������� � ������� events_types
//---------------------------------------------------------------------------
void MainWindow::ViewEventTypeRecordsCount()
{

    this->EventTypeRecordsCount = this->sdb.getRecordsCount("events_types");
    this->ui->spinBoxEventType->setRange(1, this->EventTypeRecordsCount);
    this->ui->listWidgetStatus->addItems(this->sdb.Status);

}//End of void MainWindow::ViewEventRecordsCount()

//#############################################################################
// ������ ������ MainWindow
//#############################################################################

//=============================================================================
// ����� ������ �������� ���� � �������
//=============================================================================
bool MainWindow::getFieldCollection(QString table, QString field, QComboBox* box)
{
    bool x = this->sdb.db.open();
    if(x)
    {
        QString str = "SELECT DISTINCT ";
        str += field;
        str += " FROM ";
        str += table;
        str += ";";
        QSqlQuery qSelect(str);
        box->clear();
        while (qSelect.next())
        {
            box->addItem(qSelect.value(0).toString());
        }
    }
    return x;
}//End of void MainWindow::getFieldCollection()

//=============================================================================
// ����������� ���������� �� ������� ��������
//=============================================================================
bool MainWindow::mountGenealogicTree()
{
    this->ui->listWidgetStatus->addItem("Show patriarchs execute...");

    //
    // ���������� ������ �������� ����������
    //

    bool x = this->sdb.db.open();
    if(x)
    {
        QString str = "SELECT * FROM person WHERE ";
        str += "(Id NOT IN (SELECT object FROM relationships WHERE relation = 9))";
        str += "AND ";
        str += "(Id IN (SELECT object FROM relationships WHERE relation = 1))";
        str += ";";

        this->PatriarchIndexList.clear();

        QSqlQuery qSelect(str);
        while (qSelect.next())
        {
            this->PatriarchIndexList.append(qSelect.value(0).toInt());
        }
    }

    //
    // ���������� ��� ����������
    //
    this->PatriarchTextList.clear();

    for(int i = 0; i < this->PatriarchIndexList.count(); i++)
    {
        x = this->sdb.db.open();
        if(x)
        {
            QString str = "SELECT Id || ': ' || name || ' ' || family AS fio FROM person WHERE Id = ";
            str += QString::number(this->PatriarchIndexList.at(i));
            str += ";";

             QSqlQuery qSelect(str);
            while (qSelect.next())
            {
                //this->PatriarchTextList.append(qSelect.value(0).toString());// ���������� �������� �������� �������
                this->PatriarchTextList.append(QString::number(this->PatriarchIndexList.at(i)));// ���������� �������� �������� �������
            }
        }

    }//End of ���������� ��� ����������

    //
    // ���������� �������� 1 ������ ��� ���� ��������� ���� ������
    //
    for(int i = 0; i < this->GenealogicTree.count(); i++)
    {
        cTreeItem y = this->GenealogicTree.at(i);
        int x = y.getItem();
        QString Text = QString::number(x);

        QTreeWidgetItem *itm = new QTreeWidgetItem;
        itm->setText(0, Text);
        this->ui->treeWidgetFathers->insertTopLevelItem(0, itm);

        // ���������� �������� ��������� � ��������� ��������
        /*
        for(int j = 0; j < this->GenealogicTree.at(i).ChildrenList.count(); j++)
        {
            QTreeWidgetItem *child = new QTreeWidgetItem;
            Text = QString::number(this->GenealogicTree.at(i).ChildrenList.at(j));
            child->setText(0, Text);
            this->ui->treeWidgetFathers->itemAt(0, i)->insertChild(0,child);
        }
        */
        this->ui->treeWidgetFathers->itemAt(0, i)->insertChild(0,this->GenealogicTree.at(i).ChildrenTreeItem);

    }
 /*
    //
    // ���������� �������� �������� ������
    //
    // �������� ���������� ��������� �������
    this->ChildTextList.clear();
    for(int i = 0; i < 10; i++)
        this->ChildTextList.append("Element" + QString::number(i));

    for(int i = 0; i < this->PatriarchTextList.count(); i++)
    {
        QString Text = this->PatriarchTextList.at(i);

        QTreeWidgetItem *itm = new QTreeWidgetItem;
        itm->setText(0, Text);
        this->ui->treeWidgetFathers->insertTopLevelItem(0, itm);

        // ���������� �������� ��������� � ��������� ��������
        for(int j = 0; j < this->ChildTextList.count(); j++)
        {
            QTreeWidgetItem *child = new QTreeWidgetItem;
            child->setText(0, this->ChildTextList.at(j));
            this->ui->treeWidgetFathers->itemAt(0, i)->insertChild(0,child);
        }
    }
*/
    //
    // ����� �������� � ������� ���������
    //
    QTreeWidgetItemIterator it(this->ui->treeWidgetFathers);
    //QString FindText = "12: ������ ������";
    //QString FindText = "19: �������� �������";
    QString FindText = "19";
    while (*it)
    {
        if ((*it)->text(0) == FindText)
        {
            (*it)->setSelected(true);
        }
        ++it;
    }

    return x;//������� ���������� ��������� � ���� ������

}//End of bool MainWindow::showPatriarchs()

