/****************************************************************************
** Meta object code from reading C++ file 'rclcomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/hmi/include/rclcomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rclcomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rclcomm_t {
    QByteArrayData data[13];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rclcomm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rclcomm_t qt_meta_stringdata_rclcomm = {
    {
QT_MOC_LITERAL(0, 0, 7), // "rclcomm"
QT_MOC_LITERAL(1, 8, 16), // "emitGpsTopicData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "emitGlobalData"
QT_MOC_LITERAL(4, 41, 14), // "QVector<qreal>"
QT_MOC_LITERAL(5, 56, 13), // "emitLocalData"
QT_MOC_LITERAL(6, 70, 14), // "emitLocalData1"
QT_MOC_LITERAL(7, 85, 16), // "emitCamTopicData"
QT_MOC_LITERAL(8, 102, 18), // "emitLidarTopicData"
QT_MOC_LITERAL(9, 121, 12), // "emitstopline"
QT_MOC_LITERAL(10, 134, 16), // "recvDestCallback"
QT_MOC_LITERAL(11, 151, 24), // "recvVelocityAndGearsData"
QT_MOC_LITERAL(12, 176, 15) // "QVector<qint64>"

    },
    "rclcomm\0emitGpsTopicData\0\0emitGlobalData\0"
    "QVector<qreal>\0emitLocalData\0"
    "emitLocalData1\0emitCamTopicData\0"
    "emitLidarTopicData\0emitstopline\0"
    "recvDestCallback\0recvVelocityAndGearsData\0"
    "QVector<qint64>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rclcomm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   59,    2, 0x06 /* Public */,
       3,    1,   68,    2, 0x06 /* Public */,
       5,    1,   71,    2, 0x06 /* Public */,
       6,    1,   74,    2, 0x06 /* Public */,
       7,    1,   77,    2, 0x06 /* Public */,
       8,    1,   80,    2, 0x06 /* Public */,
       9,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   86,    2, 0x08 /* Private */,
      11,    1,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QReal,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    2,
    QMetaType::Void, 0x80000000 | 12,    2,

       0        // eod
};

void rclcomm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rclcomm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitGpsTopicData((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->emitGlobalData((*reinterpret_cast< QVector<qreal>(*)>(_a[1]))); break;
        case 2: _t->emitLocalData((*reinterpret_cast< QVector<qreal>(*)>(_a[1]))); break;
        case 3: _t->emitLocalData1((*reinterpret_cast< QVector<qreal>(*)>(_a[1]))); break;
        case 4: _t->emitCamTopicData((*reinterpret_cast< QVector<qreal>(*)>(_a[1]))); break;
        case 5: _t->emitLidarTopicData((*reinterpret_cast< QVector<qreal>(*)>(_a[1]))); break;
        case 6: _t->emitstopline((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->recvDestCallback((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 8: _t->recvVelocityAndGearsData((*reinterpret_cast< QVector<qint64>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qreal> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qreal> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qreal> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qreal> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qreal> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<qint64> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (rclcomm::*)(qreal , qreal , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rclcomm::emitGpsTopicData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (rclcomm::*)(QVector<qreal> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rclcomm::emitGlobalData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (rclcomm::*)(QVector<qreal> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rclcomm::emitLocalData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (rclcomm::*)(QVector<qreal> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rclcomm::emitLocalData1)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (rclcomm::*)(QVector<qreal> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rclcomm::emitCamTopicData)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (rclcomm::*)(QVector<qreal> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rclcomm::emitLidarTopicData)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (rclcomm::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rclcomm::emitstopline)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rclcomm::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_rclcomm.data,
    qt_meta_data_rclcomm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rclcomm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rclcomm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rclcomm.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int rclcomm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void rclcomm::emitGpsTopicData(qreal _t1, qreal _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rclcomm::emitGlobalData(QVector<qreal> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rclcomm::emitLocalData(QVector<qreal> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rclcomm::emitLocalData1(QVector<qreal> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rclcomm::emitCamTopicData(QVector<qreal> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void rclcomm::emitLidarTopicData(QVector<qreal> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void rclcomm::emitstopline(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
