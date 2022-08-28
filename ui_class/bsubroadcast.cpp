//BSU基本信息-标签
#include "bsubroadcast.h"
#include "ui_bsubroadcast.h"

BSUBroadcast::BSUBroadcast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BSUBroadcast)
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

    QHBoxLayout *hbtnlay[BSUTAB_VDATA_NUMBER];

    for (int i = 0 ; i <BSUTAB_VDATA_NUMBER ; i++ )
    {
        QString str = "Cell " + QString::number(i + 1) + ":";
        hbtnlay[i] = new QHBoxLayout;
        BSUtabLabel[i] = new QLabel(this);
        BSUtabLabel[i]->setFixedWidth(65);
        BSUtabLabel[i]->setFixedHeight(18);
        BSUtabLabel[i]->setAlignment(Qt::AlignRight);
        BSUtabLabel[i]->setText(str);
        m_editBSUTabVData[i] = new QLineEdit(this);
        m_editBSUTabVData[i]->setEnabled(false);
        hbtnlay[i]->addWidget(BSUtabLabel[i]);
        hbtnlay[i]->addWidget(m_editBSUTabVData[i]);
    }
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(BSUTAB_VDATA_NUMBER_S);
    gridLayout->setMargin(BSUTAB_VDATA_NUMBER_M);   //列
    for (int i = 0 ; i < BSUTAB_VDATA_NUMBER_M ; i++)
    {
        for (int j = 0 ; j < BSUTAB_VDATA_NUMBER_S ; j++)
        {
            if ((BSUTAB_VDATA_NUMBER_S*i + j)>=BSUTAB_VDATA_NUMBER)
            {
                break;
            }
            gridLayout->addLayout(hbtnlay[BSUTAB_VDATA_NUMBER_S*i + j] , j , i);
        }
        gridLayout->setColumnStretch(i , 1);
    }
    ui->groupBox_2->setLayout(gridLayout);

    QLabel *BSUtabTempLabel[BSUTAB_TEMPDATA_NUMBER];
    QHBoxLayout *hbtnlaytemp[BSUTAB_TEMPDATA_NUMBER];

    for (int i = 0 ; i <BSUTAB_TEMPDATA_NUMBER ; i++ )
    {
        QString str = "Temp " + QString::number(i + 1) + ":";
        hbtnlaytemp[i] = new QHBoxLayout;
        BSUtabTempLabel[i] = new QLabel(this);
        BSUtabTempLabel[i]->setFixedWidth(65);
        BSUtabTempLabel[i]->setFixedHeight(18);
        BSUtabTempLabel[i]->setAlignment(Qt::AlignRight);
        BSUtabTempLabel[i]->setText(str);
        m_editBSUTabTempData[i] = new QLineEdit(this);
        m_editBSUTabTempData[i]->setEnabled(false);
        hbtnlaytemp[i]->addWidget(BSUtabTempLabel[i]);
        hbtnlaytemp[i]->addWidget(m_editBSUTabTempData[i]);
    }
    QGridLayout *gridLayout1 = new QGridLayout;
    int iSpac = 4;
    int iMarg = 5;
    gridLayout1->setSpacing(iSpac);
    gridLayout1->setMargin(iMarg);   //列
    for (int i = 0 ; i < iMarg ; i++)
    {
        for (int j = 0 ; j < iSpac ; j++)
        {
            gridLayout1->addLayout(hbtnlaytemp[iSpac*i + j] , j , i);
        }
        gridLayout1->setColumnStretch(i , 1);
    }
    ui->groupBox_3->setLayout(gridLayout1);

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
    m_bisFrush = false;
    m_nTimerID = startTimer(100);//新建定时器
}

BSUBroadcast::~BSUBroadcast()
{
    killTimer(m_nTimerID);
    delete ui;
}

void BSUBroadcast::setInit(int ibsunum)
{
    m_bisFrush = true;
    m_iBsuNum = ibsunum;
    QString str = QString::number(ibsunum);
    str = str + "#BSU";
    ui->label->setText(str);
}

//void BSUBroadcast::setTimer(int time)
//{
//    killTimer(m_nTimerID);
//    m_nTimerID = startTimer(100 * time);//新建定时器
//}

