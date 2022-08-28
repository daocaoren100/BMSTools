//充电参数设置-标签
#include "chargeparatab.h"
#include "ui_chargeparatab.h"

chargeParaTab::chargeParaTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chargeParaTab)
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

    QLabel *tab2Label[TAB6_DATA_NUMBER];
    QHBoxLayout *hbtnlay[TAB6_DATA_NUMBER];

    for (int i = 0 ; i <TAB6_DATA_NUMBER ; i++ )
    {
        hbtnlay[i] = new QHBoxLayout;
        tab2Label[i] = new QLabel(this);
        //tab2Label[i]->setFixedWidth(165);
        tab2Label[i]->setFixedHeight(18);
        tab2Label[i]->setAlignment(Qt::AlignRight);
        m_editTab6Data[i] = new QLineEdit(this);
        m_editTab6Data[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
        if (i<6)
        {
            m_editTab6Data[i]->setFixedWidth(135);
        }
        else
        {
            m_editTab6Data[i]->setFixedWidth(85);
        }
        if ((i<6) || (i>16))
        {
            m_editTab6Data[i]->setEnabled(false);
        }
        hbtnlay[i]->addWidget(tab2Label[i]);
        hbtnlay[i]->addWidget(m_editTab6Data[i]);
    }
    tab2Label[0]->setText(QString_C("充电机通信状态："));
    tab2Label[1]->setText(QString_C("充电机CC："));
    tab2Label[2]->setText(QString_C("请求电流："));
    tab2Label[3]->setText(QString_C("充电阶段："));
    tab2Label[4]->setText(QString_C("请求电压："));
    tab2Label[5]->setText(QString_C("请求电流-实际值："));

    tab2Label[6]->setText(QString_C("非车载充电机类型："));
    tab2Label[7]->setText(QString_C("最大充电电压："));
    tab2Label[8]->setText(QString_C("降电流间隔(S)："));
    tab2Label[9]->setText(QString_C("车载充电CAN(S)："));
    tab2Label[10]->setText(QString_C("车载充电机类型："));
    tab2Label[11]->setText(QString_C("最大快充电流(A)："));
    tab2Label[12]->setText(QString_C("最大慢充电流(A)："));
    tab2Label[13]->setText(QString_C("最小充电电流(A)："));
    tab2Label[14]->setText(QString_C("降电流比例(%)："));
    tab2Label[15]->setText(QString_C("单体最高允许充电电压(V)："));
    tab2Label[16]->setText(QString_C("单体最低允许充电电压(V)："));

    tab2Label[17]->setText(QString_C("充电机状态："));
    tab2Label[18]->setText(QString_C("CC电压："));
    tab2Label[19]->setText(QString_C("RESERVED1："));
    tab2Label[20]->setText(QString_C("RESERVED7："));
    tab2Label[21]->setText(QString_C("充电机控制命令："));
    tab2Label[22]->setText(QString_C("CC2电压："));
    tab2Label[23]->setText(QString_C("RESERVED2："));
    tab2Label[24]->setText(QString_C("RESERVED8："));
    tab2Label[25]->setText(QString_C("充电机故障代码："));
    tab2Label[26]->setText(QString_C("CP电压："));
    tab2Label[27]->setText(QString_C("RESERVED3："));
    tab2Label[28]->setText(QString_C("RESERVED9："));
    tab2Label[29]->setText(QString_C("充电电压-充电机输出值："));
    tab2Label[30]->setText(QString_C("CP PWM频率："));
    tab2Label[31]->setText(QString_C("RESERVED4："));
    tab2Label[32]->setText(QString_C("RESERVED10："));
    tab2Label[33]->setText(QString_C("充电电流-充电机输出值："));
    tab2Label[34]->setText(QString_C("CP占空比："));
    tab2Label[35]->setText(QString_C("RESERVED5："));
    tab2Label[36]->setText(QString_C("RESERVED11："));
    tab2Label[37]->setText(QString_C("充电继电器状态："));
    tab2Label[38]->setText(QString_C("充电座温度1："));
    tab2Label[39]->setText(QString_C("RESERVED6："));
    tab2Label[40]->setText(QString_C("RESERVED12："));
    tab2Label[41]->setText(QString_C("非车载充电机协议类型："));
    tab2Label[42]->setText(QString_C("充电座温度2："));

    QGridLayout *gridLayout1 = new QGridLayout;
    gridLayout1->setSpacing(2);
    gridLayout1->setMargin(3);
    gridLayout1->addLayout(hbtnlay[0] , 0 , 0);
    gridLayout1->addLayout(hbtnlay[1] , 0 , 1);
    gridLayout1->addLayout(hbtnlay[2] , 0 , 2);
    gridLayout1->addLayout(hbtnlay[3] , 1 , 0);
    gridLayout1->addLayout(hbtnlay[4] , 1 , 1);
    gridLayout1->addLayout(hbtnlay[5] , 1 , 2);
    ui->groupBox->setLayout(gridLayout1);

    QGridLayout *gridLayout2 = new QGridLayout;
    gridLayout2->setSpacing(3);
    gridLayout2->setMargin(4);
    gridLayout2->addLayout(hbtnlay[6] , 0 , 0);
    gridLayout2->addLayout(hbtnlay[7] , 0 , 1);
    gridLayout2->addLayout(hbtnlay[8] , 0 , 2);
    gridLayout2->addLayout(hbtnlay[9] , 0 , 3);
    gridLayout2->addLayout(hbtnlay[10] , 1 , 0);
    gridLayout2->addLayout(hbtnlay[11] , 1 , 1);
    gridLayout2->addLayout(hbtnlay[12] , 1 , 2);
    gridLayout2->addLayout(hbtnlay[13] , 1 , 3);
    gridLayout2->addLayout(hbtnlay[14] , 2 , 0);
    gridLayout2->addLayout(hbtnlay[15] , 2 , 1);
    gridLayout2->addLayout(hbtnlay[16] , 2 , 2);
    ui->groupBox_2->setLayout(gridLayout2);

    QGridLayout *gridLayout3 = new QGridLayout;
    gridLayout3->setSpacing(7);
    gridLayout3->setMargin(4);
    gridLayout3->addLayout(hbtnlay[17] , 0 , 0);
    gridLayout3->addLayout(hbtnlay[18] , 0 , 1);
    gridLayout3->addLayout(hbtnlay[19] , 0 , 2);
    gridLayout3->addLayout(hbtnlay[20] , 0 , 3);
    gridLayout3->addLayout(hbtnlay[21] , 1 , 0);
    gridLayout3->addLayout(hbtnlay[22] , 1 , 1);
    gridLayout3->addLayout(hbtnlay[23] , 1 , 2);
    gridLayout3->addLayout(hbtnlay[24] , 1 , 3);
    gridLayout3->addLayout(hbtnlay[25] , 2 , 0);
    gridLayout3->addLayout(hbtnlay[26] , 2 , 1);
    gridLayout3->addLayout(hbtnlay[27] , 2 , 2);
    gridLayout3->addLayout(hbtnlay[28] , 2 , 3);
    gridLayout3->addLayout(hbtnlay[29] , 3 , 0);
    gridLayout3->addLayout(hbtnlay[30] , 3 , 1);
    gridLayout3->addLayout(hbtnlay[31] , 3 , 2);
    gridLayout3->addLayout(hbtnlay[32] , 3 , 3);
    gridLayout3->addLayout(hbtnlay[33] , 4 , 0);
    gridLayout3->addLayout(hbtnlay[34] , 4 , 1);
    gridLayout3->addLayout(hbtnlay[35] , 4 , 2);
    gridLayout3->addLayout(hbtnlay[36] , 4 , 3);
    gridLayout3->addLayout(hbtnlay[37] , 5 , 0);
    gridLayout3->addLayout(hbtnlay[38] , 5 , 1);
    gridLayout3->addLayout(hbtnlay[39] , 5 , 2);
    gridLayout3->addLayout(hbtnlay[40] , 5 , 3);
    gridLayout3->addLayout(hbtnlay[41] , 6 , 0);
    gridLayout3->addLayout(hbtnlay[42] , 6 , 1);
    ui->groupBox_3->setLayout(gridLayout3);

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

    stControlStringEx sCtl_Bmu_Charge[TAB6_DATA_NUMBER] =
    {
        {	VID_MAKE_CHR_VID(VID_CHR_ONLINE),               m_editTab6Data[0],		DF_COMM,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_CC),                   m_editTab6Data[1],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_CURR_REQUEST),         m_editTab6Data[2],      DF_F0X1,		DT_VID_VidBsuChr,		DU_A},
        {	VID_MAKE_CHR_VID(VID_CHR_STEP),                 m_editTab6Data[3],		DF_CHRSTATE,	DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_VOLT_REQUEST),         m_editTab6Data[4],      DF_F0X1,		DT_VID_VidBsuChr,		DU_V},
        {	VID_MAKE_CHR_VID(VID_CHR_CURR_REQUEST_TMP),		m_editTab6Data[5],      DF_F0X1,		DT_VID_VidBsuChr,		DU_A},

        {	PID_SYS_CHR_TYPE_OFF_BOARD,                     m_editTab6Data[6],		DF_UINTX,		DT_PID_PidSys,          DU_NULL},
        {	PID_SYS_MAX_CHRG_VOLT,                          m_editTab6Data[7],		DF_UINTX,		DT_PID_PidSys,          DU_V},
        {	PID_SYS_CHR_ON_TRICKLE_TIME,                    m_editTab6Data[8],		DF_UINTX,		DT_PID_PidSys,          DU_SEC},
        {	PID_CHRG_ON_BOARD_CHANNEL,                      m_editTab6Data[9],		DF_UINTX,		DT_PID_PidSys,          DU_NULL},
        {	PID_SYS_CHR_TYPE_ON_BOARD,                      m_editTab6Data[10],		DF_UINTX,		DT_PID_PidSys,          DU_NULL},
        {	PID_SYS_MAX_FAST_CHRG_CURR,                     m_editTab6Data[11],		DF_UINTX,		DT_PID_PidSys,          DU_A},
        {	PID_SYS_MAX_SLOW_CHRG_CURR,                     m_editTab6Data[12],		DF_UINTX,		DT_PID_PidSys,          DU_A},
        {	PID_SYS_CHRG_END_CURR,                          m_editTab6Data[13],		DF_UINTX,		DT_PID_PidSys,          DU_A},
        {	PID_SYS_CHR_ON_CURR_COE,                        m_editTab6Data[14],		DF_UINTX,		DT_PID_PidSys,          DU_PER},
        {	PID_SYS_MAX_CELL_CHRG_VOLT,                     m_editTab6Data[15],		DF_UINTX,		DT_PID_PidSys,          DU_V},
        {	PID_SYS_MIN_CELL_CHRG_VOLT,                     m_editTab6Data[16],		DF_UINTX,		DT_PID_PidSys,          DU_V},

        {	VID_MAKE_CHR_VID(VID_CHR_STATE),                m_editTab6Data[17],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_SYS_CC_VOLT,                                m_editTab6Data[18],		DF_F0X1,		DT_VID_VidSys,          DU_V},
        {	VID_MAKE_CHR_VID(VID_CHR_CHARGING),             m_editTab6Data[19],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED7),            m_editTab6Data[20],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_CTRL),                 m_editTab6Data[21],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_SYS_CC2_VOLT,                               m_editTab6Data[22],		DF_F0X1,		DT_VID_VidSys,          DU_V},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED2),            m_editTab6Data[23],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED8),            m_editTab6Data[24],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_ALARM),                m_editTab6Data[25],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_SYS_CP_VOLT,                                m_editTab6Data[26],		DF_F0X1,		DT_VID_VidSys,          DU_V},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED3),            m_editTab6Data[27],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED9),            m_editTab6Data[28],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_VOLT_OUTPUT),          m_editTab6Data[29],     DF_F0X1,		DT_VID_VidBsuChr,		DU_V},
        {	VID_SYS_CP_PWM_FREQ,                            m_editTab6Data[30],		DF_INTX,		DT_VID_VidSys,          DU_RATE},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED4),            m_editTab6Data[31],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_CURR_REQUEST_TMP),     m_editTab6Data[32],		DF_F0X1,		DT_VID_VidBsuChr,		DU_A},
        {	VID_MAKE_CHR_VID(VID_CHR_CURR_OUTPUT),          m_editTab6Data[33],     DF_F0X1,		DT_VID_VidBsuChr,		DU_A},
        {	VID_SYS_CP_PWM_DUTY_RATIO,                      m_editTab6Data[34],		DF_F0X1,		DT_VID_VidSys,          DU_PER},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED5),            m_editTab6Data[35],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_CC2),                  m_editTab6Data[36],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_RELAY_STATE),          m_editTab6Data[37],     DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_SYS_OUT_TEMP,                               m_editTab6Data[38],		DF_F0X1,		DT_VID_VidSys,          DU_TEMP},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED6),            m_editTab6Data[39],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_RESERVED12),           m_editTab6Data[40],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_MAKE_CHR_VID(VID_CHR_TYPE),                 m_editTab6Data[41],		DF_UINTX,		DT_VID_VidBsuChr,		DU_NULL},
        {	VID_SYS_OUT_TEMP2,                              m_editTab6Data[42],		DF_F0X1,		DT_VID_VidSys,          DU_TEMP},
    };
    for (int i = 0 ; i < TAB6_DATA_NUMBER ; i++)
    {
        g_sCtl_Bmu_Charge[i] = sCtl_Bmu_Charge[i];
    }
    m_bisFrush = false;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);
}

