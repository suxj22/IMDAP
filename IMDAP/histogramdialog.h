#ifndef HISTOGRAMDIALOG_H
#define HISTOGRAMDIALOG_H

#include <QDialog>
#include <QtCharts>

namespace Ui {
class HistogramDialog;
}

class HistogramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistogramDialog(QWidget *parent = nullptr);
    ~HistogramDialog();
    void setViewChart(QChartView *chartview);

private slots:

    // 导出和复制
    void on_exportImageButton_clicked();

    void on_copyToClipboardButton_clicked();

    // 直方图是否显示
    void on_HistogramCheckBox_stateChanged(int arg1);

    // 正态拟合曲线是否显示
    void on_SplineCheckBox_stateChanged(int arg1);

private:
    Ui::HistogramDialog *ui;
    QChartView *chartView;

};

#endif // HISTOGRAMDIALOG_H
