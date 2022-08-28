//主标签窗口
#include "bmumaintabwidget.h"
#include "ui_bmumaintabwidget.h"

bmuMainTabWidget::bmuMainTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::bmuMainTabWidget)
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

    m_iBatNum = 0;
    m_bisFrush = false;

    setTabText(0, QString_C("综合信息"));
    setTabText(1, QString_C("采集模块设置"));
    setTabText(2, QString_C("系统运行信息"));
    setTabText(3, QString_C("额定参数"));
    setTabText(4, QString_C("维护参数"));
    setTabText(5, QString_C("充电参数"));
    setTabText(6, QString_C("高级设置"));
    setTabText(7, QString_C("参数校准"));
    setTabText(8, QString_C("工装模式"));

    setTabEnabled(4 ,false);//隐藏维护参数

    for (int i = 0 ; i <BAT_MAX_NUM ; i ++)
    {
        m_qBatSub[i] = NULL;
        m_qBatSub[i] = new BatSub(this);
        addTab(m_qBatSub[i] , "Bat" + QString::number(i + 1));
    }

    ui->general_tab->timer->start();//主页
    oldTimer = ui->general_tab->timer;

    m_nTimerID = startTimer(200);//新建定时器
}

bmuMainTabWidget::~bmuMainTabWidget()
{
    killTimer(m_nTimerID);
    delete ui;
}

void bmuMainTabWidget::on_bmuMainTabWidget_currentChanged(int index)
{
    switch(index)
    {
    case 0:    //BatTotal
        {
            oldTimer->stop();
            ui->general_tab->timer->start();//主页
            oldTimer = ui->general_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_BAT_TOTAL;
        }
        break;
    case 1:    //BSUSet
        {
            oldTimer->stop();
            ui->bsuSet_tab->timer->start();//采集参数设置
            oldTimer = ui->bsuSet_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_BSU_SET;
        }
        break;
    case 2:    //Run
        {
            oldTimer->stop();
            ui->sysInfo_tab->timer->start();//系统运行信息
            oldTimer = ui->sysInfo_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_RUN;
        }
        break;
    case 3:    //Rated
        {
            oldTimer->stop();
            ui->specifyPara_tab->timer->start();//额定参数设置
            oldTimer = ui->specifyPara_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_RATED;
        }
        break;
    case 4:    //
        {
            oldTimer->stop();
            ui->maintainPara_tab->timer->start();//维护参数设置
            oldTimer = ui->maintainPara_tab->timer;
        }
        break;
    case 5:    //Charge
        {
            oldTimer->stop();
            ui->chargePara_tab->timer->start();//充电参数
            oldTimer = ui->chargePara_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_CHARGE;
        }
        break;
    case 6:    //Advance
        {
            oldTimer->stop();
            ui->advancedPara_tab->timer->start();//高级设置
            oldTimer = ui->advancedPara_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_ADVANCE;
        }
        break;
    case 7:    //BMUCailbrate
        {
            oldTimer->stop();
            ui->calibrationPara_tab->timer->start();//参数校准
            oldTimer = ui->calibrationPara_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_CALIB;
        }
        break;
    case 8:    //BMUTest
        {
            oldTimer->stop();
            ui->toolModel_tab->timer->start();//工装模式
            oldTimer = ui->toolModel_tab->timer;
            g_pCommunicate->m_enCurrPage = DW_BMU_TEST;
        }
        break;
    case 9:    //Bat1Sub
        {
            oldTimer->stop();
            m_qBatSub[0]->timer->start();//Bat1
            oldTimer = m_qBatSub[0]->timer;
            g_pCommunicate->m_iBatSelNo = 1;
            g_pCommunicate->m_enCurrPage = DW_BAT_VID;
        }
        break;
    case 10:    //Bat2Sub
        {
            oldTimer->stop();
            m_qBatSub[1]->timer->start();//Bat2
            oldTimer = m_qBatSub[1]->timer;
            g_pCommunicate->m_iBatSelNo = 2;
            g_pCommunicate->m_enCurrPage = DW_BAT_VID;
        }
        break;
    case 11:    //Bat3Sub
        {
            oldTimer->stop();
            m_qBatSub[2]->timer->start();//Bat3
            oldTimer = m_qBatSub[2]->timer;
            g_pCommunicate->m_iBatSelNo = 3;
            g_pCommunicate->m_enCurrPage = DW_BAT_VID;
        }
        break;
    case 12:    //Bat4Sub
        {
            oldTimer->stop();
            m_qBatSub[3]->timer->start();//Bat4
            oldTimer = m_qBatSub[3]->timer;
            g_pCommunicate->m_iBatSelNo = 4;
            g_pCommunicate->m_enCurrPage = DW_BAT_VID;
        }
        break;
    case 13:    //Bat5Sub
        {
            oldTimer->stop();
            m_qBatSub[4]->timer->start();//Bat5
            oldTimer = m_qBatSub[4]->timer;
            g_pCommunicate->m_iBatSelNo = 5;
            g_pCommunicate->m_enCurrPage = DW_BAT_VID;
        }
        break;
    case 14:    //Bat6Sub
        {
            oldTimer->stop();
            m_qBatSub[5]->timer->start();//Bat6
            oldTimer = m_qBatSub[5]->timer;
            g_pCommunicate->m_iBatSelNo = 6;
            g_pCommunicate->m_enCurrPage = DW_BAT_VID;
        }
        break;
    default:
        break;
    }
}

int bmuMainTabWidget::getPage()
{
    int i = currentIndex();
    return  i;
}

//void bmuMainTabWidget::setMainPage(bool bPage)
//{
//    if (bPage)
//    {
//        ui.widget->setVisible(false);
//        ui.widget_2->setVisible(true);
//    }
//    else
//    {
//        ui.widget_2->setVisible(false);
//        ui.widget->setVisible(true);
//    }
//}

void bmuMainTabWidget::setInit()
{
    m_bisFrush = true;
    //m_qDlgBatTotal->setInit();
    ui->general_tab->setInit();
    //ui.tab->setInit();
    ui->bsuSet_tab->setInit();
    ui->sysInfo_tab->setInit();
    ui->specifyPara_tab->setInit();
    //ui->maintainPara_tab->setInit();
    ui->chargePara_tab->setInit();
    ui->advancedPara_tab->setInit();
    ui->calibrationPara_tab->setInit();
    ui->toolModel_tab->setInit();

    m_qBatSub[0]->setInit(0);
}

void bmuMainTabWidget::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
    if (m_iBatNum == g_pCommunicate->m_nBatNum)
    {
        return;
    }
    m_iBatNum = g_pCommunicate->m_nBatNum;
    for (int i = count() - 1 ; i > 9 ; i --)
    {
        removeTab(i);
        if (m_qBatSub[ i - 9] != NULL)
        {
            delete m_qBatSub[ i - 9];
            m_qBatSub[ i - 9] = NULL;
        }
    }
    for (int i = 1 ; i <m_iBatNum ; i ++)
    {
        QString str = "Bat" + QString::number(i + 1);
        m_qBatSub[i] = new BatSub(this);
        addTab(m_qBatSub[i] , str);
        m_qBatSub[i]->setInit(i);
    }
}
