/****************************************************************************
** Meta object code from reading C++ file 'Form_VLSensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Gui/include/Form_VLSensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Form_VLSensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form_VLSensor_t {
    QByteArrayData data[10];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form_VLSensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form_VLSensor_t qt_meta_stringdata_Form_VLSensor = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Form_VLSensor"
QT_MOC_LITERAL(1, 14, 29), // "on_LiDAR1_Btn_InvertZ_toggled"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 5), // "state"
QT_MOC_LITERAL(4, 51, 31), // "on_LiDAR1_Btn_ShowLines_toggled"
QT_MOC_LITERAL(5, 83, 35), // "on_LiDAR1_Slider_Range_valueC..."
QT_MOC_LITERAL(6, 119, 12), // "nSliderValue"
QT_MOC_LITERAL(7, 132, 29), // "on_LiDAR2_Btn_InvertZ_toggled"
QT_MOC_LITERAL(8, 162, 31), // "on_LiDAR2_Btn_ShowLines_toggled"
QT_MOC_LITERAL(9, 194, 35) // "on_LiDAR2_Slider_Range_valueC..."

    },
    "Form_VLSensor\0on_LiDAR1_Btn_InvertZ_toggled\0"
    "\0state\0on_LiDAR1_Btn_ShowLines_toggled\0"
    "on_LiDAR1_Slider_Range_valueChanged\0"
    "nSliderValue\0on_LiDAR2_Btn_InvertZ_toggled\0"
    "on_LiDAR2_Btn_ShowLines_toggled\0"
    "on_LiDAR2_Slider_Range_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form_VLSensor[] = {

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
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       7,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void Form_VLSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Form_VLSensor *_t = static_cast<Form_VLSensor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_LiDAR1_Btn_InvertZ_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_LiDAR1_Btn_ShowLines_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_LiDAR1_Slider_Range_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_LiDAR2_Btn_InvertZ_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_LiDAR2_Btn_ShowLines_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_LiDAR2_Slider_Range_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Form_VLSensor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Form_VLSensor.data,
      qt_meta_data_Form_VLSensor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Form_VLSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_VLSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form_VLSensor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Form_VLSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
