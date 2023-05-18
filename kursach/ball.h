#ifndef BALL_H
#define BALL_H
#include<QGraphicsItem>
#include <QPainter>

class Ball : public QGraphicsEllipseItem
{
public:
    Ball(qreal areaWidth, qreal areaHeight, QPointF startPos, QGraphicsItem *parent = nullptr);

    void reset(QPointF startPos);
    void advance(int phase);
    void update_params(qreal radius, qreal speed, qreal angle);
private:
    qreal R;
    qreal V;
    qreal A;
    qreal areaWidth;
    qreal areaHeight;
};
#endif // BALL_H
