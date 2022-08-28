#ifndef CALIBRATIONPARATAB_H
#define CALIBRATIONPARATAB_H

#include <QWidget>

#include "Core/Communicate.h"

#define TAB8_CALIBRATE_NUMBER   14        //У׼����
#define TAB8_CALIBRATE_W  6        //��
#define TAB8_CALIBRATE_H   13        //��

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

    QLineEdit* m_editTabCustom[2];  //�Զ�����
    QLineEdit* m_editTabCustomCode_VID[2];  //�Զ�����
    QLineEdit* m_editTabCustomVID_VID[2];  //�Զ�����
    QPushButton* m_btnTab8Zero[TAB8_CALIBRATE_NUMBER];    //�������
    QPushButton* m_btnTab8Slope[TAB8_CALIBRATE_NUMBER];  //����б��
    QLineEdit* m_editTab8CalibrateCode[TAB8_CALIBRATE_NUMBER];  //��ֵ
    QLineEdit* m_editTab8CalibrateVID[TAB8_CALIBRATE_NUMBER];  //����ֵ
    QLineEdit* m_editTab8CalibrateMeter[TAB8_CALIBRATE_NUMBER];  //ʵ��ֵ

private slots:
    void slotZeroButtonClick(int iButton);
    void slotSlopeButtonClick(int iButton);
    void on_pushButton_StartCalib_clicked();
    void on_pushButton_FinishCalib_clicked();
    void refTimeout();
    void on_pushButton_SaveCalib_clicked();
};

#endif // CALIBRATIONPARATAB_H
