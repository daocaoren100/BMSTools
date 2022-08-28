//参数校准-标签
#include "calibrationparatab.h"
#include "ui_calibrationparatab.h"

calibrationParaTab::calibrationParaTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calibrationParaTab)
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

    QButtonGroup *tab8ZeroButtonGroup = new QButtonGroup(this);
    QButtonGroup *tab8SlopeButtonGroup = new QButtonGroup(this);
    QLabel *tab8Label[TAB8_CALIBRATE_W];
    QLabel *tab8LabelName[TAB8_CALIBRATE_NUMBER];

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(TAB8_CALIBRATE_H);
    gridLayout->setMargin(TAB8_CALIBRATE_W);

    for (int k = 0 ; k< TAB8_CALIBRATE_W ; k++)
    {
        tab8Label[k] = new QLabel(this);
        tab8Label[k]->setAlignment(Qt::AlignCenter);
        tab8Label[k]->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Fixed);
        gridLayout->addWidget(tab8Label[k] , 0 , k);
    }
    tab8Label[0]->setText(QString_C("信号名称"));
    tab8Label[1]->setText(QString_C("码值"));
    tab8Label[2]->setText(QString_C("测量值"));
    tab8Label[3]->setText(QString_C("实测值"));

    for(int i=0; i < TAB8_CALIBRATE_NUMBER; i++)
    {
        if ((i < 3) || ((i > 5) && (i < 8)) || (i == 13))
        {
            m_btnTab8Zero[i] = new QPushButton(QString_C("校正斜率1") , this);
            m_btnTab8Slope[i] = new QPushButton(QString_C("校正斜率2") , this);
        }
        else
        {
            m_btnTab8Zero[i] = new QPushButton(QString_C("校正零点") , this);
            m_btnTab8Slope[i] = new QPushButton(QString_C("校正斜率") , this);
        }
        m_btnTab8Zero[i]->setFixedWidth(100);
        m_btnTab8Slope[i]->setFixedWidth(100);
        m_editTab8CalibrateCode[i] = new QLineEdit(this);
        m_editTab8CalibrateCode[i] ->setFixedWidth(100);
        m_editTab8CalibrateCode[i]->setEnabled(false);
        m_editTab8CalibrateVID[i] = new QLineEdit(this);
        m_editTab8CalibrateVID[i]->setFixedWidth(100);
        m_editTab8CalibrateVID[i]->setEnabled(false);
        m_editTab8CalibrateMeter[i] = new QLineEdit(this);
        m_editTab8CalibrateMeter[i]->setFixedWidth(100);

        if(i < (TAB8_CALIBRATE_NUMBER - 2))
        {
            tab8LabelName[i] = new QLabel(this);
            gridLayout->addWidget(tab8LabelName[i] , i + 1 , 0);
            gridLayout->addWidget(m_editTab8CalibrateCode[i] , i + 1  , 1);
            gridLayout->addWidget(m_editTab8CalibrateVID[i] , i + 1  , 2);
            gridLayout->addWidget(m_editTab8CalibrateMeter[i] , i + 1  , 3);
            tab8ZeroButtonGroup->addButton(m_btnTab8Zero[i]);
            tab8SlopeButtonGroup->addButton(m_btnTab8Slope[i]);
            gridLayout->addWidget(m_btnTab8Zero[i] , i + 1  , 4);
            gridLayout->addWidget(m_btnTab8Slope[i] , i + 1 , 5);
        }
        else
        {
            //自定义信号
            m_editTabCustom[i - 12] = new QLineEdit(this);
            m_editTabCustom[i - 12]->setFixedWidth(100);
            gridLayout->addWidget(m_editTabCustom[i - 12] , i + 1 , 0);
            QWidget *wid = new QWidget(this);
            QGridLayout *wid_grd = new QGridLayout;
            m_editTabCustomCode_VID[i - 12] = new QLineEdit;
            m_editTabCustomCode_VID[i - 12]->setFixedWidth(100);
            wid_grd->addWidget(m_editTabCustomCode_VID[i - 12], 0  , 0);
            wid_grd->addWidget(m_editTab8CalibrateCode[i], 0  , 1);
            wid->setLayout(wid_grd);
            gridLayout->addWidget(wid , i + 1  , 1);
            wid = new QWidget(this);
            wid_grd = new QGridLayout;
            m_editTabCustomVID_VID[i - 12] = new QLineEdit;
            m_editTabCustomVID_VID[i - 12]->setFixedWidth(100);
            wid_grd->addWidget(m_editTabCustomVID_VID[i - 12], 0  , 0);
            wid_grd->addWidget(m_editTab8CalibrateVID[i], 0  , 1);
            wid->setLayout(wid_grd);
            gridLayout->addWidget(wid , i + 1  , 2);
            gridLayout->addWidget(m_editTab8CalibrateMeter[i] , i + 1  , 3);
            tab8ZeroButtonGroup->addButton(m_btnTab8Zero[i]);
            tab8SlopeButtonGroup->addButton(m_btnTab8Slope[i]);
            gridLayout->addWidget(m_btnTab8Zero[i] , i + 1  , 4);
            gridLayout->addWidget(m_btnTab8Slope[i] , i + 1 , 5);
        }


        if (i == 8)
        {
            m_btnTab8Zero[i]->setVisible(false);
        }
    }

    gridLayout->setColumnStretch(0 , 1);
    gridLayout->setColumnStretch(1 , 1);
    gridLayout->setColumnStretch(2 , 1);
    gridLayout->setColumnStretch(3 , 1);
    gridLayout->setColumnStretch(4 , 1);
    gridLayout->setColumnStretch(5 , 1);
    ui->groupBox_17->setLayout(gridLayout);

    tab8LabelName[0]->setText(QString_C("预充电压(V)"));
    tab8LabelName[1]->setText(QString_C("电池总压1(V)"));
    tab8LabelName[2]->setText(QString_C("负母线电压1(V)"));
    tab8LabelName[3]->setText(QString_C("霍尔电流1(mV)"));
    tab8LabelName[4]->setText(QString_C("分流器电压(mV)"));
    tab8LabelName[5]->setText(QString_C("霍尔电流2(mV)"));
    tab8LabelName[6]->setText(QString_C("电池总压2(V)或慢充"));
    tab8LabelName[7]->setText(QString_C("负母线电压2(V)或快充"));
    tab8LabelName[8]->setText(QString_C("工作电压(V)"));
    tab8LabelName[9]->setText(QString_C("CC电压(V)"));
    tab8LabelName[10]->setText(QString_C("CC2电压(V)"));
    tab8LabelName[11]->setText(QString_C("CP电压(V)"));
