//额定参数设置-标签
#include "specifyparatab.h"
#include "ui_specifyparatab.h"

specifyParaTab::specifyParaTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::specifyParaTab)
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

    QLabel *tab4Label[TAB4_DATA_NUMBER];
    QHBoxLayout *hbtnlay[TAB4_DATA_NUMBER];

    for (int i = 0 ; i <TAB4_DATA_NUMBER ; i++ )
    {
        hbtnlay[i] = new QHBoxLayout;
        tab4Label[i] = new QLabel(this);
        //tab4Label[i]->setFixedWidth(165);
        tab4Label[i]->setFixedHeight(18);
        tab4Label[i]->setAlignment(Qt::AlignRight);
        m_editTab4Data[i] = new QLineEdit(this);
        m_editTab4Data[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
        m_editTab4Data[i]->setFixedWidth(75);
        m_editTab4Data[i]->setEnabled(false);
        hbtnlay[i]->addWidget(tab4Label[i]);
        hbtnlay[i]->addWidget(m_editTab4Data[i]);
    }

    tab4Label[0]->setText(QString_C("电池额定容量(AH)："));
    tab4Label[1]->setText(QString_C("单体额定电压(mV)："));
    tab4Label[2]->setText(QString_C("电池充电系数(%)："));
    tab4Label[3]->setText(QString_C("电池放电系数(%)："));
    tab4Label[4]->setText(QString_C("绝缘监测使能："));
    tab4Label[5]->setText(QString_C("绝缘监测速度："));

    tab4Label[6]->setText(QString_C("后台CAN协议类型："));
    tab4Label[7]->setText(QString_C("非车载充电机协议："));
    tab4Label[8]->setText(QString_C("车载充电机协议："));

    tab4Label[9]->setText(QString_C("电流传感器类型："));
    tab4Label[10]->setText(QString_C("霍尔额定电压(mV)："));
    tab4Label[11]->setText(QString_C("分流器额定电压(mV)："));
    tab4Label[12]->setText(QString_C("LEM霍尔类型："));
    tab4Label[13]->setText(QString_C("零点电流(A)："));
    tab4Label[14]->setText(QString_C("霍尔额定电流(A)："));
    tab4Label[15]->setText(QString_C("分流器额定电流(A)："));
    tab4Label[16]->setText(QString_C("霍尔安装方向："));

    tab4Label[17]->setText(QString_C("预充时间(0.1S)："));
    tab4Label[18]->setText(QString_C("预充完成电压(%)："));

    tab4Label[19]->setText(QString_C("K1："));
    tab4Label[20]->setText(QString_C("K2："));
    tab4Label[21]->setText(QString_C("K3："));
    tab4Label[22]->setText(QString_C("K4："));
    tab4Label[23]->setText(QString_C("K5："));
    tab4Label[24]->setText(QString_C("K6："));
    tab4Label[25]->setText(QString_C("K7："));

    tab4Label[26]->setText(QString_C("主动均衡电流(mA)："));
    tab4Label[27]->setText(QString_C("主动均衡启动压差(mV)："));
    tab4Label[28]->setText(QString_C("被动均衡启动压差(mV)："));
    tab4Label[29]->setText(QString_C("均衡保护上限(mV)："));
    tab4Label[30]->setText(QString_C("均衡保护下限(mV)："));

    tab4Label[31]->setText(QString_C("风扇高温启转点(℃)："));
    tab4Label[32]->setText(QString_C("风扇高温停转点(℃)："));
    tab4Label[33]->setText(QString_C("加热启动点(℃)："));
    tab4Label[34]->setText(QString_C("加热关闭点(℃)："));

    QGridLayout *gridLayout[7];
    for (int i = 0 ; i < 7 ; i++)
    {
        gridLayout[i] = new QGridLayout;
        gridLayout[i]->setMargin(4);   //列
        if ((i == 0) || (i == 2) || (i == 4) || (i == 5))
        {
            gridLayout[i]->setSpacing(0);
        }
        else
        {
            gridLayout[i]->setSpacing(0);
        }
        gridLayout[i]->setColumnStretch(0 , 1);
        gridLayout[i]->setColumnStretch(1 , 1);
        gridLayout[i]->setColumnStretch(2 , 1);
        gridLayout[i]->setColumnStretch(3 , 1);

        if (i == 0)
        {
            gridLayout[i]->addLayout(hbtnlay[0] , 0 , 0);
            gridLayout[i]->addLayout(hbtnlay[1] , 0 , 1);
            gridLayout[i]->addLayout(hbtnlay[2] , 0 , 2);
            gridLayout[i]->addLayout(hbtnlay[3] , 0 , 3);
            gridLayout[i]->addLayout(hbtnlay[4] , 1 , 0);
            gridLayout[i]->addLayout(hbtnlay[5] , 1 , 1);
        }
        else if (i == 1)
        {
            gridLayout[i]->addLayout(hbtnlay[6] , 0 , 0);
            gridLayout[i]->addLayout(hbtnlay[7] , 0 , 1);
            gridLayout[i]->addLayout(hbtnlay[8] , 0 , 2);
        }
        else if (i == 2)
        {
            gridLayout[i]->addLayout(hbtnlay[9] , 0 , 0);
            gridLayout[i]->addLayout(hbtnlay[10] , 0 , 1);
            gridLayout[i]->addLayout(hbtnlay[11] , 0 , 2);
            gridLayout[i]->addLayout(hbtnlay[12] , 0 , 3);
            gridLayout[i]->addLayout(hbtnlay[13] , 1 , 0);
            gridLayout[i]->addLayout(hbtnlay[14] , 1 , 1);
            gridLayout[i]->addLayout(hbtnlay[15] , 1 , 2);
            gridLayout[i]->addLayout(hbtnlay[16] , 1 , 3);
        }
        else if (i == 3)
        {
            gridLayout[i]->addLayout(hbtnlay[17] , 0 , 0);
            gridLayout[i]->addLayout(hbtnlay[18] , 0 , 1);
        }
        else if (i == 4)
        {
            gridLayout[i]->addLayout(hbtnlay[19] , 0 , 0);
            gridLayout[i]->addLayout(hbtnlay[20] , 0 , 1);
            gridLayout[i]->addLayout(hbtnlay[21] , 0 , 2);
            gridLayout[i]->addLayout(hbtnlay[22] , 0 , 3);
            gridLayout[i]->addLayout(hbtnlay[23] , 1 , 0);
            gridLayout[i]->addLayout(hbtnlay[24] , 1 , 1);
            gridLayout[i]->addLayout(hbtnlay[25] , 1 , 2);
        }
        else if (i == 5)
        {
            gridLayout[i]->addLayout(hbtnlay[26] , 0 , 0);
            gridLayout[i]->addLayout(hbtnlay[27] , 0 , 1);
            gridLayout[i]->addLayout(hbtnlay[28] , 0 , 2);
            gridLayout[i]->addLayout(hbtnlay[29] , 1 , 0);
            gridLayout[i]->addLayout(hbtnlay[30] , 1 , 1);
        }
        if (i == 6)
        {
            gridLayout[i]->addLayout(hbtnlay[31] , 0 , 0);
            gridLayout[i]->addLayout(hbtnlay[32] , 0 , 1);
            gridLayout[i]->addLayout(hbtnlay[33] , 0 , 2);
            gridLayout[i]->addLayout(hbtnlay[34] , 0 , 3);
        }
    }
    ui->groupBox->setLayout(gridLayout[0]);
    ui->groupBox_2->setLayout(gridLayout[1]);
    ui->groupBox_3->setLayout(gridLayout[2]);
    ui->groupBox_4->setLayout(gridLayout[3]);
    ui->groupBox_5->setLayout(gridLayout[4]);
    ui->groupBox_6->setLayout(gridLayout[5]);
    ui->groupBox_7->setLayout(gridLayout[6]);

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

    stControlStringEx sCtl_Bmu_Rated[TAB4_DATA_NUMBER] =
    {
        {	PID_BAT_RATED_CAPA,				m_editTab4Data[0],	DF_UINTX,		DT_PID_PidSys,		DU_AH},
        {	PID_BAT_CELL_RATED_VOLT,		m_editTab4Data[1],	DF_UINTX,		DT_PID_PidSys,		DU_MV},
        {	PID_BAT_CHRG_COEF,				m_editTab4Data[2],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},
        {	PID_BAT_DSCH_COEF,				m_editTab4Data[3],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_JY_ENABLE,              m_editTab4Data[4],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_JY_SPEED,               m_editTab4Data[5],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},

        {	PID_SYS_HCU_TYPE,				m_editTab4Data[6],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_CHR_TYPE_OFF_BOARD,		m_editTab4Data[7],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_CHR_TYPE_ON_BOARD,		m_editTab4Data[8],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},

        {	PID_SYS_CURR_SENSOR_TYPE,		m_editTab4Data[9],	DF_CURR,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_HALL_RATED_VOLT,		m_editTab4Data[10],	DF_UINTX,		DT_PID_PidSys,		DU_MV},
        {	PID_SYS_SHUNT_RATED_VOLT,		m_editTab4Data[11],	DF_UINTX,		DT_PID_PidSys,		DU_MV},
        {	PID_SYS_LEM_HALL_TYPE,			m_editTab4Data[12],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_HALL_ZERO,				m_editTab4Data[13],	DF_F0X1,		DT_PID_PidSys,		DU_A},
        {	PID_SYS_HALL_RATED_CURR,		m_editTab4Data[14],	DF_UINTX,		DT_PID_PidSys,		DU_A},
        {	PID_SYS_SHUNT_RATED_CURR,		m_editTab4Data[15],	DF_UINTX,		DT_PID_PidSys,		DU_A},
        {	PID_SYS_HALL_DIRECTION,         m_editTab4Data[16],	DF_UINTX,		DT_PID_PidSys,		DU_NULL},

        {	PID_SYS_PRECHARGE_MODE,			m_editTab4Data[17],	DF_PRE,         DT_PID_PidSys,		DU_SEC},
        {	PID_SYS_PRECHARGE_VOLT_RATE,	m_editTab4Data[18],	DF_UINTX,		DT_PID_PidSys,		DU_PER},

        {	PID_SYS_RELAY_1,				m_editTab4Data[19],	DF_RELAY,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_RELAY_2,				m_editTab4Data[20],	DF_RELAY,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_RELAY_3,				m_editTab4Data[21],	DF_RELAY,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_RELAY_4,				m_editTab4Data[22],	DF_RELAY,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_RELAY_5,				m_editTab4Data[23],	DF_RELAY,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_RELAY_6,				m_editTab4Data[24],	DF_RELAY,		DT_PID_PidSys,		DU_NULL},
        {	PID_SYS_RELAY_7,				m_editTab4Data[25],	DF_RELAY,		DT_PID_PidSys,		DU_NULL},

        {	PID_SYS_BAL_CURR,				m_editTab4Data[26],	DF_UINTX,		DT_PID_PidSys,		DU_A},
        {	PID_SYS_BAL_START_VOLT,			m_editTab4Data[27],	DF_UINTX,		DT_PID_PidSys,		DU_MV},
        {	PID_SYS_BAL_START_VOLT_PASSIVE,	m_editTab4Data[28],	DF_UINTX,		DT_PID_PidSys,		DU_MV},
        {	PID_SYS_BAL_PROT_VOLT_UP,		m_editTab4Data[29],	DF_UINTX,		DT_PID_PidSys,		DU_MV},
        {	PID_SYS_BAL_PROT_VOLT_DN,		m_editTab4Data[30],	DF_UINTX,		DT_PID_PidSys,		DU_MV},

        {	PID_SYS_FAN_START_TEMP,			m_editTab4Data[31],	DF_UINTX,		DT_PID_PidSys,		DU_TEMP},
        {	PID_SYS_FAN_STOP_TEMP,			m_editTab4Data[32],	DF_UINTX,		DT_PID_PidSys,		DU_TEMP},
        {	PID_SYS_HOT_START_TEMP,			m_editTab4Data[33],	DF_UINTX,		DT_PID_PidSys,		DU_TEMP},
        {	PID_SYS_HOT_STOP_TEMP,			m_editTab4Data[34],	DF_UINTX,		DT_PID_PidSys,		DU_TEMP},
    };
    for (int i = 0 ; i < TAB4_DATA_NUMBER-1 ; i++)
    {
        g_sCtl_Bmu_Rated[i] = sCtl_Bmu_Rated[i];
    }
    m_bisFrush = false;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(200);
}

