#ifndef GENERALTAB_H
#define GENERALTAB_H

#include <QWidget>

#include <QtWebKitWidgets/QWebFrame>
#include <QWebElementCollection>

#include "Core/Communicate.h"
#include "Core/EChartTest.h"

namespace Ui {
class generalTab;
}

class generalTab : public QWidget
{
    Q_OBJECT

public:
    explicit generalTab(QWidget *parent = 0);
    ~generalTab();

    void setInit();
    QTimer *timer;

private:
    Ui::generalTab *ui;

private:
    EChartTest * m_analyzer;
    const ST_ACTV_ALARM *pActAlm;
    int m_test;
    bool m_bisFrush;

private slots:
    void addJSObject();
    void refTimeout();
};

#endif // GENERALTAB_H
