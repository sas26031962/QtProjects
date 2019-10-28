#include "widget.h"
#include "ui_widget.h"

//---------------------------------------------------------------------
// Конструктор
//---------------------------------------------------------------------
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Node network control service (Base protocol)");

    on_applySettingsButton_clicked();
    connect(&mBPMHandler, SIGNAL(incParsedDatagram(QString)), this, SLOT(displayParsedMessage(QString)));

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_sendBPMessage_clicked()));
    QObject::connect(ui->pushButton_2 , SIGNAL(clicked()), this, SLOT(on_sendBPMessage_2_clicked()));
    QObject::connect(ui->pushButton_3 , SIGNAL(clicked()), this, SLOT(on_sendBPMessage_3_clicked()));
    QObject::connect(ui->pushButton_4 , SIGNAL(clicked()), this, SLOT(on_sendBPMessage_4_clicked()));
    QObject::connect(ui->pushButton_5 , SIGNAL(clicked()), this, SLOT(on_sendBPMessage_5_clicked()));
    QObject::connect(ui->pushButton_6 , SIGNAL(clicked()), this, SLOT(on_sendBPMessage_6_clicked()));
    QObject::connect(ui->pushButton_7 , SIGNAL(clicked()), this, SLOT(on_sendBPMessage_7_clicked()));
    QObject::connect(ui->pushButton_8 , SIGNAL(clicked()), this, SLOT(on_sendBPMessage_8_clicked()));

}

//---------------------------------------------------------------------
// Деструктор
//---------------------------------------------------------------------
Widget::~Widget()
{
    delete ui;
}

void Widget::on_applySettingsButton_clicked()
{
    mBPMHandler.setAddress(ui->nodePort->text().toInt(), ui->nodeIP->text());
    mBPMHandler.setListenPort(ui->listenPort->text().toInt());
}



//---------------------------------------------------------------------
// Очистка визуального элемента для логирования
//---------------------------------------------------------------------
void Widget::clearLog()
{
    this->parseLog.clear();
    this->ui->textBrowser->setText(parseLog);
}

void Widget::displayParsedMessage(QString parsedMessage)
{
    this->parseLog += parsedMessage + "\n\n";
    this->ui->textBrowser->setText(parseLog);

    this->ui->textBrowser->verticalScrollBar()->setValue(
                ui->textBrowser->verticalScrollBar()->maximum());
}



//---------------------------------------------------------------------
// Обработчики событий
//---------------------------------------------------------------------

void Widget::on_sendBPMessage_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button RESTART_NODE pressed...");

    mBPMHandler.transmit1();
}

void Widget::on_sendBPMessage_2_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button RESTART_ROUTINE pressed...");
//    mBPMHandler.transmit2();
}

void Widget::on_sendBPMessage_3_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button RESTART_CONNECTION pressed...");
//    mBPMHandler.transmit3();
}

void Widget::on_sendBPMessage_4_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button GO_TO_READY pressed...");
//    mBPMHandler.transmit4();
}

void Widget::on_sendBPMessage_5_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button START_NODE pressed...");
//    mBPMHandler.transmit5();
}

void Widget::on_sendBPMessage_6_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button STOP_NODE pressed...");
//    mBPMHandler.transmit6();
}

void Widget::on_sendBPMessage_7_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button REQUEST_NODE_STATE pressed...");
//    mBPMHandler.transmit7();
}

void Widget::on_sendBPMessage_8_clicked()
{
    clearLog();
    this->ui->textBrowser->append("button REQUEST_NODE_INFORMATION pressed...");
//    mBPMHandler.transmit8();
}
