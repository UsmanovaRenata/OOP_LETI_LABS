#include "graphwindow.h"
#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(OrientedGraph &graph, QWidget *parent) :
    QWidget(parent),
    graphp(graph),
     ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
    setFixedSize(500, 500);

}

void GraphWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    draw_circle(painter);
    painter.end();

}

void GraphWindow::draw_circle(QPainter& painter)
{
    int count = graphp.m->matrix.size();
    qreal angle = M_PI/count;
    qreal distance = 200;
    qreal centerX = 250;
    qreal centerY = 250;
    int radius = 50;
    for(int i = 0; i < count; i++){
        qreal newX = centerX + distance * cos(angle*i);
        qreal newY = centerY + distance * sin(angle*i);
        Circle newCircle;
        newCircle.id = i+1;
        newCircle.x = newX - radius;
        newCircle.y = newY - radius;
        newCircle.radius = radius;
        circles.push_back(newCircle);
    }

    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            if(QString(graphp.m->matrix[i][j]).toInt() > 0) {
                QPointF p1(circles[i].x + radius, circles[i].y + radius);
                QPointF p2(circles[j].x + radius, circles[j].y + radius);
                double angle = atan2(p2.y() - p1.y(), p2.x() - p1.x());
                p1 += QPointF(cos(angle) * radius, sin(angle) * radius);
                p2 -= QPointF(cos(angle) * radius, sin(angle) * radius);
                painter.drawLine(p1, p2);
                painter.drawEllipse(p2, 3, 3);
            }
        }
    }

    for (const auto& circle : circles) {
        painter.drawEllipse(circle.x, circle.y, 2*circle.radius, 2*circle.radius);
        QString idStr = QString::number(circle.id);
        QFont font;
        font.setPointSize(12);
        font.setWeight(QFont::Bold);
        painter.setFont(font);
        painter.drawText(circle.x + circle.radius, circle.y + circle.radius, idStr);
    }
}

GraphWindow::~GraphWindow()
{
    delete ui;

}

