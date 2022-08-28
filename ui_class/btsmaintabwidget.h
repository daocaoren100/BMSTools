#ifndef BTSMAINTABWIDGET_H
#define BTSMAINTABWIDGET_H

#include <QTabWidget>

#include "Core/Communicate.h"

namespace Ui {
class btsMainTabWidget;
}

class btsMainTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit btsMainTabWidget(QWidget *parent = 0);
    ~btsMainTabWidget();

    void setInit(int ibsunum);
    int getPage();

private:
    void timerEvent(QTimerEvent *);

private:
    Ui::btsMainTabWidget *ui;

    int m_iBtsNum;
    int m_nTimerID;
    bool m_bisFrush;
};

#endif // BTSMAINTABWIDGET_H
