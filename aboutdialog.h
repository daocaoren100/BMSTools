#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QAbstractButton>

//#include "Core/Communicate.h"

//#define FilterVersion//µ¥ÌåÂË²¨°æ±¾

#define SoftVer     "V3.2.14L"
#define ModifyTime  "2017.2.15"


namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
