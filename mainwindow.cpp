#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(QString_C("科列BMS调试软件 ") + SoftVer);

//    QDesktopWidget* desktopWidget = QApplication::desktop();
//    //获取可用桌面大小
//    QRect deskRect = desktopWidget->availableGeometry();
//    //获取设备屏幕大小
//    QRect screenRect = desktopWidget->screenGeometry();

//    m_alarmSuspend = new AlarmSuspendWidget();
//    m_alarmSuspend->move(screenRect.width() - 100, 100);
//    m_alarmSuspend->show();

#ifdef USE_LOCAL_FONT
    if(_USE_LOCAL_FONT == TRUE)
    {
        QString localFontString = loadFontFamilyFromTTF();
        QFont localFont;
        localFont.setFamily(localFontString);
        setFont(localFont);
    }
#endif

    //状态栏
    m_pstatusBarWidget = new QWidget();
    statusBarLayout = new QHBoxLayout(m_pstatusBarWidget);
    m_pgprsStatus = new QLabel();
    m_pStatusIMEI = new QLabel();
    m_pStatusCCID = new QLabel();
    m_pversionsStatus = new QLabel();
    m_pcanStatus = new QLabel();
    m_ptimesStatus = new QLabel();

    statusBarLayout->addWidget(m_pgprsStatus);
    statusBarLayout->addWidget(m_pStatusIMEI);
    statusBarLayout->addWidget(m_pStatusCCID);
    statusBarLayout->addWidget(m_pversionsStatus);
    statusBarLayout->addWidget(m_pcanStatus);
    statusBarLayout->addWidget(m_ptimesStatus);
    statusBarLayout->setMargin(0);  //设置边距
    statusBarLayout->setSpacing(3); //设置间距
    ui->statusBar->addWidget(m_pstatusBarWidget,1);
    ui->statusBar->setFixedHeight(28);
    ui->statusBar->setSizeGripEnabled(false);   //状态栏右下角按钮
    //添加边框
    m_pgprsStatus->setFrameShape (QFrame::Box);
    m_pStatusIMEI->setFrameShape (QFrame::Box);
    m_pStatusCCID->setFrameShape (QFrame::Box);
    m_pversionsStatus->setFrameShape (QFrame::Box);
    m_pcanStatus->setFrameShape (QFrame::Box);
    m_ptimesStatus->setFrameShape (QFrame::Box);

    m_ptimesStatus->setFixedWidth(100);

    m_iCurrentBMU = 0;

    m_bIsBsu = false;

    LoadVariables();
    //g_pCommunicate->UserGetCanReceive(this->gettagCanReceive , this);

    m_bIsCanOpen = false;

    ui->widget_sider->setInit();
    //ui.widget_2->setInit();
    ui->tabWidget_BMS->setInit();

    connect(ui->treeWidget, SIGNAL(sigSetCurrentBMU(int , int ,int)), this, SLOT(slotSetCurrentBMU(int , int , int)));
    //connect(this , SIGNAL(sigItemWeight(int , QVector<QString>)), ui.widget_3 , SLOT(slotItemWeight(int , QVector<QString>)));
    //connect(ui.widget_2, SIGNAL(sigShowCanData(bool)), this, SLOT(slotShowCanData(bool)));

    g_pCommunicate->m_enCurrPage = DW_BMU_BAT_TOTAL;

    ui->action_AutoSave->setCheckable(true);//开启“自动保存数据帧”钩选功能

    QTimer::singleShot(200, this, SLOT(open_login_timer()));//只触发一次定时间，延时200ms，用于打开登录界面
    m_nTimerID = startTimer(100);//新建定时器
}

MainWindow::~MainWindow()
{
    SaveVariables();
    g_pCommunicate->ClearCommunicate();
    killTimer(m_nTimerID);
    m_alarmSuspend->close();
    m_alarmSuspend->deleteLater();
    delete ui;
}

