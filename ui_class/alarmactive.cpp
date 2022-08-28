//活动告警-对话框
#include "alarmactive.h"
#include "ui_alarmactive.h"

AlarmActive::AlarmActive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmActive)
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

    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);//窗口显示最前

    int row = TABLE_ALARM_ROW;      //行
    int col = TABLE_ALARM_COL;         //列
    ui->tableWidget->setColumnCount(col);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //自适应宽度
    ui->tableWidget->verticalHeader()->hide(); //隐藏纵向的表头
    ui->tableWidget->setColumnWidth(0,60);
    ui->tableWidget->setColumnWidth(1,250);
    ui->tableWidget->setColumnWidth(2,160);
    QString strHeader[] = {tr("INDEX"),tr("ALARM"),tr("TIME")};
    for (int i=0; i<col; i++)
    {
        QTableWidgetItem *tableHeaderItem = new QTableWidgetItem;
        tableHeaderItem->setText(strHeader[i]);
        //tableHeaderItem->setTextColor(QColor(255,255,255));
        tableHeaderItem->setTextAlignment(Qt::AlignCenter);
        tableHeaderItem->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setHorizontalHeaderItem(i, tableHeaderItem);
    }
    for (int j = 0 ; j < row ; j++)
    {
        int rowid =ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowid);
        setTableItem(rowid , 0 , QString::number(j));
    }
    m_nActvAlmNum = 0;
    m_nTimerID = startTimer(950);//新建定时器
}

AlarmActive::~AlarmActive()
{
    killTimer(m_nTimerID);
    delete ui;
}

void AlarmActive::timerEvent(QTimerEvent *)
{
    if (!g_pCommunicate->m_bIsConnectOk)
    {
        return ;
    }
    const ST_ACTV_ALARM *pActAlm;
    if (m_nActvAlmNum != g_pCommunicate->ALM_GetActvAlmNum())
    {
        //InitSubView();
        m_nActvAlmNum = g_pCommunicate->ALM_GetActvAlmNum();
    }
    QString str = "Active Alarm Numbers:" + QString::number(g_pCommunicate->ALM_GetActvAlmNum());
    ui->label->setText(str);

    for (int i = 0; i<m_nActvAlmNum; i++)
    {
        pActAlm = g_pCommunicate->ALM_GetActvAlarm(i);
        if (pActAlm == NULL)
        {
            continue;
        }
        if (pActAlm->uiAlarmCode == 0)
        {
            continue;
        }
        QString strName = 	g_pCommunicate->ALM_GetAlarmFullName(pActAlm->uiAlarmCode);
        setTableItem(i , 1 , strName);

        QString strTime =
            QString::number(pActAlm->stStartTime.Year+2000) + "-" +
            QString::number(pActAlm->stStartTime.Month)  + "-" +
            QString::number(pActAlm->stStartTime.Day)  + "  " +
            QString::number(pActAlm->stStartTime.Hour) + ":" +
            QString::number(pActAlm->stStartTime.Min) + ":" +
            QString::number(pActAlm->stStartTime.Sec);
        setTableItem(i , 2 , strTime);
    }

    if (m_nActvAlmNum == 0)
    {
        clearTableItem();
    }
}

void AlarmActive::setTableItem(int row, int col, QString str)   //行列数据
{
    QTableWidgetItem *pTable_Item = new QTableWidgetItem;
    pTable_Item->setTextColor(QColor(0,0,0));
    if((row%2)==0)
    {
        pTable_Item->setBackgroundColor(QColor(216,232,248));
    }
    else
    {
        pTable_Item->setBackgroundColor(QColor(255,255,255));
    }
    pTable_Item->setTextAlignment(Qt::AlignLeft);
    pTable_Item->setTextAlignment(Qt::AlignVCenter);
    pTable_Item->setFlags(Qt::NoItemFlags);
    pTable_Item->setText(str);
    ui->tableWidget->setItem(row , col, pTable_Item);
    //ui->tableWidget->scrollToBottom();   //自动显示到最后一行
}

void AlarmActive::clearTableItem()   //清除行列数据
{
    ui->tableWidget->clearContents();
    for (int j = 0 ; j < TABLE_ALARM_ROW ; j++)
    {
        setTableItem(j , 0 , QString::number(j));
    }
}
