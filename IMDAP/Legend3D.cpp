#include "Legend3D.h"
#include <QPainter>
#include <QLinearGradient>

Legend3D::Legend3D(QWidget *parent, QList<QScatter3DSeries *> seriesList)
    : QWidget{parent}
{
    List = seriesList;
}

void Legend3D::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event)
    QPainter painter(this);

    // 绘制图例
    int y = 10;
    for (auto series : List) {
        painter.setBrush(series->baseColor());
        painter.setPen(Qt::NoPen);
        painter.drawRect(10, y, 20, 20);
        painter.setPen(Qt::black);
        painter.drawText(40, y + 15, series->name());
        y += 30; // Adjust spacing as needed
    }
}

void Legend3D::setList(QList <QScatter3DSeries*> seriesList) {
    List = seriesList;
}
