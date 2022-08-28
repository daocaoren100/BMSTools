#ifndef BSUVIDTABWIDGET_H
#define BSUVIDTABWIDGET_H

#include <QTabWidget>

#include "Core/Communicate.h"

namespace Ui {
class bsuVIDTabWidget;
}

class bsuVIDTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit bsuVIDTabWidget(QWidget *parent = 0);
    ~bsuVIDTabWidget();

    void setInit(int page);
    int getPage();

private:
    void timerEvent(QTimerEvent *);

private:
    Ui::bsuVIDTabWidget *ui;

    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;
};

#endif // BSUVIDTABWIDGET_H
