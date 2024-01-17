#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Tästä alkaa varma koodi, sitä ennen epävarma

QT_BEGIN_NAMESPACE
namespace ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MySerialPortReader * ObjectMySerialPortReader;

private slots:
    void on_PushButton_Clicked();
    void on_PushButton_2_Clicked;
    void ShowSerialportData();
};

#endif // MAINWINDOW_H
