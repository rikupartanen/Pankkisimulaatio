#include "myserialportreader.h"

MySerialPortReader::MySerialPortReader(QObject *parent): QObject(parent){
    ObjectQSerialPort = new QSerialPort;
    connect(ObjectQSerialPort,SIGNAL(readyRead)),this,SLOT(ReadSerialPort)));
    qDebug() <<"1 connect readyread/ReadSerialPort";
}

MySerialPortReader::-MySerialPortReader(){
    delete ObjectQSerialPort;
    ObjectQSerialPort = nullptr;
    qDebug() << "ObjectQSerialPort destroyed";
}

void MySerialPortReader::OpenSerialPort(){
   ObjectQSerialPort->setPortName("COM4");
   ObjectQSerialPort->setBaudRate(QSerialPort::Baud9600);
   ObjectQSerialPort->setDataBits(QSerialPort::Data8);
   ObjectQSerialPort->setParity(QSerialPort::NoParity);
   ObjectQSerialPort->setStopBits(QSerialPort::OneStop);
   ObjectQSerialPort->setFlowControl(QSerialPort::NoFlowControl);

   if(ObjectQSerialPort->open(QIODevice::ReadWrite)){
       qDebug() << "Serial port on auki";
   }
   else{
       qDebug() << "Serial portin aukaiseminen epäonnistui";
   }
}

QString MySerialPortReader::ReturnSerialPortData(){
    return SerialPortData;
}

void MySerialPortReader::ReadSerialPort(){
    SerialPortData="";
    SerialPortData=ObjectQSerialPort->readAll();
    SerialPortData.remove(0,3);
    SerialPortData.chop(3);
    qDebug() << SerialPortData;
    emit SerialPortDataDone();
    qDebug() <<"2 data emitted";
}

void MySerialPortReader::CloseSerialPort(){
    ObjectQSerialPort->close();
    qDebug() << "Serial port on kiinni";
}
