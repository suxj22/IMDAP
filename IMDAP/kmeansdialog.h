#ifndef KMEANSDIALOG_H
#define KMEANSDIALOG_H

#include "QtDataVisualization/q3dscatter.h"
#include <QDialog>
#include <QtCharts>
#include <QtDataVisualization>


namespace Ui {
class KMeansDialog;
}

class KMeansDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KMeansDialog(QWidget *parent = nullptr);
    ~KMeansDialog();
    void addChartView(QWidget *view = nullptr);
    void addChart(QChart * chart);
    void addChart(Q3DScatter * chart);

private slots:
    void on_export2DButton_clicked();

    void on_copy2DButton_clicked();

private:
    Ui::KMeansDialog *ui;

    QChart * Chart2D = nullptr;
    Q3DScatter * Chart3D = nullptr;
};

#endif // KMEANSDIALOG_H
