/****************************************************************************
** Meta object code from reading C++ file 'jalousi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "jalousi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jalousi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Jalousi_t {
    QByteArrayData data[9];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Jalousi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Jalousi_t qt_meta_stringdata_Jalousi = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Jalousi"
QT_MOC_LITERAL(1, 8, 8), // "discover"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 2), // "up"
QT_MOC_LITERAL(4, 21, 3), // "num"
QT_MOC_LITERAL(5, 25, 4), // "down"
QT_MOC_LITERAL(6, 30, 4), // "stop"
QT_MOC_LITERAL(7, 35, 4), // "time"
QT_MOC_LITERAL(8, 40, 4) // "file"

    },
    "Jalousi\0discover\0\0up\0num\0down\0stop\0"
    "time\0file"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Jalousi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    1,   51,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Char,    4,
    QMetaType::Void, QMetaType::Char,    4,
    QMetaType::Void, QMetaType::Char,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Jalousi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Jalousi *_t = static_cast<Jalousi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->discover(); break;
        case 1: _t->up((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 2: _t->down((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 3: _t->stop((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 4: _t->time(); break;
        case 5: _t->file(); break;
        default: ;
        }
    }
}

const QMetaObject Jalousi::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Jalousi.data,
      qt_meta_data_Jalousi,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Jalousi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Jalousi::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Jalousi.stringdata0))
        return static_cast<void*>(const_cast< Jalousi*>(this));
    return QObject::qt_metacast(_clname);
}

int Jalousi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
