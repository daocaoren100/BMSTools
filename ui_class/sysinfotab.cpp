//系统运行信息-标签
#include "sysinfotab.h"
#include "ui_sysinfotab.h"

sysInfoTab::sysInfoTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sysInfoTab)
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

    QLabel *tab3Label[TAB3_DATA_NUMBER];
    QHBoxLayout *hbtnlay[TAB3_DATA_NUMBER];

    for (int i = 0 ; i <TAB3_DATA_NUMBER ; i++ )
    {
        hbtnlay[i] = new QHBoxLayout;
        tab3Label[i] = new QLabel(this);
        //tab3Label[i]->setFixedWidth(110);
        tab3Label[i]->setFixedHeight(18);
        tab3Label[i]->setAlignment(Qt::AlignRight);
        m_editTab3Data[i] = new QLineEdit(this);
        m_editTab3Data[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
        m_editTab3Data[i]->setFixedWidth(85);
        m_editTab3Data[i]->setEnabled(false);
        hbtnlay[i]->addWidget(tab3Label[i]);
        hbtnlay[i]->addWidget(m_editTab3Data[i]);
    }

    tab3Label[0]->setText(QString_C("预充电压："));
    tab3Label[1]->setText(QString_C("电池总压："));
    tab3Label[2]->setText(QString_C("负对地电压："));
    tab3Label[3]->setText(QString_C("正对地电阻："));
    tab3Label[4]->setText(QString_C("负对地电阻："));
    tab3Label[5]->setText(QString_C("BMU测漏电流："));
    tab3Label[6]->setText(QString_C("电流通道1："));
    tab3Label[7]->setText(QString_C("电流通道2："));
    tab3Label[8]->setText(QString_C("LEM通道2电压："));

    tab3Label[9]->setText(QString_C("慢充电压："));
    tab3Label[10]->setText(QString_C("快充电压："));
    tab3Label[11]->setText(QString_C("原始电流："));
    tab3Label[12]->setText(QString_C("快速电流："));
    tab3Label[13]->setText(QString_C("工作电压："));
    tab3Label[14]->setText(QString_C("BMU板温度："));
    tab3Label[15]->setText(QString_C("电池管理状态："));


    tab3Label[16]->setText(QString_C("1#继电器状态："));
    tab3Label[17]->setText(QString_C("2#继电器状态："));
    tab3Label[18]->setText(QString_C("3#继电器状态："));
    tab3Label[19]->setText(QString_C("4#继电器状态："));
    tab3Label[20]->setText(QString_C("5#继电器状态："));
    tab3Label[21]->setText(QString_C("6#继电器状态："));
    tab3Label[22]->setText(QString_C("7#继电器状态："));
    tab3Label[23]->setText(QString_C("风扇控制状态："));
    tab3Label[24]->setText(QString_C("BSU电源控制："));

    tab3Label[25]->setText(QString_C("1#输入状态："));
    tab3Label[26]->setText(QString_C("2#输入状态："));
    tab3Label[27]->setText(QString_C("3#输入状态："));
    tab3Label[28]->setText(QString_C("4#输入状态："));
    tab3Label[29]->setText(QString_C("5#输入状态："));
    tab3Label[30]->setText(QString_C("6#输入状态："));
    tab3Label[31]->setText(QString_C("7#输入状态："));
    tab3Label[32]->setText(QString_C("8#输入状态："));


    QGridLayout *gridLayout_sys = new QGridLayout;
    gridLayout_sys->setSpacing(7);
    gridLayout_sys->setMargin(4);

    gridLayout_sys->addLayout(hbtnlay[0] , 0 , 1);
    gridLayout_sys->addLayout(hbtnlay[1] , 1 , 1);
    gridLayout_sys->addLayout(hbtnlay[2] , 2 , 1);
    gridLayout_sys->addLayout(hbtnlay[3] , 3 , 1);
    gridLayout_sys->addLayout(hbtnlay[4] , 4 , 1);
    gridLayout_sys->addLayout(hbtnlay[5] , 5 , 1);
    gridLayout_sys->addLayout(hbtnlay[6] , 6 , 1);
    gridLayout_sys->addLayout(hbtnlay[7] , 7 , 1);
    gridLayout_sys->addLayout(hbtnlay[8] , 8 , 1);

    gridLayout_sys->addLayout(hbtnlay[9] , 0 , 2);
    gridLayout_sys->addLayout(hbtnlay[10] , 1 , 2);
    gridLayout_sys->addLayout(hbtnlay[11] , 2 , 2);
    gridLayout_sys->addLayout(hbtnlay[12] , 3 , 2);
    gridLayout_sys->addLayout(hbtnlay[13] , 4 , 2);
    gridLayout_sys->addLayout(hbtnlay[14] , 5 , 2);
    gridLayout_sys->addLayout(hbtnlay[15] , 6 , 2);

    gridLayout_sys->setColumnStretch(0 , 1);
    gridLayout_sys->setColumnStretch(1 , 1);
    gridLayout_sys->setColumnStretch(2 , 1);
    gridLayout_sys->setColumnStretch(3 , 1);
    ui->groupBox_sys->setLayout(gridLayout_sys);

    QGridLayout *gridLayout_output = new QGridLayout;
    gridLayout_output->setSpacing(4);
    gridLayout_output->setMargin(4);

    gridLayout_output->addLayout(hbtnlay[16] , 1 , 1);
    gridLayout_output->addLayout(hbtnlay[17] , 2 , 1);
    gridLayout_output->addLayout(hbtnlay[18] , 3 , 1);
    gridLayout_output->addLayout(hbtnlay[19] , 4 , 1);
    gridLayout_output->addLayout(hbtnlay[20] , 5 , 1);
    gridLayout_output->addLayout(hbtnlay[21] , 6 , 1);
    gridLayout_output->addLayout(hbtnlay[22] , 7 , 1);
    gridLayout_output->addLayout(hbtnlay[23] , 8 , 1);
    gridLayout_output->addLayout(hbtnlay[24] , 9 , 1);

    gridLayout_output->setColumnStretch(0 , 1);
    gridLayout_output->setColumnStretch(1 , 1);
    gridLayout_output->setColumnStretch(2 , 1);
    gridLayout_output->setColumnStretch(3 , 1);
    ui->groupBox_output->setLayout(gridLayout_output);

    QGridLayout *gridLayout_input = new QGridLayout;
    gridLayout_input->setSpacing(4);
    gridLayout_input->setMargin(4);

    gridLayout_input->addLayout(hbtnlay[25] , 1 , 1);
    gridLayout_input->addLayout(hbtnlay[26] , 2 , 1);
    gridLayout_input->addLayout(hbtnlay[27] , 3 , 1);
    gridLayout_input->addLayout(hbtnlay[28] , 4 , 1);
    gridLayout_input->addLayout(hbtnlay[29] , 5 , 1);
    gridLayout_input->addLayout(hbtnlay[30] , 6 , 1);
    gridLayout_input->addLayout(hbtnlay[31] , 7 , 1);
    gridLayout_input->addLayout(hbtnlay[32] , 8 , 1);

    gridLayout_input->setColumnStretch(0 , 1);
    gridLayout_input->setColumnStretch(1 , 1);
    gridLayout_input->setColumnStretch(2 , 1);
    gridLayout_input->setColumnStretch(3 , 1);
    ui->groupBox_input->setLayout(gridLayout_input);

    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(ui->horizontalLayout);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    //ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //ui->scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    stControlStringEx sCtl_Bmu_Run[TAB3_DATA_NUMBER] =
    {
        {	VID_SYS_PRE_BUS_VOLT,			m_editTab3Data[0],		DF_F0X1,		DT_VID_VidSys,		DU_V},
        {	VID_SYS_BUS_VOLT,				m_editTab3Data[1],		DF_F0X1,		DT_VID_VidSys,		DU_V},
        {	VID_SYS_NBUS_VOLT,				m_editTab3Data[2],		DF_F0X1,		DT_VID_VidSys,		DU_V},
        {	VID_SYS_PBUS_RES,				m_editTab3Data[3],		DF_F0X1,		DT_VID_VidSys,		DU_RES},
        {	VID_SYS_NBUS_RES,				m_editTab3Data[4],		DF_F0X1,		DT_VID_VidSys,		DU_RES},
        {	VID_SYS_LEAK_CURR,				m_editTab3Data[5],		DF_F0X1,		DT_VID_VidSys,		DU_MA},
        {	VID_SYS_CURR1_VOLT,				m_editTab3Data[6],		DF_INTX,		DT_VID_VidSys,		DU_MV},
        {	VID_SYS_CURR2_VOLT,				m_editTab3Data[7],		DF_F0X1,		DT_VID_VidSys,		DU_MV},
        {	VID_SYS_LEM_VOLT2,				m_editTab3Data[8],		DF_INTX,		DT_VID_VidSys,		DU_MV},

        {	VID_SYS_SLW_BUS_VOLT,			m_editTab3Data[9],		DF_F0X1,		DT_VID_VidSys,		DU_V},
        {	VID_SYS_FST_BUS_VOLT,			m_editTab3Data[10],		DF_F0X1,		DT_VID_VidSys,		DU_V},
        {	VID_SYS_ORIGINAL_CURR,			m_editTab3Data[11],		DF_F0X1,		DT_VID_VidSys,		DU_A},
        {	VID_SYS_FAST_CURR,              m_editTab3Data[12],		DF_F0X1,		DT_VID_VidSys,		DU_A},
        {	VID_SYS_POWER_VOLT,				m_editTab3Data[13],		DF_F0X1,		DT_VID_VidSys,		DU_V},
        {	VID_SYS_BOARD_TEMP,				m_editTab3Data[14],		DF_F0X1,		DT_VID_VidSys,		DU_TEMP},
        {	VID_SYS_BAT_STATE,				m_editTab3Data[15],		DF_STATE,		DT_VID_VidSys,		DU_NULL},

        {	VID_SYS_RELAY1_STATUS,			m_editTab3Data[16],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_RELAY2_STATUS,			m_editTab3Data[17],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_RELAY3_STATUS,			m_editTab3Data[18],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_RELAY4_STATUS,			m_editTab3Data[19],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_RELAY5_STATUS,			m_editTab3Data[20],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_RELAY6_STATUS,			m_editTab3Data[21],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_RELAY7_STATUS,			m_editTab3Data[22],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_RELAY8_STATUS,			m_editTab3Data[23],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        {	VID_SYS_BSU_RELAY_STATUS,		m_editTab3Data[24],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},

        {	VID_SYS_DI1_STATUS,				m_editTab3Data[25],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
        {	VID_SYS_DI2_STATUS,				m_editTab3Data[26],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
        {	VID_SYS_DI3_STATUS,				m_editTab3Data[27],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
        {	VID_SYS_DI4_STATUS,				m_editTab3Data[28],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
        {	VID_SYS_DI5_STATUS,				m_editTab3Data[29],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
        {	VID_SYS_DI6_STATUS,				m_editTab3Data[30],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
        {	VID_SYS_DI7_STATUS,				m_editTab3Data[31],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
        {	VID_SYS_DI8_STATUS,				m_editTab3Data[32],		DF_HEX4,		DT_VID_VidSys,		DU_NULL},
    };
    for (int i = 0 ; i < TAB3_DATA_NUMBER ; i++)
    {
        g_sCtl_Bmu_Run[i] = sCtl_Bmu_Run[i];
    }
    m_bisFrush = false;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);
}

sysInfoTab::~sysInfoTab()
{
    timer->deleteLater();
    delete ui;
}

void sysInfoTab::setInit()
{
    m_bisFrush = true;
}

void sysInfoTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        /*QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_PRE_BUS_VOLT]);
        m_editTab3Data[0]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BUS_VOLT]);
        m_editTab3Data[1]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_NBUS_VOLT]);
        m_editTab3Data[2]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_PBUS_RES]);
        m_editTab3Data[3]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_NBUS_RES]);
        m_editTab3Data[4]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_LEAK_CURR]);
        m_editTab3Data[5]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CURR1_VOLT]);
        m_editTab3Data[6]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CURR2_VOLT]);
        m_editTab3Data[7]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_POWER_VOLT]);
        m_editTab3Data[8]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BOARD_TEMP]);
        m_editTab3Data[9]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BASE_BOARD_VER]);
        m_editTab3Data[10]->setText(str);


        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY1_STATUS]);
        m_editTab3Data[11]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY2_STATUS]);
        m_editTab3Data[12]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY3_STATUS]);
        m_editTab3Data[13]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY4_STATUS]);
        m_editTab3Data[14]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY5_STATUS]);
        m_editTab3Data[15]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY6_STATUS]);
        m_editTab3Data[16]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY7_STATUS]);
        m_editTab3Data[17]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_DI1_STATUS]);
        m_editTab3Data[18]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_DI2_STATUS]);
        m_editTab3Data[19]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_DI3_STATUS]);
        m_editTab3Data[20]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY8_STATUS]);
        m_editTab3Data[21]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BSU_RELAY_STATUS]);
        m_editTab3Data[22]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BAT_STATE]);
        m_editTab3Data[23]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CURR1_VOLT]);
        m_editTab3Data[24]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_LEM_VOLT2]);
        m_editTab3Data[25]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC_VOLT]);
        m_editTab3Data[26]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC2_VOLT]);
        m_editTab3Data[27]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_VOLT]);
        m_editTab3Data[28]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_PWM_FREQ]);
        m_editTab3Data[29]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_PWM_DUTY_RATIO]);
        m_editTab3Data[30]->setText(str);

        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_DI4_STATUS]);
        m_editTab3Data[31]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_DI5_STATUS]);
        m_editTab3Data[32]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_DI6_STATUS]);
        m_editTab3Data[33]->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_DI7_STATUS]);
        m_editTab3Data[34]->setText(str);*/

        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bmu_Run)/sizeof(g_sCtl_Bmu_Run[0]); i++)
        {
            sCtlEx = g_sCtl_Bmu_Run[i];
            if (sCtlEx.idLineEdit == NULL)
            {
                continue;
            }
            QString strData = g_pCommunicate->GetDataString(sCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);
            if ((i>15) && (i<25))
            {
                strData = strUnit;
            }
            else
            {
                strData = strData + strUnit;
            }
            QString strOldData = sCtlEx.idLineEdit->text();
            if (strData != strOldData)
            {
                sCtlEx.idLineEdit->setText(strData);
            }
        }

        itimeData = 0;
    }
}

bool sysInfoTab::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        for (int i=0; i<sizeof(g_sCtl_Bmu_Run)/sizeof(g_sCtl_Bmu_Run[0]); i++)// 数据
        {
            if (obj == g_sCtl_Bmu_Run[i].idLineEdit)
            {
                if (!g_sCtl_Bmu_Run[i].idLineEdit->isEnabled())
                {
                    break;
                }
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    if (g_pCommunicate->m_nProtected >= 1)
                    {
                        ModifyPara *pDlg = new ModifyPara(this);
                        if (g_sCtl_Bmu_Run[i].idType == DT_VID_VidSys)
                        {
                            pDlg->SetSigId(g_sCtl_Bmu_Run[i].idDB);
                        }
                        else
                        {
                            pDlg->SetSigId(PID_TO_VID(g_sCtl_Bmu_Run[i].idDB));
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
