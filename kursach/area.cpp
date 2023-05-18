#include "area.h"

Area::Area(QWidget *parent): QGraphicsView(parent)
{
    L = 800;
    W = 600;
    scene = new QGraphicsScene(0, 0, L, W, parent);
    scene_params();
    animation = new QTimer(this);
    connect(animation, SIGNAL(timeout()), scene, SLOT(advance()));
    animation->start(1000/60);
    QPointF startPos(L / 2, W / 2);
    ball = new Ball(L, W, startPos);
    scene->addItem(ball);
}

Area::~Area()
{
    delete scene;
    delete ball;
}

QGraphicsScene *Area::getScene()
{
    return scene;
}

qreal Area::getL()
{
    return L+3;
}

qreal Area::getW()
{
    return W+3;
}

void Area::reset()
{
    QPointF startPos(L / 2, W / 2);
    ball->reset(startPos);
    animation->stop();
}

void Area::keep_move()
{
    animation->start(1000/60);
}

void Area::scene_params()
{
    QPen myPen = QPen(Qt::red);
    myPen.setWidth(2);
    scene->addRect(scene->sceneRect(), myPen);
}

void Area::updateBallParameters(qreal radius, qreal speed, qreal angle) {

    ball->update_params(radius,speed,angle);
    reset();

}
