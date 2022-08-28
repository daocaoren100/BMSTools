#ifndef BSUSETTAB_H
#define BSUSETTAB_H

#include <QWidget>

#include "Core/Communicate.h"
#include "modifypara.h"

#define TAB2_BSU_NUMBER   60        //BSU总数量

namespace Ui {
class bsuSetTab;
}

class bsuSetTab : public QWidget
{
    Q_OBJECT

public:
    explicit bsuSetTab(QWidget *parent = 0);
    ~bsuSetTab();

    void setInit();
    QTimer *timer;

private:
    Ui::bsuSetTab *ui;

private:
    bool eventFilter(QObject *obj, QEvent *e);

    void hideshow();

private:
    bool m_bisFrush;

    int m_batNum;
    int m_bsuNum;

    QLineEdit* m_editTab2Bat[TAB2_BSU_NUMBER];  //电池
    QLineEdit* m_editTab2Tem[TAB2_BSU_NUMBER];  //温度
    QLabel *tab2LabelName[TAB2_BSU_NUMBER];
    QGroupBox *groupBat[6];
    QGridLayout *gridLayoutsub[10];
    QLabel *tab2Label[6][3];

    stControlStringEx g_siSetCtrlsEx[2];
    stControlStringEx g_sCtl_Bsu_Set[2];

private slots:
    void refTimeout();
};

#endif // BSUSETTAB_H
