#ifndef BTSBROADCAST_H
#define BTSBROADCAST_H

#include <QWidget>

#include "Core/Communicate.h"

#define BTSTAB_TEMPDATA_NUMBER      40      //单体电压数量
#define BTSTAB_TEMPDATA_NUMBER_S    8       //单体电压行
#define BTSTAB_TEMPDATA_NUMBER_M    5       //单体电压列

namespace Ui {
class BTSBroadcast;
}

class BTSBroadcast : public QWidget
{
    Q_OBJECT

public:
    explicit BTSBroadcast(QWidget *parent = 0);
    ~BTSBroadcast();

    void setInit(int ibsunum);

private:
    Ui::BTSBroadcast *ui;

private:
    void timerEvent(QTimerEvent *);

private:
    int m_iBtsNum;
    int m_nTimerID;
    bool m_bisFrush;

    QLabel *BTStabLabel[BTSTAB_TEMPDATA_NUMBER];

    QLineEdit* m_editBTSTabTempData[BTSTAB_TEMPDATA_NUMBER];
};

#endif // BTSBROADCAST_H
