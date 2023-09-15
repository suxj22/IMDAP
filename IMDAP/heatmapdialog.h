#ifndef HEATMAPDIALOG_H
#define HEATMAPDIALOG_H

#include <QDialog>
#include "drawheatmapwidget.h"

namespace Ui {
class HeatmapDialog;
}

class HeatmapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HeatmapDialog(QWidget *parent = nullptr);
    ~HeatmapDialog();
    void setDataCov(const QVector<QVector<float>> &data); // 协方差矩阵
    void setDataPer(const QVector<QVector<float>> &data); // 相关性矩阵
    void setLabels(const QStringList &names); // 设置标签

private slots:
    // 互斥的两个按钮，由用户决定绘制需要绘制的图像
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    // 导出的图像
    void on_exportButton_clicked();

    void on_copyButton_clicked();

private:
    Ui::HeatmapDialog *ui;
};

#endif // HEATMAPDIALOG_H
