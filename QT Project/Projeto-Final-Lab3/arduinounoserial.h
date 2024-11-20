#ifndef ARDUINOUNOSERIAL_H
#define ARDUINOUNOSERIAL_H
#include <QSerialPort>
#include <QSerialPortInfo>

class ArduinoUnoSerial
{
public:
    ArduinoUnoSerial();
    bool IsArduinoAvailable();
    bool SetupArduinoSerialPortRW();


    // Funções getter

    QString getArduinoUnoSerialPortName(){
        return ArduinoUnoSerialPortName;
    }

    // Funções setter

    void closeSerialPort(){
        ArduinoUno->close();
    }
    void openSerialPort(){
       ArduinoUno->open(QSerialPort::ReadWrite);
    }


private:
    QSerialPort *ArduinoUno;                        // Iniciamos um objeto da classe QSerialPort
    const quint16 ArduinoVendorID = 9025;               // Vendor ID do Arduino, vamos utilizar para identificar que tem um Arduino Conectado
    const quint16 Arduino_Uno_ProductID = 67;           // Product ID do Arduino Uno
    bool ArduinoIsAvailable;                        // Caso o programa conseguir achar o Arduino, essa variável membro será true
    QString ArduinoUnoSerialPortName;
};

#endif // ARDUINOUNOSERIAL_H
