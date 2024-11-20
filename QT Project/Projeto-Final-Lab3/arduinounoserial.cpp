#include "arduinounoserial.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
ArduinoUnoSerial::ArduinoUnoSerial()
{
    ArduinoUno = new(QSerialPort);  // Instanciamos o Objeto
}

/*
    A Função Membor IsArduinoAvailable verifica as portas seriais conectadas ao computador e verifica se a placa
    do Arduino está conectada ao PC. Caso o Vendor ID e o Product ID sejam compatíveis, a função retornará true.
    Foi possível saber a Vendor ID e a Product ID do Arduino executando o seguinte teste no construtor da
    mainwindow.cpp:

    arduino = new QSerialPort; //instanciando a porta serial do arduino como um objeto

    //Vamos verificar quantas portas seriais temos disponíveis:

    qDebug() << "Quantidade de portas seriais disponíveis: " << QSerialPortInfo::availablePorts().length();

    // o foreach é uma palavra reservada do Qt que é semelhante ao for( : ) do C++, porém com alguns poderes a mais,
    // por exemplo, aqui não tive que declarar nenhum objeto do tipo QSerialPortInfo antes de usar esse loop
    // ele é usado para facilitar justamente as iterações com os containers do próprio QT

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Tem Vendor ID: " << serialPortInfo.hasVendorIdentifier(); // verifica se a porta tem vendor ID (a função membro hasVendorIdentifier é um bool)
        if(serialPortInfo.hasVendorIdentifier()){ // se tiver um vendor identifier:

            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "ID do Produto: " << serialPortInfo.productIdentifier();
        }
    }

    // Rodando o construtor, foi possível verificar que a única porta serial que possui vendor ID é o 9025, justamente o do Arduino
    // O product identifier do Arduino Uno, é 67
*/


bool ArduinoUnoSerial::IsArduinoAvailable(){

    ArduinoIsAvailable = false;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){ // Para cada serialPortInfo em QSerialPortInfo::availablePorts()
                                                                                       // Nesse caso, availablePorts() é uma QList que será iterada
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){ // se tiver um vendor identifier:

            if((serialPortInfo.vendorIdentifier() == ArduinoVendorID) && serialPortInfo.productIdentifier() == Arduino_Uno_ProductID){
                ArduinoIsAvailable = true;
                return ArduinoIsAvailable;
            }
    }
}
    return ArduinoIsAvailable;

}
