//���ݼ�¼����-�Ի���
#include "datalogset.h"
#include "ui_datalogset.h"

DataLogSet::DataLogSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataLogSet)
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

    int inter = g_pCommunicate->m_nLogInter;
    QString str = QString::number(inter);
    ui->lineEdit->setText(str);
}

DataLogSet::~DataLogSet()
{
    delete ui;
}

void DataLogSet::on_pushButton_OK_clicked()
{
    int inter = ui->lineEdit->text().toInt();
    if (inter >= 5)
    {
        g_pCommunicate->m_nLogInter =  ui->lineEdit->text().toInt();
        close();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Warning, QString_C("����"), QString_C("�������벻ҪС��0.5S��"),QMessageBox::Ok,this);
        msgBox.exec();
    }
}
