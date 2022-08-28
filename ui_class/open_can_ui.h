#ifndef OPEN_CAN_UI_H
#define OPEN_CAN_UI_H

#include <QDialog>
#include <QAbstractButton>

#include "Core/Communicate.h"

namespace Ui {
class Open_CAN_ui;
}

class Open_CAN_ui : public QDialog
{
    Q_OBJECT

public:
    explicit Open_CAN_ui(QWidget *parent = 0);
    ~Open_CAN_ui();

private slots:
    void on_CAN_device_comboBox_currentIndexChanged(int index);

    void on_BMU_checkBox_toggled(bool checked);

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_user_comboBox_activated(int index);

private:
    Ui::Open_CAN_ui *ui;

signals:
    void sigClose();
    void sigShow();
};

#endif // OPEN_CAN_UI_H
