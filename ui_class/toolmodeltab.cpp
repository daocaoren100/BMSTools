//工装测试-标签
#include "toolmodeltab.h"
#include "ui_toolmodeltab.h"

toolModelTab::toolModelTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toolModelTab)
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

    QButtonGroup *tab9OpenButtonGroup = new QButtonGroup(this);
    QButtonGroup *tab9CloseButtonGroup = new QButtonGroup(this);
    QLabel *tab9Label[TAB9_RELAY_NUMBER];
    QVBoxLayout *vbtnlay[TAB9_RELAY_NUMBER];
    QHBoxLayout *btnlay = new QHBoxLayout;
    for (int i = 0 ; i < TAB9_RELAY_NUMBER ; i++)
    {
        tab9Label[i] = new QLabel(this);
        tab9Label[i]->setText(QString::number(i+1));
        tab9Label[i]->setAlignment(Qt::AlignCenter);
        tab9Label[i]->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Fixed);
        tab9Label[i]->setFixedHeight(24);
        m_btnTab9Open[i] = new QPushButton(QString_C("断开"),this);
        m_btnTab9Close[i] = new QPushButton(QString_C("闭合"),this);
        m_editTab9RelayStatus[i] = new QLineEdit(this);
        m_editTab9RelayStatus[i]->setAlignment(Qt::AlignCenter);
        m_editTab9RelayStatus[i]->setEnabled(false);
        vbtnlay[i] = new QVBoxLayout;
        vbtnlay[i]->addWidget(m_btnTab9Open[i]);
        vbtnlay[i]->addWidget(tab9Label[i]);
        vbtnlay[i]->addWidget(m_btnTab9Close[i]);
        vbtnlay[i]->addWidget(m_editTab9RelayStatus[i]);
        btnlay->addLayout(vbtnlay[i]);
        tab9OpenButtonGroup->addButton(m_btnTab9Open[i] , i);
        tab9CloseButtonGroup->addButton(m_btnTab9Close[i] , i);
    }
    btnlay->addStretch();
    tab9Label[TAB9_RELAY_NUMBER-2]->setText("FAN");
    tab9Label[TAB9_RELAY_NUMBER-1]->setText("BSU");

    ui->groupBox_2->setLayout(btnlay);
    ui->groupBox_2->setEnabled(false);

    //BSU风扇加热控制
    ui->lineEdit_addr->setValidator(new QIntValidator(0, 255, this)); //0, 255为输入的数字值范围
    ui->groupBox_3->setEnabled(false);

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

    connect(tab9OpenButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slotOpenButtonClick(int)));
    connect(tab9CloseButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slotCloseButtonClick(int)));

    m_bisFrush = false;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);

    ui->groupBox_2->setEnabled(true);
    ui->groupBox_3->setEnabled(true);
}

toolModelTab::~toolModelTab()
{
    timer->deleteLater();
    delete ui;
}

void toolModelTab::on_pushButton_InTool_clicked()
{
    CaliBmuCtrlTestMode(1);  //进入工装模式
}

void toolModelTab::on_pushButton_OutTool_clicked()
{
    CaliBmuCtrlTestMode(0);  //退出工装模式
}

void toolModelTab::setInit()
{
    m_bisFrush = true;
}

void toolModelTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        stControlStringEx g_sCtl_Bmu_Test[10] =
        {
            {	VID_SYS_WORK_MODE,				ui->lineEdit_18,                DF_WKMODE,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_RELAY1_STATUS,			m_editTab9RelayStatus[0],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_RELAY2_STATUS,			m_editTab9RelayStatus[1],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_RELAY3_STATUS,			m_editTab9RelayStatus[2],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_RELAY4_STATUS,			m_editTab9RelayStatus[3],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_RELAY5_STATUS,			m_editTab9RelayStatus[4],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_RELAY6_STATUS,			m_editTab9RelayStatus[5],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_RELAY7_STATUS,			m_editTab9RelayStatus[6],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_RELAY8_STATUS,			m_editTab9RelayStatus[7],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
            {	VID_SYS_BSU_RELAY_STATUS,		m_editTab9RelayStatus[8],		DF_INTX,		DT_VID_VidSys,		DU_RELAY},
        };

        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bmu_Test)/sizeof(g_sCtl_Bmu_Test[0]); i++)
        {
            sCtlEx = g_sCtl_Bmu_Test[i];
            if (sCtlEx.idLineEdit == NULL)
            {
                continue;
            }
            QString strData = g_pCommunicate->GetDataString(sCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);
            if ((i>0) && (i<10))
            {
                strData = strUnit;
            }
            else
            {
//                strData = strData + strUnit;
//                if ((i == 0) && (strData == QString_C("工装模式")))
//                {
//                    ui->groupBox_2->setEnabled(true);
//                    ui->groupBox_3->setEnabled(true);
//                }
//                else
//                {
//                    ui->groupBox_2->setEnabled(false);
//                    ui->groupBox_3->setEnabled(false);
//                }
            }

            QString strOldData = sCtlEx.idLineEdit->text();

            if (strData != strOldData)
            {
                sCtlEx.idLineEdit->setText(strData);
            }
        }

        /*QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_WORK_MODE]);
        ui.lineEdit_18->setText(str);
        for (int i = 0 ; i < TAB9_RELAY_NUMBER-1 ; i++)
        {
            str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_RELAY1_STATUS + i]);
            m_editTab9RelayStatus[i]->setText(str);
        }
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_BSU_RELAY_STATUS]);
        m_editTab9RelayStatus[TAB9_RELAY_NUMBER-1]->setText(str);*/
        itimeData = 0;
    }
}

