#ifndef BSUPIDFROMCOPPER_H
#define BSUPIDFROMCOPPER_H

#include <QWidget>

#include "Core/Communicate.h"

namespace Ui {
class BsuPidFromCopper;
}

class BsuPidFromCopper : public QWidget
{
    Q_OBJECT

public:
    explicit BsuPidFromCopper(QWidget *parent = 0);
    ~BsuPidFromCopper();

    void setInit(int ibsunum);

private slots:
    void on_pushButton_Modify_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::BsuPidFromCopper *ui;

private:
    void timerEvent(QTimerEvent *);

private:
    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;
    bool m_bModify;   //«–ªªœ‘ æ∫Õ…Ë÷√
    stControlStringEx g_sCtl_Bsu_PID_RES[4];
};

#endif // BSUPIDFROMCOPPER_H
