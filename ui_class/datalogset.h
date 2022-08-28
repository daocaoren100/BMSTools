#ifndef DATALOGSET_H
#define DATALOGSET_H

#include <QDialog>

#include "Core/Communicate.h"

namespace Ui {
class DataLogSet;
}

class DataLogSet : public QDialog
{
    Q_OBJECT

public:
    explicit DataLogSet(QWidget *parent = 0);
    ~DataLogSet();

private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::DataLogSet *ui;
};

#endif // DATALOGSET_H
