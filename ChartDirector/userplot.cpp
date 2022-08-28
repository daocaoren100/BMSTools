//#include <QApplication>
#include <QButtonGroup>
#include <QIcon>
#include <QPushButton>
#include <QComboBox>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include "userplot.h"
#include "chartdir.h"
#include <math.h>
#include <vector>
#include <sstream>

#include "Core/Communicate.h"

using namespace std;


//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    app.setStyleSheet("* {font-family:arial;font-size:11px}");
//    RealtimeTrack demo;
//    demo.show();
//    return app.exec();
//}

UserPlot::UserPlot(QWidget *parent) : QDialog(parent)
{
    LoadVariables();//加载变量
    //
    // Set up the GUI
    //

    setFixedSize(1200, 700);
    setWindowTitle("Realtime Chart with Track Line");
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);// 显示最小化

    // The frame on the left side
    QFrame *frame = new QFrame(this);
    frame->setGeometry(4, 8, 180, 688);
    frame->setFrameShape(QFrame::StyledPanel);

    // Run/Freeze push button
    QPushButton *runFreezePB = new QPushButton(QIcon(":/ioc/Start_greed.png"), "Run", frame);
    runFreezePB->setGeometry(4, 8, 170, 28);
    runFreezePB->setStyleSheet("QPushButton { text-align:left; padding:5px}");
    runFreezePB->setCheckable(true);

    // Save push button
    QPushButton *savePB = new QPushButton(QIcon(":/ioc/Save.png"), "Save", frame);
    savePB->setGeometry(4, 36, 170, 28);
    savePB->setStyleSheet("QPushButton { text-align:left; padding:5px}");
    savePB->setCheckable(true);

    // Open push button
    QPushButton *openPB = new QPushButton(QIcon(":/ioc/Open.png"), "Open", frame);
    openPB->setGeometry(4, 64, 170, 28);
    openPB->setStyleSheet("QPushButton { text-align:left; padding:5px}");
    openPB->setCheckable(true);

    // Set push button
    QPushButton *setPB = new QPushButton(QIcon(":/ioc/Maintenance.png"), "Set", frame);
    setPB->setGeometry(4, 92, 170, 28);
    setPB->setStyleSheet("QPushButton { text-align:left; padding:5px}");
    setPB->setCheckable(true);

    // Zoom in push button
    QPushButton *zoomInPB = new QPushButton(QIcon(":/ioc/ZoomIn.png"), "Zoom In", frame);
    zoomInPB->setGeometry(4, 120, 170, 28);
    zoomInPB->setStyleSheet("QPushButton { text-align:left; padding:5px}");
    zoomInPB->setCheckable(true);

    // Zoom out push button
    QPushButton *zoomOutPB = new QPushButton(QIcon(":/ioc/ZoomOut.png"), "Zoom Out", frame);
    zoomOutPB->setGeometry(4, 148, 170, 28);
    zoomOutPB->setStyleSheet("QPushButton { text-align:left; padding:5px}");
    zoomOutPB->setCheckable(true);

    // Return push button
    QPushButton *returnPB = new QPushButton(QIcon(":/ioc/return.png"), "Return", frame);
    returnPB->setGeometry(4, 176, 170, 28);
    returnPB->setStyleSheet("QPushButton { text-align:left; padding:5px}");
    returnPB->setCheckable(true);

    // The Run/Freeze/Set buttons form a button group
    buttonControl = new QButtonGroup(frame);
    buttonControl->addButton(runFreezePB, 0);
    buttonControl->addButton(savePB, 1);
    buttonControl->addButton(openPB, 2);
    buttonControl->addButton(setPB, 3);
    buttonControl->addButton(zoomInPB, 4);
    buttonControl->addButton(zoomOutPB, 5);
    buttonControl->addButton(returnPB, 6);
    connect(buttonControl, SIGNAL(buttonPressed(int)), SLOT(onButtonChanged(int)));
    //关闭缩放功能
    buttonControl->button(4)->setEnabled(false);
    buttonControl->button(5)->setEnabled(false);
    buttonControl->button(6)->setEnabled(false);

