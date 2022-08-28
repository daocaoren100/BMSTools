//�汾��V1.0

#include "Public.h"

stControlStringEx g_stParabmsVidSys[VID_SYS_MAX_NUM] =
{
	{6,NULL,7,7,7},
};

QString GetstrTime() //��ȡϵͳʱ��
{
	QDateTime dt;
	dt = QDateTime::currentDateTime();
	/*QString strtime = QString("%1-%2-%3  %4:%5:%6:%7").arg
	(dt.date().year() , 4 , 10).arg
	(dt.date().month() , 2 , 10).arg
	(dt.date().day() , 2 , 10).arg
	(dt.time().hour() , 2 , 10).arg
	(dt.time().minute() , 2 , 10).arg
	(dt.time().second() , 2 , 10).arg
	(dt.time().msec() , 4 , 10);*/
	QString strtime = QString("%1/%2/%3-%4:%5:%6:%7").arg(dt.date().year()).arg(dt.date().month()).arg(dt.date().day()).arg
		                                                                            (dt.time().hour()).arg(dt.time().minute()).arg(dt.time().second()).arg(dt.time().msec());
	return strtime;
}

QString GetLocalTime(tagSystemTime *st) //��ȡϵͳʱ��
{
    QDateTime dt;
    dt = QDateTime::currentDateTime();
    st->m_usYear = dt.date().year();
    st->m_usMonth = dt.date().month();
    st->m_usDay = dt.date().day();
    st->m_usHour = dt.time().hour();
    st->m_usMinute = dt.time().minute();
    st->m_usSecond = dt.time().second();
    st->m_usMsec = dt.time().msec();
	QString strtime = QString("%1-%2-%3  %4:%5:%6:%7").arg
		(dt.date().year() , 4 , 10).arg
		(dt.date().month() , 2 , 10).arg
		(dt.date().day() , 2 , 10).arg
		(dt.time().hour() , 2 , 10).arg
		(dt.time().minute() , 2 , 10).arg
		(dt.time().second() , 2 , 10).arg
		(dt.time().msec() , 4 , 10);
	return strtime;
}

QString TakeOutReturn(QString str) //ɾ���ַ������Ļس����пո����
{
    QString strTmp;
    int len = str.length();
    bool blk = true;
    for (int i=len-1; i>=0; i--)
    {
        if (str[i] == 13)
        {//ȥ��ĩβ�Ļس�����
            continue;
        }
        else if (str[i] == 10)
        {//ȥ��ĩβ�Ļ��з���
            continue;
        }
        else if (str[i] == 32)
        {
            if (blk)
            {//ȥ��ĩβ�Ŀո����
                continue;
            }
        }
        else
        {
            blk = false;
        }

        strTmp += str[i];
    }

    len = strTmp.length();
    str.clear();
    for (int i=len-1; i>=0; i--)
    {
        str += strTmp[i];
    }

    return str;
}

QString GetWorkPath(void) //��ȡ��ǰ����·��
{
    QString path = QCoreApplication::applicationDirPath();
    path += "/";
    return path;
}

QString GetFileName(QString strExp) //��ϵͳʱ������ȡ�ļ���
{
    tagSystemTime time;
    GetLocalTime(&time);
    QString strFileName;
    if (time.m_usMonth>=10)
    {
        strFileName = QString("%1%2").arg(time.m_usYear).arg(time.m_usMonth);
    }
    else
    {
        strFileName = QString("%1%2%3").arg(time.m_usYear).arg("0").arg(time.m_usMonth);
    }

    strFileName += strExp;

    return strFileName;
}

float StrToF(QString str)
{
    return str.toFloat();
}

