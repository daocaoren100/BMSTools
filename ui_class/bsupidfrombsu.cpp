//PID电压&温度数设置-标签
#include "bsupidfrombsu.h"
#include "ui_bsupidfrombsu.h"

BSUPidFromBsu::BSUPidFromBsu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BSUPidFromBsu)
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

    QVBoxLayout * vlay = new QVBoxLayout;
    vlay->addWidget(ui->groupBox);
    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(vlay);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    //ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //ui->scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    stControlStringEx sCtl_Bsu_PID[2] =
    {
        {	PID_BSU_CELL_NUM,			ui->lineEdit,		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	PID_BSU_TEMP_NUM,			ui->lineEdit_2,		DF_INTX,		DT_PID_PidSys,		DU_NULL},
    };
    for (int i = 0 ; i < 2 ; i++)
    {
        g_sCtl_Bsu_PID[i] = sCtl_Bsu_PID[i];
    }
    ui->lineEdit->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    ui->lineEdit_2->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    m_iBsuNum = 0;
    m_bisFrush = false;
    m_nTimerID = startTimer(100);//新建定时器
}

BSUPidFromBsu::~BSUPidFromBsu()
{
    killTimer(m_nTimerID);
    delete ui;
}

void BSUPidFromBsu::setInit(int ibsunum)
{
    m_bisFrush = true;
    m_iBsuNum = ibsunum;
    QString str = QString::number(ibsunum);
    str = "BSU No." + str;
    ui->label->setText(str);
}

void BSUPidFromBsu::timerEvent(QTimerEvent *)
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

        for (int i=0; i<sizeof(g_sCtl_Bsu_PID)/sizeof(g_sCtl_Bsu_PID[0]); i++)
        {
            sCtlEx = g_sCtl_Bsu_PID[i];
            sCtlEx.idDB = PID_MAKE_BSU_PID(m_iBsuNum - 1, sCtlEx.idDB);
            if (sCtlEx.idLineEdit == NULL)
            {
                continue;
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

bool BSUPidFromBsu::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        for (int i=0; i<sizeof(g_sCtl_Bsu_PID)/sizeof(g_sCtl_Bsu_PID[0]); i++)// 数据
        {
            if (obj == g_sCtl_Bsu_PID[i].idLineEdit)
            {
                if (!g_sCtl_Bsu_PID[i].idLineEdit->isEnabled())
                {
                    break;
                }
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    if (g_pCommunicate->m_nProtected >= 1)
                    {
                        ModifyPara *pDlg = new ModifyPara(this);
                        pDlg->SetSigId(PID_TO_VID(PID_MAKE_BSU_PID(m_iBsuNum - 1 ,g_sCtl_Bsu_PID[i].idDB)));
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
