#ifndef USERPLOT_H
#define USERPLOT_H

#include <QDialog>
#include <QDateTime>
#include <QTimer>
#include <QLabel>
#include <QCheckBox>
#include "qchartviewer.h"

#include "setvaluedialog.h"

#define MAX_DATA_NUM 20

// The number of samples per data series used in this demo
static quint64 sampleSize = 100;

class UserPlot : public QDialog
{
    Q_OBJECT
public:
    explicit UserPlot(QWidget *parent = 0);
    ~UserPlot();

private:
    void Reset();//数据重置
    void keyPressEvent(QKeyEvent * e);//键盘事件
    void closeEvent(QCloseEvent *event);//关闭事件

    void saveChartData();//保存绘图数据
    bool openChartData();//打开绘图数据

    bool isRun = false;
    QButtonGroup *buttonControl;
    int m_currentIndex;                 // 当前数组的索引位置
    //double m_timeStamps[sampleSize];	// 数据时间戳
    QVector<double> m_timeStamps;
    QDateTime m_nextDataTime;        // 下一个数据时间
    bool isZoom = false;
    bool isFollow = true;
    double m_zoomStartTime;       // 缩放起始数据时间
    double m_zoomEndTime;         // 缩放结束数据时间
    double m_zoomDiffTime;        // 缩放起始结束相差时间

    //QVector<QString> *m_Sign;
    QLabel *m_Sign[MAX_DATA_NUM];
    QLabel *m_Value[MAX_DATA_NUM];
    QCheckBox *m_Check[MAX_DATA_NUM];
    //double m_dataSeries[MAX_DATA_NUM][sampleSize];  // 绘图数据
    QVector<QVector<double>> m_dataSeries;  // 绘图数据
    int m_chartDataNum = 0;
    ChartData m_chartData[MAX_DATA_NUM];            // 绘图数据信息
    ChartCfg m_chartCfg;

    void LoadVariables();//加载变量
    void SaveVariables();//保存变量

    SetValueDialog* d_setValue;

    QChartViewer *m_ChartViewer;        // QChartViewer control
    QTimer *dataRateTimer;
    QTimer *refreshRateTimer;

    void trackLineLegend(XYChart *c, int mouseX);   // Draw Track Cursor

public:
    void getData(double dataA, double dataB, double dataC, double dataD);// Get new data values

private slots:
    void onButtonChanged(int);                      // The "Run" or "Freeze" or "Set" button has been pressed
    void onCheckClicked();
    void onUpdatePeriodChanged(QString);            // The chart update timer interval has changed.
    void onMouseMovePlotArea(QMouseEvent *event);   // Mouse move on plot area
    void setData(double* data, int data_size);      //设置数据加入实时数据
    void getData();                                 //获取数据加入实时数据
    void updateChart();                             // Update the chart.
    void drawChart();                               // Draw chart

};

#endif // USERPLOT_H