//    // Update Period drop down list box
//    (new QLabel("Update Period (ms)", frame))->setGeometry(6, 80, 108, 16);
//    QComboBox *updatePeriod = new QComboBox(frame);
//    updatePeriod->setGeometry(6, 96, 108, 21);
//    updatePeriod->addItems(QStringList() << "250" << "500" << "750" << "1000" << "1250" << "1500"
//                           << "1750" << "2000");
//    connect(updatePeriod, SIGNAL(currentIndexChanged(QString)),
//            SLOT(onUpdatePeriodChanged(QString)));

    for(int i=0; i<MAX_DATA_NUM; i++)
    {
        m_Sign[i] = new QLabel(frame);
        m_Sign[i]->setGeometry(6, 220+(i*23), 68, 21);
        m_Sign[i]->setText("A");

        m_Sign[i]->setVisible(false);

        m_Check[i] = new QCheckBox(frame);
        m_Check[i]->setGeometry(75, 220+(i*23), 21, 21);
        m_Check[i]->setChecked(true);
        connect(m_Check[i], SIGNAL(clicked()), this, SLOT(onCheckClicked()));

        m_Check[i]->setVisible(false);

        m_Value[i] = new QLabel(frame);
        m_Value[i]->setGeometry(97, 220+(i*23), 79, 21);
        m_Value[i]->setFrameShape(QFrame::StyledPanel);

        m_Value[i]->setVisible(false);
    }

    for(int i = 0; i < m_chartDataNum; i++)
    {
        m_Sign[i]->setText(m_chartData[i].name);
        m_Sign[i]->setVisible(true);
        m_Check[i]->setVisible(true);
        m_Value[i]->setVisible(true);
    }

    // Chart Viewer
    m_ChartViewer = new QChartViewer(this);
    m_ChartViewer->setGeometry(192, 8, 1192, 688);
    connect(m_ChartViewer, SIGNAL(viewPortChanged()), SLOT(drawChart()));
    connect(m_ChartViewer, SIGNAL(mouseMovePlotArea(QMouseEvent*)),
        SLOT(onMouseMovePlotArea(QMouseEvent*)));

    // Clear data arrays to Chart::NoValue
    for(int i = 0; i < sampleSize; ++i)
    {
        m_timeStamps.append(Chart::NoValue);

    }
    for(int a = 0; a < MAX_DATA_NUM; a++)
    {
        QVector<double> double_list;
        for(int i = 0; i < sampleSize; i++)
        {
            double_list.append(Chart::NoValue);
        }
        m_dataSeries.append(double_list);
    }

    m_currentIndex = 0;

    // Set m_nextDataTime to the current time. It is used by the real time random number
    // generator so it knows what timestamp should be used for the next data point.
    m_nextDataTime = QDateTime::currentDateTime();

    // Set up the data acquisition mechanism. In this demo, we just use a timer to get a
    // sample every 250ms.
    dataRateTimer = new QTimer(this);
    connect(dataRateTimer, SIGNAL(timeout()), SLOT(getData()));//更新数据
    dataRateTimer->setInterval(m_chartCfg.ref_rate);

    refreshRateTimer = new QTimer(this);
    connect(refreshRateTimer, SIGNAL(timeout()), SLOT(updateChart()));//刷新界面
    if(m_chartCfg.ref_rate < 1000)
    {
        refreshRateTimer->setInterval(1000);
    }
    else
    {
        refreshRateTimer->setInterval(m_chartCfg.ref_rate);
    }


    // 绘制图表
    drawChart();
}

UserPlot::~UserPlot()
{
    SaveVariables();//保存变量
    g_pCommunicate->isChart = false;
    delete m_ChartViewer->getChart();
}

void UserPlot::Reset()//数据重置
{
    sampleSize = 100;
    m_timeStamps.clear();
    // Clear data arrays to Chart::NoValue
    for(int i = 0; i < sampleSize; ++i)
    {
        m_timeStamps.append(Chart::NoValue);

    }
    for(int a = 0; a < MAX_DATA_NUM; a++)
    {
        m_dataSeries[a].clear();
        for(int i = 0; i < sampleSize; i++)
        {
             m_dataSeries[a].append(Chart::NoValue);
        }
    }

    m_currentIndex = 0;
}

void UserPlot::keyPressEvent(QKeyEvent * e)//键盘事件
{
    switch(e->key()){
    case Qt::Key_Left:
        if(isZoom)
        {
            isFollow = false;
            m_zoomDiffTime = m_zoomEndTime - m_zoomStartTime;
            m_zoomStartTime = m_zoomStartTime - m_zoomDiffTime / 4;
            if(m_zoomStartTime < m_timeStamps[0])
            {
                m_zoomStartTime = m_timeStamps[0];
            }
            m_zoomEndTime = m_zoomStartTime + m_zoomDiffTime;
            drawChart();
        }
        break;
    case Qt::Key_Right:
        if(isZoom)
        {
            m_zoomDiffTime = m_zoomEndTime - m_zoomStartTime;
            m_zoomEndTime = m_zoomEndTime + m_zoomDiffTime / 4;
            if(m_zoomEndTime > m_timeStamps[m_currentIndex - 1])
            {
                m_zoomEndTime = m_timeStamps[m_currentIndex - 1];
                isFollow = true;
            }
            m_zoomStartTime = m_zoomEndTime - m_zoomDiffTime;
            drawChart();
        }
        break;
    case Qt::Key_Up:
        if(m_currentIndex)
        {
            onButtonChanged(4);
        }
        break;
    case Qt::Key_Down:
        if(m_currentIndex)
        {
            onButtonChanged(5);
        }
        break;
    case Qt::Key_Escape:
        if(m_currentIndex)
        {
            onButtonChanged(6);
        }
        break;
    default:
        break;
    }
}

void UserPlot::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("是否确定退出?"),QMessageBox::Yes|QMessageBox::No,this);
    if(msgBox.exec()==QMessageBox::Yes)
    {
        SaveVariables();//保存变量
        g_pCommunicate->isChart = false;
        dataRateTimer->stop();
        dataRateTimer->deleteLater();
        refreshRateTimer->stop();
        refreshRateTimer->deleteLater();
        event->accept();          //接受退出信号，程序退出
    }
    else
    {
        event->ignore();			//忽略退出信号，程序继续运行
    }
}

