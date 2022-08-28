#ifndef ROUNDMETERREADOUT_H
#define ROUNDMETERREADOUT_H

#include <QWidget>
#include <QTimer>
#include "qchartviewer.h"

enum MeterType {
    VOLT,
    CURR,
    SOC
};

class RoundMeterReadout : public QWidget
{
    Q_OBJECT
public:
    explicit RoundMeterReadout(QWidget *parent = 0);
    void Init(MeterType t);
    ~RoundMeterReadout();

private:
    QChartViewer *m_PointerChartViewer;         // Pointer QChartViewer control
    QChartViewer *m_MeterChartViewer;           // Meter QChartViewer control
    QTimer *m_ChartUpdateTimer;                 // The chart update timer

    MeterType m_type;
    double m_Pvalue;
    int m_size;
    int m_mainColor;

    //数据范围
    double minData;
    double maxData;
    double major;
    double minor;
    double micro;

public:
    AngularMeter* roundmeterreadout();//电压表

    double m_value;

signals:

private slots:
    void updateChart();                             // Update the chart.
    void drawChart();                       // Draw chart
};

#endif // ROUNDMETERREADOUT_H
