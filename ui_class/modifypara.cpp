//参数修改-对话框
#include "modifypara.h"
#include "ui_modifypara.h"

ModifyPara::ModifyPara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyPara)
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

    m_nId = 0xFFFF;
    m_pValue = NULL;
}

ModifyPara::~ModifyPara()
{
    delete ui;
}

void ModifyPara::on_pushButton_clicked()
{
    DB_VALUE_T ptData;
    QString str;
    QString strValue = ui->lineEdit_2->text();
    if (m_pValue == NULL)
    {
        if (m_nId < PID_TO_VID_OFFSET)
        {
            ptData.uiData = g_pCommunicate->DB_GetUint16(m_nId);
            str = QString::number(ptData.uiData);
            if (str  != strValue)
            {
                g_pCommunicate->SetData(&m_sFrame, m_nId, strValue.toInt());
                g_pCommunicate->WriteData(&m_sFrame);
                g_pCommunicate->WriteData(&m_sFrame);
            }
        }
        else
        {
            ptData.uiData = g_pCommunicate->DB_GetUint16(m_nId);
            str = QString::number(ptData.siData);
            if (str  != strValue)
            {
                g_pCommunicate->SetData(&m_sFrame, m_nId, strValue.toInt());
                g_pCommunicate->WriteData(&m_sFrame);
                g_pCommunicate->WriteData(&m_sFrame);
            }
        }
    }
    else
    {
        *m_pValue = strValue.toInt();
    }
    close();
}

