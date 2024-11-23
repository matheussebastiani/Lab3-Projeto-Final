
//#include "mainwindow.h"
//#include "arduinounoserial.h"
//#include <QSerialPort>
//#include <QSerialPortInfo>
//#include <QDebug>
//#include <QMessageBox>
//#include <QByteArray>
//#include <QObject>
//#include <QIODevice>
//#include "moc_arduinoserial.cpp"
//ArduinoUnoSerial::ArduinoUnoSerial(QObject *parent) : QObject(parent){// : ArduinoIsAvailable{false}, ArduinoUnoSerialPortName{""}{
//    ArduinoUno = new(QSerialPort);  // Instanciamos o Objeto

//    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){ // Para cada serialPortInfo em QSerialPortInfo::availablePorts()
//                                                                                       // Nesse caso, availablePorts() é uma QList que será iterada
//        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){ // se tiver um vendor identifier:

//            if((serialPortInfo.vendorIdentifier() == ArduinoVendorID) && serialPortInfo.productIdentifier() == Arduino_Uno_ProductID){
//                ArduinoUnoSerialPortName = serialPortInfo.portName();     // Salva o "nome" da porta serial em uma variável membro do tipo QString

//                ArduinoIsAvailable = true;

//                if(SetupArduinoSerialPortRW()){

//                    QObject::connect(ArduinoUno, &QSerialPort::readyRead, this, &ArduinoUnoSerial::talkToArduino); // signal, objeto, slot

//                }




//            }
//    }

//}
//}


//Destrutor: checa se a porta está aberta, se estiver, fecha.

//ArduinoUnoSerial::~ArduinoUnoSerial(){

//    if(ArduinoUno->isOpen()){
//        ArduinoUno->close();
//    }
//    delete ArduinoUno;

//}


//    A Função Membor IsArduinoAvailable verifica as portas seriais conectadas ao computador e verifica se a placa
//    do Arduino está conectada ao PC. Caso o Vendor ID e o Product ID sejam compatíveis, a função retornará true.
//    Essa função também aproveita para salvar o "nome" da porta serial em questão para ser utilizada posteriormente.
//    Foi possível saber a Vendor ID e a Product ID do Arduino executando o seguinte teste no construtor da
//    mainwindow.cpp:

//    arduino = new QSerialPort; //instanciando a porta serial do arduino como um objeto

//    //Vamos verificar quantas portas seriais temos disponíveis:
//valorLuminosidade
//    qDebug() << "Quantidade de portas seriais disponíveis: " << QSerialPortInfo::availablePorts().length();

//    // o foreach é uma palavra reservada do Qt que é semelhante ao for( : ) do C++, porém com alguns poderes a mais,
//    // por exemplo, aqui não tive que declarar nenhum objeto do tipo QSerialPortInfo antes de usar esse loop
//    // ele é usado para facilitar justamente as iterações com os containers do próprio QT

//    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
//        qDebug() << "Tem Vendor ID: " << serialPortInfo.hasVendorIdentifier(); // verifica se a porta tem vendor ID (a função membro hasVendorIdentifier é um bool)
//        if(serialPortInfo.hasVendorIdentifier()){ // se tiver um vendor identifier:

//            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
//        }
//        if(serialPortInfo.hasProductIdentifier()){
//            qDebug() << "ID do Produto: " << serialPortInfo.productIdentifier();
//        }
//    }

//     Rodando o construtor, foi possível verificar que a única porta serial que possui vendor ID é o 9025, justamente o do Arduino
//     O product identifier do Arduino Uno, é 67
//


//bool ArduinoUnoSerial::IsArduinoAvailable(){
//    return ArduinoIsAvailable;

//}


//    Essa função irá basicamente inicializar a porta serial para realizar a leitura e envio de dados pela serial
//    se o Arduino estiver disponível.
//    Na porta encontrada anteriormente pela função IsArduinoAvailable, com a função de Read e Write,
//    Tendo Baud Rate de 9600 e oito bits de dados, e outras configurações padrão
//

//bool ArduinoUnoSerial::SetupArduinoSerialPortRW(){
//    if(ArduinoIsAvailable){
//        ArduinoUno->setPortName(ArduinoUnoSerialPortName);
//        ArduinoUno->setBaudRate(QSerialPort::Baud9600);
//        ArduinoUno->setDataBits(QSerialPort::Data8);
//        ArduinoUno->setStopBits(QSerialPort::OneStop);
//        ArduinoUno->setParity(QSerialPort::NoParity);
//        ArduinoUno->setFlowControl(QSerialPort::NoFlowControl);
//        openSerialPort();

//        return true; // usado apenas para debug / ver se vou abrir ou não um dialog.
//    }

//    else{
//        return false;
//    }
//}

// Esse cara vai só receber, desisti da ideia de enviar


//void ArduinoUnoSerial::talkToArduino(){

//    if(ArduinoIsAvailable && ArduinoUno->canReadLine()){

//           qDebug() << ArduinoUno->readLine();

//    }

//}