void MainWindow::LoadVariables()//加载变量
{
    QString str;
    DB_VALUE_T tData;
    QSettings setting("set/setting.ini", QSettings::IniFormat);
    str = setting.value("Setting/CAN-Device").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_eDev = (enIKCDevs)(str.toUInt());
    }
    else
    {
        str = QString::number(g_pCommunicate->m_eDev);
        setting.setValue("Setting/CAN-Device", str);
    }
    str = setting.value("Setting/CAN-Index").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nInd = (UINT32)(str.toUInt());
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nInd);
        setting.setValue("Setting/CAN-Index", str);
    }
    str = setting.value("Setting/CAN-Channel").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_eCan = (enIKCChannel)(str.toUInt());
    }
    else
    {
        str = QString::number(g_pCommunicate->m_eCan);
        setting.setValue("Setting/CAN-Channel", str);
    }
    str = setting.value("Setting/CAN-Rate").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_eBtr = (enIKCBtr)(str.toUInt());
    }
    else
    {
        str = QString::number(g_pCommunicate->m_eBtr);
        setting.setValue("Setting/CAN-Rate", str);
    }

    //////
    str = setting.value("Setting/Bat-Number").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nBatNum = str.toUInt();
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nBatNum);
        setting.setValue("Setting/Bat-Number", str);
    }
    tData.uiData = g_pCommunicate->m_nBatNum;
    g_pCommunicate->PARA_SetSys(PID_SYS_BAT_NUM, &tData);

    str = setting.value("Setting/BSU-Number").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nBsuNum = str.toUInt();
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nBsuNum);
        setting.setValue("Setting/BSU-Number", str);
    }
    tData.uiData = g_pCommunicate->m_nBsuNum;
    g_pCommunicate->PARA_SetSys(PID_SYS_BSU_NUM, &tData);

    str = setting.value("Setting/BSU-Type").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nBsuType = str.toUInt();
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nBsuType);
        setting.setValue("Setting/BSU-Type", str);
    }
    tData.uiData = g_pCommunicate->m_nBsuType;
    g_pCommunicate->PARA_SetSys(PID_SYS_BSU_TYPE, &tData);

    for (int i=0; i<BSU_MAX_NUM; i++)
    {
        QString strname = "Setting/BSUC" + QString::number(i);
        str = setting.value(strname).toString();
        if (!str.isEmpty())
        {
            g_pCommunicate->m_nCellPos[i] = str.toUInt();
        }
        else
        {
            str = QString::number(g_pCommunicate->m_nCellPos[i]);
            setting.setValue(strname, str);
        }
        tData.uiData = g_pCommunicate->m_nCellPos[i];
        g_pCommunicate->PARA_SetBsu(i, PID_BSU_CELL_NUM, &tData);

        strname = "Setting/BSUT" + QString::number(i);
        str = setting.value(strname).toString();
        if (!str.isEmpty())
        {
            g_pCommunicate->m_nTempPos[i] = str.toUInt();
        }
        else
        {
            str = QString::number(g_pCommunicate->m_nTempPos[i]);
            setting.setValue(strname, str);
        }
        tData.uiData = g_pCommunicate->m_nTempPos[i];
        g_pCommunicate->PARA_SetBsu(i, PID_BSU_TEMP_NUM, &tData);
    }

    /////////////
    str = setting.value("Setting/Cell-Number").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nCellNum = str.toUInt();
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nCellNum);
        setting.setValue("Setting/Cell-Number", str);
    }

    str = setting.value("Setting/Temp-Number").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nTempNum = str.toUInt();
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nTempNum);
        setting.setValue("Setting/Temp-Number", str);
    }

    str = setting.value("Setting/BMU-OnLine").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nBmuOnLine = str.toUInt();
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nBmuOnLine);
        setting.setValue("Setting/BMU-OnLine", str);
    }

    // 调试通道配置
    for (int i=0; i<10; i++)
    {
        QString strname = "Setting/AVID" + QString::number(i);
        str = setting.value(strname).toString();
        if (!str.isEmpty())
        {
            g_pCommunicate->m_nDebugVids[i] = str.toUInt();
        }
        else
        {
            str = QString::number(g_pCommunicate->m_nDebugVids[i]);
            setting.setValue(strname, str);
        }

        strname = "Setting/APID" + QString::number(i);
        str = setting.value(strname).toString();
        if (!str.isEmpty())
        {
            g_pCommunicate->m_nDebugPids[i] = str.toUInt();
        }
        else
        {
            str = QString::number(g_pCommunicate->m_nDebugPids[i]);
            setting.setValue(strname, str);
        }
    }

    // log
    //m_nLogInter
    str = setting.value("Setting/Log-Interval").toString();
    if (!str.isEmpty())
    {
        g_pCommunicate->m_nLogInter = str.toUInt();
    }
    else
    {
        str = QString::number(g_pCommunicate->m_nLogInter);
        setting.setValue("Setting/Log-Interval", str);
    }
}

