#ifndef ALARMACTIVE_H
#define ALARMACTIVE_H

#include <QDialog>

#include "Core/Communicate.h"

#define TABLE_ALARM_ROW 50     //行
#define TABLE_ALARM_COL 3        //列

namespace Ui {
class AlarmActive;
}

class AlarmActive : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmActive(QWidget *parent = 0);
    ~AlarmActive();

private:
    Ui::AlarmActive *ui;

    int m_nTimerID;
    int m_nActvAlmNum;

    void setTableItem(int row, int col, QString str);   //行列数据
    void clearTableItem();   //清除行列数据

private:
    void timerEvent(QTimerEvent *);
};

#endif // ALARMACTIVE_H
