/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Minesweeper/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "updateTimer"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(4, 47, 26), // "on_highscoreButton_clicked"
QT_MOC_LITERAL(5, 74, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(6, 97, 27), // "on_gamePauseShortcutPressed"
QT_MOC_LITERAL(7, 125, 23), // "on_actionMute_triggered"
QT_MOC_LITERAL(8, 149, 27), // "on_actionImmortal_triggered"
QT_MOC_LITERAL(9, 177, 29), // "on_actionGame_Rules_triggered"
QT_MOC_LITERAL(10, 207, 32), // "on_actionGame_Controls_triggered"
QT_MOC_LITERAL(11, 240, 13), // "setButtonText"
QT_MOC_LITERAL(12, 254, 24), // "decreaseBombDisplayCount"
QT_MOC_LITERAL(13, 279, 24), // "increaseBombDisplayCount"
QT_MOC_LITERAL(14, 304, 10), // "addToTimer"
QT_MOC_LITERAL(15, 315, 12), // "gameFinished"
QT_MOC_LITERAL(16, 328, 9) // "startTime"

    },
    "MainWindow\0updateTimer\0\0on_clearButton_clicked\0"
    "on_highscoreButton_clicked\0"
    "on_pauseButton_clicked\0"
    "on_gamePauseShortcutPressed\0"
    "on_actionMute_triggered\0"
    "on_actionImmortal_triggered\0"
    "on_actionGame_Rules_triggered\0"
    "on_actionGame_Controls_triggered\0"
    "setButtonText\0decreaseBombDisplayCount\0"
    "increaseBombDisplayCount\0addToTimer\0"
    "gameFinished\0startTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    1,   98,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    1,  103,    2, 0x08 /* Private */,
      15,    1,  106,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTimer(); break;
        case 1: _t->on_clearButton_clicked(); break;
        case 2: _t->on_highscoreButton_clicked(); break;
        case 3: _t->on_pauseButton_clicked(); break;
        case 4: _t->on_gamePauseShortcutPressed(); break;
        case 5: _t->on_actionMute_triggered(); break;
        case 6: _t->on_actionImmortal_triggered(); break;
        case 7: _t->on_actionGame_Rules_triggered(); break;
        case 8: _t->on_actionGame_Controls_triggered(); break;
        case 9: _t->setButtonText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->decreaseBombDisplayCount(); break;
        case 11: _t->increaseBombDisplayCount(); break;
        case 12: _t->addToTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->gameFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->startTime(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