void MainWindow::SaveVariables()//保存变量
{
    QString str;
    QSettings setting("set/setting.ini", QSettings::IniFormat);
        // CAN配置信息
    str = QString::number(g_pCommunicate->m_eDev);
    setting.setValue("Setting/CAN-Device", str);
    str = QString::number(g_pCommunicate->m_nInd);
    setting.setValue("Setting/CAN-Index", str);
    str = QString::number(g_pCommunicate->m_eCan);
    setting.setValue("Setting/CAN-Channel", str);
    str = QString::number(g_pCommunicate->m_eBtr);
    setting.setValue("Setting/CAN-Rate", str);

    // 采集配置信息
        str = QString::number(g_pCommunicate->m_nBatNum);
        setting.setValue("Setting/Bat-Number", str);
        str = QString::number(g_pCommunicate->m_nBsuNum);
        setting.setValue("Setting/BSU-Number", str);
        str = QString::number(g_pCommunicate->m_nBsuType);
        setting.setValue("Setting/BSU-Type", str);

    for (int i=0; i<BSU_MAX_NUM; i++)
    {
        QString strname = "Setting/BSUC" + QString::number(i);
        str = QString::number(g_pCommunicate->m_nCellPos[i]);
        setting.setValue(strname, str);

        strname = "Setting/BSUT" + QString::number(i);
        str = QString::number(g_pCommunicate->m_nTempPos[i]);
        setting.setValue(strname, str);
    }
        str = QString::number(g_pCommunicate->m_nCellNum);
        setting.setValue("Setting/Cell-Number", str);
        str = QString::number(g_pCommunicate->m_nTempNum);
        setting.setValue("Setting/Temp-Number", str);
        str = QString::number(g_pCommunicate->m_nBmuOnLine);
        setting.setValue("Setting/BMU-OnLine", str);
    // 调试通道配置
    for (int i=0; i<10; i++)
    {
        QString strname = "Setting/AVID" + QString::number(i);
        str = QString::number(g_pCommunicate->m_nDebugVids[i]);
        setting.setValue(strname, str);
        strname = "Setting/APID" + QString::number(i);
        str = QString::number(g_pCommunicate->m_nDebugPids[i]);
        setting.setValue(strname, str);
    }
    //m_nLogInter
        str = QString::number(g_pCommunicate->m_nLogInter);
        setting.setValue("Setting/Log-Interval", str);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("是否确定退出?"),QMessageBox::Yes|QMessageBox::No,this);
    if(msgBox.exec()==QMessageBox::Yes)
    {
        m_alarmSuspend->close();
        m_alarmSuspend->deleteLater();
        event->accept();          //接受退出信号，程序退出
    }
    else
    {
        event->ignore();			//忽略退出信号，程序继续运行
    }
}

