#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#define QString_C(txt)  QStringLiteral(txt)     //中文显示，防止乱码

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
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

    ui->label_info->setText(QString_C("科列BMS_Studio调试软件  ") + SoftVer + "  " + ModifyTime);

    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);//去除对话框边框
    //this->setWindowFlags(this->windowFlags() &~ Qt::WindowContextHelpButtonHint);
    //this->setWindowFlags(this->windowFlags() &~ Qt::WindowCloseButtonHint);
    this->setWindowFlags(Qt::CustomizeWindowHint);//去除标题栏
    this->setFixedSize( this->width (),this->height ());//固定大小
    //this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);//窗口显示最前
    //this->setWindowFlags(this->windowFlags() &~ Qt::WindowStaysOnTopHint);//取消窗口显示最前

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush (Qt::white));//设置背景为白色
    this->setPalette(palette);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if((QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::Ok)  == button)   //判断按下的是否为"OK”按钮
    {
        accept();
    }
}
