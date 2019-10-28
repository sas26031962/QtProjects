/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 1. Aug 07:26:03 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtSQL0/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      28,   11,   11,   11, 0x08,
      44,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
      95,   93,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     155,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     226,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     252,   11,   11,   11, 0x08,
     273,   11,   11,   11, 0x08,
     294,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     326,   11,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,
     369,   11,   11,   11, 0x08,
     387,   11,   11,   11, 0x08,
     406,   11,   11,   11, 0x08,
     420,   11,   11,   11, 0x08,
     435,   11,   11,   11, 0x08,
     456,   11,  451,   11, 0x08,
     473,   11,   11,   11, 0x08,
     505,   11,   11,   11, 0x08,
     530,   11,   11,   11, 0x08,
     557,   11,   11,   11, 0x08,
     581,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0viewTableList()\0viewFieldList()\0"
    "insertData()\0viewData()\0updateData()\0"
    "selectRow()\0i\0clickListData(QModelIndex)\0"
    "executeRequest()\0deleteRequest()\0"
    "selectRequest()\0grabTable()\0"
    "grabTableField()\0grabField1()\0"
    "grabField2()\0grabField3()\0grabField4()\0"
    "insertRelationship()\0updateRelationship()\0"
    "viewRelationship()\0viewEvents()\0"
    "insertEvents()\0updateEvents()\0"
    "viewObject()\0viewObjectEvent()\0"
    "viewSubjectEvent()\0viewSubject()\0"
    "viewRelation()\0viewEventType()\0bool\0"
    "showPatriarchs()\0ViewRelationshipsRecordsCount()\0"
    "ViewPersonRecordsCount()\0"
    "ViewRelationRecordsCount()\0"
    "ViewEventRecordsCount()\0"
    "ViewEventTypeRecordsCount()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: viewTableList(); break;
        case 1: viewFieldList(); break;
        case 2: insertData(); break;
        case 3: viewData(); break;
        case 4: updateData(); break;
        case 5: selectRow(); break;
        case 6: clickListData((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: executeRequest(); break;
        case 8: deleteRequest(); break;
        case 9: selectRequest(); break;
        case 10: grabTable(); break;
        case 11: grabTableField(); break;
        case 12: grabField1(); break;
        case 13: grabField2(); break;
        case 14: grabField3(); break;
        case 15: grabField4(); break;
        case 16: insertRelationship(); break;
        case 17: updateRelationship(); break;
        case 18: viewRelationship(); break;
        case 19: viewEvents(); break;
        case 20: insertEvents(); break;
        case 21: updateEvents(); break;
        case 22: viewObject(); break;
        case 23: viewObjectEvent(); break;
        case 24: viewSubjectEvent(); break;
        case 25: viewSubject(); break;
        case 26: viewRelation(); break;
        case 27: viewEventType(); break;
        case 28: { bool _r = showPatriarchs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: ViewRelationshipsRecordsCount(); break;
        case 30: ViewPersonRecordsCount(); break;
        case 31: ViewRelationRecordsCount(); break;
        case 32: ViewEventRecordsCount(); break;
        case 33: ViewEventTypeRecordsCount(); break;
        default: ;
        }
        _id -= 34;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
