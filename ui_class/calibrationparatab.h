#ifndef CALIBRATIONPARATAB_H
#define CALIBRATIONPARATAB_H

#include <QWidget>

#include "Core/Communicate.h"

#define TAB8_CALIBRATE_NUMBER   14        //校准数量
#define TAB8_CALIBRATE_W  6        //宽
#define TAB8_CALIBRATE_H   13        //高

namespace Ui {
class calibrationParaTab;
}

class calibrationParaTab : public QWidget
{
    Q_OBJECT

public:
    explicit calibrationParaTab(QWidget *parent = 0);
    ~calibrationParaTab();

    void setInit();
    QTimer *timer;

private:
    Ui::calibrationParaTab *ui;

private:
    UINT16 HV_CPU_VER;

    void CaliBmuAd(int nChn, int nType, int nVal);
    void CaliBmuCtrlTestMode(int nMode);
private:
    bool m_bisFrush;

    QLineEdit* m_editTabCustom[2];  //自定义项
    QLineEdit* m_editTabCustomCode_VID[2];  //自定义项
    QLineEdit* m_editTabCustomVID_VID[2];  //自定义项
    QPushButton* m_btnTab8Zero[TAB8_CALIBRATE_NUMBER];    //矫正零点
    QPushButton* m_btnTab8Slope[TAB8_CALIBRATE_NUMBER];  //矫正斜率
    QLineEdit* m_editTab8CalibrateCode[TAB8_CALIBRATE_NUMBER];  //码值
    QLineEdit* m_editTab8CalibrateVID[TAB8_CALIBRATE_NUMBER];  //测量值
    QLineEdit* m_editTab8CalibrateMeter[TAB8_CALIBRATE_NUMBER];  //实测值

private slots:
    void slotZeroButtonClick(int iButton);
    void slotSlopeButtonClick(int iButton);
    void on_pushButton_StartCalib_clicked();
    void on_pushButton_FinishCalib_clicked();
    void refTimeout();
    void on_pushButton_SaveCalib_clicked();
};

#endif // CALIBRATIONPARATAB_H
