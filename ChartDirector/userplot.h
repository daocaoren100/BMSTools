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
    void Reset();//��������
    void keyPressEvent(QKeyEvent * e);//�����¼�
    void closeEvent(QCloseEvent *event);//�ر��¼�

    void saveChartData();//�����ͼ����
    bool openChartData();//�򿪻�ͼ����

    bool isRun = false;
    QButtonGroup *buttonControl;
    int m_currentIndex;                 // ��ǰ���������λ��
    //double m_timeStamps[sampleSize];	// ����ʱ���
    QVector<double> m_timeStamps;
    QDateTime m_nextDataTime;        // ��һ������ʱ��
    bool isZoom = false;
    bool isFollow = true;
    double m_zoomStartTime;       // ������ʼ����ʱ��
    double m_zoomEndTime;         // ���Ž�������ʱ��
    double m_zoomDiffTime;        // ������ʼ�������ʱ��

    //QVector<QString> *m_Sign;
    QLabel *m_Sign[MAX_DATA_NUM];
    QLabel *m_Value[MAX_DATA_NUM];
    QCheckBox *m_Check[MAX_DATA_NUM];
    //double m_dataSeries[MAX_DATA_NUM][sampleSize];  // ��ͼ����
    QVector<QVector<double>> m_dataSeries;  // ��ͼ����
    int m_chartDataNum = 0;
    ChartData m_chartData[MAX_DATA_NUM];            // ��ͼ������Ϣ
    ChartCfg m_chartCfg;

    void LoadVariables();//���ر���
    void SaveVariables();//�������

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
    void setData(double* data, int data_size);      //�������ݼ���ʵʱ����
    void getData();                                 //��ȡ���ݼ���ʵʱ����
    void updateChart();                             // Update the chart.
    void drawChart();                               // Draw chart

};

#endif // USERPLOT_H
