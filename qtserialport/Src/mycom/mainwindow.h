#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "win_qextserialport.h" //加入头文件


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Win_QextSerialPort *mycom;  //声明对象

private slots:
    void readMyCom();   //声明读串口槽函数

};

#endif // MAINWINDOW_H
