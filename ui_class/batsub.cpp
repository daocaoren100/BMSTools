//BAT电池包信息-标签
#include "batsub.h"
#include "ui_batsub.h"

BatSub::BatSub(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatSub)
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

    QVBoxLayout* vhigh = new QVBoxLayout;
    QVBoxLayout* vlow = new QVBoxLayout;
    QVBoxLayout* thigh = new QVBoxLayout;
    QVBoxLayout* tlow = new QVBoxLayout;
    int i = 0;
    QHBoxLayout* hvhigh[10] ;
    QHBoxLayout*hvlow[10];
    QHBoxLayout* hthigh[4] ;
    QHBoxLayout*htlow[4];
    for (i = 0 ; i < 10 ; i++)
    {
        hvhigh[i] = new QHBoxLayout;
        hvlow[i] = new QHBoxLayout;
        m_LabelVHigh[i] = new QLineEdit(this);
        m_LabelVHigh[i]->setFixedWidth(85);
        m_LabelVHigh[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelVHighNum[i] = new QLineEdit(this);
        m_LabelVHighNum[i]->setFixedWidth(85);
        m_LabelVHighNum[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelVHigh[i]->setEnabled(false);
        m_LabelVHighNum[i]->setEnabled(false);
        hvhigh[i]->addWidget(m_LabelVHigh[i]);
        hvhigh[i]->addWidget(m_LabelVHighNum[i]);
        vhigh->addLayout(hvhigh[i]);

        m_LabelVLow[i] = new QLineEdit(this);
        m_LabelVLow[i]->setFixedWidth(85);
        m_LabelVLow[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelVLowNum[i] = new QLineEdit(this);
        m_LabelVLowNum[i]->setFixedWidth(85);
        m_LabelVLowNum[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelVLow[i]->setEnabled(false);
        m_LabelVLowNum[i]->setEnabled(false);
        hvlow[i]->addWidget(m_LabelVLow[i]);
        hvlow[i]->addWidget(m_LabelVLowNum[i]);
        vlow->addLayout(hvlow[i]);
    }
    for (i = 0 ; i < 4 ; i++)
    {
        hthigh[i] = new QHBoxLayout;
        htlow[i] = new QHBoxLayout;
        m_LabelTempHigh[i] = new QLineEdit(this);
        m_LabelTempHigh[i]->setFixedWidth(85);
        m_LabelTempHigh[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelTempHighNum[i] = new QLineEdit(this);
        m_LabelTempHighNum[i]->setFixedWidth(85);
        m_LabelTempHighNum[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelTempHigh[i]->setEnabled(false);
        m_LabelTempHighNum[i]->setEnabled(false);
        hthigh[i]->addWidget(m_LabelTempHigh[i]);
        hthigh[i]->addWidget(m_LabelTempHighNum[i]);
        thigh->addLayout(hthigh[i]);

        m_LabelTempLow[i] = new QLineEdit(this);
        m_LabelTempLow[i]->setFixedWidth(85);
        m_LabelTempLow[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelTempLowNum[i] = new QLineEdit(this);
        m_LabelTempLowNum[i]->setFixedWidth(85);
        m_LabelTempLowNum[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框
        m_LabelTempLow[i]->setEnabled(false);
        m_LabelTempLowNum[i]->setEnabled(false);
        htlow[i]->addWidget(m_LabelTempLow[i]);
        htlow[i]->addWidget(m_LabelTempLowNum[i]);
        tlow->addLayout(htlow[i]);
    }
    ui->groupBox_3->setLayout(vhigh);
    ui->groupBox_4->setLayout(vlow);
    ui->groupBox_5->setLayout(thigh);
    ui->groupBox_6->setLayout(tlow);

    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(ui->horizontalLayout_2);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    //ui.scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //ui.scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    //QHBoxLayout* hscroll = new QHBoxLayout;
    //hscroll->addWidget(ui.scrollArea);
    //setLayout(hscroll);

    stControlStringEx sCtl_Bat_Sub[75] =
    {
        {	VID_BAT_TOTAL_VOLT,			ui->lineEdit,               DF_F0X1,		DT_VID_VidBsuBat,			DU_V },
        {	VID_BAT_CURR,				ui->lineEdit_2,             DF_F0X1,		DT_VID_VidBsuBat,			DU_A },
        {	VID_BAT_SOC,				ui->lineEdit_3,             DF_F0X1,		DT_VID_VidBsuBat,			DU_PER },
        {	VID_BAT_SOH,				ui->lineEdit_4,             DF_F0X1,		DT_VID_VidBsuBat,			DU_PER },
        {	VID_BAT_CELL_NUM,			ui->lineEdit_5,             DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_AVG_VOLT,			ui->lineEdit_6,             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_TEMP_NUM,			ui->lineEdit_7,             DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_AVG_TEMP,			ui->lineEdit_8,             DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_USER_SET_SOC,		ui->lineEdit_9,             DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_PRE_STATE,			NULL,                       DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_PRE_COUNTER,		NULL,                       DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_PRE_FILTER,			NULL,                       DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_PRE_ENABLE,			NULL,                       DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX01_VOLT,		m_LabelVHigh[0],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX02_VOLT,		m_LabelVHigh[1],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX03_VOLT,		m_LabelVHigh[2],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX04_VOLT,		m_LabelVHigh[3],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX05_VOLT,		m_LabelVHigh[4],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX06_VOLT,		m_LabelVHigh[5],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX07_VOLT,		m_LabelVHigh[6],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX08_VOLT,		m_LabelVHigh[7],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX09_VOLT,		m_LabelVHigh[8],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX10_VOLT,		m_LabelVHigh[9],			DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMAX01_NO,			m_LabelVHighNum[0],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX02_NO,			m_LabelVHighNum[1],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX03_NO,			m_LabelVHighNum[2],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX04_NO,			m_LabelVHighNum[3],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX05_NO,			m_LabelVHighNum[4],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX06_NO,			m_LabelVHighNum[5],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX07_NO,			m_LabelVHighNum[6],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX08_NO,			m_LabelVHighNum[7],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX09_NO,			m_LabelVHighNum[8],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMAX10_NO,			m_LabelVHighNum[9],         DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN01_VOLT,		m_LabelVLow[0],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN02_VOLT,		m_LabelVLow[1],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN03_VOLT,		m_LabelVLow[2],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN04_VOLT,		m_LabelVLow[3],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN05_VOLT,		m_LabelVLow[4],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN06_VOLT,		m_LabelVLow[5],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN07_VOLT,		m_LabelVLow[6],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN08_VOLT,		m_LabelVLow[7],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN09_VOLT,		m_LabelVLow[8],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN10_VOLT,		m_LabelVLow[9],             DF_INTX,		DT_VID_VidBsuBat,			DU_MV },
        {	VID_BAT_VMIN01_NO,			m_LabelVLowNum[0],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN02_NO,			m_LabelVLowNum[1],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN03_NO,			m_LabelVLowNum[2],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN04_NO,			m_LabelVLowNum[3],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN05_NO,			m_LabelVLowNum[4],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN06_NO,			m_LabelVLowNum[5],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN07_NO,			m_LabelVLowNum[6],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN08_NO,			m_LabelVLowNum[7],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN09_NO,			m_LabelVLowNum[8],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_VMIN10_NO,			m_LabelVLowNum[9],          DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMAX01_TEMP,		m_LabelTempHigh[0],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMAX02_TEMP,		m_LabelTempHigh[1],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMAX03_TEMP,		m_LabelTempHigh[2],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMAX04_TEMP,		m_LabelTempHigh[3],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMAX01_NO,			m_LabelTempHighNum[0],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMAX02_NO,			m_LabelTempHighNum[1],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMAX03_NO,			m_LabelTempHighNum[2],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMAX04_NO,			m_LabelTempHighNum[3],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMIN01_TEMP,		m_LabelTempLow[0],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMIN02_TEMP,		m_LabelTempLow[1],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMIN03_TEMP,		m_LabelTempLow[2],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMIN04_TEMP,		m_LabelTempLow[3],			DF_F0X1,		DT_VID_VidBsuBat,			DU_TEMP },
        {	VID_BAT_TMIN01_NO,			m_LabelTempLowNum[0],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMIN02_NO,			m_LabelTempLowNum[1],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMIN03_NO,			m_LabelTempLowNum[2],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	VID_BAT_TMIN04_NO,			m_LabelTempLowNum[3],		DF_INTX,		DT_VID_VidBsuBat,			DU_NULL },
        {	PID_BAT_SOC,				NULL,                       DF_F0X2,		DT_PID_PidBat,              DU_PER },
        {	PID_BAT_SOH,				NULL,                       DF_F0X1,		DT_PID_PidBat,              DU_PER },
        {	PID_BAT_CHRG_SOC,			ui->lineEdit_10,            DF_F0X2,		DT_PID_PidBat,              DU_AH },
        {	PID_BAT_DSCH_SOC,			ui->lineEdit_13,            DF_INTX,		DT_PID_PidBat,              DU_AH },
        {	PID_BAT_CYCLE_TIMES,		ui->lineEdit_11,            DF_INTX,		DT_PID_PidBat,              DU_NULL },
        {	PID_BAT_HALL_ZERO,			ui->lineEdit_12,            DF_INTX,		DT_PID_PidBat,              DU_NULL },
    };

    ui->lineEdit_9->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器,否则无法被eventFilter截获从而弹出Modify对话框

    for (int i = 0 ; i < 75 ; i++)
    {
        g_sCtl_Bat_Sub[i] = sCtl_Bat_Sub[i];
    }
    m_bisFrush = false;
    m_iBatNum = 0;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);
}

BatSub::~BatSub()
{
    timer->deleteLater();
    delete ui;
}

void BatSub::setInit(int batnom)
{
    m_iBatNum = batnom;
    m_bisFrush = true;
}

bool BatSub::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        for (int i=0; i<sizeof(g_sCtl_Bat_Sub)/sizeof(g_sCtl_Bat_Sub[0]); i++)
        {
                if (obj == g_sCtl_Bat_Sub[i].idLineEdit)
                {
                    if (!g_sCtl_Bat_Sub[i].idLineEdit->isEnabled())
                    {
                        break;
                    }
                    QMouseEvent *me = (QMouseEvent*)e;
                    if(me->button() == Qt::LeftButton)
                    {
                        if (g_pCommunicate->m_nProtected >= 1)
                        {
                            ModifyPara *pModify = new ModifyPara(this);
                            pModify->SetSigId(VID_MAKE_BAT_VID(m_iBatNum , g_sCtl_Bat_Sub[i].idDB));
                            pModify->OnInit();
                            pModify->exec();
                            delete pModify;
                        }
                    }
                    break;
            }
        }
    }
    return QWidget::eventFilter(obj,e);
}

void BatSub::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bat_Sub)/sizeof(g_sCtl_Bat_Sub[0]); i++)
        {
            sCtlEx = g_sCtl_Bat_Sub[i];
            if (sCtlEx.idLineEdit == NULL)
            {
                continue;
            }
            if (sCtlEx.idType == DT_VID_VidBsuBat)
            {
                sCtlEx.idDB = VID_MAKE_BAT_VID(m_iBatNum , sCtlEx.idDB);
            }
            else if (sCtlEx.idType == DT_PID_PidBat)
            {
                sCtlEx.idDB = PID_MAKE_BAT_PID(m_iBatNum , sCtlEx.idDB);
            }
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
