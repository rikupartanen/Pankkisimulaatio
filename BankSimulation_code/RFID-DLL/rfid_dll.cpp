#include "rfid_dll.h"

RFID_DLL::RFID_DLL(){
    objectSerialEngine = new SerialEngine;
    connect (objectSerialEngine, SIGNAL(readySignal)), this, SLOT(dllSerialPortSlot());
}


void rfid_dll::interfaceFunctionOpenSerialPort(){
    objectSerialEngine = new SerialEngine;
    connect (objectSerialEngine, SIGNAL(readySignal)),this, SLOT(dllSerialPortSlot());
    objectSerialEngine->openSerialPort();
}

QString RFID_DLL::interfaceFunctionReturnCardSerialNumber(){
    return dllCardSerialNumber;
}

void RFID_DLL::interfaceFunctionCloseSerialPort(){
    objectSerialEngine->closeSerialPort();
    delete objectSerialEngine;
    objectSerialEngine = nullptr;
}

void RFID_DLL::dllSerialPortSlot(){
    dllCardSerialNumber = objectSerialEngine->returnCardSerialNumber();
    emit dataReadDone();
}
