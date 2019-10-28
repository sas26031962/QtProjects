#include "widget.h"
#include <QApplication>

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //    //Enabling Cyrillic
    //    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //    QTextCodec::setCodecForCStrings(codec);

    Widget w;
    w.show();

    return a.exec();
}
