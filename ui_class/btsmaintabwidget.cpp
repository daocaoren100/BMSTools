//BTS标签窗口
#include "btsmaintabwidget.h"
#include "ui_btsmaintabwidget.h"

btsMainTabWidget::btsMainTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::btsMainTabWidget)
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

    m_iBtsNum = 0;
    m_bisFrush = false;

    m_nTimerID = startTimer(100);//新建定时器
}

btsMainTabWidget::~btsMainTabWidget()
{
    killTimer(m_nTimerID);
    delete ui;
}

int btsMainTabWidget::getPage()
{
    int i = currentIndex();
    return  i;
}

void btsMainTabWidget::setInit(int ibsunum)
{
    m_iBtsNum = ibsunum;
    /*QString str = QString::number(m_iBtsNum);
    str = str + "#BSU";*/
    QString str = "BTS ";
    QString str1 = "Broadcast";
    QString str2 = str + str1;
    setTabText(0, str2);
    ui->tab->setInit(ibsunum);
    m_bisFrush = true;
}

void btsMainTabWidget::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
}
