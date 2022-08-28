#ifndef CHARGEPARATAB_H
#define CHARGEPARATAB_H

#include <QWidget>

#include "Core/Communicate.h"
#include "modifypara.h"

#define TAB6_DATA_NUMBER   43        //¼ÌµçÆ÷ÊýÁ¿

namespace Ui {
class chargeParaTab;
}

class chargeParaTab : public QWidget
{
    Q_OBJECT

public:
    explicit chargeParaTab(QWidget *parent = 0);
    ~chargeParaTab();

    void setInit();
    QTimer *timer;

private:
    Ui::chargeParaTab *ui;

private:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    bool m_bisFrush;

    QLineEdit* m_editTab6Data[TAB6_DATA_NUMBER];
    stControlStringEx g_sCtl_Bmu_Charge[TAB6_DATA_NUMBER];

private slots:
    void refTimeout();
};

#endif // CHARGEPARATAB_H
