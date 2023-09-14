#ifndef CHARTVIEWDIALOG_H
#define CHARTVIEWDIALOG_H

#include <QDialog>
#include <QtCharts>

namespace Ui {
class ChartViewDialog;
}

class ChartViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChartViewDialog(QWidget *parent = nullptr, QChartView * chartview = nullptr);
    ~ChartViewDialog();
    void setViewChart(QChartView *chartView);
    void showNumOfDuplicatePoints(int num); // 显示重复的点数
    void setValueLabel(int num, float p, float r2); // 显示需要显示的值

private slots:
    void on_exportImageButton_clicked(); // 导出图像

    void on_copyToClipboardButton_clicked(); // 复制图像到剪贴板

    void on_ScatterCheckBox_stateChanged(int arg1);

    void on_SplineCheckBox_stateChanged(int arg1);

    void handlePointHovered(const QPointF &point, bool state);

private:
    Ui::ChartViewDialog *ui;
    QChartView *chartView; // 存储绘出的图像
};

#endif // CHARTVIEWDIALOG_H
