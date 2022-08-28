//采集模块设置-标签
#include "bsusettab.h"
#include "ui_bsusettab.h"

bsuSetTab::bsuSetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bsuSetTab)
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

    m_bisFrush = false;
    m_batNum = -2;
    m_bsuNum = -2;

    ui->lineEdit->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    ui->lineEdit_2->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(1);
    gridLayout->setMargin(6);
    for (int i = 0 ; i < 6 ; i++)
    {
        QHBoxLayout *hbtnlay[11];
        groupBat[i] = new QGroupBox;
        gridLayoutsub[i] = new QGridLayout;
        gridLayoutsub[i] ->setSpacing(11);
        gridLayoutsub[i] ->setMargin(1);

        tab2Label[i][0] = new QLabel(QString_C("序号"));
        tab2Label[i][0] ->setAlignment(Qt::AlignLeft);
        tab2Label[i][0] ->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Fixed);
        tab2Label[i][1] = new QLabel(QString_C("电池"));
        tab2Label[i][1] ->setAlignment(Qt::AlignLeft);
        tab2Label[i][1] ->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Fixed);
        tab2Label[i][2] = new QLabel(QString_C("温度"));
        tab2Label[i][2] ->setAlignment(Qt::AlignLeft);
        tab2Label[i][2] ->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Fixed);
        hbtnlay[0] = new QHBoxLayout;
        hbtnlay[0] ->addWidget(tab2Label[i][0]);
        hbtnlay[0] ->addWidget(tab2Label[i][1]);
        hbtnlay[0] ->addWidget(tab2Label[i][2]);
        gridLayoutsub[i]->addLayout(hbtnlay[0] , 0 , 0);
        gridLayoutsub[i]->setRowStretch(0 , 1);

        for (int k = 0 ; k < 10 ; k++)
        {
            tab2LabelName[i*10 + k] = new QLabel(this);
            tab2LabelName[i*10 + k]->setAlignment(Qt::AlignRight);
            tab2LabelName[i*10 + k]->setFixedWidth(30);
            tab2LabelName[i*10 + k]->setFixedHeight(25);
            tab2LabelName[i*10 + k]->setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
            tab2LabelName[i*10 + k]->setText(QString::number(i*10 + k +1));
            m_editTab2Bat[i*10 + k] = new QLineEdit(this);
            m_editTab2Bat[i*10 + k]->setFixedWidth(70);
            m_editTab2Bat[i*10 + k]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
            m_editTab2Tem[i*10 + k] = new QLineEdit(this);
            m_editTab2Tem[i*10 + k]->setFixedWidth(70);
            m_editTab2Tem[i*10 + k]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
            hbtnlay[k+1] = new QHBoxLayout;
            hbtnlay[k+1] ->addWidget(tab2LabelName[i*10 + k]);
            hbtnlay[k+1] ->addWidget(m_editTab2Bat[i*10 + k]);
            hbtnlay[k+1] ->addWidget(m_editTab2Tem[i*10 + k]);
            gridLayoutsub[i]->addLayout(hbtnlay[k + 1] , k+1 , 0);
            gridLayoutsub[i]->setRowStretch(k +1 , 1);
        }
        groupBat[i]->setLayout(gridLayoutsub[i]);
        gridLayout->addWidget(groupBat[i] , 0 , i);
        gridLayout->setColumnStretch(i , 1);
    }
    ui->groupBox->setLayout(gridLayout);

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

    stControlStringEx siSetCtrlsEx[2] =
    {
        {	PID_BSU_CELL_NUM,			ui->lineEdit,	DF_UINTX,	DT_PID_PidBsu,		DU_NULL },
        {	PID_BSU_TEMP_NUM,			ui->lineEdit_2,	DF_UINTX,	DT_PID_PidBsu,		DU_NULL },
    };
    g_siSetCtrlsEx[0] = siSetCtrlsEx[0];
    g_siSetCtrlsEx[1] = siSetCtrlsEx[1];

    stControlStringEx sCtl_Bsu_Set[2] =
    {
        {	PID_SYS_BSU_NUM,			ui->lineEdit_2,			DF_UINTX,	DT_PID_PidBsu,		DU_NULL },
        {	PID_SYS_BAT_NUM,			ui->lineEdit,			DF_UINTX,	DT_PID_PidBsu,		DU_NULL },
    };
    g_sCtl_Bsu_Set[0] = sCtl_Bsu_Set[0];
    g_sCtl_Bsu_Set[1] = sCtl_Bsu_Set[1];

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(300);
}

bsuSetTab::~bsuSetTab()
{
    timer->deleteLater();
    delete ui;
}

void bsuSetTab::setInit()
{
    m_bisFrush = true;
}