//    tab8LabelName[12]->setText(QString_C("慢充继电器回采(V)"));
//    tab8LabelName[13]->setText(QString_C("快充继电器回采(V)"));
//    tab8LabelName[14]->setText(QString_C("总负继电器回采(V)"));

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

    connect(tab8ZeroButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slotZeroButtonClick(int)));
    connect(tab8SlopeButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slotSlopeButtonClick(int)));

    m_bisFrush = false;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);
}

calibrationParaTab::~calibrationParaTab()
{
    timer->deleteLater();
    delete ui;
}

void calibrationParaTab::on_pushButton_StartCalib_clicked()     //进入工装
{
    CaliBmuCtrlTestMode(1);
}

void calibrationParaTab::on_pushButton_FinishCalib_clicked()    //退出工装
{
    CaliBmuCtrlTestMode(0);
}

void calibrationParaTab::slotZeroButtonClick(int iButton)
{
    qDebug() << QString::number(iButton);
    float fData = m_editTab8CalibrateMeter[-iButton-2]->text().toFloat();
    if(iButton == -6)
    {
        fData = fData * 100;
    }
    else
    {
        fData = fData * 10;
    }

    if (iButton == -15)
    {
        UINT code = m_editTabCustom[1]->text().toUInt();
        if((code == 6) || (code == 16))
        {
            fData = fData * 10;
        }
        CaliBmuAd(code, 3 , (int)fData);
    }
    else if (iButton == -14)
    {
        UINT code = m_editTabCustom[0]->text().toUInt();
        if((code == 6) || (code == 16))
        {
            fData = fData * 10;
        }
        CaliBmuAd(code, 1 , 0);
    }
    else if ((HV_CPU_VER >= 1004) && ((iButton <= -2) && (iButton >= -4) || (iButton == -8) || (iButton == -9)))
    {
        CaliBmuAd(-iButton-1, 3 , (int)fData);
    }
    else
    {
        CaliBmuAd(-iButton-1, 1 , 0);
    }
}