chargeParaTab::~chargeParaTab()
{
    timer->deleteLater();
    delete ui;
}

void chargeParaTab::setInit()
{
    m_bisFrush = true;
}

void chargeParaTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        /*QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_ONLINE]);
        m_editTab6Data[0]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CC]);
        m_editTab6Data[1]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CURR_REQUEST]);
        m_editTab6Data[2]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_STEP]);
        m_editTab6Data[3]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_VOLT_REQUEST]);
        m_editTab6Data[4]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CURR_REQUEST_TMP]);
        m_editTab6Data[5]->setText(str);


        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHR_TYPE_OFF_BOARD]);
        m_editTab6Data[6]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_CHRG_MAX_VOLT]);
        m_editTab6Data[7]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHR_ON_TRICKLE_TIME]);
        m_editTab6Data[8]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_CHRG_ON_BOARD_CHANNEL]);
        m_editTab6Data[9]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHR_TYPE_ON_BOARD]);
        m_editTab6Data[10]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_CHRG_MAX_CURR]);
        m_editTab6Data[11]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHR_ON_CURR_COE]);
        m_editTab6Data[12]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[PID_SYS_CHR_MIN_CURR]);
        m_editTab6Data[13]->setText(str);


        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_STATE]);
        m_editTab6Data[14]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC_VOLT]);
        m_editTab6Data[15]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CHARGING]);
        m_editTab6Data[16]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED7]);
        m_editTab6Data[17]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CTRL]);
        m_editTab6Data[18]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC2_VOLT]);
        m_editTab6Data[19]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED2]);
        m_editTab6Data[20]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED8]);
        m_editTab6Data[21]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_ALARM]);
        m_editTab6Data[22]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_VOLT]);
        m_editTab6Data[23]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED3]);
        m_editTab6Data[24]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED9]);
        m_editTab6Data[25]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_VOLT_OUTPUT]);
        m_editTab6Data[26]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_PWM_FREQ]);
        m_editTab6Data[27]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED4]);
        m_editTab6Data[28]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CURR_REQUEST_TMP]);
        m_editTab6Data[29]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CURR_OUTPUT]);
        m_editTab6Data[30]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_PWM_DUTY_RATIO]);
        m_editTab6Data[31]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED5]);
        m_editTab6Data[32]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_CC2]);
        m_editTab6Data[33]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RELAY_STATE]);
        m_editTab6Data[34]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED6]);
        m_editTab6Data[35]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_RESERVED12]);
        m_editTab6Data[36]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidBsuChr.m_usBmsVidChr[VID_CHR_TYPE]);
        m_editTab6Data[37]->setText(str);*/

        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bmu_Charge)/sizeof(g_sCtl_Bmu_Charge[0]); i++)
        {
            sCtlEx = g_sCtl_Bmu_Charge[i];
            QString strData = g_pCommunicate->GetDataString(sCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);
            strData = strData + strUnit;
            QString strOldData = sCtlEx.idLineEdit->text();
            if (strData != strOldData)
            {
                sCtlEx.idLineEdit->setText(strData);
            }
        }

        itimeData = 0;
    }
}

bool chargeParaTab::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        for (int i=0; i<sizeof(g_sCtl_Bmu_Charge)/sizeof(g_sCtl_Bmu_Charge[0]); i++)// 数据
        {
            if (obj == g_sCtl_Bmu_Charge[i].idLineEdit)
            {
                if (!g_sCtl_Bmu_Charge[i].idLineEdit->isEnabled())
                {
                    break;
                }
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    if (g_pCommunicate->m_nProtected >= 1)
                    {
                        ModifyPara *pDlg = new ModifyPara(this);
                        if (g_sCtl_Bmu_Charge[i].idType == DT_VID_VidSys)
                        {
                            pDlg->SetSigId(g_sCtl_Bmu_Charge[i].idDB);
                        }
                        else
                        {
                            pDlg->SetSigId(PID_TO_VID(g_sCtl_Bmu_Charge[i].idDB));
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
