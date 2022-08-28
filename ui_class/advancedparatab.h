#ifndef ADVANCEDPARATAB_H
#define ADVANCEDPARATAB_H

#include <QWidget>
#include <QDebug>

#include "Core/Communicate.h"
#include "modifypara.h"

#define TAB7_SET_NUMBER   10        //ÊýÁ¿
#define TAB7_CALIBRATE_W  5        //¿í
#define TAB7_CALIBRATE_H   11        //¸ß

namespace Ui {
class advancedParaTab;
}

class advancedParaTab : public QWidget
{
    Q_OBJECT

public:
    explicit advancedParaTab(QWidget *parent = 0);
    ~advancedParaTab();

    void setInit();
    QTimer *timer;

private:
    Ui::advancedParaTab *ui;

private:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    bool m_bisFrush;
    stControlStringEx g_stCtlStr[TAB7_SET_NUMBER*2];
    QLineEdit* g_editStr[TAB7_SET_NUMBER*2];

    QLineEdit* m_editTab7VID[TAB7_SET_NUMBER];  //VID
    QLineEdit* m_editTab7VIDValue[TAB7_SET_NUMBER];  //
    QLineEdit* m_editTab7PID[TAB7_SET_NUMBER];  //PID
    QLineEdit* m_editTab7PIDPara[TAB7_SET_NUMBER];  //

private slots:
    void refTimeout();
};

#endif // ADVANCEDPARATAB_H
