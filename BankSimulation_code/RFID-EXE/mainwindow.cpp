#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("Paavalikko");

    pSerialPort=new DLLSerialPort(this);
    connect(pSerialPort, SIGNAL(cardNumberToEXE(QString)), this, SLOT(receiveSignalFromDLL(QString)));

    pSerialPort->openSerialPort();
}

MainWindow::~MainWindow(){
    delete ui;
    ui=nullptr;
}

void MainWindow::receiveSignalFromDLL(QString cardSerialNumber){
    RFID=cardSerialNumber;
   // qDebug() << "EXE serial"+ RFID;
}

void MainWindow::on_pushButton_clicked()
{
    pSerialPort->SignalReadyToRead();
    ui->textEdit->setText(RFID);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    pSerialPort->closeSerialPort();
}
