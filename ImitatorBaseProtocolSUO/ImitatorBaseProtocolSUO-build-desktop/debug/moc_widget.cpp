/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Tue 21. Feb 09:36:26 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ImitatorBaseProtocolSUO/widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,    8,    7,    7, 0x08,
      52,    7,    7,    7, 0x08,
      85,    7,    7,    7, 0x08,
     112,    7,    7,    7, 0x08,
     141,    7,    7,    7, 0x08,
     170,    7,    7,    7, 0x08,
     199,    7,    7,    7, 0x08,
     228,    7,    7,    7, 0x08,
     257,    7,    7,    7, 0x08,
     286,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0parsedMessage\0"
    "displayParsedMessage(QString)\0"
    "on_applySettingsButton_clicked()\0"
    "on_sendBPMessage_clicked()\0"
    "on_sendBPMessage_2_clicked()\0"
    "on_sendBPMessage_3_clicked()\0"
    "on_sendBPMessage_4_clicked()\0"
    "on_sendBPMessage_5_clicked()\0"
    "on_sendBPMessage_6_clicked()\0"
    "on_sendBPMessage_7_clicked()\0"
    "on_sendBPMessage_8_clicked()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: displayParsedMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_applySettingsButton_clicked(); break;
        case 2: on_sendBPMessage_clicked(); break;
        case 3: on_sendBPMessage_2_clicked(); break;
        case 4: on_sendBPMessage_3_clicked(); break;
        case 5: on_sendBPMessage_4_clicked(); break;
        case 6: on_sendBPMessage_5_clicked(); break;
        case 7: on_sendBPMessage_6_clicked(); break;
        case 8: on_sendBPMessage_7_clicked(); break;
        case 9: on_sendBPMessage_8_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
