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
    inicio_noite.setHMS(19,0,0);
    inicio_dia.setHMS(5,30,0);

    ui->imagem_label->setPixmap(loading);
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


void MainWindow::showImage(){

    if((hora < inicio_noite) && (hora > inicio_dia)){ // checa se é dia. antes das 19:30 e dps das 5:30

        if(data->getFC37_read() < 1000){ // se for de dia e estiver chovendo

            if(data->getMQ2_read() > 5000){
                ui->imagem_label->setPixmap(chuva_poluicao); // se for dia, estiver chovendo e o sensor de gases detectar alta concentracao de gases
            }

            else
                ui->imagem_label->setPixmap(sol_chuva);
        }
        else if((data->getFC37_read() >= 1000) && (data->getLuminosidade() > 650)){ // se estiver "escuro" e de dia

            if(data->getMQ2_read() > 5000){ // se o sensor de gás estiver detectando algo acima da média
                ui->imagem_label->setPixmap(sol_poluicao);
            }

            else
                ui->imagem_label->setPixmap(nublado);
        }

            ui->imagem_label->setPixmap(sol_sem_nuvens);
        }


    else{

        if(data->getFC37_read() < 1000){ // se for de noite e estiver chovendo

            if(data->getMQ2_read() > 5000){
                ui->imagem_label->setPixmap(chuva_poluicao);    // se estiver chovendo e com alta concentração de gases
            }
            else
                ui->imagem_label->setPixmap(lua_chuva);
        }
        else if((data->getFC37_read() >= 1000) && (data->getLuminosidade() > 900)){ // se estiver de noite e muito escuro

            if(data->getMQ2_read() > 5000){ // se estiver escuro e poluido
                ui->imagem_label->setPixmap(lua_poluida);
            }
            else
                ui->imagem_label->setPixmap(lua_nublada);

    }
        else{

            if(data->getMQ2_read() > 5000){ // se estiver escuro e poluido
                ui->imagem_label->setPixmap(lua_poluida);
            }
            else
            ui->imagem_label->setPixmap(lua_cheia);
        }


}
}


void MainWindow::updateMainWindow(const QString& dados){

   // qDebug() << dados;
    qDebug() << "Oi, eu sou a updateMainWindow!";


    qDebug() << dados;

    updateDateAndTime();

    data->setupSubStrings(dados);

    showImage();

    ui->valor_temperatura_label->setText(QString::number(data->getTemperature()) + "ºC");
    ui->temp_max_label->setText(QString::number(data->getTempMax()) + " ºC");
    ui->temp_min_label->setText(QString::number(data->getTempMin()) + " ºC");

    ui->valor_gases_label->setText(QString::number(data->getMQ2_read()) + " ppm"); // Só vai QString KKKKKKKKKKKKKK


    //ui->valor_temperatura_label->setText(QString::number(data->getTemperature()));

    ui->valor_UV_label->setText(QString::number(data->getTensaoUV()));

}