void calibrationParaTab::slotSlopeButtonClick(int iButton)
{
    qDebug() << QString::number(iButton);
    float fData = m_editTab8CalibrateMeter[-iButton-2]->text().toFloat();
    if(iButton == -6)
    {
        fData = fData * 100;
    }
    else if(iButton == -5)
    {

    }
    else
    {
        fData = fData * 10;
    }
    

    if (iButton == -15)
    {
        UINT code = m_editTabCustom[0]->text().toUInt();
        if((code == 6) || (code == 16))
        {
            fData = fData * 10;
        }
        CaliBmuAd(m_editTabCustom[1]->text().toInt(), 4 , (int)fData);
    }
    else if (iButton == -14)
    {
        UINT code = m_editTabCustom[0]->text().toUInt();
        if((code == 6) || (code == 16))
        {
            fData = fData * 10;
        }
        CaliBmuAd(m_editTabCustom[0]->text().toInt(), 2 , (int)fData);
    }
    else if ((HV_CPU_VER >= 1004) && ((iButton <= -2) && (iButton >= -4) || (iButton == -8) || (iButton == -9)))
    {
        CaliBmuAd(-iButton-1, 4 , (int)fData);
    }
    else
    {
        CaliBmuAd(-iButton-1, 2 , (int)fData);
    }
}

void calibrationParaTab::setInit()
{
    m_bisFrush = true;
}

void calibrationParaTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        //高压CPU1004版本以下支持双点校准
        HV_CPU_VER = g_pCommunicate->DB_GetUint16(VID_SYS_RESERVED3);
        if (HV_CPU_VER < 1004)
        {
            m_btnTab8Zero[0]->setVisible(false);
            m_btnTab8Zero[1]->setVisible(false);
            m_btnTab8Zero[2]->setVisible(false);
            m_btnTab8Zero[6]->setVisible(false);
            m_btnTab8Zero[7]->setVisible(false);

            m_btnTab8Slope[0]->setText(QString_C("校正斜率"));
            m_btnTab8Slope[1]->setText(QString_C("校正斜率"));
            m_btnTab8Slope[2]->setText(QString_C("校正斜率"));
            m_btnTab8Slope[6]->setText(QString_C("校正斜率"));
            m_btnTab8Slope[7]->setText(QString_C("校正斜率"));
        }

        for(int i=0; i < TAB8_CALIBRATE_NUMBER; i++)
        {
            if (g_pCommunicate->m_nProtected ==2)
            {
                m_btnTab8Zero[i]->setEnabled(true);
                m_btnTab8Slope[i]->setEnabled(true);
                ui->pushButton_StartCalib->setEnabled(true);
                ui->pushButton_FinishCalib->setEnabled(true);
            }
            else
            {
                m_btnTab8Zero[i]->setEnabled(false);
                m_btnTab8Slope[i]->setEnabled(false);
                ui->pushButton_StartCalib->setEnabled(false);
                ui->pushButton_FinishCalib->setEnabled(false);
            }
        }

