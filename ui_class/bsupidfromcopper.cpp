//PID通牌补偿配置-标签
#include "bsupidfromcopper.h"
#include "ui_bsupidfromcopper.h"

BsuPidFromCopper::BsuPidFromCopper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BsuPidFromCopper)
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

    stControlStringEx sCtl_Bsu_PID_RES[4] =
    {
        {	PID_BSU_BAR_CFG1,			ui->lineEdit,		DF_HEX4,	DT_PID_PidBsu,		DU_NULL },
        {	PID_BSU_BAR_CFG2,			ui->lineEdit_2,		DF_HEX4,	DT_PID_PidBsu,		DU_NULL },
        {	PID_BSU_BAR_CFG3,			ui->lineEdit_3,		DF_HEX4,	DT_PID_PidBsu,		DU_NULL },
        {	PID_BSU_BAR_CFG4,			ui->lineEdit_4,		DF_HEX4,	DT_PID_PidBsu,		DU_NULL },
    };
    for (int i = 0 ; i < 4 ; i++)
    {
        g_sCtl_Bsu_PID_RES[i] = sCtl_Bsu_PID_RES[i];
    }
    m_nTimerID = startTimer(100);//新建定时器
}

BsuPidFromCopper::~BsuPidFromCopper()
{
    killTimer(m_nTimerID);
    delete ui;
}

void BsuPidFromCopper::on_pushButton_Modify_clicked()   //进入修改状态
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

void BsuPidFromCopper::on_pushButton_OK_clicked()       //确定修改
{
    UINT16 nCellNo, nBatR, nData;
    QString str;

    ST_CAN_FRAME stFrame = {0};

    // CFG1
    str = ui->lineEdit_5->text();
    nCellNo = str.toInt();
    str = ui->lineEdit_6->text();
    nBatR = str.toInt() / 10.0f + 0.5f;
    nData = nBatR * 64 + nCellNo;

    if (g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG1] != nData)
    {
        g_pCommunicate->SetData(&stFrame , PID_TO_VID(PID_MAKE_BSU_PID(m_iBsuNum - 1 , PID_BSU_BAR_CFG1)), nData);
        //g_pCommunicate->m_piCan->IKS_Write(g_pCommunicate->m_eCan, &stFrame);
        g_pCommunicate->WriteData(&stFrame);
    }

    // CFG2
    str = ui->lineEdit_7->text();
    nCellNo = str.toInt();
    str = ui->lineEdit_8->text();
    nBatR = str.toInt() / 10.0f + 0.5f;
    nData = nBatR * 64 + nCellNo;

    if (g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG2] != nData)
    {
        g_pCommunicate->SetData(&stFrame , PID_TO_VID(PID_MAKE_BSU_PID(m_iBsuNum - 1 , PID_BSU_BAR_CFG2)), nData);
        //g_pCommunicate->m_piCan->IKS_Write(g_pCommunicate->m_eCan, &stFrame);
        g_pCommunicate->WriteData(&stFrame);
    }

    // CFG3
    str = ui->lineEdit_9->text();
    nCellNo = str.toInt();
    str = ui->lineEdit_10->text();
    nBatR = str.toInt() / 10.0f + 0.5f;
    nData = nBatR * 64 + nCellNo;

    if (g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG3] != nData)
    {
        g_pCommunicate->SetData(&stFrame , PID_TO_VID(PID_MAKE_BSU_PID(m_iBsuNum - 1 , PID_BSU_BAR_CFG3)), nData);
        //g_pCommunicate->m_piCan->IKS_Write(g_pCommunicate->m_eCan, &stFrame);
        g_pCommunicate->WriteData(&stFrame);
    }

    // CFG4
    str = ui->lineEdit_11->text();
    nCellNo = str.toInt();
    str = ui->lineEdit_12->text();
    nBatR = str.toInt() / 10.0f + 0.5f;
    nData = nBatR * 64 + nCellNo;

    if (g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG4] != nData)
    {
        g_pCommunicate->SetData(&stFrame , PID_TO_VID(PID_MAKE_BSU_PID(m_iBsuNum - 1 , PID_BSU_BAR_CFG4)), nData);
        //g_pCommunicate->m_piCan->IKS_Write(g_pCommunicate->m_eCan, &stFrame);
        g_pCommunicate->WriteData(&stFrame);
    }

    m_bModify = false;
    ui->pushButton_OK->setEnabled(false);
}

void BsuPidFromCopper::setInit(int ibsunum)
{
    m_bisFrush = true;
    m_iBsuNum = ibsunum;
    QString str = QString::number(ibsunum);
    str = "BSU No." + str;
    ui->label->setText(str);
}

void BsuPidFromCopper::timerEvent(QTimerEvent *)
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
        for (int i=0; i<sizeof(g_sCtl_Bsu_PID_RES)/sizeof(g_sCtl_Bsu_PID_RES[0]); i++)
        {
            sCtlEx = g_sCtl_Bsu_PID_RES[i];
            sCtlEx.idDB = PID_MAKE_BSU_PID(m_iBsuNum - 1 , sCtlEx.idDB);
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

        /*QString str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum][PID_BSU_BAR_CFG1]);
        ui.lineEdit->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum][PID_BSU_BAR_CFG2]);
        ui.lineEdit_2->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum][PID_BSU_BAR_CFG3]);
        ui.lineEdit_3->setText(str);
        str = QString::number(g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum][PID_BSU_BAR_CFG4]);
        ui.lineEdit_4->setText(str);*/
        QString str;
        if (!m_bModify)
        {
            UINT16 nCellNo, nBatR, nData;

            // 1
            nData =g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG1];
            nCellNo = nData & 0x3F;
            nBatR = nData >> 6;
            if (nData == 0xFFFF)
            {
                str = "null";
                ui->lineEdit_5->setText(str);
                ui->lineEdit_6->setText(str);
            }
            else
            {
                str = QString::number(nCellNo);
                ui->lineEdit_5->setText(str);
                str = QString::number(nBatR * 10);
                ui->lineEdit_6->setText(str);
            }

            // 2
            nData =g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG2];
            nCellNo = nData & 0x3F;
            nBatR = nData >> 6;
            if (nData == 0xFFFF)
            {
                str = "null";
                ui->lineEdit_7->setText(str);
                ui->lineEdit_8->setText(str);
            }
            else
            {
                str = QString::number(nCellNo);
                ui->lineEdit_7->setText(str);
                str = QString::number(nBatR * 10);
                ui->lineEdit_8->setText(str);
            }

            // 3
            nData =g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG3];
            nCellNo = nData & 0x3F;
            nBatR = nData >> 6;
            if (nData == 0xFFFF)
            {
                str = "null";
                ui->lineEdit_9->setText(str);
                ui->lineEdit_10->setText(str);
            }
            else
            {
                str = QString::number(nCellNo);
                ui->lineEdit_9->setText(str);
                str = QString::number(nBatR * 10);
                ui->lineEdit_10->setText(str);
            }

            //4
            nData =g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_BAR_CFG4];
            nCellNo = nData & 0x3F;
            nBatR = nData >> 6;
            if (nData == 0xFFFF)
            {
                str = "null";
                ui->lineEdit_11->setText(str);
                ui->lineEdit_12->setText(str);
            }
            else
            {
                str = QString::number(nCellNo);
                ui->lineEdit_11->setText(str);
                str = QString::number(nBatR * 10);
                ui->lineEdit_12->setText(str);
            }
        }
        itimeData = 0;
    }
}