void MainWindow::open_login_timer()
{
    on_action_OpenCAN_triggered();

    //显示告警悬浮控件
    QDesktopWidget* desktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = desktopWidget->availableGeometry();
    //获取设备屏幕大小
    QRect screenRect = desktopWidget->screenGeometry();

    m_alarmSuspend = new AlarmSuspendWidget();
    m_alarmSuspend->move(screenRect.width() - 256, 100);
    m_alarmSuspend->show();

    //关联告警悬浮控件
    connect(this, SIGNAL(sigSetAlarm(QStringList, UINT)), m_alarmSuspend, SLOT(soltSetAlarm(QStringList, UINT)));
    connect(this, SIGNAL(sigClearAlarm(UINT)), m_alarmSuspend, SLOT(soltClearAlarm(UINT)));
}

void MainWindow::timerEvent(QTimerEvent *)
{
    static int iOtherMessagetime = 0;
    iOtherMessagetime ++ ;
    if (iOtherMessagetime == 10)
    {
        if (m_bIsCanOpen)
        {
            //g_pCommunicate->TestCanActive();   //CAN通讯断开则自动重连
            g_pCommunicate->m_bCanActive = true;   //CAN通讯断开则自动重连
        }

        iOtherMessagetime = 0;
        QDateTime dt;
        dt = QDateTime::currentDateTime();
        QString strtime = QString("%1:%2:%3").arg
            (dt.time().hour() , 2 , 10).arg
            (dt.time().minute() , 2 , 10).arg
            (dt.time().second() , 2 , 10);
        m_ptimesStatus->setText(strtime);

        QString str = "";
        if (!g_pCommunicate->m_bIsConnectState)
        {
            str ="CAN:OFF    RxNum:0    TxNum:0";
            m_pcanStatus->setText(str);
            g_pCommunicate->m_bIsConnectState_bak = g_pCommunicate->m_bIsConnectState;
        }
        else
        {
            if(!g_pCommunicate->m_bIsConnectState_bak)
            {
                ST_CAN_FRAME stFrame;
                g_pCommunicate->SelectPidVIPData(&stFrame);//请求获取一次系统重要参数
                g_pCommunicate->WriteData(&stFrame);
            }
            str = "CAN:ON    RxNum:" + QString::number(g_pCommunicate->GetRxQueueSize())
                + "    TxNum:" + QString::number(g_pCommunicate->GetTxQueueSize());
            m_pcanStatus->setText(str);
            g_pCommunicate->m_bIsConnectState_bak = g_pCommunicate->m_bIsConnectState;
        }

        if (g_pCommunicate->DB_GetUint16(VID_GPRS_RECV_OK_NUM) == 0)
        {
            str = QString("%1  %2  %3  %4").arg("GPRS:OFF").arg
                (g_pCommunicate->DB_GetUint16(VID_GPRS_SIG_STRENGTH)).arg
                (g_pCommunicate->DB_GetUint16(VID_GPRS_CONNECT_STEP)).arg
                (g_pCommunicate->DB_GetUint16(VID_GPRS_RECV_OK_NUM));
        }
        else
        {
            str = QString("%1  %2  %3  %4").arg("GPRS:ON").arg
                (g_pCommunicate->DB_GetUint16(VID_GPRS_SIG_STRENGTH)).arg
                (g_pCommunicate->DB_GetUint16(VID_GPRS_CONNECT_STEP)).arg
                (g_pCommunicate->DB_GetUint16(VID_GPRS_RECV_OK_NUM));
        }
        m_pgprsStatus->setText(str);

        str = QString("%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15%16").arg
            (g_pCommunicate->m_sIMEI[0]).arg(g_pCommunicate->m_sIMEI[1]).arg
            (g_pCommunicate->m_sIMEI[2]).arg(g_pCommunicate->m_sIMEI[3]).arg
            (g_pCommunicate->m_sIMEI[4]).arg(g_pCommunicate->m_sIMEI[5]).arg
            (g_pCommunicate->m_sIMEI[6]).arg(g_pCommunicate->m_sIMEI[7]).arg
            (g_pCommunicate->m_sIMEI[8]).arg(g_pCommunicate->m_sIMEI[9]).arg
            (g_pCommunicate->m_sIMEI[10]).arg(g_pCommunicate->m_sIMEI[11]).arg
            (g_pCommunicate->m_sIMEI[12]).arg(g_pCommunicate->m_sIMEI[13]).arg
            (g_pCommunicate->m_sIMEI[14]).arg(g_pCommunicate->m_sIMEI[15]);
        m_pStatusIMEI->setText(str);

        str = QString("%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15%16%17%18%19%20").arg
            (g_pCommunicate->m_sCCID[0]).arg(g_pCommunicate->m_sCCID[1]).arg
            (g_pCommunicate->m_sCCID[2]).arg(g_pCommunicate->m_sCCID[3]).arg
            (g_pCommunicate->m_sCCID[4]).arg(g_pCommunicate->m_sCCID[5]).arg
            (g_pCommunicate->m_sCCID[6]).arg(g_pCommunicate->m_sCCID[7]).arg
            (g_pCommunicate->m_sCCID[8]).arg(g_pCommunicate->m_sCCID[9]).arg
            (g_pCommunicate->m_sCCID[10]).arg(g_pCommunicate->m_sCCID[11]).arg
            (g_pCommunicate->m_sCCID[12]).arg(g_pCommunicate->m_sCCID[13]).arg
            (g_pCommunicate->m_sCCID[14]).arg(g_pCommunicate->m_sCCID[15]).arg
            (g_pCommunicate->m_sCCID[16]).arg(g_pCommunicate->m_sCCID[17]).arg
            (g_pCommunicate->m_sCCID[18]).arg(g_pCommunicate->m_sCCID[19]);
        m_pStatusCCID->setText(str);

        str = QString("S:%1 %2 H:%3 %4 C:%5 L:%6 B:%7 A:%8 V:%9").arg
            (g_pCommunicate->DB_GetUint16(VID_SYS_SW_VER) , 4 , 10).arg
            (g_pCommunicate->DB_GetUint16(VID_SYS_SW_SUB_VER) , 2 , 10).arg
            (g_pCommunicate->DB_GetUint16(VID_SYS_HW_VER) , 4 , 10).arg
            (g_pCommunicate->DB_GetUint16(VID_SYS_BASE_BOARD_VER) , 2 , 10).arg
            (g_pCommunicate->PARA_GetUint16(PID_SYS_CFG_VER) , 4 , 10).arg
            (g_pCommunicate->DB_GetUint16(VID_SYS_LIB_VER) , 4 , 10).arg
            (g_pCommunicate->DB_GetUint16(VID_SYS_BOOT_VER) , 4 ,10).arg
            (g_pCommunicate->DB_GetUint16(VID_SYS_RESERVED2) , 4 ,10).arg//激活CPU版本
            (g_pCommunicate->DB_GetUint16(VID_SYS_RESERVED3) , 4 ,10);//高压CPU版本

        m_pversionsStatus->setText(str);

        if(m_alarmSuspend != NULL)
        {
            //告警悬浮窗显示
            QString m_scrollWarn = QString_C("");
            static UINT16 nAlmIndex = 0;
            UINT16 nAlmSize = g_pCommunicate->ALM_GetActvAlmNum();
            QStringList m_slAlarmList;
            if (nAlmSize == 0)
            {
                emit sigClearAlarm(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_SOC] / 10);
            }
            for(nAlmIndex = 0; nAlmIndex < nAlmSize; nAlmIndex++)
            {
                const ST_ACTV_ALARM *pActAlm = g_pCommunicate->ALM_GetActvAlarm(nAlmIndex);
                if (pActAlm == NULL)
                {
                    emit sigClearAlarm(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_SOC] / 10);
                }
                else
                {
                    if (pActAlm->uiAlarmCode == 0)
                    {
                        emit sigClearAlarm(g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_SOC] / 10);
                    }
                    else
                    {
                        m_scrollWarn = g_pCommunicate->ALM_GetAlarmFullName(pActAlm->uiAlarmCode);
                        m_slAlarmList << m_scrollWarn;
                        emit sigSetAlarm(m_slAlarmList, g_pCommunicate->m_tagCanBMS.m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[VID_SYS_SOC] / 10);
                    }
                }
            }
        }
    }
    g_pCommunicate->ProcessInfoWithoutBmu();
}

