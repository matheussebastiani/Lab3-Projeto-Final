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


};
#endif // MAINWINDOW_H