void BSUBroadcast::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
    //static int itimeData = 0;
    //itimeData++;
    //if (itimeData == 6)
    {
        DB_VALUE_T tData;
        g_pCommunicate->PARA_Get(PID_MAKE_BSU_PID(m_iBsuNum - 1, PID_BSU_CELL_NUM) , &tData);
        UINT16 iCellNum = tData.uiData;

        UINT16 bsu02Swver = g_pCommunicate->m_tagCanBMS.m_unBSU02Data.stStructData.aatBsu02AllData[m_iBsuNum -1].aatBsu02Data[BID_BSU02_SWVER].uiData;
        QString str = QString::number(bsu02Swver);
        if (bsu02Swver == 0xFFFF)
        {
            str = "null";
        }
        ui->lineEdit->setText(str);

        int iRealCell = 0;
        for (int i = 0 ; i < BSUTAB_VDATA_NUMBER ; i++)
        {
            INT16 bsu02Data = g_pCommunicate->m_tagCanBMS.m_unBSU02Data.stStructData.aatBsu02AllData[m_iBsuNum -1].aatBsu02Data[BID_BSU02_VOLT1 + i].uiData;
            if (bsu02Data == 0xFFFF)
            {
                str = "null";
            }
            else
            {
                str = QString::number(bsu02Data);
            }

            /////////跳线//
            int kT = i/16;
            int jT = i%16;

            if (i  < iCellNum)
            {
                    if ((g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_CHN_CFG1 + kT] & (1<<jT)))
                    {
                        iRealCell++;
                        QString strTName = "Cell " + QString::number(iRealCell) + ":";
                        BSUtabLabel[i]->setText(strTName);
                        m_editBSUTabVData[i]->setText(str);
                        BSUtabLabel[i]->setVisible(true);
                        m_editBSUTabVData[i]->setVisible(true);
                    }
                    else
                    {
                        str = "null";
                        QString strTName = "Cell :";
                        BSUtabLabel[i]->setText(strTName);
                        m_editBSUTabVData[i]->setText(str);
                        BSUtabLabel[i]->setVisible(true);
                        m_editBSUTabVData[i]->setVisible(true);
                    }
            }
            else
            {
                str = "null";
                QString strTName = "Cell :";
//                BSUtabLabel[i]->setText(strTName);
//                m_editBSUTabVData[i]->setText(str);
                BSUtabLabel[i]->setVisible(false);
                m_editBSUTabVData[i]->setVisible(false);
            }
            /////////跳线//
        }

        g_pCommunicate->PARA_Get(PID_MAKE_BSU_PID(m_iBsuNum - 1, PID_BSU_TEMP_NUM) , &tData);
        UINT16 iTempNum = tData.uiData;

        for (int j = 0 ; j < BSUTAB_TEMPDATA_NUMBER ; j++)
        {
            if (j < iTempNum)
            {
                /////////跳线//
                int kT = j/16;
                int jT = j%16;

                unsigned int abc = g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[m_iBsuNum - 1][PID_BSU_TEMP_CFG1 + kT];
                if ((abc & (1<<jT)))
                {
                    INT16 bsu02Temp = g_pCommunicate->m_tagCanBMS.m_unBSU02Data.stStructData.aatBsu02AllData[m_iBsuNum -1].aatBsu02Data[BID_BSU02_TEMP1 + j].uiData;
                    float ftemp =((float)bsu02Temp)/10.0f;
                    str = QString("%1").arg(ftemp) + QString_C("℃");
                }
                else
                {
                    str = "null";
                }

                /////////跳线//
//                INT16 bsu02Temp = g_pCommunicate->m_tagCanBMS.m_unBSU02Data.stStructData.aatBsu02AllData[m_iBsuNum -1].aatBsu02Data[BID_BSU02_TEMP1 + j].uiData;
//                float ftemp =((float)bsu02Temp)/10.0f;
//                str = QString("%1").arg(ftemp) + QString_C("℃");
            }
            else
            {
                str = "null";
            }

            m_editBSUTabTempData[j]->setText(str);
        }
        //itimeData = 0;
    }
}
