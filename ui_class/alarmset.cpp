//告警参数设置-对话框
#include "alarmset.h"
#include "ui_alarmset.h"

AlarmSet::AlarmSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmSet)
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

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(ALM_MAX_NUM + 1);
    gridLayout->setMargin(ALM_PARA_MAX_NUM +3);

    gridLayout->addWidget(ui->label_3 , 0 , 2);
    gridLayout->addWidget(ui->label_4 , 0 , 3);
    gridLayout->addWidget(ui->label_5 , 0 , 4);
    gridLayout->addWidget(ui->label_6 , 0 , 5);
    gridLayout->addWidget(ui->label_2 , 0 , 6);
    gridLayout->addWidget(ui->label_10 , 0 , 7);
    gridLayout->addWidget(ui->label_7 , 0 , 8);
    gridLayout->addWidget(ui->label_8 , 0 , 9);
    gridLayout->addWidget(ui->label_9 , 0 , 10);
    gridLayout->addWidget(ui->label , 0 , 11);

    gridLayout->addWidget(ui->label_11 , 1 , 0);
    gridLayout->addWidget(ui->label_12 , 2 , 0);
    gridLayout->addWidget(ui->label_13 , 3 , 0);
    gridLayout->addWidget(ui->label_14 , 4 , 0);
    gridLayout->addWidget(ui->label_15 , 5 , 0);
    gridLayout->addWidget(ui->label_16 , 6 , 0);
    gridLayout->addWidget(ui->label_17 , 7 , 0);
    gridLayout->addWidget(ui->label_18 , 8 , 0);
    gridLayout->addWidget(ui->label_19 , 9 , 0);
    gridLayout->addWidget(ui->label_20 , 10 , 0);
    gridLayout->addWidget(ui->label_21 , 11 , 0);
    gridLayout->addWidget(ui->label_22 , 12 , 0);
    gridLayout->addWidget(ui->label_23 , 13 , 0);
    gridLayout->addWidget(ui->label_24 , 14 , 0);
    gridLayout->addWidget(ui->label_25 , 15 , 0);
    gridLayout->addWidget(ui->label_26 , 16 , 0);
    gridLayout->addWidget(ui->label_27 , 17 , 0);
    gridLayout->addWidget(ui->label_28 , 18, 0);
    gridLayout->addWidget(ui->label_29 , 19 , 0);
    gridLayout->addWidget(ui->label_30 , 20 , 0);
    gridLayout->addWidget(ui->label_31 , 21 , 0);
    gridLayout->addWidget(ui->label_32 , 22 , 0);
    gridLayout->addWidget(ui->label_33 , 23 , 0);
    gridLayout->addWidget(ui->label_34 , 24 , 0);
    gridLayout->addWidget(ui->label_35 , 25 , 0);
    gridLayout->addWidget(ui->label_57 , 26 , 0);
    gridLayout->addWidget(ui->label_61 , 27 , 0);
    gridLayout->addWidget(ui->label_60 , 28 , 0);
    gridLayout->addWidget(ui->label_56 , 29 , 0);
    gridLayout->addWidget(ui->label_59 , 30 , 0);
    gridLayout->addWidget(ui->label_58 , 31 , 0);
    gridLayout->addWidget(ui->label_62 , 32 , 0);

    for (int i = 0 ; i < ALM_MAX_NUM ; i++)
    {
        //if (i >=ALM_RESERVED25)
        //{
        //	break;
        //}
        m_AlarmPicLabel[0][i] = new QLabel(this);
        m_AlarmPicLabel[0][i]->setPixmap(QPixmap("res/unable.ico"));
        m_AlarmPicLabel[0][i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        m_AlarmPicLabel[1][i] = new QLabel(this);
        m_AlarmPicLabel[1][i]->setPixmap(QPixmap("res/yes.ico"));
        m_AlarmPicLabel[1][i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        gridLayout->addWidget(m_AlarmPicLabel[0][i]  , i+1 , 1);
        gridLayout->addWidget(m_AlarmPicLabel[1][i]  , i+1 , 12);
        for (int j = 0 ; j < ALM_PARA_MAX_NUM ; j++)
        {
            m_AlarmEdit[i][j] = new QLineEdit();
            m_AlarmEdit[i][j]->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
            stCtlStr[ALM_PARA_MAX_NUM * i + j].idDB = 	PID_MAKE_ALM_PID(ALM_CELL_OV + i , ALM_PARA_LEVEL1 + j);
            stCtlStr[ALM_PARA_MAX_NUM * i + j].idLineEdit = m_AlarmEdit[i][j];
            gridLayout->addWidget(m_AlarmEdit[i][j]  , i+1 , j+2);
        }
    }
    gridLayout->setSpacing(0);
    //gridLayout->setMargin(0);
    //gridLayout->setContentsMargins(0,0,0,0);
    ui->groupBox->setLayout(gridLayout);

    QWidget* scrollAreaWidgetContents = new QWidget();
    //scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 251));
    scrollAreaWidgetContents->setLayout(ui->horizontalLayout);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    //ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //ui->scrollArea->setBackgroundRole(QPalette::Dark);// 设置滚动区域的背景
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowMaximizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    ui->label_48->setPixmap(QPixmap("res/protected.ico"));
    ui->label_50->setPixmap(QPixmap("res/able.ico"));
    ui->label_52->setPixmap(QPixmap("res/unable.ico"));
    ui->label_54->setPixmap(QPixmap("res/yes.ico"));
    ui->label_55->setPixmap(QPixmap("res/no.ico"));

    m_nTimerID = startTimer(150);//新建定时器
}

AlarmSet::~AlarmSet()
{
    killTimer(m_nTimerID);
    delete ui;
}

bool AlarmSet::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        //for (int i=0; i<sizeof(stCtlStr)/sizeof(stCtlStr[0]); i++)
        for (int i=0 ;  i<ALM_MAX_NUM ; i++)
        {
            for (int j = 0 ; j < ALM_PARA_MAX_NUM ; j ++)
            {
                if (obj == stCtlStr[i * ALM_PARA_MAX_NUM + j].idLineEdit)
                {
                    if (! stCtlStr[i * ALM_PARA_MAX_NUM + j].idLineEdit->isEnabled())
                    {
                        break;
                    }
                    QMouseEvent *me = (QMouseEvent*)e;
                    if(me->button() == Qt::LeftButton)
                    {
                        if (g_pCommunicate->m_nProtected >= 1)
                        {
                            ModifyPara *pDlg = new ModifyPara(this);
                            pDlg->SetSigId(PID_TO_VID(stCtlStr[i * ALM_PARA_MAX_NUM + j].idDB));
                            pDlg->OnInit();
                            pDlg->exec();
                            delete pDlg;
                            //emit sigClicked();
                        }
                    }
                    break;
                }
            }
        }
    }
    return QWidget::eventFilter(obj,e);
}

