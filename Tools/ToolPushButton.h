#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QBitmap>
#include <QPixmap>

class ToolPushButton : public QPushButton
{
	Q_OBJECT

public:
    ToolPushButton(QWidget *parent);
    ~ToolPushButton();

public:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void setMask(QString filepath);
signals:
	void signalMouseMove(QMouseEvent *e);
	void signalPressPoint(QMouseEvent *e);
	void signalReleasePoint(QMouseEvent *e);
};

#endif // MYPUSHBUTTON_H
