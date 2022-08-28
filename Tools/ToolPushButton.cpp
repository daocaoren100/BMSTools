#include "ToolPushButton.h"
#include <QDebug>
ToolPushButton::ToolPushButton(QWidget *parent)
	: QPushButton(parent)
{
	//setAttribute(Qt::WA_TransparentForMouseEvents);
	setAttribute(Qt::WA_TranslucentBackground, true);	
}

ToolPushButton::~ToolPushButton()
{

}

void ToolPushButton::mouseMoveEvent(QMouseEvent *e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		emit signalMouseMove(e);
	}
	QPushButton::mouseMoveEvent(e);
}

void ToolPushButton::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
	{
		emit signalPressPoint(e);
	}
	QPushButton::mousePressEvent(e);
	
}

void ToolPushButton::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
	{
		emit signalReleasePoint(e);
	}
	QPushButton::mouseReleaseEvent(e);
}

void ToolPushButton::setMask(QString filepath)
{
	QPixmap pixmap(filepath);

	QPushButton::setMask(pixmap.mask());
}

