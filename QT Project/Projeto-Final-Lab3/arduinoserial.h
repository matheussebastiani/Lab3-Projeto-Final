#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class ArduinoSerial : public QObject
{
    Q_OBJECT
public:
    ArduinoSerial();
};

#endif // ARDUINOSERIAL_H