specifyParaTab::~specifyParaTab()
{
    timer->deleteLater();
    delete ui;
}

void specifyParaTab::setInit()
{
    m_bisFrush = true;
}

void specifyParaTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    if (g_pCommunicate->m_nProtected > 0)
    {
        if (!m_editTab4Data[0]->isEnabled())
        {
            for (int p =0 ; p < sizeof(g_sCtl_Bmu_Rated)/sizeof(g_sCtl_Bmu_Rated[0]) ; p++)
            {
                g_sCtl_Bmu_Rated[p].idLineEdit->setEnabled(true);
            }
        }
    }
    else if (g_pCommunicate->m_nProtected == 0)
    {
        if (m_editTab4Data[0]->isEnabled())
        {
            for (int p =0 ; p < sizeof(g_sCtl_Bmu_Rated)/sizeof(g_sCtl_Bmu_Rated[0]) ; p++)
            {
                g_sCtl_Bmu_Rated[p].idLineEdit->setEnabled(false);
            }
        }
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bmu_Rated)/sizeof(g_sCtl_Bmu_Rated[0]); i++)
        {
            sCtlEx = g_sCtl_Bmu_Rated[i];
            if (sCtlEx.idLineEdit == NULL)
            {
                continue;
            }
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

        /*QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[PID_BAT_RATED_CAPA]);
        m_editTab4Data[0]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[PID_BAT_CELL_RATED_VOLT]);
        m_editTab4Data[1]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[PID_BAT_CHRG_COEF]);
        m_editTab4Data[2]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[PID_BAT_DSCH_COEF]);
        m_editTab4Data[3]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_HCU_TYPE]);
        m_editTab4Data[4]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHR_TYPE_OFF_BOARD]);
        m_editTab4Data[5]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHR_TYPE_ON_BOARD]);
        m_editTab4Data[6]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CURR_SENSOR_TYPE]);
        m_editTab4Data[7]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_HALL_RATED_VOLT]);
        m_editTab4Data[8]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_SHUNT_RATED_VOLT]);
        m_editTab4Data[9]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_LEM_HALL_TYPE]);
        m_editTab4Data[10]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_HALL_ZERO]);
        m_editTab4Data[11]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_HALL_RATED_CURR]);
        m_editTab4Data[12]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_SHUNT_RATED_CURR]);
        m_editTab4Data[13]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_PRECHARGE_MODE]);
        m_editTab4Data[14]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_PRECHARGE_VOLT_RATE]);
        m_editTab4Data[15]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHECK_HV_ENABLE]);
        m_editTab4Data[16]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_RELAY_1]);
        m_editTab4Data[17]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_RELAY_2]);
        m_editTab4Data[18]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_RELAY_3]);
        m_editTab4Data[19]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_RELAY_4]);
        m_editTab4Data[20]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_RELAY_5]);
        m_editTab4Data[21]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_RELAY_6]);
        m_editTab4Data[22]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_RELAY_7]);
        m_editTab4Data[23]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_BAL_CURR]);
        m_editTab4Data[24]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_BAL_START_VOLT]);
        m_editTab4Data[25]->setText(str);
        str = "NULL"; // 没有 //QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[]);
        m_editTab4Data[26]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_FAN_START_TEMP]);
        m_editTab4Data[27]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_FAN_STOP_TEMP]);
        m_editTab4Data[28]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_HOT_START_TEMP]);
        m_editTab4Data[29]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_HOT_STOP_TEMP]);
        m_editTab4Data[30]->setText(str);*/

        itimeData = 0;
    }
}

bool specifyParaTab::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        for (int i=0; i<sizeof(g_sCtl_Bmu_Rated)/sizeof(g_sCtl_Bmu_Rated[0]); i++)// 数据
        {
            if (obj == g_sCtl_Bmu_Rated[i].idLineEdit)
            {
                if (!g_sCtl_Bmu_Rated[i].idLineEdit->isEnabled())
                {
                    break;
                }
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    if (g_pCommunicate->m_nProtected >= 1)
                    {
                        ModifyPara *pDlg = new ModifyPara(this);
                        if (g_sCtl_Bmu_Rated[i].idType == DT_VID_VidSys)
                        {
                            pDlg->SetSigId(g_sCtl_Bmu_Rated[i].idDB);
                        }
                        else
                        {
                            pDlg->SetSigId(PID_TO_VID(g_sCtl_Bmu_Rated[i].idDB));
                        }
                        pDlg->OnInit();
                        pDlg->exec();
                        delete pDlg;
                    }
                }
            }
        }
    }
    return QWidget::eventFilter(obj,e);
}