//        int vid_vid1 = m_editTabCustomVID_VID[0]->text().toInt();
//        int vid_vid2 = m_editTabCustomVID_VID[1]->text().toInt();
//        int code_vid1 = m_editTabCustomCode_VID[0]->text().toInt();
//        int code_vid2 = m_editTabCustomCode_VID[1]->text().toInt();
        int vid_vid1 = 0;
        int vid_vid2 = 0;
        int code_vid1 = 0;
        int code_vid2 = 0;

        ST_CAN_FRAME pFrame;
        g_pCommunicate->SelectVidData(&pFrame, vid_vid1, 1);
        g_pCommunicate->WriteData(&pFrame);
        g_pCommunicate->SelectVidData(&pFrame, vid_vid2, 1);
        g_pCommunicate->WriteData(&pFrame);
        g_pCommunicate->SelectVidData(&pFrame, code_vid1, 1);
        g_pCommunicate->WriteData(&pFrame);
        g_pCommunicate->SelectVidData(&pFrame, code_vid2, 1);
        g_pCommunicate->WriteData(&pFrame);


        stControlStringEx g_sCtl_Bmu_Calib[30] =
        {
            {	VID_SYS_WORK_MODE,		ui->lineEdit_18,                DF_WKMODE,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_PRE_BUS_VOLT,	m_editTab8CalibrateVID[0],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_BUS_VOLT1,		m_editTab8CalibrateVID[1],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_NBUS_VOLT1,		m_editTab8CalibrateVID[2],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_SLW_BUS_VOLT,	m_editTab8CalibrateVID[6],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_FST_BUS_VOLT,	m_editTab8CalibrateVID[7],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE1,		ui->lineEdit,                   DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE2,		m_editTab8CalibrateCode[0],		DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE3,		m_editTab8CalibrateCode[1],     DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE4,		m_editTab8CalibrateCode[2],		DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE5,		m_editTab8CalibrateCode[6],     DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE6,		m_editTab8CalibrateCode[7],		DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CURR1_VOLT,		m_editTab8CalibrateVID[3],		DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_LEM_VOLT2,		m_editTab8CalibrateVID[5],		DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CURR2_VOLT,		m_editTab8CalibrateVID[4],		DF_F0X2,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE7,		m_editTab8CalibrateCode[3],     DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_LEM_CODE,		m_editTab8CalibrateCode[5],     DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_AD_CODE8,		m_editTab8CalibrateCode[4],     DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_POWER_VOLT,		m_editTab8CalibrateVID[8],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CC_VOLT,		m_editTab8CalibrateVID[9],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CC2_VOLT,		m_editTab8CalibrateVID[10],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CP_VOLT,		m_editTab8CalibrateVID[11],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_PWR_CODE,		m_editTab8CalibrateCode[8],     DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CC_CODE,		m_editTab8CalibrateCode[9],		DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CC2_CODE,		m_editTab8CalibrateCode[10],	DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_CP_CODE,		m_editTab8CalibrateCode[11],	DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	vid_vid1,               m_editTab8CalibrateVID[12],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	vid_vid2,               m_editTab8CalibrateVID[13],		DF_F0X1,		DT_VID_VidSys,		DU_NULL},
            {	code_vid1,              m_editTab8CalibrateCode[12],	DF_UINTX,		DT_VID_VidSys,		DU_NULL},
            {	code_vid2,              m_editTab8CalibrateCode[13],	DF_UINTX,		DT_VID_VidSys,		DU_NULL},
        };

        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bmu_Calib)/sizeof(g_sCtl_Bmu_Calib[0]); i++)
        {
            sCtlEx = g_sCtl_Bmu_Calib[i];
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

        //QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_WORK_MODE]);
        ////QString str = g_pCommunicate->GetDataString(g_stParabmsVidSys[VID_SYS_WORK_MODE]) + g_pCommunicate->GetDataUnit(g_stParabmsVidSys[VID_SYS_WORK_MODE]);
        //ui.lineEdit_18->setText(str);
        //
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_PRE_BUS_VOLT]);
        //m_editTab8CalibrateVID[0]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE2]);
        //m_editTab8CalibrateCode[0]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BUS_VOLT1]);
        //m_editTab8CalibrateVID[1]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE3]);
        //m_editTab8CalibrateCode[1]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_NBUS_VOLT1]);
        //m_editTab8CalibrateVID[2]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE4]);
        //m_editTab8CalibrateCode[2]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CURR1_VOLT]);
        //m_editTab8CalibrateVID[3]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE7]);
        //m_editTab8CalibrateCode[3]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CURR2_VOLT]);
        //m_editTab8CalibrateVID[4]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE8]);
        //m_editTab8CalibrateCode[4]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_LEM_VOLT2]);
        //m_editTab8CalibrateVID[5]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_LEM_CODE]);
        //m_editTab8CalibrateCode[5]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BUS_VOLT2]);
        //m_editTab8CalibrateVID[6]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE5]);
        //m_editTab8CalibrateCode[6]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_NBUS_VOLT2]);
        //m_editTab8CalibrateVID[7]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE6]);
        //m_editTab8CalibrateCode[7]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_POWER_VOLT]);
        //m_editTab8CalibrateVID[8]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_PWR_CODE]);
        //m_editTab8CalibrateCode[8]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC_VOLT]);
        //m_editTab8CalibrateVID[9]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC_CODE]);
        //m_editTab8CalibrateCode[9]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC2_VOLT]);
        //m_editTab8CalibrateVID[10]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CC2_CODE]);
        //m_editTab8CalibrateCode[10]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_VOLT]);
        //m_editTab8CalibrateVID[11]->setText(str);
        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CP_CODE]);
        //m_editTab8CalibrateCode[11]->setText(str);

        //str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_AD_CODE1]);
        //ui.lineEdit->setText(str);

        itimeData = 0;
    }
}

void calibrationParaTab::CaliBmuCtrlTestMode(int nMode)
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x147D6465;
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0x01;
    frame.unData.abyData[1] = nMode;
    g_pCommunicate->WriteData(&frame);
}

void calibrationParaTab::CaliBmuAd(int nChn, int nType, int nVal)
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x147D6465;
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0x06;
    frame.unData.abyData[1] = nChn;
    frame.unData.awdData[1] = nType;
    frame.unData.auiData[1] = nVal;
    g_pCommunicate->WriteData(&frame);
}

void calibrationParaTab::on_pushButton_SaveCalib_clicked()
{
    QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("确认保存当前参数?"),QMessageBox::Ok|QMessageBox::Cancel,this);
    if(msgBox.exec()==QMessageBox::Ok)
    {
        ST_CAN_FRAME frame;
        g_pCommunicate->SaveCorrect(&frame);
        g_pCommunicate->WriteData(&frame);
    }
}
