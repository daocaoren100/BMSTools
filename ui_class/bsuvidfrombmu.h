#ifndef BSUVIDFROMBMU_H
#define BSUVIDFROMBMU_H

#include <QWidget>

#include "Core/Communicate.h"

#define BSUVIDTAB_DATA_NUMBER   15      //ÊýÁ¿

namespace Ui {
class BsuVidFromBMU;
}

class BsuVidFromBMU : public QWidget
{
    Q_OBJECT

public:
    explicit BsuVidFromBMU(QWidget *parent = 0);
    ~BsuVidFromBMU();

    void setInit(int ibsunum);

private:
    Ui::BsuVidFromBMU *ui;

private:
    void timerEvent(QTimerEvent *);

private:
    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;

    QLineEdit* m_editBSUvidTabData[BSUVIDTAB_DATA_NUMBER];
    QLabel* m_labelNo;
};

#endif // BSUVIDFROMBMU_H
