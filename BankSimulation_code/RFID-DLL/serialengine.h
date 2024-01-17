#ifndef SERIALENGINE_H
#define SERIALENGINE_H
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QObject>


class SerialEngine : public QObject{
    Q_OBJECT
public:
    explicit SerialEngine(QObject *parent = nullptr);
    ~SerialEngine();
    void openSerialPort();
    void closeSerialPort();
    QString returnCardSerialNumber();

private:
    QSerialPort * objectQSerialPort;
    QString cardSerialNumber;

signals:
    void readySignal();

private slots:
    void readPort();
};

#endif // SERIALENGINE_H
