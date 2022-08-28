//BUS标签窗口
#include "bsumaintabwidget.h"
#include "ui_bsumaintabwidget.h"

bsuMainTabWidget::bsuMainTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::bsuMainTabWidget)
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

    m_iBsuNum = 0;
    m_bisFrush = false;

    m_nTimerID = startTimer(100);//新建定时器
}

bsuMainTabWidget::~bsuMainTabWidget()
{
    killTimer(m_nTimerID);
    delete ui;
}

int bsuMainTabWidget::getPage()
{
    int i = currentIndex();
    return  i;
}

void bsuMainTabWidget::setInit(int ibsunum)
{
    m_iBsuNum = ibsunum;
    /*QString str = QString::number(m_iBsuNum);
    str = str + "#BSU";*/
    QString str = "BSU02 ";
    QString str1 = "Broadcast";
    QString str2 = str + str1;
    setTabText(0, str2);
    ui->tab->setInit(ibsunum);
    m_bisFrush = true;
}

void bsuMainTabWidget::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
}
