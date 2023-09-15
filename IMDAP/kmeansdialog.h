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
    // 添加图表视图
    void addChartView(QWidget *view = nullptr);

private slots:

    // 导出和复制
    void on_export2DButton_clicked();

    void on_copy2DButton_clicked();

private:
    Ui::KMeansDialog *ui;

};

#endif // KMEANSDIALOG_H
