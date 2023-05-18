#ifndef AREA_H
#define AREA_H
#include <QGraphicsView>
#include<QGraphicsScene>
#include <QWidget>
#include<QTimer>
#include"ball.h"
#include"parametersdialog.h"
class Area : public QGraphicsView
{
public:
     Area(QWidget *parent = 0);
    ~Area();
     QGraphicsScene* getScene();
     qreal getL();
     qreal getW();
     void reset();
     void keep_move();
     void updateBallParameters(qreal radius, qreal speed, qreal angle);
private:
    qreal L;
    qreal W;
    QGraphicsScene *scene;
    void scene_params();
    Ball *ball;
    QTimer *animation;
};

#endif // AREA_H
