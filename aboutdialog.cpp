#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#define QString_C(txt)  QStringLiteral(txt)     //������ʾ����ֹ����

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

    ui->label_info->setText(QString_C("����BMS_Studio�������  ") + SoftVer + "  " + ModifyTime);

    //this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);//ȥ���Ի���߿�
    //this->setWindowFlags(this->windowFlags() &~ Qt::WindowContextHelpButtonHint);
    //this->setWindowFlags(this->windowFlags() &~ Qt::WindowCloseButtonHint);
    this->setWindowFlags(Qt::CustomizeWindowHint);//ȥ��������
    this->setFixedSize( this->width (),this->height ());//�̶���С
    //this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);//������ʾ��ǰ
    //this->setWindowFlags(this->windowFlags() &~ Qt::WindowStaysOnTopHint);//ȡ��������ʾ��ǰ

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush (Qt::white));//���ñ���Ϊ��ɫ
    this->setPalette(palette);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if((QAbstractButton *)ui->buttonBox->button(QDialogButtonBox::Ok)  == button)   //�жϰ��µ��Ƿ�Ϊ"OK����ť
    {
        accept();
    }
}
