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

   // qDebug() << dados;
    qDebug() << "Oi, eu sou a updateMainWindow!";
    ui->imagem_1_label->setText(dados);

    qDebug() << dados;

    data->setupSubStrings(dados);



    ui->valor_gases_label->setText(QString::number(data->getMQ2_read())); // Só vai QString KKKKKKKKKKKKKK
    ui->presenca_chuva_label->setText(QString::number(data->getFC37_read()));
    ui->valor_temperatura_label->setText(QString::number(data->getTemperature()));
    ui->valor_UV_label->setText(QString::number(data->getTensaoUV()));

}
