//参数修改对话框
#include "bsuaddrmodify.h"
#include "ui_bsuaddrmodify.h"

#define Addr_Row        11//行
#define Addr_Column     24//列

BSUAddrModify::BSUAddrModify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BSUAddrModify)
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

    QRegExp regx("[0-9]+$");
    QValidator *validator_modif = new QRegExpValidator(regx, ui->lineEdit_modif );
    ui->lineEdit_modif->setValidator( validator_modif );//限制地址只能输入数字
    QValidator *validator_app = new QRegExpValidator(regx, ui->lineEdit_app );
    ui->lineEdit_app->setValidator( validator_app );//限制地址只能输入数字

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(Addr_Row);  //行
    gridLayout->setMargin(Addr_Column);   //列
    for (int i = 0 ; i < Addr_Column ; i++)
    {
        for (int j = 0 ; j < Addr_Row ; j++)
        {
            if ((Addr_Row * i + j) >= 255)
            {
                break;
            }
            m_act_addr[Addr_Row * i + j] = new QCheckBox;
            m_act_addr[Addr_Row * i + j]->installEventFilter(this);  //在窗体上为QCheckBox安装过滤器
            m_act_addr[Addr_Row * i + j]->setText(QString::number(Addr_Row * i + j + 1));
            m_act_addr[Addr_Row * i + j]->setChecked(false);
            m_act_addr[Addr_Row * i + j]->setCheckable(true);
            m_act_addr[Addr_Row * i + j]->setEnabled(false);
            gridLayout->addWidget(m_act_addr[Addr_Row * i + j] , j , i);
        }
        gridLayout->setColumnStretch(i , 1);
    }
    ui->groupBox->setLayout(gridLayout);

    act_addr_num = 0;//在线模块数

    g_pCommunicate->b_Addr_test_open = true;

    m_nTimerID = startTimer(3000);//新建定时器
}

BSUAddrModify::~BSUAddrModify()
{
    g_pCommunicate->b_Addr_test_open = false;
    killTimer(m_nTimerID);
    delete ui;
}

bool BSUAddrModify::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QCheckBox *_CheckBox = (QCheckBox*)obj;
        if (!_CheckBox->isChecked())
        {
            return QDialog::eventFilter(obj,e);
        }
        for (int i=0; i<255; i++)// 数据
        {
            if (obj == m_act_addr[i])
            {
                QMouseEvent *me = (QMouseEvent*)e;
                if(me->button() == Qt::LeftButton)
                {
                    ui->lineEdit_app->setText(QString::number(i + 1));
                }
            }
        }
    }
    return QDialog::eventFilter(obj,e);
}

void BSUAddrModify::timerEvent(QTimerEvent *)
{
    if (!g_pCommunicate->m_bIsConnectOk)
    {
        return ;
    }
    act_addr_num = 0;
    g_pCommunicate->b_Addr_test_open = false;
    for(int i = 0; i < 255; i++)
    {
        if(g_pCommunicate->b_Addr_state[i] == true)
        {
            m_act_addr[i]->setChecked(true);
            QPalette* palette = new QPalette();
            palette->setBrush(QPalette::Foreground, Qt::red);
            m_act_addr[i]->setPalette(*palette);
            g_pCommunicate->b_Addr_state[i] = false;
            act_addr_num++;
        }
        else
        {
            m_act_addr[i]->setChecked(false);
        }
    }
    g_pCommunicate->b_Addr_test_open = true;
    ui->label_online_num->setText(QString::number(act_addr_num));
}

void BSUAddrModify::on_modifyPushButton_clicked()
{
    int addr_modif = ui->lineEdit_modif->text().toInt();
    int addr_app = ui->lineEdit_app->text().toInt();
    if ((addr_modif > 0) && (addr_modif < 256))
    {
        QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("是否确定修改?"),QMessageBox::Yes|QMessageBox::No,this);
        if(msgBox.exec()==QMessageBox::Yes)
        {
            ST_CAN_FRAME stFrame;
            g_pCommunicate->SetBSUAddr(&stFrame, addr_app, addr_modif);
            g_pCommunicate->WriteData(&stFrame);
            g_pCommunicate->WriteData(&stFrame);
        }
        else
        {

        }
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("请输入正确地址！"),QMessageBox::Yes,this);
        msgBox.exec();
    }
}
