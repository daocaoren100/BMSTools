#ifndef USERCHARTS_H
#define USERCHARTS_H

class AngularMeter;
class MeterPointer;
class TextBox;

//返回结构体
typedef struct _ANGULAR_METER_STRUCT{
    AngularMeter *b;
    MeterPointer *p;
    TextBox *tb;
}ANGULAR_METER_STRUCT;

ANGULAR_METER_STRUCT roundmeterreadout_volt(int chartIndex);//电压表
ANGULAR_METER_STRUCT roundmeterreadout_current(int chartIndex);//电流表
ANGULAR_METER_STRUCT roundmeterreadout_SOC(int chartIndex);//SOC

#endif // USERCHARTS_H
