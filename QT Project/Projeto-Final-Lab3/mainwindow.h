#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
    void updateDateAndTime();


private:
    Ui::MainWindow *ui;
    ArduinoSerial *Arduino;
    DealWithData *data;
    QDate dia;
    QTime hora;
    float temp_max;
    float temp_min;

};
#endif // MAINWINDOW_H
