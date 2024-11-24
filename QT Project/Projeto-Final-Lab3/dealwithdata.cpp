#include "dealwithdata.h"
#include <QDebug>


DealWithData::DealWithData()
    {

    qDebug() << "DealWithData criado!";
    // Aqui você pode usar a instância de mainWindow como necessário
}


// tenho que fazer o seguinte: mainwindow instancia dealwithdata e arduinoserial. arduinoserial vai ter um objeto do tipo mainwindow para chamar a função que atualiza a tela