void UserPlot::LoadVariables()//加载变量
{
    QString str;
    QSettings setting("./set/chartsetting.ini", QSettings::IniFormat);

    // 配置信息
    str = setting.value("Config/Ref_Rate").toString();
    if (!str.isEmpty())
    {
        m_chartCfg.ref_rate = str.toInt();
        if(m_chartCfg.ref_rate == 0)
        {
            m_chartCfg.ref_rate = 1000;
        }
    }
    str = setting.value("Config/Only_Mode").toString();
    if (!str.isEmpty())
    {
        m_chartCfg.onlyMode = str.toInt();
    }
    str = setting.value("Config/yAxis1").toString();
    if (!str.isEmpty())
    {
        Str2Char(m_chartCfg.yAxis1, str, yAxis1_SIZE);
    }
    else
    {
        memset(m_chartCfg.yAxis1, 0, yAxis1_SIZE);
        memcpy(m_chartCfg.yAxis1, "Volt (V)", sizeof("Volt (V)"));
    }
    str = setting.value("Config/yAxis2").toString();
    if (!str.isEmpty())
    {
        Str2Char(m_chartCfg.yAxis2, str, yAxis1_SIZE);
    }
    else
    {
        memset(m_chartCfg.yAxis2, 0, yAxis1_SIZE);
        memcpy(m_chartCfg.yAxis2, "Temp (C)", sizeof("Temp (C)"));
    }

    // 数据信息
    str = setting.value("DATA/Chart-DataNum").toString();
    if (!str.isEmpty())
    {
        m_chartDataNum = str.toInt();

        for(int i = 0; i < m_chartDataNum; i++)
        {
            str = setting.value(QString("DATA/Chart-%1-VID").arg(i)).toString();
            if (!str.isEmpty())
            {
                m_chartData[i].vid = str.toUInt();
            }
            else
            {
                m_chartData[i].vid = 0;
            }
            str = setting.value(QString("DATA/Chart-%1-NAME").arg(i)).toString();
            if (!str.isEmpty())
            {
                Str2Char(m_chartData[i].name, str, name_SIZE);
            }
            else
            {
                memset(m_chartData[i].name, '\0', name_SIZE);
            }
            str = setting.value(QString("DATA/Chart-%1-UNIT").arg(i)).toString();
            if (!str.isEmpty())
            {
                Str2Char(m_chartData[i].unit, str, unit_SIZE);
            }
            else
            {
                memset(m_chartData[i].unit, '\0', unit_SIZE);
            }
            str = setting.value(QString("DATA/Chart-%1-FACTOR").arg(i)).toString();
            if (!str.isEmpty())
            {
                m_chartData[i].factor = str.toDouble();
            }
            else
            {
                m_chartData[i].factor = 1;
            }
            str = setting.value(QString("DATA/Chart-%1-OFFSET").arg(i)).toString();
            if (!str.isEmpty())
            {
                m_chartData[i].offset = str.toDouble();
            }
            else
            {
                m_chartData[i].offset = 0;
            }
            str = setting.value(QString("DATA/Chart-%1-COLOR").arg(i)).toString();
            if (!str.isEmpty())
            {
                m_chartData[i].color = str.toInt(0, 16);
            }
            else
            {
                m_chartData[i].color = 0;
            }
            str = setting.value(QString("DATA/Chart-%1-RELEVANCE").arg(i)).toString();
            if (!str.isEmpty())
            {
                m_chartData[i].relevance = str.toInt();
            }
            else
            {
                m_chartData[i].relevance = 0;
            }
        }
    }

}

void UserPlot::SaveVariables()//保存变量
{
    QString str;
    QSettings setting("./set/chartsetting.ini", QSettings::IniFormat);

    // 配置信息
    str = QString::number(m_chartCfg.ref_rate);
    setting.setValue("Config/Ref_Rate", str);
    str = QString::number(m_chartCfg.onlyMode);
    setting.setValue("Config/Only_Mode", str);
    str = m_chartCfg.yAxis1;
    setting.setValue("Config/yAxis1", str);
    str = m_chartCfg.yAxis2;
    setting.setValue("Config/yAxis2", str);

    // 数据信息
    str = QString::number(m_chartDataNum);
    setting.setValue("DATA/Chart-DataNum", str);
    for(int i = 0; i < m_chartDataNum; i++)
    {
        str = QString::number(m_chartData[i].vid);
        setting.setValue(QString("DATA/Chart-%1-VID").arg(i), str);
        str = m_chartData[i].name;
        setting.setValue(QString("DATA/Chart-%1-NAME").arg(i), str);
        str = m_chartData[i].unit;
        setting.setValue(QString("DATA/Chart-%1-UNIT").arg(i), str);
        str = QString::number(m_chartData[i].factor);
        setting.setValue(QString("DATA/Chart-%1-FACTOR").arg(i), str);
        str = QString::number(m_chartData[i].offset);
        setting.setValue(QString("DATA/Chart-%1-OFFSET").arg(i), str);
        str = QString::number(m_chartData[i].color, 16);
        setting.setValue(QString("DATA/Chart-%1-COLOR").arg(i), str);
        str = QString::number(m_chartData[i].relevance);
        setting.setValue(QString("DATA/Chart-%1-RELEVANCE").arg(i), str);
    }
}

static void shiftData(double *data, int len, double newValue)//数据偏移
{
    memmove(data, data + 1, sizeof(*data) * (len - 1));
    data[len - 1] = newValue;
}

