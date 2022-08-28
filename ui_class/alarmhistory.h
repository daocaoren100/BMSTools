#ifndef ALARMHISTORY_H
#define ALARMHISTORY_H

#include <QDialog>

#include "Core/Communicate.h"

#define TABLE_ALARMHIS_ROW 60     //行
#define TABLE_ALARMHIS_COL 4        //列

namespace Ui {
class AlarmHistory;
}

class AlarmHistory : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmHistory(QWidget *parent = 0);
    ~AlarmHistory();

private slots:
    void on_pushButton_clear_clicked();

private:
    Ui::AlarmHistory *ui;

    int m_nTimerID;
    int m_nHistAlmNum;

    void setTableItem(int row, int col, QString str);   //行列数据

private:
    void timerEvent(QTimerEvent *);
};

#endif // ALARMHISTORY_H
