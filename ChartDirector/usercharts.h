#ifndef USERCHARTS_H
#define USERCHARTS_H

class AngularMeter;
class MeterPointer;
class TextBox;

//���ؽṹ��
typedef struct _ANGULAR_METER_STRUCT{
    AngularMeter *b;
    MeterPointer *p;
    TextBox *tb;
}ANGULAR_METER_STRUCT;

ANGULAR_METER_STRUCT roundmeterreadout_volt(int chartIndex);//��ѹ��
ANGULAR_METER_STRUCT roundmeterreadout_current(int chartIndex);//������
ANGULAR_METER_STRUCT roundmeterreadout_SOC(int chartIndex);//SOC

#endif // USERCHARTS_H