void UserPlot::setData(double* data, int data_size)//设置实时数据
{
    if(data_size > 20){data_size = 20;}

    // The current time
    QDateTime now = QDateTime::currentDateTime();

    // This is our formula for the random number generator
    do
    {
        // We need the currentTime in millisecond resolution
        double currentTime = Chart::chartTime2(m_nextDataTime.toTime_t())
                             + m_nextDataTime.time().msec() / 1000.0;

        // Get a data sample
        double p = currentTime * 4;

        // After obtaining the new values, we need to update the data arrays.
        if (m_currentIndex < sampleSize)
        {
            // Store the new values in the current index position, and increment the index.
            for(int i = 0; i < data_size; i++)
            {
                m_dataSeries[i][m_currentIndex] = *(data + i);
            }
            m_timeStamps[m_currentIndex] = currentTime;
            ++m_currentIndex;
        }
        else
        {
            for(int i = 0; i < data_size; i++)
            {
                m_dataSeries[i].append(*(data + i));
            }
            m_timeStamps.append(currentTime);
            ++sampleSize;
            ++m_currentIndex;
        }

        m_nextDataTime = m_nextDataTime.addMSecs(m_chartCfg.ref_rate);
    }
    while (m_nextDataTime < now);

    //
    // We provide some visual feedback to the latest numbers generated, so you can see the
    // data being generated.
    //
    for(int i = 0; i < data_size; i++)
    {
        m_Value[i]->setText(QString::number(m_dataSeries[i][m_currentIndex - 1], 'f', 3));
    }
}

void UserPlot::getData()//设置实时数据
{
    if(m_chartDataNum > 20){m_chartDataNum = 20;}
    if(m_chartDataNum < 0){m_chartDataNum = 0;}

    // The current time
    QDateTime now = QDateTime::currentDateTime();

    // This is our formula for the random number generator
    do
    {
        // We need the currentTime in millisecond resolution
        double currentTime = Chart::chartTime2(m_nextDataTime.toTime_t())
                             + m_nextDataTime.time().msec() / 1000.0;

        // Get a data sample
        double p = currentTime * 4;

        // After obtaining the new values, we need to update the data arrays.
        if (m_currentIndex < sampleSize)
        {
            // Store the new values in the current index position, and increment the index.
            for(int i = 0; i < m_chartDataNum; i++)
            {
                DB_VALUE_T data;
                g_pCommunicate->DB_GetData(m_chartData[i].vid, &data);
                m_dataSeries[i][m_currentIndex] = (data.uiData * m_chartData[i].factor) + m_chartData[i].offset;
            }
            m_timeStamps[m_currentIndex] = currentTime;
            ++m_currentIndex;
        }
        else
        {
            for(int i = 0; i < m_chartDataNum; i++)
            {
                DB_VALUE_T data;
                g_pCommunicate->DB_GetData(m_chartData[i].vid, &data);
                m_dataSeries[i].append((data.uiData * m_chartData[i].factor) + m_chartData[i].offset);
            }
            m_timeStamps.append(currentTime);
            ++sampleSize;
            ++m_currentIndex;
        }

        m_nextDataTime = m_nextDataTime.addMSecs(m_chartCfg.ref_rate);
    }
    while (m_nextDataTime < now);

    //
    // We provide some visual feedback to the latest numbers generated, so you can see the
    // data being generated.
    //
    for(int i = 0; i < m_chartDataNum; i++)
    {
        m_Value[i]->setText(QString::number(m_dataSeries[i][m_currentIndex - 1], 'f', 3));
    }
}

