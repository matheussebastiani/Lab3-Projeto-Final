#include <QString>
#include <QStringList>

#ifndef DEALWITHDATA_H
#define DEALWITHDATA_H



class DealWithData
{

private:

    QStringList Valores;

    int MQ2_read;
    int FC37_read;
    float temperature;
    int luminosidade;
    double tensaoUV;
    long long DSM501_read;


    int valorUV;

    int setupUVRate(double uvVoltage);

public:
    DealWithData();
    void setupSubStrings(const QString& string);

    // Funções getter

    int getMQ2_read(){
        return MQ2_read;
    }

    int getFC37_read(){
        return FC37_read;
    }

    float getTemperature(){
        return temperature;
    }

    int getLuminosidade(){
        return luminosidade;
    }

    double getTensaoUV(){
        return tensaoUV;
    }

    int getUVRate(){
        return valorUV;
    }
};

#endif // DEALWITHDATA_H
