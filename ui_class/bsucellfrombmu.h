#ifndef BSUCELLFROMBMU_H
#define BSUCELLFROMBMU_H

#include <QWidget>

#include "Core/Communicate.h"

#define CELLTAB_DATA_NUMBER   54      //ÊýÁ¿

namespace Ui {
class BsuCellFromBMU;
}

class BsuCellFromBMU : public QWidget
{
    Q_OBJECT

public:
    explicit BsuCellFromBMU(QWidget *parent = 0);
    ~BsuCellFromBMU();

    void setInit(int ibsunum);

private:
    Ui::BsuCellFromBMU *ui;

private:
    void timerEvent(QTimerEvent *);

private:
    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;

    QLineEdit* m_editBSUCellTab2Data[6][CELLTAB_DATA_NUMBER];
};

#endif // BSUCELLFROMBMU_H
