//登录对话框
#include "open_can_ui.h"
#include "ui_open_can_ui.h"

Open_CAN_ui::Open_CAN_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Open_CAN_ui)
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

    ui->CAN_device_comboBox->setCurrentIndex(g_pCommunicate->m_eDev);
    ui->CAN_index_comboBox->setCurrentIndex(g_pCommunicate->m_nInd);
    ui->CAN_pass_comboBox->setCurrentIndex(g_pCommunicate->m_eCan);
    ui->CAN_bitRate_comboBox->setCurrentIndex(g_pCommunicate->m_eBtr -1);
    ui->user_comboBox->setCurrentIndex(0);

    ui->BSU_num_lineEdit->setText(QString::number(g_pCommunicate->m_nBsuNum));
    ui->volt_num_lineEdit->setText(QString::number(g_pCommunicate->m_nCellNum));
    ui->temp_num_lineEdit->setText(QString::number(g_pCommunicate->m_nTempNum));

    if (g_pCommunicate->m_nBmuOnLine == 0)
    {
        ui->BMU_checkBox->setChecked(true);
        on_BMU_checkBox_toggled(true);
    }
    else if (g_pCommunicate->m_nBmuOnLine == 1)
    {
        ui->BMU_checkBox->setChecked(false);
        on_BMU_checkBox_toggled(false);
    }
    else
    {
        ui->BMU_groupBox->setVisible(false);
        this->setFixedWidth(400);
    }

    ui->passWord_lineEdit->setVisible(false);
}

Open_CAN_ui::~Open_CAN_ui()
{
    delete ui;
}

void Open_CAN_ui::on_CAN_device_comboBox_currentIndexChanged(int index)
{
    switch(index)
    {
        case IKC_DEV_ZLG:      //ZLG-USBCAN-1/2I
            {
                ui->CAN_index_comboBox->setCurrentIndex(0);
                ui->CAN_pass_comboBox->setCurrentIndex(0);
                ui->CAN_bitRate_comboBox->setCurrentIndex(0);
                ui->CAN_index_comboBox->setEnabled(true);
                ui->CAN_pass_comboBox->setEnabled(true);
            }
            break;
        case IKC_DEV_PEAK:         //PEAK-PCAN USB
            {
                ui->CAN_index_comboBox->setCurrentIndex(0);
                ui->CAN_pass_comboBox->setCurrentIndex(0);
                ui->CAN_bitRate_comboBox->setCurrentIndex(0);
                ui->CAN_index_comboBox->setEnabled(false);
                ui->CAN_pass_comboBox->setEnabled(false);
            }
            break;
        case IKC_DEV_KVASER:          //Kvaser-USBCAN II
            {
                ui->CAN_index_comboBox->setCurrentIndex(0);
                ui->CAN_pass_comboBox->setCurrentIndex(0);
                ui->CAN_bitRate_comboBox->setCurrentIndex(0);
                ui->CAN_index_comboBox->setEnabled(false);
                ui->CAN_pass_comboBox->setEnabled(true);
            }
            break;
        case IKC_DEV_ZLG_E:        //ZLG-USBCAN-1/2E-U
            {
                ui->CAN_index_comboBox->setCurrentIndex(0);
                ui->CAN_pass_comboBox->setCurrentIndex(0);
                ui->CAN_bitRate_comboBox->setCurrentIndex(0);
                //ui->CAN_index_comboBox->setEnabled(false);
                //ui->CAN_pass_comboBox->setEnabled(false);
            }
            break;
        case IKC_PCI9840_ZLG:        //ZLG-PCI9840
            {
                ui->CAN_index_comboBox->setCurrentIndex(0);
                ui->CAN_pass_comboBox->setCurrentIndex(0);
                ui->CAN_bitRate_comboBox->setCurrentIndex(0);
                ui->CAN_index_comboBox->setEnabled(true);
                ui->CAN_pass_comboBox->setEnabled(true);
            }
            break;
        default:
            break;
    }
}

void Open_CAN_ui::on_BMU_checkBox_toggled(bool checked)
{
    if (checked)
    {
        g_pCommunicate->m_nBmuOnLine = 0;
        this->setFixedWidth(600);
        ui->BMU_groupBox->setVisible(true);
        ui->BMU_groupBox->setEnabled(true);
    }
    else
    {
        g_pCommunicate->m_nBmuOnLine = 1;
        this->setFixedWidth(400);
        ui->BMU_groupBox->setVisible(false);
        ui->BMU_groupBox->setEnabled(false);
    }
}

