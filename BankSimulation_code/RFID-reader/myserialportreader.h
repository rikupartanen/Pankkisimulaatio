#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

class MySerialPortReader : public QObject
{
    Q_OBJECT
public:
    MySerialPortReader(QObject *parent = nullptr);
    ~MySerialPortReader();

    void OpenSerialPort();
    void CloseSerialPort();

    QString ReturnSerialPortData();

private:
    QSerialPort *ObjectQSerialPort = nullptr;
    QString SerialPortData;

private slots:
    void ReadSerialPort();

signals:
    void SerialPortDataReadDone();
};

#endif // MYSERIALPORTREADER_H
