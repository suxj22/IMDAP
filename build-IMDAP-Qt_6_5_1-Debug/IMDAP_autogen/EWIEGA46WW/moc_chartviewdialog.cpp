/****************************************************************************
** Meta object code from reading C++ file 'chartviewdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../IMDAP/chartviewdialog.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartviewdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSChartViewDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSChartViewDialogENDCLASS = QtMocHelpers::stringData(
    "ChartViewDialog",
    "on_exportImageButton_clicked",
    "",
    "on_copyToClipboardButton_clicked",
    "on_ScatterCheckBox_stateChanged",
    "arg1",
    "on_SplineCheckBox_stateChanged",
    "handlePointHovered",
    "point",
    "state"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSChartViewDialogENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[16];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[33];
    char stringdata4[32];
    char stringdata5[5];
    char stringdata6[31];
    char stringdata7[19];
    char stringdata8[6];
    char stringdata9[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSChartViewDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSChartViewDialogENDCLASS_t qt_meta_stringdata_CLASSChartViewDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "ChartViewDialog"
        QT_MOC_LITERAL(16, 28),  // "on_exportImageButton_clicked"
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 32),  // "on_copyToClipboardButton_clicked"
        QT_MOC_LITERAL(79, 31),  // "on_ScatterCheckBox_stateChanged"
        QT_MOC_LITERAL(111, 4),  // "arg1"
        QT_MOC_LITERAL(116, 30),  // "on_SplineCheckBox_stateChanged"
        QT_MOC_LITERAL(147, 18),  // "handlePointHovered"
        QT_MOC_LITERAL(166, 5),  // "point"
        QT_MOC_LITERAL(172, 5)   // "state"
    },
    "ChartViewDialog",
    "on_exportImageButton_clicked",
    "",
    "on_copyToClipboardButton_clicked",
    "on_ScatterCheckBox_stateChanged",
    "arg1",
    "on_SplineCheckBox_stateChanged",
    "handlePointHovered",
    "point",
    "state"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSChartViewDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    1,   46,    2, 0x08,    3 /* Private */,
       6,    1,   49,    2, 0x08,    5 /* Private */,
       7,    2,   52,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,    8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject ChartViewDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSChartViewDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSChartViewDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSChartViewDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ChartViewDialog, std::true_type>,
        // method 'on_exportImageButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_copyToClipboardButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ScatterCheckBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_SplineCheckBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handlePointHovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPointF &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void ChartViewDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChartViewDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_exportImageButton_clicked(); break;
        case 1: _t->on_copyToClipboardButton_clicked(); break;
        case 2: _t->on_ScatterCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_SplineCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->handlePointHovered((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *ChartViewDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartViewDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSChartViewDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ChartViewDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
