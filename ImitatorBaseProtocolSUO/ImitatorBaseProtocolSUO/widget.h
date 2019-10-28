#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QScrollBar>
#include "bpmessages.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    //---------------------------------------------------------------------
    // Конструктор, деструктор
    //---------------------------------------------------------------------
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    //---------------------------------------------------------------------
    // Слоты
    //---------------------------------------------------------------------
    void displayParsedMessage(QString parsedMessage);

    void on_applySettingsButton_clicked();

    void on_sendBPMessage_clicked();

    void on_sendBPMessage_2_clicked();

    void on_sendBPMessage_3_clicked();

    void on_sendBPMessage_4_clicked();

    void on_sendBPMessage_5_clicked();

    void on_sendBPMessage_6_clicked();

    void on_sendBPMessage_7_clicked();

    void on_sendBPMessage_8_clicked();

private:
    //---------------------------------------------------------------------
    // Атрибуты
    //---------------------------------------------------------------------
    Ui::Widget *ui;

    BaseProtocolHandler mBPMHandler;

    QString parseLog;

    //---------------------------------------------------------------------
    // Методы
    //---------------------------------------------------------------------
    void clearLog();

};

#endif // WIDGET_H
