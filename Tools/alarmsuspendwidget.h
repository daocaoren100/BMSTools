#ifndef ALARMSUSPENDWIDGET_H
#define ALARMSUSPENDWIDGET_H

#include <QWidget>
#include <QTimer>

#include "Core/Public.h"

namespace Ui {
class AlarmSuspendWidget;
}

class AlarmSuspendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmSuspendWidget(QWidget *parent = 0);
    ~AlarmSuspendWidget();

private:
    Ui::AlarmSuspendWidget *ui;

protected:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

public slots:
    void slotPushBtnClicked(QMouseEvent *e);
    void slotPushBtnPressed(QMouseEvent *e);
    void slotPushBtnReleased(QMouseEvent *e);
    void slotSetTableViewSize();

    void soltSetAlarm(QStringList AlarmList, UINT SOC);
    void soltClearAlarm(UINT SOC);
    void SOC_Calculate(UINT SOC);

private:
    QPoint dragPostiton;
    QPoint pressPosition;
    QPoint releasePosition;
    QTimer *m_time;
    bool b_flag;

    QMenu *cmenu = NULL;//ÓÒ¼ü²Ëµ¥
};

#endif // ALARMSUSPENDWIDGET_H
