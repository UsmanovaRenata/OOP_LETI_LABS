#include "ball.h"

Ball::Ball(qreal areaWidth, qreal areaHeight, QPointF startPos, QGraphicsItem *parent)
    : QGraphicsEllipseItem(parent), areaWidth(areaWidth), areaHeight(areaHeight)
{
    R = 25;
    V = 20;
    A = 45;
    reset(startPos);
}

void Ball::reset(QPointF startPos)
{
    setBrush(Qt::red);
    setRect(QRectF(-R, -R, 2 * R, 2 * R));
    setPos(startPos);
}

void Ball::advance(int phase)
{
    qreal dx = V * cos(A * M_PI / 180);
    qreal dy = V * sin(A * M_PI / 180);
    moveBy(dx, dy);

    if (pos().x() - R < 0 || pos().x() + R > areaWidth)
    {

        A = 180 - A;
    }

    if (pos().y() - R < 0 || pos().y() + R > areaHeight)
    {

        A = -A;
    }
}

void Ball::update_params(qreal radius, qreal speed, qreal angle)
{
    R = radius;
    V = speed;
    A = angle;
}
