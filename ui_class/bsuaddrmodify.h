#ifndef BSUADDRMODIFY_H
#define BSUADDRMODIFY_H

#include <QDialog>

#include "Core/Communicate.h"

namespace Ui {
class BSUAddrModify;
}

class BSUAddrModify : public QDialog
{
    Q_OBJECT

public:
    explicit BSUAddrModify(QWidget *parent = 0);
    ~BSUAddrModify();

private slots:
    void on_modifyPushButton_clicked();

private:
    Ui::BSUAddrModify *ui;

private:
    bool eventFilter(QObject *obj, QEvent *e);
    void timerEvent(QTimerEvent *);

private:
    int m_nTimerID;
    QCheckBox* m_act_addr[255];
    int act_addr_num;           //在线模块数
};

#endif // BSUADDRMODIFY_H
