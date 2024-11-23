/*
#include "mainwindow.h" // DEIXA AQUI

#ifndef ARDUINOUNOSERIAL_H
#define ARDUINOUNOSERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
// Vou precisar chamar uma função da MainWindow para atualizar os valores, passando um objeto de outra classe

class ArduinoUnoSerial : public QObject
{


    Q_OBJECT

private:
//    QSerialPort *ArduinoUno;                        // Iniciamos um objeto da classe QSerialPort
//    const quint16 ArduinoVendorID = 9025;               // Vendor ID do Arduino, vamos utilizar para identificar que tem um Arduino Conectado
//    const quint16 Arduino_Uno_ProductID = 67;           // Product ID do Arduino Uno
//    bool ArduinoIsAvailable;                        // Caso o programa conseguir achar o Arduino, essa variável membro será true
//    QString ArduinoUnoSerialPortName;


public:
    ArduinoUnoSerial(QObject *parent = nullptr);
  //  ArduinoUnoSerial(const ArduinoUnoSerial&) = delete; //sem construtor de cópia
  //  ArduinoUnoSerial operator=(const ArduinoUnoSerial&) = delete; // sem operador de atribuição aqui eles não são necessários
     ~ArduinoUnoSerial() override;
   // bool SetupArduinoSerialPortRW();


    // Funções getter

//    QString getArduinoUnoSerialPortName(){
//        return ArduinoUnoSerialPortName;
//    }

 //   bool IsArduinoAvailable();

    // Funções setter

//    void closeSerialPort(){
//        ArduinoUno->close();
//    }
//    bool openSerialPort(){
//        return ArduinoUno->open(QSerialPort::ReadWrite);
//    }


//public slots:
//    void talkToArduino();


};

#endif // ARDUINOUNOSERIAL_H
*/
