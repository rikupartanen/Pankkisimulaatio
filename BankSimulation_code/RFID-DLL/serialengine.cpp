#include "serialengine.h"

SerialEngine::SerialEngine(QObject *parent):QObject(parent){
    QDebug() << "objectSerialPort olio luotu";
    objectQSerialPort = new QSerialPort;
    connect(objectQSerialPort, SIGNAL(readyRead)), this, SLOT(readPort());
}

SerialEngine::~SerialEngine(){
   qDebug() << "objectSerialPort olio poistettu";
   delete objectQSerialPort;
   objectQSerialPort = nullptr;
}

void SerialEngine::openSerialPort(){
    objectQSerialPort->setPortName("COM4");
    objectQSerialPort->setBaudRate(9600);
    objectQSerialPort->setDataBits(QSerialPort::Data8);
    objectQSerialPort->setParity(QSerialPort::NoParity);
    objectQSerialPort->setStopBits(QSerialPort::OneStop);
    objectQSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    if (objectQSerialPort->open(QIODevice::ReadWrite)){
        qDebug() << "Portti auki";
    }
    else
    {
        qDebug() << "Portti ei auennut";
    }
}

void SerialEngine::readPort(){
    qDebug() << "Luetaan dataa serial portilta";
    cardSerialNumber="";
    cardSerialNumber=objectQSerialPort->readAll();
    qDebug() << cardSerialNumber;
    qDebug() << "EMIT dataReadDone";
    emit readySignal();
}

QString SerialEngine::returnCardSerialNumber(){
    cardSerialNumber.remove(0,3);
    cardSerialNumber.chop(3);
    return cardSerialNumber;
}

void SerialEngine::closeSerialPort(){
    qDebug() << "Portti suljettu";
    objectQSerialPort->close();
}
