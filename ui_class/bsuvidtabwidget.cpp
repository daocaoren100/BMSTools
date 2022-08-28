//BSU-VID标签窗口
#include "bsuvidtabwidget.h"
#include "ui_bsuvidtabwidget.h"

bsuVIDTabWidget::bsuVIDTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::bsuVIDTabWidget)
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

    m_nTimerID = startTimer(100);   //新建定时器
}

bsuVIDTabWidget::~bsuVIDTabWidget()
{
    killTimer(m_nTimerID);
    delete ui;
}

int bsuVIDTabWidget::getPage()
{
    int i = currentIndex();
    return  i;
}

void bsuVIDTabWidget::setInit(int ibsunum)
{
    m_iBsuNum = ibsunum;
    /*QString str = QString::number(m_iPage);
    str = str + "#BSU VID From BMU03";*/
    QString str = "BSU VID From BMU03";
    setTabText(0, str);

    str = "CELL VID From BMU03";
    setTabText(1, str);

    ui->tab->setInit(ibsunum);
    ui->tab_2->setInit(ibsunum);
    m_bisFrush = true;
}

void bsuVIDTabWidget::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
}
