#ifndef MAINTAINPARATAB_H
#define MAINTAINPARATAB_H

#include <QWidget>

#include "Core/Communicate.h"

namespace Ui {
class maintainParaTab;
}

class maintainParaTab : public QWidget
{
    Q_OBJECT

public:
    explicit maintainParaTab(QWidget *parent = 0);
    ~maintainParaTab();

    QTimer *timer;

private:
    Ui::maintainParaTab *ui;

private slots:
    void refTimeout();
};

#endif // MAINTAINPARATAB_H
