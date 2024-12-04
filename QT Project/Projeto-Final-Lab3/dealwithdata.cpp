#include "dealwithdata.h"
#include <QDebug>
#include <QString>
#include <QStringList>

#define QTD_SENSORES 5


DealWithData::DealWithData() : MQ2_read{0}, FC37_read{0}, temperature{0}, luminosidade{0}, tensaoUV{0}
    {

    qDebug() << "DealWithData criado!";
    // Aqui você pode usar a instância de mainWindow como necessário
}


int DealWithData::setupUVRate(double uvVoltage){ // baseado na tabela do sensor

    if(uvVoltage < 50){
        return 0;

    }
    else if((uvVoltage >= 227) && (uvVoltage < 318)){
        return 1;
    }
    else if((uvVoltage >= 318) && (uvVoltage < 408)){
        return 2;
    }
    else if((uvVoltage >= 408) && (uvVoltage < 503)){
        return 3;
    }
    else if((uvVoltage >= 503) && (uvVoltage < 606)){
        return 4;
    }
    else if((uvVoltage >= 606) && (uvVoltage < 696)){
        return 5;
    }
    else if((uvVoltage >= 696) && (uvVoltage < 795)){
        return 6;
    }
    else if ((uvVoltage >= 795) && (uvVoltage < 881)){
        return 7;
    }
    else if((uvVoltage >= 881) && (uvVoltage < 972)){
        return 8;
    }
    else if((uvVoltage >= 972) && (uvVoltage < 1079)){
        return 9;
    }
    else if((uvVoltage >= 1079) && (uvVoltage < 1170)){
        return 10;

    }
    else{
        return 11;
    }

}




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
    valorUV = setupUVRate(Valores[4].toDouble());

    qDebug() << "Cai no if";
    }




}
