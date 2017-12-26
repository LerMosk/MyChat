/****************************************************************************
** Meta object code from reading C++ file 'myclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CLIENT/myclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyClient_t {
    QByteArrayData data[25];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyClient_t qt_meta_stringdata_MyClient = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyClient"
QT_MOC_LITERAL(1, 9, 7), // "Checked"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "Verification"
QT_MOC_LITERAL(4, 31, 10), // "MyCallRead"
QT_MOC_LITERAL(5, 42, 9), // "goToLogin"
QT_MOC_LITERAL(6, 52, 13), // "slotReadyRead"
QT_MOC_LITERAL(7, 66, 12), // "slotReadFile"
QT_MOC_LITERAL(8, 79, 13), // "slotTrySignUp"
QT_MOC_LITERAL(9, 93, 12), // "slotTryLogin"
QT_MOC_LITERAL(10, 106, 15), // "ShowContextMenu"
QT_MOC_LITERAL(11, 122, 9), // "slotError"
QT_MOC_LITERAL(12, 132, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(13, 161, 16), // "slotSendToServer"
QT_MOC_LITERAL(14, 178, 25), // "on_listWidget_itemClicked"
QT_MOC_LITERAL(15, 204, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(16, 221, 4), // "item"
QT_MOC_LITERAL(17, 226, 13), // "slotCloseMain"
QT_MOC_LITERAL(18, 240, 30), // "on_tabWidget_tabCloseRequested"
QT_MOC_LITERAL(19, 271, 5), // "index"
QT_MOC_LITERAL(20, 277, 13), // "slotOpenLogin"
QT_MOC_LITERAL(21, 291, 14), // "slotOpenSignUp"
QT_MOC_LITERAL(22, 306, 14), // "slotChangeUser"
QT_MOC_LITERAL(23, 321, 17), // "slotDeleteAccount"
QT_MOC_LITERAL(24, 339, 12) // "slotSendFile"

    },
    "MyClient\0Checked\0\0Verification\0"
    "MyCallRead\0goToLogin\0slotReadyRead\0"
    "slotReadFile\0slotTrySignUp\0slotTryLogin\0"
    "ShowContextMenu\0slotError\0"
    "QAbstractSocket::SocketError\0"
    "slotSendToServer\0on_listWidget_itemClicked\0"
    "QListWidgetItem*\0item\0slotCloseMain\0"
    "on_tabWidget_tabCloseRequested\0index\0"
    "slotOpenLogin\0slotOpenSignUp\0"
    "slotChangeUser\0slotDeleteAccount\0"
    "slotSendFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       3,    1,  112,    2, 0x06 /* Public */,
       4,    0,  115,    2, 0x06 /* Public */,
       5,    0,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  117,    2, 0x08 /* Private */,
       7,    0,  118,    2, 0x08 /* Private */,
       8,    2,  119,    2, 0x08 /* Private */,
       9,    2,  124,    2, 0x08 /* Private */,
      10,    1,  129,    2, 0x08 /* Private */,
      11,    1,  132,    2, 0x08 /* Private */,
      13,    0,  135,    2, 0x08 /* Private */,
      14,    1,  136,    2, 0x08 /* Private */,
      17,    0,  139,    2, 0x08 /* Private */,
      18,    1,  140,    2, 0x08 /* Private */,
      20,    0,  143,    2, 0x08 /* Private */,
      21,    0,  144,    2, 0x08 /* Private */,
      22,    0,  145,    2, 0x08 /* Private */,
      23,    0,  146,    2, 0x08 /* Private */,
      24,    0,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyClient *_t = static_cast<MyClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Checked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->Verification((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->MyCallRead(); break;
        case 3: _t->goToLogin(); break;
        case 4: _t->slotReadyRead(); break;
        case 5: _t->slotReadFile(); break;
        case 6: _t->slotTrySignUp((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->slotTryLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->ShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 10: _t->slotSendToServer(); break;
        case 11: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->slotCloseMain(); break;
        case 13: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->slotOpenLogin(); break;
        case 15: _t->slotOpenSignUp(); break;
        case 16: _t->slotChangeUser(); break;
        case 17: _t->slotDeleteAccount(); break;
        case 18: _t->slotSendFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyClient::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClient::Checked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyClient::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClient::Verification)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClient::MyCallRead)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyClient::goToLogin)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MyClient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyClient.data,
      qt_meta_data_MyClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyClient.stringdata0))
        return static_cast<void*>(const_cast< MyClient*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MyClient::Checked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyClient::Verification(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyClient::MyCallRead()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MyClient::goToLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
