#ifndef ALARMSET_H
#define ALARMSET_H

#include <QDialog>

#include "Core/Communicate.h"
#include "modifypara.h"

namespace Ui {
class AlarmSet;
}

class AlarmSet : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmSet(QWidget *parent = 0);
    ~AlarmSet();

private:
    Ui::AlarmSet *ui;

private:
    void ShowAlmAble(int nDis, int nCut, int nCtl);


    int m_nTimerID;
    QLineEdit * m_AlarmEdit[ALM_MAX_NUM][ALM_PARA_MAX_NUM];
    stControlString stCtlStr[ALM_MAX_NUM * ALM_PARA_MAX_NUM];
    QLabel* m_AlarmPicLabel[2][ALM_MAX_NUM];

private:
    void timerEvent(QTimerEvent *);
    bool eventFilter(QObject *obj, QEvent *e);

signals:
    void sigClicked();
};

#endif // ALARMSET_H
