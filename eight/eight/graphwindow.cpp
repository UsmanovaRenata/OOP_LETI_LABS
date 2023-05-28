#include "graphwindow.h"
#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(StateGraph &graph, QWidget *parent) :
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
    repaint();
    draw_circle(painter);
    painter.end();

}

void GraphWindow::draw_circle(QPainter& painter)
{
    for (int i = 0; i < circles.size(); i++) {
          Circle circle = circles[i];
          bool isActiveNode = (circle.id == graphp.active);

          // Отрисовка вершины
          painter.setPen(isActiveNode ? Qt::red : Qt::black);
          painter.drawEllipse(circle.x, circle.y, 2 * circle.radius, 2 * circle.radius);

          // Отрисовка номера вершины
          QString idStr = QString::number(circle.id);
          QFont font;
          font.setPointSize(12);
          font.setWeight(QFont::Bold);
          painter.setFont(font);
          painter.drawText(circle.x + circle.radius, circle.y + circle.radius, idStr);
      }

      // Отрисовка ребер
      for (int i = 0; i < circles.size(); i++) {
          for (int j = 0; j < circles.size(); j++) {
              if (QString(graphp.m->matrix[i][j]).toInt() > 0) {
                  Circle startCircle = circles[i];
                  Circle endCircle = circles[j];
                  QPointF p1(startCircle.x + startCircle.radius, startCircle.y + startCircle.radius);
                  QPointF p2(endCircle.x + endCircle.radius, endCircle.y + endCircle.radius);
                  double angle = atan2(p2.y() - p1.y(), p2.x() - p1.x());
                  p1 += QPointF(cos(angle) * startCircle.radius, sin(angle) * startCircle.radius);
                  p2 -= QPointF(cos(angle) * endCircle.radius, sin(angle) * endCircle.radius);
                  painter.setPen(Qt::black);
                  painter.drawLine(p1, p2);
                  painter.setBrush(Qt::black);
                  painter.setPen(Qt::black);
                  painter.drawEllipse(p2, 3, 3);
              }
          }
      }

}

void GraphWindow::repaint()
{
    circles.clear();
        int count = graphp.m->matrix.size();

        qreal angle = 2 * M_PI / count;
        qreal distance = 200;
        qreal centerX = width() / 2;
        qreal centerY = height() / 2;
        int radius = 50;

        for (int i = 0; i < count; i++) {
            qreal newX = centerX + distance * cos(angle * i);
            qreal newY = centerY + distance * sin(angle * i);
            Circle newCircle;
            newCircle.id = i + 1;
            newCircle.x = newX - radius;
            newCircle.y = newY - radius;
            newCircle.radius = radius;
            circles.push_back(newCircle);
        }


}

void GraphWindow::get_active(int active)
{
    graphp.active = active;
    update();
}

int GraphWindow::get_event(int eventNumber)
{
    if (eventNumber >= 0 && eventNumber < graphp.m->matrix.size()) {
        int activeNode = graphp.active - 1;

        // Получение информации о направлении ребер из матрицы смежности
        std::vector<std::vector<qint16>>& matrix = graphp.m->matrix;
        std::vector<qint16> outgoingEdges;

        for (int i = 0; i < matrix[activeNode].size(); i++) {
            if (QString(matrix[activeNode][i]).toInt() > 0) {
                outgoingEdges.push_back(i);
            }
        }

        if ((eventNumber - 1) < outgoingEdges.size()) {
            int newActiveNode = outgoingEdges[eventNumber - 1];
            get_active(newActiveNode + 1);
            return newActiveNode + 1;
        } else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Введен некорректный номер события."), QMessageBox::Ok);
            return -1;
        }

    }else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Введен некорректный номер события."), QMessageBox::Ok);
        return -1;
    }

}

GraphWindow::~GraphWindow()
{
    delete ui;

}

