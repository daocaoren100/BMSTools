//高级设置-标签
#include "advancedparatab.h"
#include "ui_advancedparatab.h"

advancedParaTab::advancedParaTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::advancedParaTab)
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

    QLabel *tab7Label[TAB7_SET_NUMBER];
    QLabel *tab7LabelName[TAB7_SET_NUMBER];
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(TAB7_CALIBRATE_H);
    gridLayout->setMargin(TAB7_CALIBRATE_W);

    for (int k = 0 ; k< TAB7_CALIBRATE_W ; k++)
    {
        tab7Label[k] = new QLabel(this);
        tab7Label[k]->setAlignment(Qt::AlignCenter);
        tab7Label[k]->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Fixed);
        gridLayout->addWidget(tab7Label[k] , 0 , k);
    }
    tab7Label[1]->setText(QString_C("VID"));
    tab7Label[2]->setText(QString_C("变量值"));
    tab7Label[3]->setText(QString_C("PID"));
    tab7Label[4]->setText(QString_C("参数值"));

    for(int i=0; i < TAB7_SET_NUMBER; i++)
    {
        m_editTab7VID[i] = new QLineEdit(this);
        m_editTab7VID[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
        m_editTab7VIDValue[i] = new QLineEdit(this);
        m_editTab7VIDValue[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
        m_editTab7PID[i] = new QLineEdit(this);
        m_editTab7PID[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
        m_editTab7PIDPara[i] = new QLineEdit(this);
        m_editTab7PIDPara[i]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
        tab7LabelName[i] = new QLabel(this);
        tab7LabelName[i]->setAlignment(Qt::AlignCenter);
        tab7LabelName[i]->setText(QString::number(i + 1));
        gridLayout->addWidget(tab7LabelName[i] , i + 1 , 0);
        gridLayout->addWidget(m_editTab7VID[i] , i + 1  , 1);
        gridLayout->addWidget(m_editTab7VIDValue[i] , i + 1  , 2);
        gridLayout->addWidget(m_editTab7PID[i] , i + 1  , 3);
        gridLayout->addWidget(m_editTab7PIDPara[i] , i + 1  , 4);
    }
    gridLayout->setColumnStretch(0 , 1);
    gridLayout->setColumnStretch(1 , 1);
    gridLayout->setColumnStretch(2 , 1);
    gridLayout->setColumnStretch(3 , 1);
    gridLayout->setColumnStretch(4 , 1);

    //ui->groupBox_2->setLayout(gridLayout);

    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(gridLayout);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    //ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //ui->scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    stControlStringEx stCtlStr[20] =
    {
        {	stAdvanceVid[0],			m_editTab7VIDValue[0],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[1],			m_editTab7VIDValue[1],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[2],			m_editTab7VIDValue[2],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[3],			m_editTab7VIDValue[3],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[4],			m_editTab7VIDValue[4],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[5],			m_editTab7VIDValue[5],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[6],			m_editTab7VIDValue[6],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[7],			m_editTab7VIDValue[7],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[8],			m_editTab7VIDValue[8],		DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[9],			m_editTab7VIDValue[9],      DF_INTX,		DT_VID_VidSys,		DU_NULL},
        {	stAdvanceVid[10],			m_editTab7PIDPara[0],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[11],			m_editTab7PIDPara[1],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[12],			m_editTab7PIDPara[2],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[13],			m_editTab7PIDPara[3],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[14],			m_editTab7PIDPara[4],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[15],			m_editTab7PIDPara[5],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[16],			m_editTab7PIDPara[6],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[17],			m_editTab7PIDPara[7],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[18],			m_editTab7PIDPara[8],		DF_INTX,		DT_PID_PidSys,		DU_NULL},
        {	stAdvanceVid[19],			m_editTab7PIDPara[9],       DF_INTX,		DT_PID_PidSys,		DU_NULL},
    };
    for (int i = 0 ; i < TAB7_SET_NUMBER*2 ; i++)
    {
        g_stCtlStr[i] = stCtlStr[i];
    }
    m_bisFrush = false;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);
}

advancedParaTab::~advancedParaTab()
{
    timer->deleteLater();
    delete ui;
}

void advancedParaTab::setInit()
{
    for (int i = 0 ; i < TAB7_SET_NUMBER*2 ; i++)
    {
        if (i<TAB7_SET_NUMBER)
        {
            g_editStr[i] = m_editTab7VID[i];
            g_editStr[i]->setText(QString::number(g_pCommunicate->m_nDebugVids[i]));
        }
        else
        {
            g_editStr[i] = m_editTab7PID[i-TAB7_SET_NUMBER];
            g_editStr[i]->setText(QString::number(g_pCommunicate->m_nDebugPids[i - TAB7_SET_NUMBER]));
        }
    }

    m_bisFrush = true;
}

bool advancedParaTab::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        for (int i=0; i<sizeof(g_stCtlStr)/sizeof(g_stCtlStr[0]); i++)// 数据
        {
            if (obj == g_stCtlStr[i].idLineEdit)
            {
                if (!g_stCtlStr[i].idLineEdit->isEnabled())
                {
                    break;
                }
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    if (g_pCommunicate->m_nProtected >= 1)
                    {
                        ModifyPara *pDlg = new ModifyPara(this);
                        if (g_stCtlStr[i].idType == DT_VID_VidSys)
                        {
                            pDlg->SetSigId(g_stCtlStr[i].idDB);
                        }
                        else
                        {
                            pDlg->SetSigId(PID_TO_VID(g_stCtlStr[i].idDB));
                        }
                        pDlg->OnInit();
                        pDlg->exec();
                        delete pDlg;
                    }
                }
            }
        }

        for (int i=0; i<sizeof(g_editStr)/sizeof(g_editStr[0]); i++)// ID
        {
            if (obj == g_editStr[i])
            {
                if (!g_editStr[i]->isEnabled())
                {
                    break;
                }
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    if (g_pCommunicate->m_nProtected >= 1)
                    {
                        QString sBuffer = g_editStr[i]->text();
                        int nData = 0;
                        nData = sBuffer.toInt();

                        ModifyPara *pDlg = new ModifyPara(this);
                        pDlg->SetDataPoint(&nData);
                        pDlg->OnInit();
                        pDlg->exec();
                        delete pDlg;

                        sBuffer = QString::number(nData);
                        if (!sBuffer.isEmpty())
                        {
                            g_editStr[i]->setText(sBuffer);
                            if (i >= 10)
                            {
                                g_pCommunicate->m_nDebugPids[i-10] = sBuffer.toInt();
                            }
                            else if (i >= 0)
                            {
                                g_pCommunicate->m_nDebugVids[i] = sBuffer.toInt();
                            }
                        }
                    }
                }
            }
        }
    }
    return QWidget::eventFilter(obj,e);
}

void advancedParaTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 3)
    {
        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_stCtlStr)/sizeof(g_stCtlStr[0]); i++)
        {
            QString str1 = g_editStr[i]->text();
            QString str ;//= QString::number(stAdvanceVid[i]);
            if (i >= 10)
            {
                str = QString::number(g_pCommunicate->m_nDebugPids[i-10]);
                if (str != str1)
                {
                    g_pCommunicate->m_nDebugPids[i-10] = str1.toInt();
                    qDebug()<<"DebugPids "<<str1;
                }
                g_stCtlStr[i].idDB = g_pCommunicate->m_nDebugPids[i-10];
            }
            else if (i >= 0)
            {
                str = QString::number(g_pCommunicate->m_nDebugVids[i]);
                if (str != str1)
                {
                    g_pCommunicate->m_nDebugVids[i] = str1.toInt();
                }
                g_stCtlStr[i].idDB = g_pCommunicate->m_nDebugVids[i];
            }
            /*if (str != str1)
            {
                stAdvanceVid[i] = str1.toInt();
                qDebug()<<"VPID="<<i<<stAdvanceVid[i]<<str1;
            }
            g_stCtlStr[i].idDB = stAdvanceVid[i];*/
        }

        for (int i=0; i<sizeof(g_stCtlStr)/sizeof(g_stCtlStr[0]); i++)
        {
            sCtlEx = g_stCtlStr[i];
            if (sCtlEx.idLineEdit == NULL)
            {
                continue;
            }
            QString strData = g_pCommunicate->GetDataString(sCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);

            strData = strData + strUnit;
            //qDebug()<<"GetDataVIDandPID "<<strData;
            QString strOldData = sCtlEx.idLineEdit->text();
            if (strData != strOldData)
            {
                sCtlEx.idLineEdit->setText(strData);
            }
        }
        itimeData = 0;
    }
}
