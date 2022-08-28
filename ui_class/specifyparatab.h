#ifndef SPECIFYPARATAB_H
#define SPECIFYPARATAB_H

#include <QWidget>

#include "Core/Communicate.h"
#include "modifypara.h"

#define TAB4_DATA_NUMBER   35       //runÊýÁ¿

namespace Ui {
class specifyParaTab;
}

class specifyParaTab : public QWidget
{
    Q_OBJECT

public:
    explicit specifyParaTab(QWidget *parent = 0);
    ~specifyParaTab();

    void setInit();
    QTimer *timer;

private:
    Ui::specifyParaTab *ui;

private:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    bool m_bisFrush;

    QLineEdit* m_editTab4Data[TAB4_DATA_NUMBER];
    stControlStringEx g_sCtl_Bmu_Rated[TAB4_DATA_NUMBER-1];

private slots:
    void refTimeout();
};

#endif // SPECIFYPARATAB_H
