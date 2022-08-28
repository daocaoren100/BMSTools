#include "alarmsuspendwidget.h"
#include "ui_alarmsuspendwidget.h"

AlarmSuspendWidget::AlarmSuspendWidget(QWidget *parent) :
    QWidget(parent, Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint),
    ui(new Ui::AlarmSuspendWidget)
{
    ui->setupUi(this);
    setWindowTitle("Alarm Suspend Widget");

    ui->exclPushButton->setVisible(false);

    setAttribute(Qt::WA_TranslucentBackground, true);

    ui->alarmTableWidget->setMinimumSize(220, 0);
    ui->alarmTableWidget->setFixedSize(220, 0);
    ui->alarmTableWidget->setHidden(b_flag);
    b_flag = false;

    QList<ToolPushButton *> btnList = this->findChildren<ToolPushButton *>();
    foreach(ToolPushButton * btn, btnList)
    {
        connect(btn, &ToolPushButton::signalPressPoint, this, &AlarmSuspendWidget::slotPushBtnPressed);
        connect(btn, &ToolPushButton::signalMouseMove, this, &AlarmSuspendWidget::slotPushBtnClicked);
        connect(btn, &ToolPushButton::signalReleasePoint, this, &AlarmSuspendWidget::slotPushBtnReleased);
    }

    ui->alarmTableWidget->setColumnCount(2);//��������
    /*��������*/
    QStringList headers;
    headers<<QString_C("���")
           <<QString_C("�澯");
    ui->alarmTableWidget->setHorizontalHeaderLabels(headers);
    ui->alarmTableWidget->verticalHeader()->setVisible(false);
    ui->alarmTableWidget->setColumnWidth(0, 50);
    ui->alarmTableWidget->setColumnWidth(1, 150);

    m_time = new QTimer(this);
    m_time->setInterval(5);
    connect(m_time, SIGNAL(timeout()), this, SLOT(slotSetTableViewSize()));
}

AlarmSuspendWidget::~AlarmSuspendWidget()
{
    delete ui;
}

void AlarmSuspendWidget::soltSetAlarm(QStringList AlarmList, UINT SOC)
{
    if(!m_time->isActive() && b_flag == false)
    {
        m_time->start();
        b_flag = true;
        ui->exclPushButton->setVisible(true);
    }

    SOC_Calculate(SOC);

    QTableWidgetItem *item;
    ui->alarmTableWidget->setRowCount(AlarmList.size());
    for(int i = 0; i < AlarmList.size(); i++)
    {
        item = new QTableWidgetItem(QString::number(i+1));
        item->setTextAlignment(Qt::AlignCenter);
        ui->alarmTableWidget->setItem(i, 0, item);
        item = new QTableWidgetItem(AlarmList.at(i));
        item->setTextAlignment(Qt::AlignCenter);
        ui->alarmTableWidget->setItem(i, 1, item);
    }
}

void AlarmSuspendWidget::soltClearAlarm(UINT SOC)
{
    if(!m_time->isActive() && b_flag == true)
    {
        m_time->start();
        b_flag = false;
        ui->exclPushButton->setVisible(false);
    }
    SOC_Calculate(SOC);
}

void AlarmSuspendWidget::SOC_Calculate(UINT SOC)
{
    static UINT SOC_bak = 60;
    UINT SOC_block;
    if(SOC >= 80)
    {
        SOC_block = 100;
    }
    else if(SOC >= 60)
    {
        SOC_block = 80;
    }
    else if(SOC >= 40)
    {
        SOC_block = 60;
    }
    else if(SOC >= 20)
    {
        SOC_block = 40;
    }
    else if(SOC > 0)
    {
        SOC_block = 20;
    }
    else
    {
        SOC_block = 0;
    }
    if(SOC_block != SOC_bak)
    {
        ui->alarmPushButton->setStyleSheet(QString("border-image: url(:/BMS_Center/Image/SOC/%1.png);").arg(SOC_block));
        SOC_bak = SOC_block;
    }
}

