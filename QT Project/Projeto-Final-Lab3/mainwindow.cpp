#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduinounoserial.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino = new(ArduinoUnoSerial);

    qDebug() << "A porta do arduino está disponível? " << arduino->IsArduinoAvailable();

}

MainWindow::~MainWindow()
{
    delete ui;
}

