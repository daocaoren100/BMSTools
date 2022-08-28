//主页-标签
#include "generaltab.h"
#include "ui_generaltab.h"

generalTab::generalTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::generalTab)
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
    scrollAreaWidgetContents->setLayout(ui->verticalLayout_4);
    ui->scrollArea->setWidget(scrollAreaWidgetContents);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setBackgroundRole(QPalette::Base);
    ui->scrollArea->setFocusPolicy(Qt::NoFocus);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);

    QPalette pt;
    pt.setColor(QPalette::Text, Qt::red);
    ui->label_warn->setPalette(pt);

    m_analyzer = new EChartTest(this);
    m_analyzer->pwebview = this->ui->webView;
    QObject::connect(ui->webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(addJSObject()));  // Signal is emitted before frame loads any web content:

    ui->webView->load(QUrl::fromLocalFile(qApp->applicationDirPath() + "/echarts/index.html"));
    //ui.webView->load(QUrl("http://www.hao123.com")); //加载页面必须有“http://”开头

    m_test = 0;
    m_bisFrush = false;

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);
}

generalTab::~generalTab()
{
    timer->deleteLater();
    delete ui;
}

void generalTab::addJSObject()
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject(QString("echarttest"), m_analyzer);
}

void generalTab::setInit()
{
    m_bisFrush = true;
}