void AlarmSuspendWidget::slotSetTableViewSize()
{
    int height = ui->alarmTableWidget->height();
    if (b_flag)
    {
        ui->alarmTableWidget->setHidden(!b_flag);
        if (ui->alarmTableWidget->height() > 200)
        {
            m_time->stop();
        }
        else
        {
            ui->alarmTableWidget->setFixedSize(220, height + 1);
        }
    }
    else
    {
        if (ui->alarmTableWidget->height() <= 0)
        {
            m_time->stop();
        }
        else
        {
            ui->alarmTableWidget->setFixedSize(220, height - 1);
        }
    }
}

void AlarmSuspendWidget::slotPushBtnClicked(QMouseEvent *e)
{
    QPoint widgetPos = this->pos();
    QPoint pt(e->pos() - dragPostiton + widgetPos);

    this->move(pt);
}

void AlarmSuspendWidget::slotPushBtnPressed(QMouseEvent *e)
{

    dragPostiton = e->pos();
    pressPosition = e->globalPos();

}

void AlarmSuspendWidget::slotPushBtnReleased(QMouseEvent *e)
{
    releasePosition = e->globalPos();

}

void AlarmSuspendWidget::mousePressEvent(QMouseEvent *event)
{
    //�����Ҽ������˵�
    if(event->button() == Qt::RightButton)
    {
//        if(cmenu)//��֤ͬʱֻ����һ��menu����ʱ�ͷ��ڴ�
//        {
//            delete cmenu;
//            cmenu = NULL;
//        }
//        cmenu = new QMenu(this);

//        QAction *skipStepAction = cmenu->addAction(QString_C("�����˴�ִ��"));
//        QAction *setStopAction = cmenu->addAction(QString_C("���öϵ�"));
//        QAction *insertRowLastAction = cmenu->addAction(QString_C("�Ϸ�������"));
//        QAction *insertRowNextAction = cmenu->addAction(QString_C("�·�������"));
//        QAction *editAction = cmenu->addAction(QString_C("�༭"));
//        QAction *copyAction = cmenu->addAction(QString_C("����"));
//        QAction *cutAction = cmenu->addAction(QString_C("����"));
//        QAction *pasteUpAction = cmenu->addAction(QString_C("�Ϸ�ճ��"));
//        QAction *pasteDownAction = cmenu->addAction(QString_C("�·�ճ��"));
//        QAction *deleteAction = cmenu->addAction(QString_C("ɾ����"));

//        connect(skipStepAction, SIGNAL(triggered(bool)), this, SLOT(skip_step()));
//        connect(setStopAction, SIGNAL(triggered(bool)), this, SLOT(set_stop()));
//        connect(insertRowLastAction, SIGNAL(triggered(bool)), this, SLOT(insert_row_last()));
//        connect(insertRowNextAction, SIGNAL(triggered(bool)), this, SLOT(insert_row_next()));
//        connect(editAction, SIGNAL(triggered(bool)), this, SLOT(edit_row()));
//        connect(copyAction, SIGNAL(triggered(bool)), this, SLOT(copy_row()));
//        connect(cutAction, SIGNAL(triggered(bool)), this, SLOT(cut_row()));
//        connect(pasteUpAction, SIGNAL(triggered(bool)), this, SLOT(paste_up_row()));
//        connect(pasteDownAction, SIGNAL(triggered(bool)), this, SLOT(paste_down_row()));
//        connect(deleteAction, SIGNAL(triggered(bool)), this, SLOT(delete_row()));

//        cmenu->exec(QCursor::pos());//�ڵ�ǰ���λ����ʾ
    }
}

void AlarmSuspendWidget::leaveEvent(QEvent *event)
{
    //����뿪����ʱ����ͨ��ָ��
    setCursor(Qt::ArrowCursor);
}

void AlarmSuspendWidget::enterEvent(QEvent *event)
{
    //������ڴ�����ʱ��һ����ָ
    setCursor(Qt::PointingHandCursor);
}