bool ModifyPara::OnInit()
{
    int nBat, nBsu, nOffset, nCell;
    int nId;
    QString str;
    DB_VALUE_T ptData;

    if (m_pValue == NULL)
    {
        nId = m_nId;
        if (nId < PID_TO_VID_OFFSET)
        {
            str = "VID - " + QString::number(nId);
            ui->label_12->setText(str);
            ptData.uiData = g_pCommunicate->DB_GetUint16(nId);
            str = QString::number(ptData.uiData);
            ui->lineEdit_2->setText(str);

            // 系统类
            if (nId < VID_SYS_MAX_NUM)
            {
                str = "VID SYS Name";
                //sprintf_s(buffer, 1024, "%s", app.m_tSysVid[nId].sName);
                ui->label_10->setText(str);
                str = "VID SYS Remark";
                //sprintf_s(buffer, 1024, "%s", app.m_tSysVid[nId].sRemark);
                ui->label_14->setText(str);
                return true;
            }

            // BSU类
            nId = nId - 4096;
            if (nId < VID_BSU_TOTAL_SIZE)
            {
                nBsu = nId / VID_BSU_SIZE;
                nOffset = nId % VID_BSU_SIZE;

                if (nBsu >= BSU_MAX_NUM)
                {
                    return false;
                }

                if (nOffset < VID_BSU_HEAD_SIZE)
                {
                    if (nOffset < VID_BSU_HEAD_MAX_NUM)
                    {
                        str = "VID - " + QString::number(nId) + " BSU:" + QString::number(nBsu) + " OFFSET:" + QString::number(nOffset);
                        ui->label_12->setText(str);

                        //sprintf_s(buffer, 1024, "%s", app.m_tBsuVid[nBsu][nOffset].sName);
                        str = "VID BSU Name";
                        ui->label_10->setText(str);

                        str = "VID BSU Remark";
                        ui->label_14->setText(str);
                        //sprintf_s(buffer, 1024, "%s", app.m_tBsuVid[nBsu][nOffset].sRemark);
                    }
                }
                else
                {
                    nOffset -= VID_BSU_HEAD_SIZE;

                    nCell = nOffset >> 4;	// uiOffset / VID_BSU_CELL_SIZE;
                    nOffset &= 0x0F;			// uiOffset % VID_BSU_CELL_SIZE;

                    if (nCell >= BSU_CELL_NUM)
                    {
                        return FALSE;
                    }
                    else
                    {
                        if (nOffset < VID_BSU_CELL_MAX_NUM)
                        {
                            str = "VID - " + QString::number(nId) + " BSU:" + QString::number(nBsu) + " CELL:" + QString::number(nCell) + " OFFSET:" + QString::number(nOffset);
                            ui->label_12->setText(str);

                            //sprintf_s(buffer, 1024, "%s", app.m_tCellVid[nBsu][nCell][nOffset].sName);
                            str = "VID Cell Name";
                            ui->label_10->setText(str);

                            str = "VID Cell Remark";
                            ui->label_14->setText(str);
                            //sprintf_s(buffer, 1024, "%s", app.m_tCellVid[nBsu][nCell][nOffset].sRemark);
                        }
                    }
                }
                return true;
            }

            // BAT类
            nId = nId - VID_BSU_TOTAL_SIZE;
            if (nId < VID_BAT_TOTAL_SIZE)
            {
                nBat = nId >> 9;		// vid / VID_BAT_SIZE
                nOffset = nId & 0x01FF;

                if (nBat >= BAT_MAX_NUM)
                {
                    return false;
                }

                if (nOffset < VID_BAT_HEAD_SIZE)
                {
                    if (nOffset < VID_BAT_MAX_NUM)
                    {
                        str = "VID - " + QString::number(nId) + " Bat:" + QString::number(nBat)  + " OFFSET:" + QString::number(nOffset);
                        ui->label_12->setText(str);

                        //sprintf_s(buffer, 1024, "%s", app.m_tBatVid[nBat][nOffset].sName);
                        str = "VID Bat Name";
                        ui->label_10->setText(str);

                        str = "VID Bat Remark";
                        ui->label_14->setText(str);
                        //sprintf_s(buffer, 1024, "%s", app.m_tBatVid[nBat][nOffset].sRemark);
                    }
                }
                return true;
            }
        }
        else
        {
            nId = nId - PID_TO_VID_OFFSET;
            // 系统参数
            if (nId < PID_SYS_SIZE)
            {
                str = "PID - " + QString::number(nId);
                ui->label_12->setText(str);

                //sprintf_s(buffer, 1024, "%s", app.m_tSysPid[nId].sName);
                str = "PID SYS Name";
                ui->label_10->setText(str);

                str = "PID SYS Remark";
                ui->label_14->setText(str);
                //sprintf_s(buffer, 1024, "%s", app.m_tSysPid[nId].sRemark);
            }
            nId -= PID_SYS_SIZE;

            if ((nId < PID_BSU_TOTAL_SIZE) && (nId >= 0))
            {
                nBsu = nId / PID_BSU_SIZE;
                nOffset = nId % PID_BSU_SIZE;

                str = "PID - " + QString::number(m_nId - PID_TO_VID_OFFSET) + " BSU:" + QString::number(nBsu)  + " OFFSET:" + QString::number(nOffset);
                ui->label_12->setText(str);

                //sprintf_s(buffer, 1024, "%s", app.m_tBsuPid[nBsu][nOffset].sName);
                str = "PID BSU Name";
                ui->label_10->setText(str);

                str = "PID BSU Remark";
                ui->label_14->setText(str);
                //sprintf_s(buffer, 1024, "%s", app.m_tBsuPid[nBsu][nOffset].sRemark);
            }

            str = QString::number(g_pCommunicate->PARA_GetInt16(m_nId - PID_TO_VID_OFFSET));
            ui->lineEdit_2->setText(str);
            //sprintf_s(buffer, 1024, "%d", app.m_cBmu03Data.PARA_GetInt16(m_nId - PID_TO_VID_OFFSET));
            //SetWindowTextA(GetItem(IDC_MOD_LBL_VALUE), buffer);
        }
    }
    return true;
}

void ModifyPara::SetSigId(UINT32 id)
{
    m_nId = id;
}

void ModifyPara::SetDataPoint(int* pData)
{
    m_pValue = pData;
}
