#ifndef BSUPIDTABWIDGET_H
#define BSUPIDTABWIDGET_H

#include <QTabWidget>

#include "Core/Communicate.h"

namespace Ui {
class bsuPIDTabWidget;
}

class bsuPIDTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit bsuPIDTabWidget(QWidget *parent = 0);
    ~bsuPIDTabWidget();

    void setInit(int ibsunum);
    int getPage();

private:
    void timerEvent(QTimerEvent *);

private:
    Ui::bsuPIDTabWidget *ui;

    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;
};

#endif // BSUPIDTABWIDGET_H
