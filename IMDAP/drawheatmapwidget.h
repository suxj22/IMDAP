#ifndef DRAWHEATMAPWIDGET_H
#define DRAWHEATMAPWIDGET_H

#include <QWidget>
#include <QVector>

class DrawHeatmapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DrawHeatmapWidget(QWidget *parent = nullptr);
    void setDataCov(const QVector<QVector<float>> &data); // 设置dataCov值
    void setDataPer(const QVector<QVector<float>> &data); // 设置dataPer值
    void setLabels(const QStringList &labels); // 设置标签值
    void setMode(bool); // 设置图表模式
protected:
    void paintEvent(QPaintEvent *event) override; // 重写绘画函数

private:
    QColor getColorForValue(float value) const; // 输入值返回颜色
    QVector<QVector<float>> dataCov;
    QVector<QVector<float>> dataPer;
    float minValue; // data最小值
    float maxValue; // data最大值
    float interval; // 间隔值
    int numIntervals = 100; // 间隔数量
    QStringList xLabels; // x坐标标签
    bool isDataCov = true; // 当前绘制的图像
};

#endif // DRAWHEATMAPWIDGET_H
