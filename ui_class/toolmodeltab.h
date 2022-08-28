#ifndef TOOLMODELTAB_H
#define TOOLMODELTAB_H

#include <QWidget>

#include "Core/Communicate.h"

#define TAB9_RELAY_NUMBER   9        //¼ÌµçÆ÷ÊýÁ¿

namespace Ui {
class toolModelTab;
}

class toolModelTab : public QWidget
{
    Q_OBJECT

public:
    explicit toolModelTab(QWidget *parent = 0);
    ~toolModelTab();

    void setInit();
    QTimer *timer;

private:
    Ui::toolModelTab *ui;

private:
    bool m_bisFrush;

    QPushButton* m_btnTab9Open[TAB9_RELAY_NUMBER];
    QPushButton* m_btnTab9Close[TAB9_RELAY_NUMBER];
    QLineEdit* m_editTab9RelayStatus[TAB9_RELAY_NUMBER];

    void CaliBmuCtrlTestMode(int nMode);

private slots:
    void slotOpenButtonClick(int iButton);
    void slotCloseButtonClick(int iButton);
    void on_pushButton_InTool_clicked();
    void on_pushButton_OutTool_clicked();
    void refTimeout();
    void on_pushButton_FAN_off_clicked();
    void on_pushButton_FAN_on_clicked();
    void on_pushButton_HOT_off_clicked();
    void on_pushButton_HOT_on_clicked();
};

#endif // TOOLMODELTAB_H
