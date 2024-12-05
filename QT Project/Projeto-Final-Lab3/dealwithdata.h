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
    float temp_max;
    float temp_min;
    int contador;

    int valorUV;

    int setupUVRate(double uvVoltage);
    void setupTemp(float temp);

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

    float getTempMin(){
        return temp_min;
    }

    float getTempMax(){
        return temp_max;
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
