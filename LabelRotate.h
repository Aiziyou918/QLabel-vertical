#pragma once

#include <QLabel>
#include <QStylePainter>

enum class EmLabelState:char {HORIZONTAL, VERTICAL};

class CLabelRotate : public QLabel
{
	Q_OBJECT

public:
	CLabelRotate(QWidget *parent, EmLabelState pState);
	~CLabelRotate();
	int LabelHeight() { return m_height; };
	int LabelWidth() { return m_width; };

private:
	bool isFirst = true;
	int m_height, m_width;
	EmLabelState m_labelState;
	QRect m_rect;
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);
};
