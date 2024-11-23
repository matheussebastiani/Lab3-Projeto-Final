#include "arduinoserial.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>
#include <QByteArray>
#include <QDebug>


ArduinoSerial::ArduinoSerial(){

 ArduinoUno = new(QSerialPort);
 foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){ // Para cada serialPortInfo em QSerialPortInfo::availablePorts()
                                                                                       // Nesse caso, availablePorts() é uma QList que será iterada
  if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){ // se tiver um vendor identifier:

    if((serialPortInfo.vendorIdentifier() == ArduinoVendorID) && serialPortInfo.productIdentifier() == Arduino_Uno_ProductID){
         ArduinoUnoSerialPortName = serialPortInfo.portName();     // Salva o "nome" da porta serial em uma variável membro do tipo QString
         ArduinoIsAvailable = true;
         if(SetupArduinoSerialPortRW()){
            QObject::connect(ArduinoUno, &QSerialPort::readyRead, this, &ArduinoSerial::talkToArduino); // signal, objeto, slot
         }
      }
    }

 }

}

ArduinoSerial::~ArduinoSerial(){

    if(ArduinoUno->isOpen()){
        ArduinoUno->close();
    }
    delete ArduinoUno;

}

bool ArduinoSerial::IsArduinoAvailable(){
    return ArduinoIsAvailable;

}

bool ArduinoSerial::SetupArduinoSerialPortRW(){
    if(ArduinoIsAvailable){
        ArduinoUno->setPortName(ArduinoUnoSerialPortName);
        ArduinoUno->setBaudRate(QSerialPort::Baud9600);
        ArduinoUno->setDataBits(QSerialPort::Data8);
        ArduinoUno->setStopBits(QSerialPort::OneStop);
        ArduinoUno->setParity(QSerialPort::NoParity);
        ArduinoUno->setFlowControl(QSerialPort::NoFlowControl);
        openSerialPort();

        return true; // usado apenas para debug ver se vou abrir ou não um dialog.
    }

    else{
        return false;
    }
}

void ArduinoSerial::talkToArduino(){

    if(ArduinoIsAvailable && ArduinoUno->canReadLine()){

           qDebug() << ArduinoUno->readLine();

    }

}


