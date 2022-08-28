//BSU-VID基本信息-标签
#include "bsuvidfrombmu.h"
#include "ui_bsuvidfrombmu.h"

BsuVidFromBMU::BsuVidFromBMU(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BsuVidFromBMU)
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

    m_labelNo = new QLabel(this);
    m_labelNo->setFixedWidth(100);
    m_labelNo->setFixedHeight(18);
    m_labelNo->setAlignment(Qt::AlignRight);

    QLabel *BSUtabLabel[BSUVIDTAB_DATA_NUMBER];
    QHBoxLayout *hbtnlay[BSUVIDTAB_DATA_NUMBER];

    for (int i = 0 ; i <BSUVIDTAB_DATA_NUMBER ; i++ )
    {
        hbtnlay[i] = new QHBoxLayout;
        BSUtabLabel[i] = new QLabel(this);
        BSUtabLabel[i]->setFixedWidth(150);
        BSUtabLabel[i]->setFixedHeight(18);
        BSUtabLabel[i]->setAlignment(Qt::AlignRight);
        m_editBSUvidTabData[i] = new QLineEdit(this);
        m_editBSUvidTabData[i]->setFixedWidth(100);
        m_editBSUvidTabData[i]->setEnabled(false);
        hbtnlay[i]->addWidget(BSUtabLabel[i]);
        hbtnlay[i]->addWidget(m_editBSUvidTabData[i]);
    }
    BSUtabLabel[0]->setText("BSU Software Version:");
    BSUtabLabel[1]->setText("BSU Volt:");
    BSUtabLabel[2]->setText("BSU Run Status:");
    BSUtabLabel[3]->setText("BSU Balance Fail:");
    BSUtabLabel[4]->setText("BSU Balance Cell No.:");
    BSUtabLabel[5]->setText("BSU AD 1:");
    BSUtabLabel[6]->setText("BSU DI 1:");
    BSUtabLabel[7]->setText("BSU Fan Command:");
    BSUtabLabel[8]->setText("BSU Fan Status:");
    BSUtabLabel[9]->setText("BSU Offline Version:");
    BSUtabLabel[10]->setText("BSU Balance Current:");
    BSUtabLabel[11]->setText("BSU AD2:");
    BSUtabLabel[12]->setText("BSU DI 2:");
    BSUtabLabel[13]->setText("BSU Hot Command:");
    BSUtabLabel[14]->setText("BSU Hot Status:");

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(10);
    gridLayout->setMargin(4);   //列
    gridLayout->addWidget(m_labelNo , 0 , 0);
    for (int k = 0 ; k < 9 ; k++)
    {
        gridLayout->addLayout(hbtnlay[k] , k+1 , 1);
    }
    gridLayout->addLayout(hbtnlay[9] , 3 , 2);
    for (int kk = 10 ; kk < BSUVIDTAB_DATA_NUMBER ; kk++)
    {
        gridLayout->addLayout(hbtnlay[kk] , kk-6 +1 , 2);
    }
    gridLayout->setColumnStretch(0 , 2);
    gridLayout->setColumnStretch(1 , 3);
    gridLayout->setColumnStretch(2 , 3);
    gridLayout->setColumnStretch(3 , 3);
    //ui.groupBox->setLayout(gridLayout);

    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(gridLayout);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    //ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //ui->scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    m_iBsuNum = 0;
    m_bisFrush = false;
    m_nTimerID = startTimer(100);//新建定时器
}

BsuVidFromBMU::~BsuVidFromBMU()
{
    killTimer(m_nTimerID);
    delete ui;
}

void BsuVidFromBMU::setInit(int ibsunum)
{
    m_bisFrush = true;
    m_iBsuNum = ibsunum;
    QString str = QString::number(ibsunum);
    str = "BSU No." + str;
    m_labelNo->setText(str);
}

void BsuVidFromBMU::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        static stControlStringEx stCtlStr[] =
        {
            {	VID_BSU_SW_VER,				m_editBSUvidTabData[0],		DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_RUN_STATUS,			m_editBSUvidTabData[2],		DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_OFFLINE_STATUS,		m_editBSUvidTabData[9],		DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_TOTAL_VOLT,			m_editBSUvidTabData[1],		DF_F0X2,		DT_VID_VidBsu,		DU_V },
            {	VID_BSU_CHN1_VOLT,			m_editBSUvidTabData[5],		DF_INTX,		DT_VID_VidBsu,		DU_MV },
            {	VID_BSU_CHN2_VOLT,			m_editBSUvidTabData[11],	DF_INTX,		DT_VID_VidBsu,		DU_MV },
            {	VID_BSU_BAL1_NO,			m_editBSUvidTabData[4],		DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_BAL1_CURR,			m_editBSUvidTabData[10],	DF_INTX,		DT_VID_VidBsu,		DU_MA },
            {	VID_BSU_FAN_CMD,			m_editBSUvidTabData[7],		DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_HOT_CMD,			m_editBSUvidTabData[13],	DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_FAN_STATUS,			m_editBSUvidTabData[8],     DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_HOT_STATUS,			m_editBSUvidTabData[14],	DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_BAL_FAIL,			m_editBSUvidTabData[3],		DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_DI1_STATUS,			m_editBSUvidTabData[6],		DF_INTX,		DT_VID_VidBsu,		DU_NULL },
            {	VID_BSU_DI2_STATUS,			m_editBSUvidTabData[12],	DF_INTX,		DT_VID_VidBsu,		DU_NULL },
        };
        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(stCtlStr)/sizeof(stCtlStr[0]); i++)
        {
            sCtlEx = stCtlStr[i];
            if (sCtlEx.idLineEdit == NULL)
            {
                continue;
            }
            sCtlEx.idDB = VID_MAKE_BSU_HEAD_VID(m_iBsuNum - 1, sCtlEx.idDB);
            QString strData = g_pCommunicate->GetDataString(sCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);
            /*if ((i>10) && (i<20))
            {
                strData = strUnit;
            }
            else
            {*/
                strData = strData + strUnit;
            //}
            QString strOldData = sCtlEx.idLineEdit->text();
            if (strData != strOldData)
            {
                sCtlEx.idLineEdit->setText(strData);
            }
        }
        /*QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_SW_VER]);
        //QString str = g_pCommunicate->GetDataString(g_stParabmsVidSys[VID_SYS_WORK_MODE]) + g_pCommunicate->GetDataUnit(g_stParabmsVidSys[VID_SYS_WORK_MODE]);
        m_editBSUvidTabData[0]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_TOTAL_VOLT]);
        m_editBSUvidTabData[1]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_RUN_STATUS]);
        m_editBSUvidTabData[2]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_BAL_FAIL]);
        m_editBSUvidTabData[3]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_BAL1_NO]);
        m_editBSUvidTabData[4]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_CHN1_VOLT]);
        m_editBSUvidTabData[5]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_DI1_STATUS]);
        m_editBSUvidTabData[6]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_FAN_CMD]);
        m_editBSUvidTabData[7]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_FAN_STATUS]);
        m_editBSUvidTabData[8]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_OFFLINE_STATUS]);
        m_editBSUvidTabData[9]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_BAL1_CURR]);
        m_editBSUvidTabData[10]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_CHN2_VOLT]);
        m_editBSUvidTabData[11]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_DI2_STATUS]);
        m_editBSUvidTabData[12]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_HOT_CMD]);
        m_editBSUvidTabData[13]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsu.m_usBmsVidBsu[VID_BSU_HOT_STATUS]);
        m_editBSUvidTabData[14]->setText(str);*/

        itimeData = 0;
    }
}
