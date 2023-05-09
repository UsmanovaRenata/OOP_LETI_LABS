#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include"orientedgraph.h"
#include <QPainter>
namespace Ui {
class GraphWindow;
}
struct Circle {
    int id;
    qreal x;
    qreal y;
    qreal radius;
};

class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWindow(OrientedGraph &graph, QWidget *parent = nullptr);
    ~GraphWindow();
    void draw_circle(QPainter &painter);

private:
    void paintEvent(QPaintEvent *event) ;
    OrientedGraph graphp;
    Ui::GraphWindow *ui;
    std::vector<Circle> circles;

};

#endif // GRAPHWINDOW_H
