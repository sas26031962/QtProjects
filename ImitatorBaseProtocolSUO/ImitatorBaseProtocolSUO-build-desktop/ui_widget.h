/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue 21. Feb 12:03:09 2017
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textBrowser;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nodeIP;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *listenPort;
    QLineEdit *nodePort;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_Exit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(445, 344);
        textBrowser = new QTextEdit(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(190, 20, 201, 171));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(190, 200, 251, 101));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 46, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 20, 61, 16));
        nodeIP = new QLineEdit(groupBox);
        nodeIP->setObjectName(QString::fromUtf8("nodeIP"));
        nodeIP->setGeometry(QRect(50, 40, 111, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 41, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 31, 21));
        listenPort = new QLineEdit(groupBox);
        listenPort->setObjectName(QString::fromUtf8("listenPort"));
        listenPort->setGeometry(QRect(170, 70, 61, 20));
        nodePort = new QLineEdit(groupBox);
        nodePort->setObjectName(QString::fromUtf8("nodePort"));
        nodePort->setGeometry(QRect(170, 40, 61, 20));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 171, 23));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 50, 171, 23));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 80, 171, 23));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 130, 171, 23));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 160, 171, 23));
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 190, 171, 23));
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 240, 171, 23));
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 270, 171, 23));
        pushButton_Exit = new QPushButton(Widget);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(370, 310, 75, 23));

        retranslateUi(Widget);
        QObject::connect(pushButton_Exit, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Widget", "Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "IP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "Port", 0, QApplication::UnicodeUTF8));
        nodeIP->setText(QApplication::translate("Widget", "192.168.100.2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "Remote", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "Local", 0, QApplication::UnicodeUTF8));
        listenPort->setText(QApplication::translate("Widget", "15001", 0, QApplication::UnicodeUTF8));
        nodePort->setText(QApplication::translate("Widget", "15000", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "Restart node", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "Restart routine", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Widget", "Restart connection", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Widget", "Got to ready", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Widget", "Start node", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Widget", "Stop node", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Widget", "Request node state", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Widget", "Request node info", 0, QApplication::UnicodeUTF8));
        pushButton_Exit->setText(QApplication::translate("Widget", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