void bsuSetTab::hideshow()
{
    if ((m_batNum == g_pCommunicate->m_nBatNum) && (m_bsuNum == g_pCommunicate->m_nBsuNum))
    {
        return;
    }
    m_batNum = g_pCommunicate->m_nBatNum;//电池组数
    m_bsuNum = g_pCommunicate->m_nBsuNum;//每组电池的BSU个数
    for (int i = 0 ; i < 6 ; i++)
    {
        if (i<((m_batNum*m_bsuNum-1)/10 +1))
        {
            groupBat[i]->setVisible(true);
            tab2Label[i][0]->setVisible(true);
            tab2Label[i][1]->setVisible(true);
            tab2Label[i][2]->setVisible(true);
        }
        else
        {
            groupBat[i]->setVisible(false);
            tab2Label[i][0]->setVisible(false);
            tab2Label[i][1]->setVisible(false);
            tab2Label[i][2]->setVisible(false);
        }
    }
    for (int k = 0 ; k < TAB2_BSU_NUMBER ; k++)
    {
        if (k<((m_batNum*m_bsuNum)%TAB2_BSU_NUMBER))
        {
            m_editTab2Bat[k]->setVisible(true);  //电池
            m_editTab2Tem[k]->setVisible(true); //温度
            //tab2LabelName[k]->setVisible(true);
            tab2LabelName[k]->setText(QString::number(k + 1));
        }
        else
        {
            m_editTab2Bat[k]->setVisible(false);  //电池
            m_editTab2Tem[k]->setVisible(false); //温度
            tab2LabelName[k]->setText(" ");
            //tab2LabelName[k]->setVisible(false);
        }
    }
}

void bsuSetTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    //ui.lineEdit->setText(QString::number(m_batNum));
    //ui.lineEdit_2->setText(QString::number(m_bsuNum));
    stControlStringEx stCtlEx;
    for (int i=0; i<sizeof(g_sCtl_Bsu_Set)/sizeof(g_sCtl_Bsu_Set[0]); i++)
    {
        stCtlEx = g_sCtl_Bsu_Set[i];
        QString strData = g_pCommunicate->GetDataString(stCtlEx);
        QString strUnit = g_pCommunicate->GetDataUnit(stCtlEx);
        strData = strData + strUnit;
        QString strOldData = m_editTab2Bat[i]->text();
        if (strData != strOldData)
        {
            stCtlEx.idLineEdit->setText(strData);
        }
    }

    hideshow();

    for (int i=0; i<60; i++)
    {
        for (int j=0; j<2; j++)
        {
            if (j == 0)
            {
                stCtlEx = g_siSetCtrlsEx[0];
                stCtlEx.idDB = PID_MAKE_BSU_PID(i, stCtlEx.idDB);
                QString strData = g_pCommunicate->GetDataString(stCtlEx);
                QString strUnit = g_pCommunicate->GetDataUnit(stCtlEx);
                /*if ((i>10) && (i<20))
                {
                    strData = strUnit;
                }
                else
                {*/
                strData = strData + strUnit;
                //}
                QString strOldData = m_editTab2Bat[i]->text();
                if (strData != strOldData)
                {
                    m_editTab2Bat[i]->setText(strData);
                }
            }
            else if ( j == 1)
            {
                stCtlEx = g_siSetCtrlsEx[1];
                stCtlEx.idDB = PID_MAKE_BSU_PID(i, stCtlEx.idDB);
                QString strData = g_pCommunicate->GetDataString(stCtlEx);
                QString strUnit = g_pCommunicate->GetDataUnit(stCtlEx);
                /*if ((i>10) && (i<20))
                {
                    strData = strUnit;
                }
                else
                {*/
                strData = strData + strUnit;
                //}
                QString strOldData = m_editTab2Tem[i]->text();
                if (strData != strOldData)
                {
                    m_editTab2Tem[i]->setText(strData);
                }
            }
        }
    }
}

bool bsuSetTab::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        for (int i=0; i<sizeof(g_sCtl_Bsu_Set)/sizeof(g_sCtl_Bsu_Set[0]); i++)// 数据
        {
            if (obj == g_sCtl_Bsu_Set[i].idLineEdit)
            {
                if (!g_sCtl_Bsu_Set[i].idLineEdit->isVisible())
                {
                    break;
                }
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    if (g_pCommunicate->m_nProtected >= 1)
                    {
                        ModifyPara *pDlg = new ModifyPara(this);
                        if (g_sCtl_Bsu_Set[i].idType == DT_VID_VidSys)
                        {
                            pDlg->SetSigId(g_sCtl_Bsu_Set[i].idDB);
                        }
                        else
                        {
                            pDlg->SetSigId(PID_TO_VID(g_sCtl_Bsu_Set[i].idDB));
                        }
                        pDlg->OnInit();
                        pDlg->exec();
                        delete pDlg;
                    }
                }
            }
        }
        stControlStringEx stCtlEx;
        for (int i=0; i<60; i++)
        {
            if (obj == m_editTab2Bat[i])
            {
                if (!m_editTab2Bat[i]->isVisible())
                {
                    continue;
                }
                stCtlEx = g_siSetCtrlsEx[0];
            }
            else if (obj == m_editTab2Tem[i])
            {
                if (!m_editTab2Tem[i]->isVisible())
                {
                    continue;
                }
                stCtlEx = g_siSetCtrlsEx[1];
            }
            else
            {
                continue;
            }

            QMouseEvent *me = (QMouseEvent*)e;
            if(me->button() == Qt::LeftButton)
            {
                if (g_pCommunicate->m_nProtected >= 1)
                {
                    ModifyPara *pDlg = new ModifyPara(this);
                    stCtlEx.idDB = PID_MAKE_BSU_PID(i, stCtlEx.idDB);
                    pDlg->SetSigId(PID_TO_VID(stCtlEx.idDB));
                    pDlg->OnInit();
                    pDlg->exec();
                    delete pDlg;
                }
            }
        }
    }
    return QWidget::eventFilter(obj,e);
}
