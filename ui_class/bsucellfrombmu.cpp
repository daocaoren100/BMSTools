//单体VID信息显示-标签
#include "bsucellfrombmu.h"
#include "ui_bsucellfrombmu.h"

BsuCellFromBMU::BsuCellFromBMU(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BsuCellFromBMU)
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

    QLabel *BSUtabLabel[CELLTAB_DATA_NUMBER];
    QVBoxLayout *vbtnlay[CELLTAB_DATA_NUMBER];
    QHBoxLayout *hbtnlay = new QHBoxLayout;
    for (int k = 0 ; k < 6 ; k++)
    {
        vbtnlay[k] = new QVBoxLayout;
        BSUtabLabel[k] = new QLabel(this);
        BSUtabLabel[k]->setFixedWidth(80);
        BSUtabLabel[k]->setFixedHeight(18);
        BSUtabLabel[k]->setAlignment(Qt::AlignCenter);
        vbtnlay[k]->addWidget(BSUtabLabel[k]);
        for (int i = 0 ; i <CELLTAB_DATA_NUMBER ; i++ )
        {
            m_editBSUCellTab2Data[k][i] = new QLineEdit(this);
            m_editBSUCellTab2Data[k][i]->setEnabled(false);
            vbtnlay[k]->addWidget(m_editBSUCellTab2Data[k][i]);
        }
        hbtnlay->addLayout(vbtnlay[k]);
    }
    BSUtabLabel[0]->setText(QString_C("序号"));
    BSUtabLabel[1]->setText(QString_C("单体电压"));
    BSUtabLabel[2]->setText(QString_C("温度"));
    BSUtabLabel[3]->setText(QString_C("均衡电流"));
    BSUtabLabel[4]->setText(QString_C("铜牌电阻"));
    BSUtabLabel[5]->setText(QString_C("原始电压"));

    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(hbtnlay);
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

BsuCellFromBMU::~BsuCellFromBMU()
{
    killTimer(m_nTimerID);
    delete ui;
}

void BsuCellFromBMU::setInit(int ibsunum)
{
    m_bisFrush = true;
    m_iBsuNum = ibsunum;
}

void BsuCellFromBMU::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 2)
    {
        static stControlStringEx stCtlStr[] =
        {
            {	VID_BSU_CELL_UNIQUE_NO,			NULL,		DF_INTX,		DT_VID_VidBsuCell,		DU_NULL},
            {	VID_BSU_CELL_VOLT,				NULL,		DF_INTX,		DT_VID_VidBsuCell,		DU_MV},
            {	VID_BSU_CELL_TEMP,				NULL,		DF_F0X1,		DT_VID_VidBsuCell,		DU_TEMP},
            {	VID_BSU_CELL_BAL_CURR,			NULL,		DF_INTX,		DT_VID_VidBsuCell,		DU_MA},
            {	VID_BSU_CELL_BAR_R,				NULL,		DF_INTX,		DT_VID_VidBsuCell,		DU_NULL},
            {	VID_BSU_CELL_VOLT_ORG,			NULL,		DF_INTX,		DT_VID_VidBsuCell,		DU_MV},
            //{	VID_BSU_CELL_UNIQUE_NO,			NULL,			DF_INTX,		DT_VID,		DU_NULL},
            //{	PID_BSU_TEMP_NUM,			NULL,		DF_INTX,		DT_PID,		DU_NULL},
        };
        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(stCtlStr)/sizeof(stCtlStr[0]); i++)
        {
            for (int j=0; j<CELLTAB_DATA_NUMBER; j++)
            {
                sCtlEx = stCtlStr[i];
                sCtlEx.idDB = VID_MAKE_BSU_CELL_VID(m_iBsuNum -1 , j, sCtlEx.idDB);
                QString strData = g_pCommunicate->GetDataString(sCtlEx);
                QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);
                strData = strData + strUnit;
                //QString strOldData = sCtlEx.idLineEdit->text();
                QString strOldData = m_editBSUCellTab2Data[i][j]->text();
                if (strData != strOldData)
                {
                    m_editBSUCellTab2Data[i][j]->setText(strData);
                    //sCtlEx.idLineEdit->setText(strData);
                }
            }
        }

        itimeData = 0;
    }
}

