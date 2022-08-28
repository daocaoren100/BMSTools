//右信息栏
#include "mainsider.h"
#include "ui_mainsider.h"

mainSider::mainSider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainSider)
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

//    QWidget* scrollAreaWidgetContents = new QWidget();
//    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
//    scrollAreaWidgetContents->setLayout(ui->verticalLayout);
//    ui->scrollArea->setWidget(scrollAreaWidgetContents);
//    //ui.scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    //ui->scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
//    ui->scrollArea->setBackgroundRole(QPalette::Base);
//    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
//    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    m_bisFrush = false;
    m_nTimerID = startTimer(200);//新建定时器

    //暂时屏蔽8#继电器
    ui->label_18->setVisible(false);
    ui->lineEdit_8Relay1->setVisible(false);
    ui->lineEdit_8Relay2->setVisible(false);
}

mainSider::~mainSider()
{
    killTimer(m_nTimerID);
    delete ui;
}

void mainSider::setInit()
{
    m_bisFrush = true;
}

void mainSider::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        stControlStringEx g_sCtl_Sider[30] =
        {
            {	VID_SYS_BAT_STATE,			ui->lineEdit_BATState,		DF_STATE,		DT_VID_VidSys,		DU_NULL },
            {	VID_SYS_CURR,				ui->lineEdit_Current,		DF_F0X1,		DT_VID_VidSys,		DU_A },
            {	VID_SYS_BUS_VOLT,			ui->lineEdit_AllVolt,		DF_F0X1,		DT_VID_VidSys,		DU_V },
            {	VID_SYS_PRE_BUS_VOLT,		ui->lineEdit_PreVolt,		DF_F0X1,		DT_VID_VidSys,		DU_V },
            {	VID_SYS_SOC,				ui->lineEdit_SOC,			DF_F0X1,		DT_VID_VidSys,		DU_PER },
            {	VID_SYS_MAX_VOLT,			ui->lineEdit_MaxVolt1,		DF_INTX,		DT_VID_VidSys,		DU_MV },
            {	VID_SYS_MAXV_POSI,			ui->lineEdit_MaxVolt2,		DF_INTX,		DT_VID_VidSys,		DU_POSI },
            {	VID_SYS_MIN_VOLT,			ui->lineEdit_MinVolt1,		DF_INTX,		DT_VID_VidSys,		DU_MV },
            {	VID_SYS_MINV_POSI,			ui->lineEdit_MinVolt2,		DF_INTX,		DT_VID_VidSys,		DU_POSI },
            {	VID_SYS_MAX_TEMP,			ui->lineEdit_MaxTemp1,		DF_F0X1,		DT_VID_VidSys,		DU_TEMP },
            {	VID_SYS_MAXT_POSI,			ui->lineEdit_MaxTemp2,		DF_INTX,		DT_VID_VidSys,		DU_POSI },
            {	VID_SYS_MIN_TEMP,			ui->lineEdit_MinTemp1,		DF_F0X1,		DT_VID_VidSys,		DU_TEMP },
            {	VID_SYS_MINT_POSI,			ui->lineEdit_MinTemp2,		DF_INTX,		DT_VID_VidSys,		DU_POSI },
            {	VID_SYS_RELAY1_STATUS,		ui->lineEdit_1Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_RELAY2_STATUS,		ui->lineEdit_2Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_RELAY3_STATUS,		ui->lineEdit_3Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_RELAY4_STATUS,		ui->lineEdit_4Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_RELAY5_STATUS,		ui->lineEdit_5Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_RELAY6_STATUS,		ui->lineEdit_6Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_RELAY7_STATUS,		ui->lineEdit_7Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_RELAY8_STATUS,		ui->lineEdit_8Relay1,		DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	VID_SYS_BSU_RELAY_STATUS,	ui->lineEdit_BSRelay,       DF_INTX,		DT_VID_VidSys,		DU_RELAY },
            {	PID_SYS_RELAY_1,            ui->lineEdit_1Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL },
            {	PID_SYS_RELAY_2,            ui->lineEdit_2Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL },
            {	PID_SYS_RELAY_3,            ui->lineEdit_3Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL },
            {	PID_SYS_RELAY_4,            ui->lineEdit_4Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL },
            {	PID_SYS_RELAY_5,            ui->lineEdit_5Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL },
            {	PID_SYS_RELAY_6,            ui->lineEdit_6Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL },
            {	PID_SYS_RELAY_7,            ui->lineEdit_7Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL },
            {	PID_SYS_RELAY_8,            ui->lineEdit_8Relay2,		DF_RELAY,		DT_PID_PidSys,		DU_NULL }
        };

        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Sider)/sizeof(g_sCtl_Sider[0]); i++)
        {
            sCtlEx = g_sCtl_Sider[i];
            QString strData = g_pCommunicate->GetDataString(sCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);
            if ((i == 6) || (i == 8) || (i == 10) || (i == 12) || ((i>12) && (i<22)))
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
        QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_TM_YEAR]) + "-" +
                             QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_TM_MONTH]) + "-" +
                             QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_TM_DAY]) + " " +
                             QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_TM_HOUR]) + ":" +
                             QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_TM_MIN]) + ":" +
                             QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_TM_SEC]) ;
        ui->lineEdit_BMSTimes->setText(str);

        int nSecs = g_pCommunicate->DB_GetUint16(VID_SYS_LIFE);
        str = QString("%1H:%2M:%3S")
                .arg((nSecs/3600)%60 , 2 , 10)
                .arg((nSecs/60)%60 , 2 , 10)
                .arg(nSecs%60 , 2 , 10);
        ui->lineEdit_BMSRunTimes->setText(str);
        itimeData = 0;
    }
}

void mainSider::on_pushButton_calibrationTime_clicked()
{
    ui->pushButton_calibrationTime->setEnabled(false);
    ST_CAN_FRAME frame;
    g_pCommunicate->SetTime(&frame);
    g_pCommunicate->WriteData(&frame);
    ui->pushButton_calibrationTime->setEnabled(true);
}

void mainSider::on_pushButton_calibrationSOC_clicked()
{
    QString strValue = ui->lineEdit_SetSOC->text();
    if (strValue.isEmpty())
    {
        return;
    }
    UINT16 unValue = strValue.toFloat();
    ui->pushButton_calibrationSOC->setEnabled(false);
    ST_CAN_FRAME frame;
    g_pCommunicate->SetData(&frame , VID_MAKE_BAT_VID(g_pCommunicate->m_iBatSelNo - 1, VID_BAT_USER_SET_SOC) , unValue);
    g_pCommunicate->WriteData(&frame);
    g_pCommunicate->WriteData(&frame);
    ui->pushButton_calibrationSOC->setEnabled(true);
    ui->lineEdit_SetSOC->setText("");
}
