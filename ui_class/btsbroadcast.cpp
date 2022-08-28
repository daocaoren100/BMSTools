//BTS基本信息-标签
#include "btsbroadcast.h"
#include "ui_btsbroadcast.h"

BTSBroadcast::BTSBroadcast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BTSBroadcast)
{
    ui->setupUi(this);

#ifdef USE_LOCAL_FONT
    if(_USE_LOCAL_FONT == TRUE)
    {
        QString localFontString = loadFontFamilyFromTTF();
        QFont localFont;
        localFont.setFamily(localFontString);
        setFont(localFont);
    }
#endif

    QHBoxLayout *hbtnlay[BTSTAB_TEMPDATA_NUMBER];

    for (int i = 0 ; i <BTSTAB_TEMPDATA_NUMBER ; i++ )
    {
        QString str = "TEMP " + QString::number(i + 1) + ":";
        hbtnlay[i] = new QHBoxLayout;
        BTStabLabel[i] = new QLabel(this);
        BTStabLabel[i]->setFixedWidth(65);
        BTStabLabel[i]->setFixedHeight(18);
        BTStabLabel[i]->setAlignment(Qt::AlignRight);
        BTStabLabel[i]->setText(str);
        m_editBTSTabTempData[i] = new QLineEdit(this);
        m_editBTSTabTempData[i]->setEnabled(false);
        hbtnlay[i]->addWidget(BTStabLabel[i]);
        hbtnlay[i]->addWidget(m_editBTSTabTempData[i]);
    }
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(BTSTAB_TEMPDATA_NUMBER_S);
    gridLayout->setMargin(BTSTAB_TEMPDATA_NUMBER_M);   //列
    for (int i = 0 ; i < BTSTAB_TEMPDATA_NUMBER_M ; i++)
    {
        for (int j = 0 ; j < BTSTAB_TEMPDATA_NUMBER_S ; j++)
        {
            if ((BTSTAB_TEMPDATA_NUMBER_S*i + j)>=BTSTAB_TEMPDATA_NUMBER)
            {
                break;
            }
            gridLayout->addLayout(hbtnlay[BTSTAB_TEMPDATA_NUMBER_S*i + j] , j , i);
        }
        gridLayout->setColumnStretch(i , 1);
    }
    ui->groupBox_2->setLayout(gridLayout);

    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(ui->verticalLayout);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    //ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //ui->scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    m_iBtsNum = 0;
    m_bisFrush = false;
    m_nTimerID = startTimer(100);//新建定时器
}

BTSBroadcast::~BTSBroadcast()
{
    killTimer(m_nTimerID);
    delete ui;
}

void BTSBroadcast::setInit(int ibsunum)
{
    m_bisFrush = true;
    m_iBtsNum = ibsunum;
    QString str = QString::number(ibsunum);
    str = str + "#BTS";
    ui->label->setText(str);
}

//void BTSBroadcast::setTimer(int time)
//{
//    killTimer(m_nTimerID);
//    m_nTimerID = startTimer(100 * time);//新建定时器
//}

void BTSBroadcast::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
    //static int itimeData = 0;
    //itimeData++;
    //if (itimeData == 6)
    {
        UINT16 btsSwver = g_pCommunicate->m_tagCanBMS.m_unBTSData.stStructData.aatBtsAllData[m_iBtsNum -1].aatBtsData[BID_BTS_SOFT_VER].uiData;
        QString str = QString::number(btsSwver);
        if (btsSwver == 0xFFFF)
        {
            str = "null";
        }
        ui->lineEdit->setText(str);

        for (int i = 0 ; i < BTSTAB_TEMPDATA_NUMBER ; i++)
        {
            INT16 btsData = g_pCommunicate->m_tagCanBMS.m_unBTSData.stStructData.aatBtsAllData[m_iBtsNum -1].aatBtsData[BID_BTS_TEMP1 + i].uiData;
            if (btsData == -450)
            {
                str = "null";
            }
            else
            {
                float temp = btsData;
                str = QString("%1").arg(temp/10, 0, 'f', 1);
            }

            QString strTName = "TEMP " + QString::number(i+1) + ":";
            BTStabLabel[i]->setText(strTName);
            m_editBTSTabTempData[i]->setText(str);
        }
        //itimeData = 0;
    }
}
