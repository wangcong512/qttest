#include "background.h"

BackGround::BackGround(QWidget *parent) : QWidget(parent)
{

}

void BackGround::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setPen(Qt::red);
    paint.drawLine(0,50,50,50);

}

void BackGround::init()
{

}
