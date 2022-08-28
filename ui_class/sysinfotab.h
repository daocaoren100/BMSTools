#ifndef SYSINFOTAB_H
#define SYSINFOTAB_H

#include <QWidget>

#include "Core/Communicate.h"
#include "modifypara.h"

#define TAB3_DATA_NUMBER   33        //runÊýÁ¿

namespace Ui {
class sysInfoTab;
}

class sysInfoTab : public QWidget
{
    Q_OBJECT

public:
    explicit sysInfoTab(QWidget *parent = 0);
    ~sysInfoTab();

    void setInit();
    QTimer *timer;

private:
    Ui::sysInfoTab *ui;

private:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    bool m_bisFrush;

    QLineEdit* m_editTab3Data[TAB3_DATA_NUMBER];
    stControlStringEx g_sCtl_Bmu_Run[TAB3_DATA_NUMBER];

private slots:
    void refTimeout();
};

#endif // SYSINFOTAB_H
