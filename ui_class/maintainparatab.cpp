//ά����������-��ǩ
#include "maintainparatab.h"
#include "ui_maintainparatab.h"

maintainParaTab::maintainParaTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::maintainParaTab)
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

    timer = new QTimer();//�½���ʱ��
    connect(timer, SIGNAL(timeout()), this, SLOT(refTimeout()));
    timer->setInterval(100);
}

maintainParaTab::~maintainParaTab()
{
    timer->deleteLater();
    delete ui;
}

void maintainParaTab::refTimeout()
{

}