void toolModelTab::slotOpenButtonClick(int iButton)  //断开按钮
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x147D6466;
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0x02;
    frame.unData.abyData[1] = iButton + 1;
    frame.unData.awdData[1] = 0;
    frame.unData.auiData[1] = 0;
    g_pCommunicate->WriteData(&frame);
}

void toolModelTab::slotCloseButtonClick(int iButton)  //闭合按钮
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x147D6466;
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0x02;
    frame.unData.abyData[1] = iButton + 1;
    frame.unData.awdData[1] = 0;
    frame.unData.auiData[1] = 1;
    g_pCommunicate->WriteData(&frame);
}

void toolModelTab::CaliBmuCtrlTestMode(int nMode)   //模式切换
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x147D6466;
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0x01;
    frame.unData.abyData[1] = nMode;
    g_pCommunicate->WriteData(&frame);
}

void toolModelTab::on_pushButton_FAN_off_clicked()  //风扇断开
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x180A80F4;
    frame.unId.stPdf1.DA = ui->lineEdit_addr->text().toInt();
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0xAA;
    frame.unData.abyData[1] = 0xFF;
    frame.unData.abyData[2] = 0xFF;
    frame.unData.abyData[3] = 0xFF;
    frame.unData.abyData[4] = 0xFF;
    frame.unData.abyData[5] = 0xFF;
    frame.unData.abyData[6] = 0xFF;
    frame.unData.abyData[7] = 0xFF;
    g_pCommunicate->WriteData(&frame);
}

void toolModelTab::on_pushButton_FAN_on_clicked()   //风扇闭合
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x180A80F4;
    frame.unId.stPdf1.DA = ui->lineEdit_addr->text().toInt();
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0x55;
    frame.unData.abyData[1] = 0xFF;
    frame.unData.abyData[2] = 0xFF;
    frame.unData.abyData[3] = 0xFF;
    frame.unData.abyData[4] = 0xFF;
    frame.unData.abyData[5] = 0xFF;
    frame.unData.abyData[6] = 0xFF;
    frame.unData.abyData[7] = 0xFF;
    g_pCommunicate->WriteData(&frame);
}

void toolModelTab::on_pushButton_HOT_off_clicked()  //加热断开
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x180A80F4;
    frame.unId.stPdf1.DA = ui->lineEdit_addr->text().toInt();
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0xFF;
    frame.unData.abyData[1] = 0xFF;
    frame.unData.abyData[2] = 0xAA;
    frame.unData.abyData[3] = 0xFF;
    frame.unData.abyData[4] = 0xFF;
    frame.unData.abyData[5] = 0xFF;
    frame.unData.abyData[6] = 0xFF;
    frame.unData.abyData[7] = 0xFF;
    g_pCommunicate->WriteData(&frame);
}

void toolModelTab::on_pushButton_HOT_on_clicked()   //加热闭合
{
    ST_CAN_FRAME frame;
    memset(&frame, 0, sizeof(ST_CAN_FRAME));
    frame.unId.all = 0x180A80F4;
    frame.unId.stPdf1.DA = ui->lineEdit_addr->text().toInt();
    frame.stFrameInfo.uiDLC = 8;
    frame.stFrameInfo.bEFF = 1;
    frame.unData.abyData[0] = 0xFF;
    frame.unData.abyData[1] = 0xFF;
    frame.unData.abyData[2] = 0x55;
    frame.unData.abyData[3] = 0xFF;
    frame.unData.abyData[4] = 0xFF;
    frame.unData.abyData[5] = 0xFF;
    frame.unData.abyData[6] = 0xFF;
    frame.unData.abyData[7] = 0xFF;
    g_pCommunicate->WriteData(&frame);
}
