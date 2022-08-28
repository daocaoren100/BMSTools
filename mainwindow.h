#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QDebug>

#include "Core/Communicate.h"
#include "aboutdialog.h"
#include "ui_class/open_can_ui.h"
#include "ui_class/mainsider.h"
#include "ui_class/bmumaintabwidget.h"
#include "ui_class/datalogset.h"
#include "ui_class/alarmactive.h"
#include "ui_class/alarmhistory.h"
#include "ui_class/alarmset.h"
#include "ui_class/bsuaddrmodify.h"

#include "HexEdit/HexEdit.h"
#include "ChartDirector/userplot.h"
#include "alarmsuspendwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sigItemWeight(int bissend , QVector<QString> vecstr);

    void sigSetAlarm(QStringList AlarmList, UINT SOC);
    void sigClearAlarm(UINT SOC);

private:
    HexEdit *w_HexEdit = NULL;
    int m_nTimerID;
    volatile int m_iCurrentBMU;

    QSplitter *hspliter;        //QTabWidget中的水平分割
    QSplitter *vspliter;        //mainwindow中的竖直分割
    QHBoxLayout *tab_h_layout;  //QTabWidget中的tab的layout
    QVBoxLayout *tab_v_layout;  //QTabWidget中的tab的layout

    bool m_bIsBsu;              //是否已经前两秒读取了BSU个数
    QScrollArea *pArea1;

    bool m_bIsCanOpen;

    AlarmSuspendWidget* m_alarmSuspend = NULL;//告警悬浮窗

private:
    void freshDlgSendReceive(tagCanUnitRealData tagCanReceive);
    void sendCicle();

private:
    void timerEvent(QTimerEvent *);
    void closeEvent(QCloseEvent *event);

private slots:
    void slotSetCurrentBMU(int bms , int bmu , int bsu);

    void on_action_About_triggered();

    void on_action_OpenCAN_triggered();

    void on_action_CloseCAN_triggered();

    void on_action_ResetCAN_triggered();

    void on_action_SyncSet_triggered();

    void on_action_SyncTime_triggered();

    void on_action_SaveParm_triggered();

    void on_action_RedoParm_triggered();

    void on_action_WarnParm_triggered();

    void on_action_ActWarn_triggered();

    void on_action_HistoryWarn_triggered();

    void on_actionLOG_triggered();

    void on_action_AutoSave_triggered();

private:
    Ui::MainWindow *ui;

    QWidget *m_pstatusBarWidget;
    QHBoxLayout *statusBarLayout;
    QLabel *m_pgprsStatus;
    QLabel *m_pStatusIMEI;
    QLabel *m_pStatusCCID;
    QLabel *m_pversionsStatus;
    QLabel *m_pcanStatus;
    QLabel *m_ptimesStatus;

    AboutDialog *about;
    Open_CAN_ui *open_can_ui;
    BSUAddrModify *bsu_addr_modify;

private slots:
    void slotClose();
    void slotShow();

    void open_login_timer();

    void on_action_BSU_ADDR_triggered();

    void on_actionEEPROM_triggered();

    void on_action_plot_triggered();

public:
    static void gettagCanReceive(void *pWindow, tagCanUnitRealData tagCanReceive);

    void LoadVariables();
    void SaveVariables();

};

#endif // MAINWINDOW_H
