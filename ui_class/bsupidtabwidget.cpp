//BSU-PID��ǩ����
#include "bsupidtabwidget.h"
#include "ui_bsupidtabwidget.h"

bsuPIDTabWidget::bsuPIDTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::bsuPIDTabWidget)
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

    m_nTimerID = startTimer(100);   //�½���ʱ��
}

bsuPIDTabWidget::~bsuPIDTabWidget()
{
    killTimer(m_nTimerID);
    delete ui;
}

int bsuPIDTabWidget::getPage()
{
    int i = currentIndex();
    return  i;
}


void bsuPIDTabWidget::setInit(int ibsunum)
{
    m_iBsuNum = ibsunum;
    /*QString str = QString::number(m_iPage);
    str = str + "#BSU PID";*/
    QString str = "BSU02 PID";
    setTabText(0, str);

    str = QString_C("�ɼ�ͨ������");
    setTabText(1, str);

    str = QString_C("ͭ�Ʋ�������");
    setTabText(2, str);

    ui->tab->setInit(ibsunum);
    ui->tab_2->setInit(ibsunum);
    ui->tab_3->setInit(ibsunum);
    m_bisFrush = true;
}

void bsuPIDTabWidget::timerEvent(QTimerEvent *)
{
    if (!m_bisFrush)
    {
        return;
    }
}
