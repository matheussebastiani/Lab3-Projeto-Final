#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include "dealwithdata.h"
#include "arduinoserial.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow), Arduino(nullptr), data(nullptr){

    ui->setupUi(this);
    Arduino = new ArduinoSerial(this);
    data = new DealWithData;
    }



MainWindow::~MainWindow()
{
    delete ui;
    delete Arduino;
    delete data;
}

void MainWindow::updateMainWindow(const QString& dados){

    qDebug() << dados;

}