void UserPlot::onButtonChanged(int button)//按钮事件
{
    switch (button) {
    case 0:// Run/Freeze push button
        if(!isRun)// Run
        {
            if(m_currentIndex != 0)
            {
                Reset();
            }
            dataRateTimer->start();
            refreshRateTimer->start();

            //关闭数据保存/打开功能
            //buttonControl->button(1)->setEnabled(false);
            buttonControl->button(2)->setEnabled(false);

            //打开缩放功能
            buttonControl->button(4)->setEnabled(true);
            buttonControl->button(5)->setEnabled(true);
            buttonControl->button(6)->setEnabled(true);
            isZoom = false;

            buttonControl->button(button)->setIcon(QIcon(":/ioc/Stop_red.png"));
            buttonControl->button(button)->setText("Freeze");
            isRun = true;
        }
        else// Freeze
        {
            dataRateTimer->stop();
            refreshRateTimer->stop();

            //使能数据保存/打开功能
            buttonControl->button(1)->setEnabled(true);
            buttonControl->button(2)->setEnabled(true);

            buttonControl->button(button)->setIcon(QIcon(":/ioc/Start_greed.png"));
            buttonControl->button(button)->setText("Run");
            isRun = false;
        }
        break;
    case 1:// Save push button
        saveChartData();
        break;
    case 2:// Open push button
        if(!openChartData())
        {
            QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("打开DAT文件失败！"), QMessageBox::Ok, this);
            msgBox.exec();
            return;
        }

        for(int i = 0; i < m_chartDataNum; i++)
        {
            m_Sign[i]->setText(m_chartData[i].name);
            m_Sign[i]->setVisible(true);
            m_Value[i]->setVisible(true);
        }
        drawChart();

        //打开缩放功能
        buttonControl->button(4)->setEnabled(true);
        buttonControl->button(5)->setEnabled(true);
        buttonControl->button(6)->setEnabled(true);
        isZoom = false;

        break;
    case 3:// Set push button
        d_setValue = new SetValueDialog();
        d_setValue->setData(m_chartData, m_chartDataNum, m_chartCfg);
        if(d_setValue->exec() == QDialog::Accepted)
        {
            m_chartDataNum = d_setValue->chartDataNum;
            g_pCommunicate->m_nChartNum = m_chartDataNum;
            for(int i = 0; i < 20; i++)
            {
                if (i >= m_chartDataNum)
                {
                    m_Sign[i]->setVisible(false);
                    m_Check[i]->setVisible(false);
                    m_Value[i]->setVisible(false);
                    continue;
                }

                m_chartData[i].vid = d_setValue->m_chartData[i].vid;
                memcpy(m_chartData[i].name, d_setValue->m_chartData[i].name, name_SIZE);
                memcpy(m_chartData[i].unit, d_setValue->m_chartData[i].unit, unit_SIZE);
                m_chartData[i].factor = d_setValue->m_chartData[i].factor;
                m_chartData[i].offset = d_setValue->m_chartData[i].offset;
                m_chartData[i].color = d_setValue->m_chartData[i].color;
                m_chartData[i].relevance = d_setValue->m_chartData[i].relevance;

                g_pCommunicate->m_nChartVids[i] = m_chartData[i].vid;

                m_Sign[i]->setText(m_chartData[i].name);
                m_Sign[i]->setVisible(true);
                m_Check[i]->setVisible(true);
                m_Value[i]->setVisible(true);
            }
            m_chartCfg.ref_rate = d_setValue->m_chartCfg.ref_rate;
            memcpy(m_chartCfg.yAxis1, d_setValue->m_chartCfg.yAxis1, yAxis1_SIZE);
            memcpy(m_chartCfg.yAxis2, d_setValue->m_chartCfg.yAxis2, yAxis2_SIZE);

            dataRateTimer->setInterval(m_chartCfg.ref_rate);//重设定时器
            if(m_chartCfg.ref_rate < 1000)
            {
                refreshRateTimer->setInterval(1000);
            }
            else
            {
                refreshRateTimer->setInterval(m_chartCfg.ref_rate);
            }
        }
        else
        {
            if(d_setValue->isApply)
            {
                m_chartDataNum = d_setValue->chartDataNum;
                g_pCommunicate->m_nChartNum = m_chartDataNum;
                for(int i = 0; i < 20; i++)
                {
                    if (i >= m_chartDataNum)
                    {
                        m_Sign[i]->setVisible(false);
                        m_Check[i]->setVisible(false);
                        m_Value[i]->setVisible(false);
                        continue;
                    }

                    m_chartData[i].vid = d_setValue->m_chartData[i].vid;
                    memcpy(m_chartData[i].name, d_setValue->m_chartData[i].name, name_SIZE);
                    memcpy(m_chartData[i].unit, d_setValue->m_chartData[i].unit, unit_SIZE);
                    m_chartData[i].factor = d_setValue->m_chartData[i].factor;
                    m_chartData[i].offset = d_setValue->m_chartData[i].offset;
                    m_chartData[i].color = d_setValue->m_chartData[i].color;
                    m_chartData[i].relevance = d_setValue->m_chartData[i].relevance;

                    g_pCommunicate->m_nChartVids[i] = m_chartData[i].vid;

                    m_Sign[i]->setText(m_chartData[i].name);
                    m_Sign[i]->setVisible(true);
                    m_Check[i]->setVisible(true);
                    m_Value[i]->setVisible(true);
                }
                m_chartCfg = d_setValue->m_chartCfg;
                dataRateTimer->setInterval(m_chartCfg.ref_rate);//重设定时器
                if(m_chartCfg.ref_rate < 1000)
                {
                    refreshRateTimer->setInterval(1000);
                }
                else
                {
                    refreshRateTimer->setInterval(m_chartCfg.ref_rate);
                }
            }
        }
        break;
    case 4:// Zoom in push button
        if(!isZoom)
        {
            m_zoomEndTime = m_timeStamps[m_currentIndex - 1];
            m_zoomStartTime = m_zoomEndTime - (m_zoomEndTime - m_timeStamps[0]) / 2;
        }
        else
        {
            if(isFollow)
            {
                m_zoomEndTime = m_timeStamps[m_currentIndex - 1];;
                if((m_zoomEndTime - m_zoomStartTime) < 60)
                {
                    m_zoomStartTime = m_zoomEndTime - 30;
                }
                else
                {
                    m_zoomStartTime = m_zoomEndTime - (m_zoomEndTime - m_zoomStartTime) / 2;
                }
            }
            else
            {
                if((m_zoomEndTime - m_zoomStartTime) < 60)
                {
                    m_zoomStartTime = m_zoomStartTime + (m_zoomEndTime - m_zoomStartTime) / 2 - 15;
                    m_zoomEndTime = m_zoomStartTime + (m_zoomEndTime - m_zoomStartTime) / 2 + 15;;
                }
                else
                {
                    m_zoomStartTime = m_zoomStartTime + (m_zoomEndTime - m_zoomStartTime) / 4;
                    m_zoomEndTime = m_zoomEndTime - (m_zoomEndTime - m_zoomStartTime) / 4;
                }
            }
        }
        m_zoomDiffTime = m_zoomEndTime - m_zoomStartTime;
        isZoom = true;
        drawChart();
        break;
    case 5:// Zoom out push button
        if(isFollow)
        {
            m_zoomEndTime = m_timeStamps[m_currentIndex - 1];
            m_zoomStartTime = m_zoomStartTime * 2 - m_zoomEndTime;
            if(m_zoomStartTime < m_timeStamps[0])
            {
                m_zoomStartTime = m_timeStamps[0];
            }
        }
        else
        {
            m_zoomStartTime = m_zoomStartTime - (m_zoomEndTime - m_zoomStartTime) / 2;
            m_zoomEndTime = m_zoomEndTime + (m_zoomEndTime - m_zoomStartTime) / 2;
            if(m_zoomStartTime < m_timeStamps[0])
            {
                m_zoomStartTime = m_timeStamps[0];
            }
            if(m_zoomEndTime > m_timeStamps[m_currentIndex - 1])
            {
                m_zoomEndTime = m_timeStamps[m_currentIndex - 1];
            }
        }
        m_zoomDiffTime = m_zoomEndTime - m_zoomStartTime;
        isZoom = true;
        drawChart();
        break;
    case 6:// Return push button
        isZoom = false;
        drawChart();
        break;
    default:
        break;
    }
}

