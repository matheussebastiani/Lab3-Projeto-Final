#include "dealwithdata.h"
#include "arduinoserial.h"
#include "mainwindow.h"
DealWithData::DealWithData()
{
    ArduinoSerial *Arduino = new(ArduinoSerial);
    //MainWindow caller = new(MainWindow);
}
