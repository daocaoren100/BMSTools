#ifndef BATSUB_H
#define BATSUB_H

#include <QWidget>

#include "Core/Communicate.h"
#include "ui_class/modifypara.h"

namespace Ui {
class BatSub;
}

class BatSub : public QWidget
{
    Q_OBJECT

public:
    explicit BatSub(QWidget *parent = 0);
    ~BatSub();

    void setInit(int batnom);
    QTimer *timer;

private:
    Ui::BatSub *ui;

private:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    QLineEdit* m_LabelVHigh[10];
    QLineEdit* m_LabelVHighNum[10];
    QLineEdit* m_LabelVLow[10];
    QLineEdit* m_LabelVLowNum[10];

    QLineEdit* m_LabelTempHigh[4];
    QLineEdit* m_LabelTempHighNum[4];
    QLineEdit* m_LabelTempLow[4];
    QLineEdit* m_LabelTempLowNum[4];

private:
    int m_iBatNum;
    bool m_bisFrush;
    stControlStringEx g_sCtl_Bat_Sub[75];

private slots:
    void refTimeout();
};

#endif // BATSUB_H
