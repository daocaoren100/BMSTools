#ifndef EChartTest_H
#define EChartTest_H

#include <QFutureWatcher>
#include <QtWidgets>
#include <QtWebKitWidgets/QWebView>

class EChartTest : public QObject
{
    Q_OBJECT
public:
    EChartTest(QObject * parent=0);
	~EChartTest();

	QWebView * pwebview;

public slots:
	QStringList GetMaxValue();
	QStringList GetMinValue();
	void submit();
	QString GetValue();
	void SetValue(int value);
	void PageReload();

private:
	int m_nBaseData;
	int m_value;
};

#endif
