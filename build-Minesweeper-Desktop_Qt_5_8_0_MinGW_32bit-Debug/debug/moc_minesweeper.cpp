/****************************************************************************
** Meta object code from reading C++ file 'minesweeper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Minesweeper/minesweeper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minesweeper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MineSweeper_t {
    QByteArrayData data[7];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MineSweeper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MineSweeper_t qt_meta_stringdata_MineSweeper = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MineSweeper"
QT_MOC_LITERAL(1, 12, 10), // "bombMarked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "bombUnMarked"
QT_MOC_LITERAL(4, 37, 10), // "addToTimer"
QT_MOC_LITERAL(5, 48, 8), // "gameOver"
QT_MOC_LITERAL(6, 57, 11) // "gameStarted"

    },
    "MineSweeper\0bombMarked\0\0bombUnMarked\0"
    "addToTimer\0gameOver\0gameStarted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MineSweeper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,
       6,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void MineSweeper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MineSweeper *_t = static_cast<MineSweeper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bombMarked(); break;
        case 1: _t->bombUnMarked(); break;
        case 2: _t->addToTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->gameOver((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->gameStarted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MineSweeper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MineSweeper::bombMarked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MineSweeper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MineSweeper::bombUnMarked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MineSweeper::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MineSweeper::addToTimer)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MineSweeper::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MineSweeper::gameOver)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MineSweeper::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MineSweeper::gameStarted)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MineSweeper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MineSweeper.data,
      qt_meta_data_MineSweeper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MineSweeper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MineSweeper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MineSweeper.stringdata0))
        return static_cast<void*>(const_cast< MineSweeper*>(this));
    return QObject::qt_metacast(_clname);
}

int MineSweeper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MineSweeper::bombMarked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MineSweeper::bombUnMarked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MineSweeper::addToTimer(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MineSweeper::gameOver(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MineSweeper::gameStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
