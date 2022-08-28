#ifndef BSUBROADCAST_H
#define BSUBROADCAST_H

#include <QWidget>

#include "Core/Communicate.h"

#define BSUTAB_VDATA_NUMBER   64      //�����ѹ����
#define BSUTAB_VDATA_NUMBER_S   11      //�����ѹ��
#define BSUTAB_VDATA_NUMBER_M   6     //�����ѹ��

#define BSUTAB_TEMPDATA_NUMBER   20      //�¶�����

namespace Ui {
class BSUBroadcast;
}

class BSUBroadcast : public QWidget
{
    Q_OBJECT

public:
    explicit BSUBroadcast(QWidget *parent = 0);
    ~BSUBroadcast();

    void setInit(int ibsunum);

private:
    Ui::BSUBroadcast *ui;

private:
    void timerEvent(QTimerEvent *);

private:
    int m_iBsuNum;
    int m_nTimerID;
    bool m_bisFrush;

    int m_jumpNum = 0;

    QLabel *BSUtabLabel[BSUTAB_VDATA_NUMBER];

    QLineEdit* m_editBSUTabVData[BSUTAB_VDATA_NUMBER];
    QLineEdit* m_editBSUTabTempData[BSUTAB_TEMPDATA_NUMBER];
};

#endif // BSUBROADCAST_H
