#include "myserialportreader.h"

myserialportreader::myserialportreader()
{

}



// Tästä alkaa varma koodi rivillä 28

else {
QDebug() << "Serial port ei auennut":
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

            //En tiedä jatkuuko