void UserPlot::onCheckClicked()
{
    drawChart();
}

void UserPlot::saveChartData()//保存绘图数据
{
    //选择保存绘图数据文件
    QString m_path = QFileDialog::getSaveFileName(this,
                  tr("Save DATA Files"),
                  "",
                  tr("DAT Files (*.dat);;CSV Files (*.csv)")); //选择路径

    QString suffix = m_path.right(m_path.size() - m_path.lastIndexOf("."));// .dat 或 .csv

    if(suffix == ".csv")
    {
        QFile file(m_path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("保存CSV文件失败！"), QMessageBox::Ok, this);
            msgBox.exec();
            return;
        }

        QString data = "";
        data += QString_C("时间");
        for(int i = 0; i < m_chartDataNum; i++)
        {
            data = data + "," + m_chartData[i].name;
        }
        data += "\n";

        if(file.write(data.toLocal8Bit()) == -1)
        {
            QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("写入CSV文件失败！"), QMessageBox::Ok, this);
            msgBox.exec();
            file.close();
            return;
        }

        for(int i = 0; i < m_currentIndex; i++)
        {
            //数据写入
            data = "";
            QDateTime dateTime;
            dateTime.setTime_t((UINT)(m_timeStamps[i] - 62135625600));
            data += QString::number(dateTime.date().year()) + "/";
            data += QString::number(dateTime.date().month()) + "/";
            data += QString::number(dateTime.date().day()) + " ";
            data += QString::number(dateTime.time().hour()) + ":";
            data += QString::number(dateTime.time().minute()) + ":";
            data += QString::number(dateTime.time().second()) + ":";
            data += QString::number((UINT)(m_timeStamps[i] * 1000) % 1000);

            for(int a = 0; a < m_chartDataNum; a++)
            {
                data += ",";
                data += QString::number((double)(m_dataSeries[a][i]), 'f', 3);
            }
            data += "\n";

            if(file.write(data.toLocal8Bit()) == -1)
            {
                QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("写入CSV文件失败！"), QMessageBox::Ok, this);
                msgBox.exec();
                file.close();
                return;
            }
        }

        file.close();
        QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("保存CSV文件成功！"), QMessageBox::Ok, this);
        msgBox.exec();
    }
    else if(suffix == ".dat")
    {
        QFile file(m_path);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("保存DAT文件失败！"), QMessageBox::Ok, this);
            msgBox.exec();
            return;
        }

        QByteArray byte_array;
        byte_array.clear();
        byte_array.append((char*)&m_currentIndex, sizeof(m_currentIndex));  // 当前数组的索引位置
        byte_array.append((char*)&sampleSize, sizeof(sampleSize));          // 数据尺寸
        byte_array.append((char*)&m_chartDataNum, sizeof(m_chartDataNum));  // 数据种类数
        byte_array.append((char*)&m_chartCfg, sizeof(m_chartCfg));          // 配置信息
        for(int i = 0; i < m_chartDataNum; i++)
        {
            byte_array.append((char*)&(m_chartData[i]), sizeof(m_chartData[i]));
        }
        for(int i = 0; i < m_currentIndex; i++)
        {
            byte_array.append((char*)&m_timeStamps.at(i), sizeof(m_timeStamps[i])); // 保存时间戳
            for(int a = 0; a < m_chartDataNum; a++)
            {
                double d = m_dataSeries[a][i];
                byte_array.append((char*)&d, sizeof(d));// 保存数据
            }
        }

        if(file.write(byte_array.data(), byte_array.size()) == -1)
        {
            QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("写入DAT文件失败！"), QMessageBox::Ok, this);
            msgBox.exec();
            file.close();
            return;
        }

        file.close();
        QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("保存DAT文件成功！"), QMessageBox::Ok, this);
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("保存文件错误！"), QMessageBox::Ok, this);
        msgBox.exec();
        return;
    }
}