bool GetDataBit(_US usData, _US usPos)
{
	_US usBit = usData & (0x01 << usPos);
	if (usBit >0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int HexStrToI(QString str) //ʮ�����Ƶ��ַ���תʮ����,����0x1C->28
{
    bool ok;
    return str.toInt(&ok, 16);
}

QString FloatToStr(enParameterDisplayFormat disFormat, float fData, int iNumOfZero)
{
    QString str,str1;
    const char* ch;

    if (iNumOfZero == -1)
    {
        str = QObject::tr("Unknown");
        return str;
    }

    switch(disFormat)
    {
    case PDF_Decimal:
    case PDF_Enum:
        if (iNumOfZero == 0)
        {
            str.sprintf("%d",int(fData));
        }
        else if (iNumOfZero == 1)
        {
            str.sprintf("%.1f",fData);
        }
        else if (iNumOfZero == 2)
        {
            str.sprintf("%.2f",fData);
        }
        else if (iNumOfZero == 3)
        {
            str.sprintf("%.3f",fData);
        }
        else if (iNumOfZero == 4)
        {
            str.sprintf("%.4f",fData);
        }
        else if (iNumOfZero == 5)
        {
            str.sprintf("%.5f",fData);
        }
        else
        {
            str1.sprintf("%d",iNumOfZero);
            str1 = "%." + str1 + "f";
            ch = qPrintable(str1);
            str.sprintf(ch,fData);
        }
        break;
    case PDF_Hex:
        str = QString::number((int)fData,16).toUpper();
        break;
    case PDF_Asterrisk:
        str = "***";
        break;
    case PDF_Bottom:
        str = QObject::tr("Unknown");
        break;
    default:
        Q_ASSERT(0);
        break;
    }

    return str;
}

bool FindFile(QString path)
{
    QDir dir(path);
    if (!dir.exists())
    {
        return false;
    }

    dir.setFilter(QDir::Dirs|QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    int i=0,nFiles=0;
    do
    {
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.fileName()=="." || fileInfo.fileName()=="..")
        {
            i++;
            continue;
        }

        bool bisDir=fileInfo.isDir();
        if(bisDir)
        {
            nFiles++;
            QString str1 = QString("%1 %2 %3").arg(fileInfo.size()).arg(fileInfo.fileName()).arg(fileInfo.path());
            FindFile(fileInfo.filePath());
        }
        else
        {
            nFiles++;
            QString str2 = QString("%1 %2 %3").arg(fileInfo.size()).arg(fileInfo.fileName()).arg(fileInfo.path());
        }
        i++;
    }while(i<list.size());

    return true;
}

void AutoRemoveFaultFiles(void) //�Զ�ɾ������Ϊ���Լ�12������ǰ�Ĺ��ϼ�¼
{
    //1.�����12����ǰ���ļ���
    tagSystemTime time;
    GetLocalTime(&time);
    int year,month;
    year = time.m_usYear - 1;
    month = time.m_usMonth;
    QString strFaultName;
    strFaultName.sprintf("%d%02d.FDAT", year, month);
    QString strFaultPath = GetWorkPath() + "Configure/Fault/" + strFaultName;

    QString path = GetWorkPath() + "Configure/Fault/";
    QDir dir(path);
    if (!dir.exists())
    {
        return;
    }

    dir.setFilter(QDir::Dirs|QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    int fileNum = list.size();
    int i=0;
    do
    {
        QString strFilePath = list.at(i).absoluteFilePath();
        QFile file(strFilePath);
        int size = file.size();

        if (size==0 || strFilePath<strFaultPath)
        {
            if (file.isOpen())
            {
                file.close();
            }

            file.remove();
        }

        i++;
    }while(i<fileNum);
}

void AutoRemoveRunParaFiles(void) //�Զ�ɾ������Ϊ���Լ�12������ǰ�����в���
{
    //1.�����12����ǰ���ļ���
    tagSystemTime time;
    GetLocalTime(&time);
    int year,month;
    year = time.m_usYear - 1;
    month = time.m_usMonth;
    QString strFaultName;
    strFaultName.sprintf("%d%02d.RPDAT", year, month);
    QString strFaultPath = GetWorkPath() + "Configure/RunPara/" + strFaultName;

    QString path = GetWorkPath() + "Configure/RunPara/";
    QDir dir(path);
    if (!dir.exists())
    {
        return;
    }

    dir.setFilter(QDir::Dirs|QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    int fileNum = list.size();
    int i=0;
    do
    {
        QString strFilePath = list.at(i).absoluteFilePath();
        QFile file(strFilePath);
        int size = file.size();

        if (size==0 || strFilePath<strFaultPath)
        {
            if (file.isOpen())
            {
                file.close();
            }

            file.remove();
        }

        i++;
    }while(i<fileNum);
}
