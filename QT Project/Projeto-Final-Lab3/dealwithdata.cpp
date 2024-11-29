#include "dealwithdata.h"
#include <QDebug>
#include <QString>
#include <QStringList>

#define QTD_SENSORES 5


DealWithData::DealWithData()
    {

    qDebug() << "DealWithData criado!";
    // Aqui você pode usar a instância de mainWindow como necessário
}


// tenho que fazer o seguinte: mainwindow instancia dealwithdata e arduinoserial. arduinoserial vai ter um objeto do tipo mainwindow para chamar a função que atualiza a tela


// Ok, o que eu estou fazendo aqui: Basicamente, a UpdateMainWindow chama esse cara aqui passando
// o que ela recebeu. Quando eu recebo os dados, eu reparto as strings com o método split e
// coloco em uma List de QStrings. Como eu consigo operar com índices, vou trabalhar assim para
// atribuir cada valor a cada variável membro. Esse método não é tão eficaz, principalmente se
// algum sensor parar de funcionar. O ideal seria utilizar alguma forma de identificar o que é o que
// formando um tipo de pacote de dados. Como a aplicação é extremamente simples, vou tentar trabalhar
// mexendo com os índices do QList.

void DealWithData::setupSubStrings(const QString &string){
   // qDebug() << "Oi!";
    Valores = string.split(";");

    if(Valores.size() == QTD_SENSORES){

    Valores[4].contains("\r\n") ? (Valores[4] = Valores[4]) : Valores[4] = Valores[4].remove("\r\n");

    MQ2_read = Valores[0].toInt();
    FC37_read = Valores[1].toInt();
    temperature = Valores[2].toFloat();
    luminosidade = Valores[3].toInt();
    tensaoUV = Valores[4].toDouble();
    }




}
