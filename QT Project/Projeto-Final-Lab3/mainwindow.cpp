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
    ui(new Ui::MainWindow), Arduino(nullptr), data(nullptr), temp_max{0}, temp_min{0}, contador{0}{

    ui->setupUi(this);
    Arduino = new ArduinoSerial(this);
    data = new DealWithData;
    inicio_noite.setHMS(19,0,0);
    inicio_dia.setHMS(5,30,0);
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

void MainWindow::setupTemp(float temp){

    if(!contador && temp > 0){ // necessário por conta de algumas interações ruidosas no começo
        temp_min = temp;
        temp_max = temp;



        contador = 1;

    }

    else if(contador){
        if((temp - temp_max) > 3){
            temp_max = temp;
        }

        else if((temp_min - temp) > 3){
            temp_min = temp;
        }
    }


}

void MainWindow::updateMainWindow(const QString& dados){

   // qDebug() << dados;
    qDebug() << "Oi, eu sou a updateMainWindow!";


    qDebug() << dados;

    updateDateAndTime();

    data->setupSubStrings(dados);

    setupTemp(data->getTemperature());

    ui->temp_max_label->setText(QString::number(temp_max) + " ºC");
    ui->temp_min_label->setText(QString::number(temp_min) + " ºC");


    ui->valor_gases_label->setText(QString::number(data->getMQ2_read())); // Só vai QString KKKKKKKKKKKKKK
    ui->presenca_chuva_label->setText(QString::number(data->getFC37_read()));
    //ui->valor_temperatura_label->setText(QString::number(data->getTemperature()));
    ui->valor_UV_label->setText(QString::number(data->getTensaoUV()));

}
