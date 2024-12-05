#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QCoreApplication>
#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDateTime>

class ArduinoSerial;
class DealWithData;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateMainWindow(const QString& dados);



private:
    Ui::MainWindow *ui;
    ArduinoSerial *Arduino;
    DealWithData *data;
    QDate dia;
    QTime hora;
    QTime inicio_noite;
    QTime inicio_dia;

    // Funções internas para atualizar a UI

    void updateDateAndTime();



    // Variáveis membro para as imagens

    void showImage();

    QPixmap imagem;

    QString lua_cheia = ":/img/lua_cheia.png";
    QString lua_chuva = ":img/lua_chuva.png";
    QString lua_nublada = ":img/lua_nublada.png";
    QString nublado = ":img/nublado.png";
    QString sol_chuva = ":img/sol_chuva.png";
    QString sol_sem_nuvens = ":img/sun.png";
    QString loading = ":img/loading.png";
    QString lua_poluida = ":img/lua_poluicao.png";  // Mas por que essa imagem como se a visão da lua estivesse turva por conta da poluição? verifique o fenômeno da lua de sangue/lua vermelha
    QString sol_poluicao = ":img/sol_poluicao.png";
    QString chuva_poluicao = ":img/chuva_poluicao.png";

};
#endif // MAINWINDOW_H
