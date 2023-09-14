#ifndef LEGEND3D_H
#define LEGEND3D_H

#include <QWidget>
#include "QtDataVisualization/qscatter3dseries.h"


class Legend3D : public QWidget
{
    Q_OBJECT
public:
    explicit Legend3D(QWidget *parent = nullptr, QList <QScatter3DSeries*> seriesList = {});
    void setList (QList <QScatter3DSeries*> seriesList);
protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QList <QScatter3DSeries*> List;
};

#endif // LEGEND3D_H
