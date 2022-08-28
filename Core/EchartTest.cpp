#include <QWebElement>
#include <QWebFrame>
#include "EChartTest.h"

EChartTest::EChartTest(QObject* parent)
    : QObject(parent)
{
	m_nBaseData = 0;
	m_value = 10;
	pwebview = NULL;
}

EChartTest::~EChartTest()
{
}

QString EChartTest::GetValue()
{
	QString str = QString::number(m_value);
	return str;
	//QString str = "value: " + QString::number(m_value) + ", name: " + QString_C("\'母线电压\'");
	//QStringList lst;	
	//lst << str;
	/*str = "name: " + QString_C("母线电压");
	lst << str;*/
	//return lst;
}

void EChartTest::SetValue(int value)
{
	m_value = value;
}

void EChartTest::PageReload()
{
	QWebView * widget = (QWebView*)pwebview;
	if (widget == NULL)	
		return;
	widget->reload();
}

QStringList EChartTest::GetMaxValue()
{
	QTime t = QTime::currentTime();
	QStringList lst;
	for (int i = 0; i < 7; i++)
	{
		lst << QString::number(m_nBaseData + + 30 + i%4*10 );
	}
	return lst;
}

QStringList EChartTest::GetMinValue()
{
	QTime t = QTime::currentTime();
	QStringList lst;
	for (int i = 0; i < 7; i++)
	{
		lst << QString::number(m_nBaseData + i % 3 * 10);
	}
	return lst;
}

void EChartTest::submit()
{
	QWebView * widget = (QWebView*)pwebview;
	if (widget == NULL)	
		return;

	QWebFrame *frame = widget->page()->mainFrame();
	QWebElement firstName = frame->findFirstElement("#basedata");
	m_nBaseData = firstName.evaluateJavaScript("this.value").toInt();
	widget->reload();
}
