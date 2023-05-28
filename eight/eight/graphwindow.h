#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include"stategraph.h"
#include <QPainter>
#include<QMessageBox>
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
    explicit GraphWindow(StateGraph &graph, QWidget *parent = nullptr);
    ~GraphWindow();
    void draw_circle(QPainter &painter);
    void repaint();
    void get_active(int active);
    int get_event(int eventNumber);

private:
    void paintEvent(QPaintEvent *event);
    StateGraph graphp;
    Ui::GraphWindow *ui;
    std::vector<Circle> circles;

};

#endif // GRAPHWINDOW_H