void Open_CAN_ui::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok)  == button)   //判断按下的是否为"确定”按钮
    {
        //是否勾选整车CAN
        if(ui->BMU_checkBox_CAN2->checkState() == Qt::Checked)
        {
            g_pCommunicate->m_bisCan2 = true;
        }
        else
        {
            g_pCommunicate->m_bisCan2 = false;
        }

        if (g_pCommunicate->m_nBmuOnLine == 1)
        {
            int pass =  ui->passWord_lineEdit->text().toInt();
            int iUser = ui->user_comboBox->currentIndex();
            if (iUser >0)
            {
                if (pass != 302090)
                {
                    QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("密码无效，没有密码请使用用户权限!"),QMessageBox::Ok,NULL);
                    if(msgBox.exec()==QMessageBox::Ok)
                    {
                        return;
                    }
                }
                else
                {
                    QMessageBox msgBox(QMessageBox::Warning, QString_C("警告!!"),
                        QString_C("免责声明：\n只有本公司人员才能输入写保护密码取得修改参数权限！\n获取修改参数权限后，随便修改参数会产生不可预知问题！\n如果非本公司人员输入写保护密码获取修改参数权限，因修改参数产生的一切问题，本公司不负任何责任！！"),
                        QMessageBox::Ok|QMessageBox::Cancel,NULL);
                    if(msgBox.exec()==QMessageBox::Ok)
                    {
                        if (iUser == 1)
                        {
                            g_pCommunicate->m_nProtected = 1;
                        }
                        else
                        {
                            g_pCommunicate->m_nProtected = 2;
                        }
                    }
                    else
                    {
                        g_pCommunicate->m_nProtected = 0;
                        ui->passWord_lineEdit->setText("");
                    }
                }
            }
            else
            {
                g_pCommunicate->m_nProtected = 0;
                QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("用户权限只能查看数据!"),QMessageBox::Ok,NULL);
                if(msgBox.exec()==QMessageBox::Ok)
                {
                }
            }
        }

        enIKCDevs en_ikcdevs = (enIKCDevs)ui->CAN_device_comboBox->currentIndex();
        int idindex = ui->CAN_index_comboBox->currentIndex();
        enIKCChannel en_ikcchannel = (enIKCChannel)ui->CAN_pass_comboBox->currentIndex();
        enIKCBtr en_ikcbtr = (enIKCBtr)(ui->CAN_bitRate_comboBox->currentIndex() + 1);     //从1开始计算值
        bool biscom = false;
        biscom = g_pCommunicate->CanIsOpen(en_ikcdevs, idindex , en_ikcchannel, en_ikcbtr);
        if (!biscom)
        {
            QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("CAN设备打开错误!"),QMessageBox::Ok,NULL);
            if(msgBox.exec()==QMessageBox::Ok)
            {
                emit sigClose();
                return;
            }
        }

        DB_VALUE_T tData;
        if (ui->BMU_checkBox->checkState() == Qt::Checked)  //无主控器
        {
            int lineEdit =  ui->BSU_num_lineEdit->text().toInt();   //BSU数量
            if ((lineEdit > BSU_MAX_NUM) || (lineEdit == 0))
            {
                QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("参数设置错误 -- BSU数量!"),QMessageBox::Ok,NULL);
                if(msgBox.exec()==QMessageBox::Ok)
                {
                    return;
                }
            }
            g_pCommunicate->m_nBsuNum = lineEdit;
            tData.uiData = g_pCommunicate->m_nBsuNum;
            g_pCommunicate->PARA_SetSys(PID_SYS_BSU_NUM, &tData);
            tData.uiData = 1;
            g_pCommunicate->PARA_SetSys(PID_SYS_BAT_NUM, &tData);

            lineEdit =  ui->volt_num_lineEdit->text().toInt();   //电压采集数量
            if ((lineEdit > CELL_MAX_NUM) || (lineEdit == 0))
            {
                QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("参数设置错误 -- 电压采集数量!"),QMessageBox::Ok,NULL);
                if(msgBox.exec()==QMessageBox::Ok)
                {
                    return;
                }
            }
            g_pCommunicate->m_nCellNum = lineEdit;

            lineEdit =  ui->temp_num_lineEdit->text().toInt();   //温度采集数量
            if ((lineEdit > BSU_TEMP_NUM) || (lineEdit == 0))
            {
                QMessageBox msgBox(QMessageBox::Warning, QString_C("提示"), QString_C("参数设置错误 -- 温度采集数量!"),QMessageBox::Ok,NULL);
                if(msgBox.exec()==QMessageBox::Ok)
                {
                    return;
                }
            }
            g_pCommunicate->m_nTempNum = lineEdit;
            g_pCommunicate->m_nBmuOnLine = 0;

            for (int i=0; i<g_pCommunicate->m_nBsuNum; i++)
            {
                g_pCommunicate->m_nCellPos[i] = g_pCommunicate->m_nCellNum;
                tData.uiData = g_pCommunicate->m_nCellNum;
                g_pCommunicate->PARA_SetBsu(i, PID_BSU_CELL_NUM, &tData);

                g_pCommunicate->m_nTempPos[i] = g_pCommunicate->m_nTempNum;
                tData.uiData = g_pCommunicate->m_nTempNum;
                g_pCommunicate->PARA_SetBsu(i, PID_BSU_TEMP_NUM, &tData);
            }
        }
        else//有主控模式需在启动时读取主控基本信息
        {
            ST_CAN_FRAME stFrame;
            g_pCommunicate->SelectPidVIPData(&stFrame);//请求获取一次系统重要参数
            g_pCommunicate->WriteData(&stFrame);
            //读取BSU跳线信息
            for(int i = 0; i < BMS_BSU_NUMBER; i++)
            {
                g_pCommunicate->SelectPidBsuPara(i, &stFrame);
                g_pCommunicate->WriteData(&stFrame);
            }
        }

        emit sigShow();
        this->close();
    }
    else if(button == ui->buttonBox->button((QDialogButtonBox::Cancel)))
    {
        this->close();
    }

}

void Open_CAN_ui::on_user_comboBox_activated(int index)
{
    switch(index)
    {
    case 0:
        ui->passWord_lineEdit->setVisible(false);
        break;
    case 1:
        ui->passWord_lineEdit->setVisible(true);
        break;
    case 2:
        ui->passWord_lineEdit->setVisible(true);
        break;
    default:
        break;
    }
}
