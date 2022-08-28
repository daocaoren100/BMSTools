#ifndef BMUMAINTABWIDGET_H
#define BMUMAINTABWIDGET_H

#include <QTabWidget>

#include "Core/Communicate.h"
#include "ui_class/generaltab.h"
#include "ui_class/bsusettab.h"
#include "ui_class/sysinfotab.h"
#include "ui_class/specifyparatab.h"
#include "ui_class/maintainparatab.h"
#include "ui_class/chargeparatab.h"
#include "ui_class/advancedparatab.h"
#include "ui_class/calibrationparatab.h"
#include "ui_class/toolmodeltab.h"
#include "ui_class/batsub.h"

namespace Ui {
class bmuMainTabWidget;
}

class bmuMainTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit bmuMainTabWidget(QWidget *parent = 0);
    ~bmuMainTabWidget();

    void setInit();
    int getPage();
    QTimer *oldTimer;
    //void setMainPage(bool bPage);

    BatSub *m_qBatSub[BAT_MAX_NUM];
    //qDlgBatTotal *m_qDlgBatTotal;
    generalTab *m_qGeneralTab;

private:
    void timerEvent(QTimerEvent *);

private slots:
    void on_bmuMainTabWidget_currentChanged(int index);

private:
    Ui::bmuMainTabWidget *ui;

    int m_iBatNum;
    int m_nTimerID;
    bool m_bisFrush;
};

#endif // BMUMAINTABWIDGET_H
