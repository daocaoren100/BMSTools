#ifndef BSUMAINTABWIDGET_H
#define BSUMAINTABWIDGET_H

#include <QTabWidget>

#include "Core/Communicate.h"

namespace Ui {
class bsuMainTabWidget;
}

class bsuMainTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit bsuMainTabWidget(QWidget *parent = 0);
    ~bsuMainTabWidget();

    void setInit(int ibsunum);
    int getPage();

private:
    void timerEvent(QTimerEvent *);

private:
    Ui::bsuMainTabWidget *ui;

    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;
};

#endif // BSUMAINTABWIDGET_H
