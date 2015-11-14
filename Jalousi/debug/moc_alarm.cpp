/****************************************************************************
** Meta object code from reading C++ file 'alarm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../alarm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AlarmModel_t {
    QByteArrayData data[14];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlarmModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlarmModel_t qt_meta_stringdata_AlarmModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AlarmModel"
QT_MOC_LITERAL(1, 11, 3), // "add"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 4), // "time"
QT_MOC_LITERAL(4, 21, 4), // "week"
QT_MOC_LITERAL(5, 26, 6), // "repeat"
QT_MOC_LITERAL(6, 33, 4), // "open"
QT_MOC_LITERAL(7, 38, 6), // "remove"
QT_MOC_LITERAL(8, 45, 3), // "row"
QT_MOC_LITERAL(9, 49, 6), // "r_time"
QT_MOC_LITERAL(10, 56, 6), // "r_week"
QT_MOC_LITERAL(11, 63, 8), // "r_repeat"
QT_MOC_LITERAL(12, 72, 6), // "r_open"
QT_MOC_LITERAL(13, 79, 6) // "r_isOn"

    },
    "AlarmModel\0add\0\0time\0week\0repeat\0open\0"
    "remove\0row\0r_time\0r_week\0r_repeat\0"
    "r_open\0r_isOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlarmModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x0a /* Public */,
       7,    1,   58,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,
      10,    0,   62,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,
      12,    0,   64,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void AlarmModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlarmModel *_t = static_cast<AlarmModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->r_time();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->r_week();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->r_repeat();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->r_open();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->r_isOn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject AlarmModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_AlarmModel.data,
      qt_meta_data_AlarmModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AlarmModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlarmModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AlarmModel.stringdata0))
        return static_cast<void*>(const_cast< AlarmModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int AlarmModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
