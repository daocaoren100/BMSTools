#include "mainwindow.h"
#include <QApplication>
#include <QObject>

#include "Core/Communicate.h"

#ifdef USE_LOCAL_FONT
bool _USE_LOCAL_FONT;      //�����Ƿ�ʹ�ñ������ԣ�΢���źڣ�
#endif

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qhexedit);
    Q_INIT_RESOURCE(chartdirector);
    Q_INIT_RESOURCE(main);
    QApplication a(argc, argv);
    //QApplication::setStyle("windows");    //����Ϊwindows���
    QApplication::setStyle(QStyleFactory::create("Fusion")); //Fusion���
    a.setApplicationName("BMS_KLclear_Tool");
    a.setOrganizationName("KLclear");

    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    // Identify locale and load translation if available
    QString locale = QLocale::system().name();
    QTranslator translator;
    if (locale == "zh_CN")
    {
        QString locale_translator = QString("qhexedit_zh_CN");
        translator.load(locale_translator, ":/translations/");
        a.installTranslator(&translator);
    }
    else
    {
        QString locale_translator = QString("qhexedit_en_US");
        translator.load(locale_translator, ":/translations/");
        a.installTranslator(&translator);
    }

    QFileInfo fiinfo("./set/setting.ini");
    if (!fiinfo.isFile())   //�ļ�������
    {
        QMessageBox msgBox(QMessageBox::Warning, "Warning", QString_C("�����ļ���ʧ��") , QMessageBox::Yes ,NULL);
        if(msgBox.exec()==QMessageBox::Yes)
        {
            exit(0);
        }
        exit(0);
    }

    QDir *temp = new QDir;
    bool exist = temp->exists("./log");
    if (!exist)   //�ļ��в�����
    {
        bool okmk = temp->mkdir("./log");   //�����ļ���
    }

#ifdef USE_LOCAL_FONT
    //���Ӷ�����֧��
    QLocale m_locale;
    _USE_LOCAL_FONT = TRUE;
    if(m_locale.language() == QLocale::Chinese)
    {
        _USE_LOCAL_FONT = FALSE;      //�����Ƿ�ʹ�ñ������ԣ�΢���źڣ�
    }
#endif

    g_pCommunicate = new QCommunicate;

    MainWindow w;
    //w.show();
    w.showMaximized();

#ifdef USE_LOCAL_FONT
    if(_USE_LOCAL_FONT == TRUE)
    {
        QString localFontString = loadFontFamilyFromTTF();
        QFont localFont  = a.font();
        localFont.setFamily(localFontString);
        localFont.setPixelSize(12);
        localFont.setBold(true);
        QApplication::setFont(localFont);
    }
#endif

    return a.exec();
}

#ifdef USE_LOCAL_FONT
//���ر�������
QString loadFontFamilyFromTTF()
{
    if(_USE_LOCAL_FONT == TRUE)
    {
        static QString font;
        static bool loaded = false;
        if(!loaded)
        {
            loaded = true;
            int loadedFontID = QFontDatabase::addApplicationFont(QString_C("./Font/msyhbd.ttc"));
            QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(loadedFontID);
            if(!loadedFontFamilies.empty())
                font = loadedFontFamilies.at(0);
        }
        return font;
    }
    return "";
}
#endif
