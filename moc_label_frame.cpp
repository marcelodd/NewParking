/****************************************************************************
** Meta object code from reading C++ file 'label_frame.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "label_frame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'label_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_label_frame[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      29,   12,   12,   12, 0x05,
      46,   12,   12,   12, 0x05,
      59,   12,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_label_frame[] = {
    "label_frame\0\0Mouse_Pressed()\0"
    "Mouse_Position()\0Mouse_Left()\0"
    "Mouse_Release()\0"
};

void label_frame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        label_frame *_t = static_cast<label_frame *>(_o);
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->Mouse_Position(); break;
        case 2: _t->Mouse_Left(); break;
        case 3: _t->Mouse_Release(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData label_frame::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject label_frame::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_label_frame,
      qt_meta_data_label_frame, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &label_frame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *label_frame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *label_frame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_label_frame))
        return static_cast<void*>(const_cast< label_frame*>(this));
    return QLabel::qt_metacast(_clname);
}

int label_frame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void label_frame::Mouse_Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void label_frame::Mouse_Position()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void label_frame::Mouse_Left()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void label_frame::Mouse_Release()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
