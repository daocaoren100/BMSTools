#ifndef MAINSIDER_H
#define MAINSIDER_H

#include <QWidget>

#include "Core/Communicate.h"

namespace Ui {
class mainSider;
}

class mainSider : public QWidget
{
    Q_OBJECT

public:
    explicit mainSider(QWidget *parent = 0);
    ~mainSider();

    void setInit();

private slots:
    void on_pushButton_calibrationTime_clicked();

    void on_pushButton_calibrationSOC_clicked();

private:
    Ui::mainSider *ui;

private:
    void timerEvent(QTimerEvent *);

private:
    int m_nTimerID;
    bool m_bisFrush;
};

#endif // MAINSIDER_H