void MainWindow::gettagCanReceive(void *pWindow, tagCanUnitRealData tagCanReceive)
{
    MainWindow *view = (MainWindow *)pWindow;
    if (view == NULL)
    {
        return;
    }
    view->freshDlgSendReceive(tagCanReceive);
}

void MainWindow::freshDlgSendReceive(tagCanUnitRealData tagCanReceive)
{
    QString str = "null";
    QVector<QString> vecstr;
    str = QString::number (tagCanReceive.m_uBMUId , 16 );
    vecstr.push_back(str);
    BYTE bnum = tagCanReceive.m_uBMUId;
    bnum = bnum - 0xEF;
    str = "BMU" + QString::number (bnum , 10 );
    vecstr.push_back(str);
    if (tagCanReceive.m_bSendOrRece == 0)
    {
        str = QString_C("发送帧");
    }
    else if (tagCanReceive.m_bSendOrRece == 1)
    {
        str = QString_C("接收帧");
    }
    else if (tagCanReceive.m_bSendOrRece == 2)
    {
        str = QString_C("全部帧");
    }
    vecstr.push_back(str);
    for (int i = 0 ; i < 8 ; i++)
    {
        str = QString::number (tagCanReceive.m_BData[i] , 16 );
        vecstr.push_back(str);
    }
    emit sigItemWeight(tagCanReceive.m_bSendOrRece , vecstr);
}