bool UserPlot::openChartData()//打开绘图数据
{
    //选择打开绘图数据文件
    QString m_path = QFileDialog::getOpenFileName(this,
                  tr("Open DATA Files"),
                  "",
                  tr("DAT Files (*.dat)")); //选择路径

    QString suffix = m_path.right(m_path.size() - m_path.lastIndexOf("."));// .dat

    if(suffix == ".dat")
    {
        QFile file(m_path);
        if (!file.open(QIODevice::ReadOnly))
        {
            return false;
        }

        if(isRun)// Run
        {
            dataRateTimer->stop();
            refreshRateTimer->stop();
            buttonControl->button(0)->setIcon(QIcon(":/ioc/Start_greed.png"));
            buttonControl->button(0)->setText("Run");
            isRun = false;
        }

        Reset();//数据重置

        file.seek(0);
        if(file.read((char*)&m_currentIndex, sizeof(m_currentIndex)) == -1){file.close();return false;}  // 当前数组的索引位置
        if(file.read((char*)&sampleSize, sizeof(sampleSize)) == -1){file.close();return false;}          // 数据尺寸
        if(file.read((char*)&m_chartDataNum, sizeof(m_chartDataNum)) == -1){file.close();return false;}  // 数据种类数
        if(file.read((char*)&m_chartCfg, sizeof(m_chartCfg)) == -1){file.close();return false;}          // 配置信息
        for(int i = 0; i < m_chartDataNum; i++)
        {
            if(file.read((char*)&(m_chartData[i]), sizeof(m_chartData[i])) == -1){file.close();return false;}
        }
        for(int i = 0; i < m_currentIndex; i++)
        {
            if(file.atEnd())
            {
                file.close();
                return false;
            }

            double timeStamps;
            if(file.read((char*)&timeStamps, sizeof(timeStamps)) == -1){file.close();return false;}// 打开时间戳
            if(i < m_timeStamps.size())
            {
                m_timeStamps[i] = timeStamps;
            }
            else
            {
                m_timeStamps.append(timeStamps);
            }

            for(int a = 0; a < m_chartDataNum; a++)
            {
                double dataSeries;
                if(file.read((char*)&dataSeries, sizeof(dataSeries)) == -1){file.close();return false;}// 打开数据
                if(i < m_dataSeries[a].size())
                {
                    m_dataSeries[a][i] = dataSeries;
                }
                else
                {
                    m_dataSeries[a].append(dataSeries);
                }
            }
        }
        qDebug() << "file.close()";
        file.close();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Warning, QString_C("警告"), QString_C("打开文件错误！"), QMessageBox::Ok, this);
        msgBox.exec();
        return false;
    }
    return true;
}

void UserPlot::onUpdatePeriodChanged(QString text)//更改图表更新周期
{

}

void UserPlot::updateChart()//更新图表
{
    m_ChartViewer->updateViewPort(true, false);
}

void UserPlot::drawChart()//绘制图表
{
    // Create an XYChart object 700 x 270 pixels in size, with light grey (f4f4f4)
    // background, black (000000) border, 1 pixel raised effect, and with a rounded frame.
    XYChart *c = new XYChart(1000, 680, 0xf4f4f4, 0x000000, 1);
    QColor bgColor = palette().color(backgroundRole()).rgb();
    c->setRoundedFrame((bgColor.red() << 16) + (bgColor.green() << 8) + bgColor.blue());

    // Set the plotarea at (55, 55) and of size 590 x 185 pixels. Use white (ffffff)
    // background. Enable both horizontal and vertical grids by setting their colors to
    // grey (cccccc). Set clipping mode to clip the data lines to the plot area.
    c->setPlotArea(55, 55, 890, 600, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);
    c->setClipping();

    // Add a title to the chart using 15 pts Times New Roman Bold Italic font, with a light
    // grey (dddddd) background, black (000000) border, and a glass like raised effect.
    c->addTitle("Real-time Data Curves", "timesbi.ttf", 15
        )->setBackground(0xdddddd, 0x000000, Chart::glassEffect());

    // Set the reference font size of the legend box
    c->getLegend()->setFontSize(8);

    // Configure the y-axis with a 10pts Arial Bold axis title
    c->yAxis()->setTitle(m_chartCfg.yAxis1, "arialbd.ttf", 10);

    // Configure the y-axis with a 10pts Arial Bold axis title
    c->yAxis2()->setTitle(m_chartCfg.yAxis2, "arialbd.ttf", 10);

    // Configure the x-axis to auto-scale with at least 75 pixels between major tick and
    // 15  pixels between minor ticks. This shows more minor grid lines on the chart.
    c->xAxis()->setTickDensity(75, 15);

    // Set the axes width to 2 pixels
    c->xAxis()->setWidth(2);
    c->yAxis()->setWidth(2);

    // Now we add the data to the chart.
    double firstTime, endTime;
    if(isZoom &&
            (m_zoomStartTime >= m_timeStamps[0]) &&
            (m_zoomEndTime <= m_timeStamps[m_currentIndex - 1]))
    {
        if(isFollow)
        {
            firstTime = m_timeStamps[m_currentIndex - 1] - m_zoomDiffTime;
            endTime = m_timeStamps[m_currentIndex - 1];
        }
        else
        {
            firstTime = m_zoomStartTime;
            endTime = m_zoomEndTime;
        }
    }
    else
    {
        firstTime  = m_timeStamps[0];
        endTime = m_timeStamps[m_currentIndex - 1];
    }

    if (firstTime != Chart::NoValue)
    {
        // Set up the x-axis to show the time range in the data buffer
        c->xAxis()->setDateScale(firstTime, endTime);

        // Set the x-axis label format
        c->xAxis()->setLabelFormat("{value|hh:nn:ss}");

        // Create a line layer to plot the lines
        LineLayer *layer = c->addLineLayer();

        // The x-coordinates are the timeStamps.
        layer->setXData(DoubleArray(m_timeStamps.begin(), sampleSize));

        // 绘制曲线
        for(int i = 0; i < m_chartDataNum; i++)
        {
            if(!m_Check[i]->isChecked())
            {
                continue;
            }

            if(m_chartData[i].relevance == 0)
            {
                layer->addDataSet(DoubleArray(m_dataSeries[i].begin(), sampleSize), m_chartData[i].color, m_chartData[i].name);
            }
            else if(m_chartData[i].relevance == 1)
            {
                layer->addDataSet(DoubleArray(m_dataSeries[i].begin(), sampleSize), m_chartData[i].color, m_chartData[i].name)->setUseYAxis2();
            }
        }
    }

    // Include track line with legend. If the mouse is on the plot area, show the track
    // line with legend at the mouse position; otherwise, show them for the latest data
    // values (that is, at the rightmost position).
    trackLineLegend(c, m_ChartViewer->isMouseOnPlotArea() ? m_ChartViewer->getPlotAreaMouseX() :
        c->getPlotArea()->getRightX());

    // Set the chart image to the WinChartViewer
    delete m_ChartViewer->getChart();
    m_ChartViewer->setChart(c);
}

