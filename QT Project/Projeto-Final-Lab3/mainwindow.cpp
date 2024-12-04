#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include "dealwithdata.h"
#include "arduinoserial.h"
#include <QDateTime>

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

void MainWindow::updateDateAndTime(){

    dia = QDate::currentDate();
    hora = QTime::currentTime();

    ui->hora_label->setText(hora.toString("HH:mm"));
    ui->dia_label->setText(dia.toString("dd/MM/yyyy"));

}

void MainWindow::updateMainWindow(const QString& dados){

   // qDebug() << dados;
    qDebug() << "Oi, eu sou a updateMainWindow!";


    qDebug() << dados;

    updateDateAndTime();


    ui->valor_gases_label->setText(QString::number(data->getMQ2_read())); // Só vai QString KKKKKKKKKKKKKK
    ui->presenca_chuva_label->setText(QString::number(data->getFC37_read()));
    ui->valor_temperatura_label->setText(QString::number(data->getTemperature()));
    ui->valor_UV_label->setText(QString::number(data->getTensaoUV()));

}
