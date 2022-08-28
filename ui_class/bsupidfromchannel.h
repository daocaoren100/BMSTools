#ifndef BSUPIDFROMCHANNEL_H
#define BSUPIDFROMCHANNEL_H

#include <QWidget>

#include "Core/Communicate.h"
#include "modifypara.h"

#define BSUPIDCH_DATA_NUMBER   64     //数量

namespace Ui {
class BSUPidFromChannel;
}

class BSUPidFromChannel : public QWidget
{
    Q_OBJECT

public:
    explicit BSUPidFromChannel(QWidget *parent = 0);
    ~BSUPidFromChannel();

    void setInit(int ibsunum);

private slots:
    void on_pushButton_Modify_clicked();

    void on_pushButton_OK_clicked();

private:
    Ui::BSUPidFromChannel *ui;

private:
    void timerEvent(QTimerEvent *);
    //bool eventFilter(QObject *obj, QEvent *e);

private:
    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;
    bool m_bModify;   //切换显示和设置

    QCheckBox* m_checkCell[BSUPIDCH_DATA_NUMBER];
    stControlStringEx g_sCtl_Bsu_PID_CHN[4];
};

#endif // BSUPIDFROMCHANNEL_H
