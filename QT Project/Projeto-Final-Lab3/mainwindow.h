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
    float temp_max;
    float temp_min;
    QTime inicio_noite;
    QTime inicio_dia;
    int contador;



    // Funções internas para atualizar a UI

    void updateDateAndTime();

    void setupTemp(float temp);

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

};
#endif // MAINWINDOW_H
