#ifndef CANITEMSTREE_H
#define CANITEMSTREE_H

#include <QWidget>
#include <QTreeWidgetItem>

#include "Core/Communicate.h"

namespace Ui {
class canItemsTree;
}

class canItemsTree : public QWidget
{
    Q_OBJECT

public:
    explicit canItemsTree(QWidget *parent = 0);
    ~canItemsTree();

private:
    Ui::canItemsTree *ui;

private:
    void timerEvent(QTimerEvent *);
private:
    int m_nTimerID;
    int m_batNum;
    int m_bsuNum;
    QTreeWidgetItem *treeRoot;
signals:
    void sigSetCurrentBMU(int bms , int bmu , int bsu);
private slots:
    void slotItemClicked(QTreeWidgetItem *item,int columns);
};

#endif // CANITEMSTREE_H
