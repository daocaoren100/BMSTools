#ifndef BSUPIDFROMBSU_H
#define BSUPIDFROMBSU_H

#include <QWidget>

#include "Core/Communicate.h"
#include "modifypara.h"

namespace Ui {
class BSUPidFromBsu;
}

class BSUPidFromBsu : public QWidget
{
    Q_OBJECT

public:
    explicit BSUPidFromBsu(QWidget *parent = 0);
    ~BSUPidFromBsu();

    void setInit(int ibsunum);

private:
    Ui::BSUPidFromBsu *ui;

private:
    void timerEvent(QTimerEvent *);
    bool eventFilter(QObject *obj, QEvent *e);

private:
    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;
    stControlStringEx g_sCtl_Bsu_PID[2];
};

#endif // BSUPIDFROMBSU_H