void MainWindow::slotSetCurrentBMU(int bms , int bmu , int bsu)
{
    if (bms == -1)  //all deviese
    {
        ui->tabWidget_BMS->setInit();
        ui->stackedWidget->setCurrentIndex(0);
        g_pCommunicate->m_enCurrTree = DW_BAT;
        return;
    }
    if (bsu == -1)
    {
        ui->tabWidget_BMS->setInit();
        ui->stackedWidget->setCurrentIndex(0);
        g_pCommunicate->m_enCurrTree = DW_BAT;
        return;
    }
    if (bmu == 0)   //bmu03
    {
        if (bsu == 0)   //bmu03
        {
            ui->tabWidget_BMS->setInit();
            ui->stackedWidget->setCurrentIndex(0);
            g_pCommunicate->m_enCurrTree = DW_BAT;
            return;
        }
    }
    if (bmu == 1)   //BTS
    {
        ui->tabWidget_BTS->setInit(bsu + 1);
        g_pCommunicate->m_iCurrBtsNo = bsu;
        ui->stackedWidget->setCurrentIndex(1);
        g_pCommunicate->m_enCurrTree = DW_BTS;
        return;
    }
    ui->stackedWidget->setCurrentIndex(bsu + 2);
    if (bsu == 0)   //bsu
    {
        ui->tabWidget_BSU->setInit(bmu - 1);
        g_pCommunicate->m_iCurrBsuNo = bmu -2;
        g_pCommunicate->m_enCurrTree = DW_BSU_PID;    //bsu界面数据不需要读，是下面主动发送的，但是需要读DW_BSU_PID的数据区分跳线
    }
    else if (bsu == 1)   //bsu vid
    {
        ui->tabWidget_BSU_VID->setInit(bmu - 1);
        g_pCommunicate->m_iCurrBsuNo = bmu -2;
        g_pCommunicate->m_enCurrTree = DW_BSU_VID_BSU;
    }
    else if (bsu == 2)   //bsu pid
    {
        ui->tabWidget_BSU_PID->setInit(bmu - 1);
        g_pCommunicate->m_iCurrBsuNo = bmu -2;
        g_pCommunicate->m_enCurrTree = DW_BSU_PID;
    }
    //qDebug()<<"g_pCommunicate->m_iCurrBsuNo"<<g_pCommunicate->m_iCurrBsuNo;
}

