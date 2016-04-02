/****************************************************************************
** Meta object code from reading C++ file 'Debug.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Debug.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Debug.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Debug[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      16,    6,    6,    6, 0x0a,
      43,    6,    6,    6, 0x0a,
      69,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Debug[] = {
    "Debug\0\0update()\0sliderChangeThreshold(int)\0"
    "sliderChangeMaxValue(int)\0salvar_settings()\0"
};

void Debug::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Debug *_t = static_cast<Debug *>(_o);
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->sliderChangeThreshold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sliderChangeMaxValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->salvar_settings(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Debug::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Debug::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Debug,
      qt_meta_data_Debug, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Debug::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Debug::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Debug::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Debug))
        return static_cast<void*>(const_cast< Debug*>(this));
    return QDialog::qt_metacast(_clname);
}

int Debug::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