void generalTab::refTimeout()
{
    if (!m_bisFrush)
    {
        return;
    }
    static QString total[7];
    static int itimeData = 0;
    itimeData++;
    if (itimeData == 1)
    {
        static INT16 sysvolt;
        INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_VOLT];
        if (sysvolt == gressvalue)
        {
            return;
        }
        sysvolt = gressvalue;
        QString strVal = QString("callfromqtone(\"%1\");").arg(QString::number(((float)gressvalue)/10));
        ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
    }
    else if (itimeData == 2)
    {
        static INT16 syscurr;
        INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_CURR];
        if (syscurr == gressvalue)
        {
            return;
        }
        syscurr = gressvalue;
        QString strVal = QString("callfromqttwo(\"%1\");").arg(QString::number(((float)gressvalue)/10));
        ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
    }
    else if (itimeData == 3)
    {
        static INT16 syssoc;
        INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_SOC];
        if (syssoc == gressvalue)
        {
            return;
        }
        syssoc = gressvalue;
        QString strVal = QString("callfromqtthree(\"%1\");").arg(QString::number(((float)gressvalue)/10));
        ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
    }
    else if (itimeData == 4)
    {
        static INT16 systemp;
        INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_TEMP];
        if (systemp == gressvalue)
        {
            return;
        }
        systemp = gressvalue;
        QString strVal = QString("callfromqtfour(\"%1\");").arg(QString::number(((float)gressvalue)/10));
        ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
    }
    else if (itimeData == 5)
    {
        static INT16 sysmaxv;
        static INT16 sysminv;
        static QString strsysv;
        //INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_MAX_VOLT];
        //INT16 gressvalue1 = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_MIN_VOLT];
        INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_nMaxCell;
        INT16 gressvalue1 = g_pCommunicate->m_tagCanBMS.m_nMinCell;

        QString strVal = QString("callfromqtfive(\"%1\",\"%2\"").arg(QString::number(((float)gressvalue))).arg(QString::number(((float)gressvalue1)));
        //QString strVc = QString::number(gressvalue - gressvalue1);
        QString strVc = QString::number(g_pCommunicate->m_tagCanBMS.m_nCellDiff);
        strVc = QString_C(",\"最大压差:") + strVc;
        strVc = strVc + "mV\"";
        //strVc = strVc + QString_C(",\"最高电压:") + total[1] + "  No." + total[2] ;//+ "\"";
        //strVc = strVc + QString_C("\\n最低电压:") + total[3] + "  No." + total[4] +"\"";
        strVc = strVc + QString_C(",\"最高电压:") + QString("BSU%1 CELL%2").arg(g_pCommunicate->m_tagCanBMS.m_unMaxVPosi.stBit.uiBsuNo + 1).arg(g_pCommunicate->m_tagCanBMS.m_unMaxVPosi.stBit.uiCellNo + 1) + "  No." + total[2] ;//+ "\"";
        strVc = strVc + QString_C("\\n最低电压:") + QString("BSU%1 CELL%2").arg(g_pCommunicate->m_tagCanBMS.m_unMinVPosi.stBit.uiBsuNo + 1).arg(g_pCommunicate->m_tagCanBMS.m_unMinVPosi.stBit.uiCellNo + 1) + "  No." + total[4] +"\"";
        strVc = strVc + ");";
        strVal = strVal + strVc;
        if ((sysmaxv == gressvalue) && (sysminv == gressvalue1) && (strsysv == strVal))
        {
            return;
        }
        sysmaxv = gressvalue;
        sysminv = gressvalue1;
        strsysv = strVal;
        ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
    }
    else if (itimeData == 6)
    {
        static INT16 systmaxv;
        static INT16 systminv;
        static QString strsyst;
        //INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_MAX_TEMP];
        //INT16 gressvalue1 = g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_MIN_TEMP];
        INT16 gressvalue = g_pCommunicate->m_tagCanBMS.m_nMaxTemp;
        INT16 gressvalue1 = g_pCommunicate->m_tagCanBMS.m_nMinTemp;

        QString strVal = QString("callfromqtsix(\"%1\",\"%2\"").arg(QString::number(((float)gressvalue)/10)).arg(QString::number(((float)gressvalue1)/10));
        //QString strVc = QString::number(((float)(gressvalue - gressvalue1))/10);
        QString strVc = QString::number(((float)(g_pCommunicate->m_tagCanBMS.m_nTempDiff))/10);
        strVc = QString_C(",\"最大温差:") + strVc;
        strVc = strVc + QString_C("℃\"");
        //strVc = strVc + QString_C(",\"最高温度:") + total[5];// + "\"";
        //strVc = strVc + QString_C("  最低温度:") + total[6] + "\"";
        strVc = strVc + QString_C(",\"最高温度:") + QString("BSU%1 CELL%2").arg(g_pCommunicate->m_tagCanBMS.m_unMaxTPosi.stBit.uiBsuNo + 1).arg(g_pCommunicate->m_tagCanBMS.m_unMaxTPosi.stBit.uiCellNo + 1);// + "\"";
        strVc = strVc + QString_C("  最低温度:") + QString("BSU%1 CELL%2").arg(g_pCommunicate->m_tagCanBMS.m_unMinTPosi.stBit.uiBsuNo + 1).arg(g_pCommunicate->m_tagCanBMS.m_unMinTPosi.stBit.uiCellNo + 1) + "\"";
        strVc = strVc + ");";
        strVal = strVal + strVc;
        if ((systmaxv == gressvalue) && (systminv == gressvalue1) && (strsyst == strVal))
        {
            return;
        }
        systmaxv = gressvalue;
        systminv = gressvalue1;
        strsyst = strVal;
        ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
    }
    else if (itimeData == 7)
    {
        static int nWarnIndex = 0;
        nWarnIndex++;
        if (nWarnIndex == 5)
        {
            nWarnIndex = 0;

            QString m_scrollWarn = QString_C("");
            static UINT16 nAlmIndex = 0;
            UINT16 nAlmSize = g_pCommunicate->ALM_GetActvAlmNum();
            if (nAlmIndex >= nAlmSize)
            {
                nAlmIndex = 0;
            }
            pActAlm = g_pCommunicate->ALM_GetActvAlarm(nAlmIndex);
            if (pActAlm == NULL)
            {
                m_scrollWarn = QString_C("无告警");
            }
            else
            {
                if (pActAlm->uiAlarmCode == 0)
                {
                    m_scrollWarn = QString_C("无告警");
                }
                else
                {
                    m_scrollWarn = g_pCommunicate->ALM_GetAlarmFullName(pActAlm->uiAlarmCode);
                }
            }
            nAlmIndex++;
            ui->label_warn->setText(m_scrollWarn);
        }
    }
    else if (itimeData == 8)
    {
        if (g_pCommunicate->m_nBmuOnLine == 0)
        {
            ui->label_7->setText(QString_C("无主控器模式"));   //主控器模式
        }
        else
        {
            ui->label_7->setText(QString_C(""));   //主控器模式
        }

        stControlStringEx g_sCtl_Bat_Total[7] =
        {
            {	VID_SYS_BAT_STATE,                          NULL,	DF_STATE,		DT_VID_VidSys,		DU_NULL},
            {	VID_SYS_MAXV_POSI,                          NULL,	DF_INTX,		DT_VID_VidSys,		DU_POSI},
            {	VID_MAKE_BAT_VID(0, VID_BAT_VMAX01_NO),		NULL,	DF_INTX,		DT_VID_VidBsuBat,	DU_NULL},
            {	VID_SYS_MINV_POSI,                          NULL,	DF_INTX,		DT_VID_VidSys,		DU_POSI},
            {	VID_MAKE_BAT_VID(0, VID_BAT_VMIN01_NO),		NULL,	DF_INTX,		DT_VID_VidBsuBat,	DU_NULL},
            {	VID_SYS_MAXT_POSI,                          NULL,	DF_INTX,		DT_VID_VidSys,		DU_POSI},
            {	VID_SYS_MINT_POSI,                          NULL,	DF_INTX,		DT_VID_VidSys,		DU_POSI},
        };
        stControlStringEx sCtlEx;
        for (int i=0; i<sizeof(g_sCtl_Bat_Total)/sizeof(g_sCtl_Bat_Total[0]); i++)
        {
            sCtlEx = g_sCtl_Bat_Total[i];
            QString strData = g_pCommunicate->GetDataString(sCtlEx);
            QString strUnit = g_pCommunicate->GetDataUnit(sCtlEx);
            if ((i==1) || (i==3) || (i==5) || (i==6))
            {
                strData = strUnit;
            }
            else
            {
                strData = strData + strUnit;
            }
            QString strOldData;
            if (i ==0)
            {
                strOldData = ui->label_6->text();
            }
            else
            {
                strOldData = total[i];
            }
            if (strData != strOldData)
            {
                if (i == 0)
                {
                    ui->label_6->setText(strData);
                    if ((g_pCommunicate->DB_GetSysData(VID_SYS_BAT_STATE) == 5))
                    {
                        QPalette palette;
                        palette.setColor(QPalette::WindowText  , QColor(0, 255, 0));
                        ui->label_6->setPalette(palette);
                    }
                    else if ((g_pCommunicate->DB_GetSysData(VID_SYS_BAT_STATE) == 3))
                    {
                        QPalette palette;
                        palette.setColor(QPalette::WindowText, QColor(11, 157, 60));
                        ui->label_6->setPalette(palette);
                    }
                    else
                    {
                        QPalette palette;
                        palette.setColor(QPalette::WindowText, QColor(255, 0, 0));
                        ui->label_6->setPalette(palette);
                    }
                    continue;
                }
                total[i] = strData;
            }
        }
        itimeData = 0;
    }
}
