#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义一个结构体，用来存放串口各个参数
    struct PortSettings myComSetting = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 500};

    //定义串口对象，并传递参数，在构造函数里对其进行初始化
    mycom = new Win_QextSerialPort("com1", myComSetting, QextSerialBase::EventDriven);

    //以可读可写方式打开串口
    mycom->open(QIODevice::ReadWrite);

    //信号和槽函数相关联，相当于串口接收缓冲区，缓冲区有数据时进行读串口操作
    connect(mycom, SIGNAL(readyRead()), this, SLOT(readMyCom()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
