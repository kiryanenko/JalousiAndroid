/****************************************************************************
** Meta object code from reading C++ file 'bluetooth.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bluetooth.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetooth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Bluetooth_t {
    QByteArrayData data[8];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bluetooth_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bluetooth_t qt_meta_stringdata_Bluetooth = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Bluetooth"
QT_MOC_LITERAL(1, 10, 16), // "deviceDiscovered"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(4, 49, 4), // "info"
QT_MOC_LITERAL(5, 54, 5), // "error"
QT_MOC_LITERAL(6, 60, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(7, 98, 3) // "err"

    },
    "Bluetooth\0deviceDiscovered\0\0"
    "QBluetoothDeviceInfo\0info\0error\0"
    "QBluetoothDeviceDiscoveryAgent::Error\0"
    "err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bluetooth[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       5,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void Bluetooth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Bluetooth *_t = static_cast<Bluetooth *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceDiscovered((*reinterpret_cast< QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        }
    }
}

const QMetaObject Bluetooth::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_Bluetooth.data,
      qt_meta_data_Bluetooth,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Bluetooth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bluetooth::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Bluetooth.stringdata0))
        return static_cast<void*>(const_cast< Bluetooth*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int Bluetooth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
