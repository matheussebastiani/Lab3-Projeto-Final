#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduinounoserial.h"
#include <QWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // arduino = new(ArduinoUnoSerial);

  //  qDebug() << "A porta do arduino está disponível? " << arduino->IsArduinoAvailable();
  //  qDebug() << "A porta serial do Arduino é a " << arduino->getArduinoUnoSerialPortName();

   //    arduino->SetupArduinoSerialPortRW();

    }



MainWindow::~MainWindow()
{
    delete ui;
    //delete arduino;
}

