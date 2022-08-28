#ifndef MODIFYPARA_H
#define MODIFYPARA_H

#include <QWidget>

#include "Core/Communicate.h"

namespace Ui {
class ModifyPara;
}

class ModifyPara : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPara(QWidget *parent = 0);
    ~ModifyPara();

    bool OnInit();
    void SetSigId(UINT32 id);
    void SetDataPoint(int* pData);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ModifyPara *ui;

private:
    UINT32	m_nId;
    int m_nValue;
    int *m_pValue;

    ST_CAN_FRAME m_sFrame;
};

#endif // MODIFYPARA_H
