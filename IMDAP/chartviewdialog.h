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
    explicit ChartViewDialog(QWidget *parent = nullptr);
    ~ChartViewDialog();
    void setViewChart(QChartView *charView);
    void showNumOfDuplicatePoints(int num); // 显示重复的点数

private slots:
    void on_exportImageButton_clicked(); // 导出图像

    void on_copyToClipboardButton_clicked(); // 复制图像到剪贴板

private:
    Ui::ChartViewDialog *ui;
    QChartView *chartView; // 存储绘出的图像
};

#endif // CHARTVIEWDIALOG_H
