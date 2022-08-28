//PID采集通道设置-标签
#include "bsupidfromchannel.h"
#include "ui_bsupidfromchannel.h"

BSUPidFromChannel::BSUPidFromChannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BSUPidFromChannel)
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

    QHBoxLayout* hboxlay[4];
    for (int i=0; i<4; i++)
    {
        hboxlay[i] = new QHBoxLayout;
        for (int j=0; j<16; j++)
        {
            m_checkCell[16 * i + j] = new QCheckBox;
            m_checkCell[16 * i + j]->setText(QString::number(16 * i + j + 1));
            m_checkCell[16 * i + j]->setChecked(false);
            hboxlay[i]->addWidget(m_checkCell[16 * i + j]);
        }
    }
    ui->groupBox_2->setLayout(hboxlay[0]);
    ui->groupBox_3->setLayout(hboxlay[1]);
    ui->groupBox_4->setLayout(hboxlay[2]);
    ui->groupBox_5->setLayout(hboxlay[3]);

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

    m_iBsuNum = 0;
    m_bModify = false;
    m_bisFrush = false;

    stControlStringEx sCtl_Bsu_PID_CHN[4] =
    {
        {	PID_BSU_CHN_CFG1,			ui->lineEdit,		DF_HEX4,		DT_PID_PidBsu,		DU_NULL},
        {	PID_BSU_CHN_CFG2,			ui->lineEdit_2,		DF_HEX4,		DT_PID_PidBsu,		DU_NULL},
        {	PID_BSU_CHN_CFG3,			ui->lineEdit_3,		DF_HEX4,		DT_PID_PidBsu,		DU_NULL},
        {	PID_BSU_CHN_CFG4,			ui->lineEdit_4,		DF_HEX4,		DT_PID_PidBsu,		DU_NULL},
    };
    for (int i=0; i<sizeof(sCtl_Bsu_PID_CHN)/sizeof(sCtl_Bsu_PID_CHN[0]); i++)
    {
        g_sCtl_Bsu_PID_CHN[i] = sCtl_Bsu_PID_CHN[i];
    }

    m_nTimerID = startTimer(100);//新建定时器
}

BSUPidFromChannel::~BSUPidFromChannel()
{
    killTimer(m_nTimerID);
    delete ui;
}

void BSUPidFromChannel::on_pushButton_Modify_clicked()  //进入修改状态
{
    if (m_bModify)
    {
        m_bModify = false;
    }
    else
    {
        m_bModify = true;
    }

    if (m_bModify)
    {
        ui->pushButton_OK->setEnabled(true);
    }
    else
    {
        ui->pushButton_OK->setEnabled(false);
    }
}

void BSUPidFromChannel::on_pushButton_OK_clicked()      //确定修改
{
    UINT16 uiData = 0;
    ST_CAN_FRAME stFrame = {0};
    for (int i=0; i<4; i++)
    {
        uiData = 0;
        for (int j=0; j<16; j++)
        {
            if (true == m_checkCell[16 * i + j]->isChecked())
            {
                uiData |= (1<<j);
            }
        }
        if (g_pCommunicate->m_nBmuOnLine == 0)     //无主控模式
        {
            g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_CHN_CFG1 + i] = uiData;
        }
        else
        {
            //app.m_cBmu03Msg.SetData(&stFrame, PID_TO_VID(PID_MAKE_BSU_PID(m_nBsuNo, g_sCtl_Bsu_PID_CHN[i].idDB)), uiData);
            g_pCommunicate->SetData(&stFrame , PID_TO_VID(PID_MAKE_BSU_PID(m_iBsuNum - 1 , g_sCtl_Bsu_PID_CHN[i].idDB)), uiData);
            //g_pCommunicate->m_piCan->IKS_Write(g_pCommunicate->m_eCan, &stFrame);
            g_pCommunicate->WriteData(&stFrame);
        }
    }
    m_bModify = false;
    ui->pushButton_OK->setEnabled(false);
}

void BSUPidFromChannel::setInit(int ibsunum)
{
    m_bisFrush = true;
    m_iBsuNum = ibsunum;
    QString str = QString::number(ibsunum);
    str = "BSU No." + str;
    ui->label->setText(str);
}

void BSUPidFromChannel::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        stControlStringEx stCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bsu_PID_CHN)/sizeof(g_sCtl_Bsu_PID_CHN[0]); i++)
        {
            stCtlEx = g_sCtl_Bsu_PID_CHN[i];
            stCtlEx.idDB = PID_MAKE_BSU_PID(m_iBsuNum - 1 , stCtlEx.idDB);
            if (stCtlEx.idLineEdit == NULL)
            {
                continue;
            }
            QString strData = g_pCommunicate->GetDataString(stCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(stCtlEx);
            strData = strData + strUnit;
            QString strOldData = stCtlEx.idLineEdit->text();
            if (strData != strOldData)
            {
                stCtlEx.idLineEdit->setText(strData);
            }
        }

        if (!m_bModify)
        {
            for (int i=0; i<4; i++)
            {
                for (int j=0; j<16; j++)
                {
                    if ((g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][g_sCtl_Bsu_PID_CHN[i].idDB] & (1<<j)))
                    {
                        m_checkCell[16 * i + j]->setChecked(true);
                    }
                    else
                    {
                        m_checkCell[16 * i + j]->setChecked(false);
                    }
                }
            }
        }
        itimeData = 0;
    }
}