void MainWindow::slotClose()
{
    this->close();
}

void MainWindow::slotShow()
{
    m_bIsBsu = true;   //是否已经前两秒读取了BSU个数
    ui->action_OpenCAN->setEnabled(false);
    ui->action_CloseCAN->setEnabled(true);
    ui->action_ResetCAN->setEnabled(true);
    m_bIsCanOpen = true;
}

void MainWindow::on_action_About_triggered()//帮助->关于
{
    about = new AboutDialog();
    about->exec();
    delete about;
}

void MainWindow::on_action_OpenCAN_triggered()//CAN->打开can
{
    open_can_ui = new Open_CAN_ui(this);
    connect(open_can_ui, SIGNAL(sigClose()), this, SLOT(slotClose()));
    connect(open_can_ui, SIGNAL(sigShow()), this, SLOT(slotShow()));
    open_can_ui->exec();
//    if(open_can_ui->exec() == QDialog::Accepted)
//    {
//        //slotShow();
//    }
//    else
//    {
//        slotClose();
//    }

    delete open_can_ui;
}

void MainWindow::on_action_CloseCAN_triggered()//CAN->关闭can
{
    if (g_pCommunicate->CanIsClose())
    {
        m_bIsCanOpen = false;
        m_bIsBsu = false;   //是否已经前两秒读取了BSU个数
        ui->action_OpenCAN->setEnabled(true);
        ui->action_CloseCAN->setEnabled(false);
        ui->action_ResetCAN->setEnabled(false);
    }
}

void MainWindow::on_action_ResetCAN_triggered()//CAN->复位can
{
    g_pCommunicate->CanResert();
}

//void MainWindow::slotShowCanData(bool bisshow)
//{
//    if (bisshow)
//    {
//        ui.widget_3->setVisible(true);
//    }
//    else
//    {
//        ui.widget_3->setVisible(false);
//    }
//}

//void MainWindow::slotSendActivate()
//{
//    if (m_pOpenWidget[0]->isChecked())
//    {
//        //ui.widget_3->setVisible(true);
//        g_pCommunicate->m_bisSaveRece = true;
//    }
//    else
//    {
//        //ui.widget_3->setVisible(false);
//        g_pCommunicate->m_bisSaveRece = false;
//    }
//}

//void MainWindow::slotMainActivate()
//{
//    if (m_pOpenWidget[2]->isChecked())
//    {
//        ui.page->setMainPage(true);
//    }
//    else
//    {
//        ui.page->setMainPage(false);
//    }
//}

//void MainWindow::slotSiderActivate()
//{
//    if (m_pOpenWidget[1]->isChecked())
//    {
//        pArea1->setVisible(true);
//    }
//    else
//    {
//        pArea1->setVisible(false);
//    }
//}

void MainWindow::on_action_SyncSet_triggered()//BMU->同步配置信息
{
    //m_bIsBsu = true;   //是否已经前两秒读取了BSU个数
    if (!g_pCommunicate->m_bIsConnectOk)
    {
        return;
    }
    g_pCommunicate->m_iSyncServiceRun = 100;
}

void MainWindow::on_action_SyncTime_triggered()//BMU->校准时间
{
    ST_CAN_FRAME frame;
    g_pCommunicate->SetTime(&frame);
    g_pCommunicate->WriteData(&frame);
}

