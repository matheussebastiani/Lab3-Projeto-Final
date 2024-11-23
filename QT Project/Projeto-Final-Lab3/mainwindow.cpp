#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QWidget>
#include <QMessageBox>
#include "dealwithdata.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // arduino = new(ArduinoSerial);
  //  qDebug() << "A porta do arduino está disponível? " << arduino->IsArduinoAvailable();
  //  qDebug() << "A porta serial do Arduino é a " << arduino->getArduinoUnoSerialPortName();
    DealWithData *dados = new(DealWithData);
   //    arduino->SetupArduinoSerialPortRW();

    }


MainWindow::~MainWindow()
{
    delete ui;
  //  delete arduino;
}

void updateMainWindow(QString dados){



}
