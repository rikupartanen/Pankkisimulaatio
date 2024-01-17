#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include <QDebug>
#include "dllserialport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DLLSerialPort * pSerialPort;
    QString RFID;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void receiveSignalFromDLL(QString);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
