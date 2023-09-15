#ifndef LEGEND3D_H
#define LEGEND3D_H

#include <QWidget>
#include "QtDataVisualization/qscatter3dseries.h"


class Legend3D : public QWidget
{
    Q_OBJECT
public:
    explicit Legend3D(QWidget *parent = nullptr, QList <QScatter3DSeries*> seriesList = {});

    // 存储三维图表信息以绘制标签
    void setList (QList <QScatter3DSeries*> seriesList);
protected:
    // 三维聚类图标签绘制
    void paintEvent(QPaintEvent* event) override;

private:
    QList <QScatter3DSeries*> List;
};

#endif // LEGEND3D_H
