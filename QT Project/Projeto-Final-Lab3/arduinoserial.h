#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class ArduinoSerial : public QObject
{
    Q_OBJECT
private:
    QSerialPort *ArduinoUno;                        // Iniciamos um objeto da classe QSerialPort
    const quint16 ArduinoVendorID = 9025;               // Vendor ID do Arduino, vamos utilizar para identificar que tem um Arduino Conectado
    const quint16 Arduino_Uno_ProductID = 67;           // Product ID do Arduino Uno
    bool ArduinoIsAvailable;                        // Caso o programa conseguir achar o Arduino, essa variável membro será true
    QString ArduinoUnoSerialPortName;

    void closeSerialPort(){
        ArduinoUno->close();
    }
    bool openSerialPort(){
        return ArduinoUno->open(QSerialPort::ReadWrite);
    }


public:
    ArduinoSerial();
    ArduinoSerial(const ArduinoSerial&) = delete; //sem construtor de cópia
    ArduinoSerial operator=(const ArduinoSerial&) = delete; // sem operador de atribuição aqui eles não são necessários
    virtual ~ArduinoSerial();
    bool SetupArduinoSerialPortRW();

    // Funções getter

    QString getArduinoUnoSerialPortName(){
        return ArduinoUnoSerialPortName;
    }

    bool IsArduinoAvailable();

//     Funções setter




public slots:
    void talkToArduino();


};

#endif // ARDUINOSERIAL_H