void AlarmSet::timerEvent(QTimerEvent *)
{
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 6)
    {
        for (int i=0 ;  i<ALM_MAX_NUM ; i++)
        {
            ShowAlmAble(PID_MAKE_ALM_PID(i, ALM_PARA_DIS_LEVEL), PID_MAKE_ALM_PID(i, ALM_PARA_RELAY1), i);
            for (int j = 0 ; j < ALM_PARA_MAX_NUM ; j ++)
            {
                QString strData ;
                UINT16 pid	= stCtlStr[i * ALM_PARA_MAX_NUM + j].idDB - PID_SYS_SIZE - PID_BSU_TOTAL_SIZE;
                UINT16 uiBsu, uiOffset;
                if (pid < PID_ALM_TOTAL_SIZE)
                {
                    uiBsu = pid / PID_ALM_SIZE;
                    uiOffset = pid % PID_ALM_SIZE;
                    strData = QString::number(((short)g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidAlarm.m_usBmsPidAlarm[uiBsu][uiOffset]));
                }
                QString strOldData = stCtlStr[i * ALM_PARA_MAX_NUM + j].idLineEdit->text();
                if (strData != strOldData)
                {
                    stCtlStr[i * ALM_PARA_MAX_NUM + j].idLineEdit->setText(strData);
                }
            }
        }
        itimeData = 0;
    }
}

void AlarmSet::ShowAlmAble(int nDis, int nCut, int nCtl)
{
    UINT16 pid	= nDis - PID_SYS_SIZE - PID_BSU_TOTAL_SIZE;
    UINT16 uiBsu, uiOffset ,sidata;
    if (pid < PID_ALM_TOTAL_SIZE)
    {
        uiBsu = pid / PID_ALM_SIZE;
        uiOffset = pid % PID_ALM_SIZE;
        sidata = g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidAlarm.m_usBmsPidAlarm[uiBsu][uiOffset];
    }
    if (sidata == 0 )
    {
        m_AlarmPicLabel[0][nCtl]->setPixmap(QPixmap("res/unable.ico"));
    }
    else
    {
        pid	= nCut - PID_SYS_SIZE - PID_BSU_TOTAL_SIZE;
        if (pid < PID_ALM_TOTAL_SIZE)
        {
            uiBsu = pid / PID_ALM_SIZE;
            uiOffset = pid % PID_ALM_SIZE;
            sidata = g_pCommunicate->m_tagCanBMS.m_tagBmsPid.m_tagBmsPidAlarm.m_usBmsPidAlarm[uiBsu][uiOffset];
        }
        if (sidata == 0 )
        {
            m_AlarmPicLabel[0][nCtl]->setPixmap(QPixmap("res/able.ico"));
        }
        else
        {
            m_AlarmPicLabel[0][nCtl]->setPixmap(QPixmap("res/protected.ico"));
        }
    }
}