void UserPlot::onMouseMovePlotArea(QMouseEvent *)//鼠标跟踪
{
    trackLineLegend((XYChart *)m_ChartViewer->getChart(), m_ChartViewer->getPlotAreaMouseX());
    m_ChartViewer->updateDisplay();
}

void UserPlot::trackLineLegend(XYChart *c, int mouseX)//绘制鼠标跟踪位置信息
{
    // Clear the current dynamic layer and get the DrawArea object to draw on it.
    DrawArea *d = c->initDynamicLayer();

    // The plot area object
    PlotArea *plotArea = c->getPlotArea();

    // Get the data x-value that is nearest to the mouse, and find its pixel coordinate.
    double xValue = c->getNearestXValue(mouseX);
    int xCoor = c->getXCoor(xValue);

    // Draw a vertical track line at the x-position
    d->vline(plotArea->getTopY(), plotArea->getBottomY(), xCoor, d->dashLineColor(0x000000, 0x0101));

    // Container to hold the legend entries
    vector<string> legendEntries;

    // Iterate through all layers to build the legend array
    for (int i = 0; i < c->getLayerCount(); ++i) {
        Layer *layer = c->getLayerByZ(i);

        // The data array index of the x-value
        int xIndex = layer->getXIndexOf(xValue);

        // Iterate through all the data sets in the layer
        for (int j = 0; j < layer->getDataSetCount(); ++j) {
            DataSet *dataSet = layer->getDataSetByZ(j);

            // We are only interested in visible data sets with names
            const char *dataName = dataSet->getDataName();
            int color = dataSet->getDataColor();
            if (dataName && *dataName && (color != (int)Chart::Transparent)) {
                // Build the legend entry, consist of the legend icon, name and data value.
                double dataValue = dataSet->getValue(xIndex);
                ostringstream legendEntry;
                QByteArray dataName_byte = QString::fromLocal8Bit(dataName).toLocal8Bit();
                legendEntry << "<*block*>" << dataSet->getLegendIcon() << " " << dataName_byte.data() << ": " <<
                    ((dataValue == Chart::NoValue) ? "N/A" : c->formatValue(dataValue, "{value|P4}"))
                    << "<*/*>";
                legendEntries.push_back(legendEntry.str());

                // Draw a track dot for data points within the plot area
                int yCoor = c->getYCoor(dataSet->getPosition(xIndex), dataSet->getUseYAxis());
                if ((yCoor >= plotArea->getTopY()) && (yCoor <= plotArea->getBottomY())) {
                    d->circle(xCoor, yCoor, 4, 4, color, color);
                }
            }
        }
    }

    // Create the legend by joining the legend entries
    ostringstream legendText;
    legendText << "<*block,maxWidth=" << plotArea->getWidth() << "*><*block*><*font=arialbd.ttf*>["
        << c->xAxis()->getFormattedLabel(xValue, "hh:nn:ss") << "]<*/*>";
    for (int i = ((int)legendEntries.size()) - 1; i >= 0; --i)
        legendText << "        " << legendEntries[i];

    // Display the legend on the top of the plot area
    TTFText *t = d->text(legendText.str().c_str(), "arial.ttf", 8);
    //TTFText *t = d->text(tr("线损率曲线"), "simsun.ttc", 8);
    //TTFText *t = d->text(QTextCodec::codecForName("UTF-8")->fromUnicode("线损率曲线").constData(), "simhei.ttf", 8);
    //TTFText *t = d->text(legendText.str().c_str(), "simsun.ttc", 8);
    t->draw(plotArea->getLeftX() + 5, plotArea->getTopY() - 3, 0x000000, Chart::BottomLeft);
    t->destroy();
}

