/****************************************************************************
** Meta object code from reading C++ file 'multiwin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "multiwin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Multiwin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      30,    9,    9,    9, 0x0a,
      53,    9,    9,    9, 0x0a,
      74,    9,    9,    9, 0x0a,
      94,    9,    9,    9, 0x0a,
     114,    9,    9,    9, 0x0a,
     135,    9,    9,    9, 0x0a,
     156,    9,    9,    9, 0x0a,
     176,    9,    9,    9, 0x0a,
     196,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Multiwin[] = {
    "Multiwin\0\0loadButtonClicked()\0"
    "inspectButtonClicked()\0closeButtonClicked()\0"
    "hideButtonClicked()\0quitButtonClicked()\0"
    "quitButton2Clicked()\0breakButtonClicked()\0"
    "contButtonClicked()\0stepButtonClicked()\0"
    "updateButtonClicked()\0"
};

void Multiwin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Multiwin *_t = static_cast<Multiwin *>(_o);
        switch (_id) {
        case 0: _t->loadButtonClicked(); break;
        case 1: _t->inspectButtonClicked(); break;
        case 2: _t->closeButtonClicked(); break;
        case 3: _t->hideButtonClicked(); break;
        case 4: _t->quitButtonClicked(); break;
        case 5: _t->quitButton2Clicked(); break;
        case 6: _t->breakButtonClicked(); break;
        case 7: _t->contButtonClicked(); break;
        case 8: _t->stepButtonClicked(); break;
        case 9: _t->updateButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Multiwin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Multiwin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Multiwin,
      qt_meta_data_Multiwin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Multiwin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Multiwin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Multiwin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Multiwin))
        return static_cast<void*>(const_cast< Multiwin*>(this));
    return QWidget::qt_metacast(_clname);
}

int Multiwin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