void MainWindow::on_action_SaveParm_triggered()//BMU->保存当前参数
{
    QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("确认保存当前参数?"),QMessageBox::Ok|QMessageBox::Cancel,this);
    if(msgBox.exec()==QMessageBox::Ok)
    {
        ST_CAN_FRAME frame;
        g_pCommunicate->SaveFlash(&frame);
        g_pCommunicate->WriteData(&frame);
    }
}

void MainWindow::on_action_RedoParm_triggered()//BMU->恢复默认参数
{
    QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("确认恢复默认参数?"), QMessageBox::Ok|QMessageBox::Cancel, this);
    int i = msgBox.exec();
    if(i==QMessageBox::Ok)
    {
        ST_CAN_FRAME frame;
        g_pCommunicate->ResetParam(&frame);
        g_pCommunicate->WriteData(&frame);
        g_pCommunicate->WriteData(&frame);
    }
}

void MainWindow::on_action_WarnParm_triggered()//告警->告警参数设置
{
    g_pCommunicate->m_enoldCurrTree = g_pCommunicate->m_enCurrTree;
    g_pCommunicate->m_enCurrTree = DW_BMU_PID_ALM;
    AlarmSet *pAlarmSet = new AlarmSet(this);
    //connect(pAlarmSet, SIGNAL(sigClicked()), this, SLOT(slotAlarmSetData()));
    pAlarmSet->exec();
    delete pAlarmSet;
    g_pCommunicate->m_enCurrTree = g_pCommunicate->m_enoldCurrTree;
}

//void MainWindow::slotAlarmSetData()
//{
//    qDebug()<<"slotAlarmSetData";
//}

void MainWindow::on_action_ActWarn_triggered()//告警->活动告警
{
    g_pCommunicate->m_enoldCurrTree = g_pCommunicate->m_enCurrTree;
    g_pCommunicate->m_enCurrTree = DW_ALM_ACTIVE;
    AlarmActive *pAlarmActive = new AlarmActive(this);
    pAlarmActive->show();
    //delete pAlarmActive;
    g_pCommunicate->m_enCurrTree = g_pCommunicate->m_enoldCurrTree;
}

void MainWindow::on_action_HistoryWarn_triggered()//告警->历史告警
{
    g_pCommunicate->m_enoldCurrTree = g_pCommunicate->m_enCurrTree;
    g_pCommunicate->m_enCurrTree = DW_ALM_HISTORY;
    AlarmHistory *pAlarmHistory = new AlarmHistory(this);
    pAlarmHistory->exec();
    delete pAlarmHistory;
    g_pCommunicate->m_enCurrTree = g_pCommunicate->m_enoldCurrTree;
}

void MainWindow::on_actionLOG_triggered()//LOG->log设置
{
    DataLogSet *pLog = new DataLogSet(this);
    pLog->exec();
    delete pLog;
}

void MainWindow::on_action_AutoSave_triggered()//数据->自动保存数据帧
{
    if (ui->action_AutoSave->isChecked())
    {
        //qDebug("action_AutoSave_TRUE");
        g_pCommunicate->m_bisSaveRece = true;
    }
    else
    {
        //qDebug("action_AutoSave_FALSE");
        g_pCommunicate->m_bisSaveRece = false;
    }
}

void MainWindow::on_action_BSU_ADDR_triggered()//bsu->修改BSU地址
{
    bsu_addr_modify = new BSUAddrModify();
    bsu_addr_modify->exec();
    delete bsu_addr_modify;
}

void MainWindow::on_actionEEPROM_triggered()//BMS->EEPROM
{
    if ((w_HexEdit == Q_NULLPTR) || (g_pCommunicate->b_EEPROM_edit_isOpen == false))
    {
        w_HexEdit = new HexEdit();
        w_HexEdit->show();
    }
}

void MainWindow::on_action_plot_triggered()
{
    UserPlot *plot = new UserPlot();
    plot->show();
    g_pCommunicate->isChart = true;
}
