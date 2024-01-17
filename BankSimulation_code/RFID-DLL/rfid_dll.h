#ifndef RFID_DLL_H
#define RFID_DLL_H

#include "rfid_dll_global.h"
#include "serialengine.h"
#include <QObject>
#include <QDebug>

class rfid_dll:public QObject{
Q_Object
public:
    RFID_DLLSHARED_EXPORT DLLSerialPort();
    void interfaceFunctionOpenSerialPort();
    void interfaceFunctionCloseSerialPort();
    QString interfaceFunctionReturnCardSerialNumber();
private:
    QString dllCardSerialNumber;
    SerialEngine *objectSerialEngine;
private slots:
    void dllSerialPortSlot();
signals:
    void dataReadDone();
};

#endif // RFID_DLL_H
