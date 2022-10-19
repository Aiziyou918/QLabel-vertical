#include "LabelRotate.h"

CLabelRotate::CLabelRotate(QWidget *parent, EmLabelState pState)
	: QLabel(parent)
{
	m_labelState = pState;
	if (isFirst && m_labelState == EmLabelState::VERTICAL)
	{
		m_width = rect().height();
		m_height = rect().width();
	}
	m_width = rect().width();
	m_height = rect().height();
}

CLabelRotate::~CLabelRotate()
{}

void CLabelRotate::paintEvent(QPaintEvent* event)
{
	QStylePainter painter(this);
	if (m_labelState == EmLabelState::VERTICAL)
	{
		painter.rotate(-90);
		painter.translate(-m_rect.width(), 0);
		painter.drawText(m_rect, alignment(), text());
		resize(m_rect.height(), m_rect.width());
		return QWidget::paintEvent(event);
	}
	painter.drawText(rect(), alignment(), text());
	return QWidget::paintEvent(event);
}


void CLabelRotate::resizeEvent(QResizeEvent* event)
{
	if (isFirst && m_labelState == EmLabelState::VERTICAL)
	{
		m_rect = rect();
		isFirst = false;
		return QWidget::resizeEvent(event);
	}

	return QWidget::resizeEvent(event);
}