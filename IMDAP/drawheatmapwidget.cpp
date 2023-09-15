#include "drawheatmapwidget.h"
#include <QPainter>
#include <QLinearGradient>

DrawHeatmapWidget::DrawHeatmapWidget(QWidget *parent) : QWidget(parent)
{

}

void DrawHeatmapWidget::setMode(bool flag) {
    isDataCov = flag;
}
void DrawHeatmapWidget::setDataCov(const QVector<QVector<float>> &newData) {
    dataCov = newData;
    minValue = dataCov[0][0];
    maxValue = dataCov[0][0];
    for (const auto& row : dataCov) {
        for (float val : row) {
            if (val < minValue) minValue = val;
            if (val > maxValue) maxValue = val;
        }
    }
    interval = (maxValue - minValue) / numIntervals;
    if (isDataCov) {
        update(); // 重画热图
    }
}

void DrawHeatmapWidget::setDataPer(const QVector<QVector<float>> &newData) {
    dataPer = newData;
    if (!isDataCov) {
        update();
    }
}

void DrawHeatmapWidget::setLabels(const QStringList &labels) {
    xLabels = labels;
}
void DrawHeatmapWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);

    // 定义热图、标签、刻度尺的大小
    int margin = 30; // 预留30像素的空间来绘制标签
    int colorBarWidth = width() * 0.05;
    int colorBarTextWidth = width() * 0.10;
    int colorBarSpacing = width() * 0.05;
    int colorBarX = width() - colorBarWidth - colorBarTextWidth;
    int cellWidth = (width() - colorBarWidth - margin - colorBarTextWidth - colorBarSpacing) / dataCov[0].size();
    int cellHeight = (height() - margin) / dataCov.size();
    int colorBarHeight = dataCov.size() * cellHeight;

    QFont font = painter.font();
    font.setPointSize(15); // 选择合适的字体大小
    painter.setFont(font);


    if (isDataCov) {
        painter.setPen(Qt::black);
        for (int i = 0; i < dataCov.size(); i++) {
            for (int j = 0; j < dataCov[i].size(); j++) {
                double value = dataCov[i][j];
                QColor cellColor = getColorForValue(value);
                auto startX = j * cellWidth + margin;
                auto startY = i * cellHeight;
                painter.fillRect(startX, startY, cellWidth, cellHeight, cellColor);

                // 绘制热图的每个区块
                QString cellValueStrint = QString::number(value, 'f', 2); // 2个小数位
                painter.drawText(startX,
                                 startY,
                                 cellWidth,
                                 cellHeight,
                                 Qt::AlignCenter,
                                 cellValueStrint);
            }
        }
    }
    else {
        painter.setPen(Qt::white);
        for (int i = 0; i < dataCov.size(); i++) {
            for (int j = 0; j < dataPer[i].size(); j++) {
                double value = dataPer[i][j];
                QColor cellColor = getColorForValue(value);
                auto startX = j * cellWidth + margin;
                auto startY = i * cellHeight;
                painter.fillRect(startX, startY, cellWidth, cellHeight, cellColor);

                // 绘制热图的每个区块
                QString cellValueStrint = QString::number(value, 'f', 2); // 2个小数位
                painter.drawText(startX,
                                 startY,
                                 cellWidth,
                                 cellHeight,
                                 Qt::AlignCenter,
                                 cellValueStrint);
            }
        }
    }

    // 绘制刻度尺
    int segments = 100; // 颜色区块总数
    float segmentHeight = static_cast<double>(colorBarHeight) / segments;

    if (isDataCov) {
        for (int i = 0; i < segments; i++) {
            float value = maxValue - static_cast<float>(i) * interval;
            QColor segmentColor = getColorForValue(value);
            int yStart = static_cast<int>(i * segmentHeight);
            int yEnd = static_cast<int>((i + 1) * segmentHeight);
            painter.fillRect(colorBarX, yStart, colorBarWidth, yEnd - yStart, segmentColor);
        }
    }
    else {
        float interval = 2.0 / segments;  // 因为范围是[-1, 1]
        for (int i = 0; i < segments; i++) {
            float value = 1 - static_cast<float>(i) * interval;  // 从1到-1
            QColor segmentColor = getColorForValue(value);
            int yStart = static_cast<int>(i * segmentHeight);
            int yEnd = static_cast<int>((i + 1) * segmentHeight);
            painter.fillRect(colorBarX, yStart, colorBarWidth, yEnd - yStart, segmentColor);
        }
    }

    // 绘制刻度说明
    painter.setPen(Qt::black); // 设置字体颜色为黑色
    int numberOfLabels = 10;
    float labelValueStep, labelValueStart;
    if (isDataCov) {
        labelValueStart = maxValue;
        labelValueStep = (maxValue - minValue) / numberOfLabels;
    }
    else {
        labelValueStart = 1.0;  // dataPer的最大值
        labelValueStep = 2.0 / numberOfLabels;  // 由于范围是[-1,1]
    }

    for (int i = 0; i <= numberOfLabels; i++) {
        float labelValue = labelValueStart - i * labelValueStep;
        QString labelText = QString::number(labelValue, 'f', 2);

        int textY;
        if (i == 0) {
            textY = painter.fontMetrics().height(); // 最上方的文字稍微下移，以显示完全
        } else if (i == numberOfLabels) {
            textY = colorBarHeight - painter.fontMetrics().descent(); // 最下方的文字稍微上移，已显示完全
        } else {
            textY = i * (colorBarHeight / numberOfLabels);
        }

        painter.drawText(colorBarX + colorBarWidth + 5,
                         textY,
                         labelText);
    }
    QFontMetrics fm(painter.font());
    QStringList yLabels = xLabels;

        // 绘制x轴的标签
        for (int i = 0; i < xLabels.size(); i++) {
            int textWidth = fm.horizontalAdvance(xLabels[i]);
            int x = i * cellWidth + (cellWidth - textWidth) / 2;
            int y = height() - margin + 20;
            painter.drawText(x + margin, y, xLabels[i]);
        }

        // 绘制y轴的标签
        for (int i = 0; i < yLabels.size(); i++) {
            int temp = i;
            int textHeight = fm.height();
            int x = margin - textHeight;
            int textWidth = fm.horizontalAdvance(yLabels[temp]);
            int y = i * cellHeight + (cellHeight + textWidth) / 2;

            painter.save();  // 保存painter当前的状态
            painter.translate(x, y);  // 将painter移动到文本的起始点
            painter.rotate(-90);  // 旋转painter
            painter.drawText(0, 0, yLabels[temp]);  // 在旋转后的位置绘制文本
            painter.restore();  // 恢复painter到平移和旋转之前的状态
        }
}

QColor DrawHeatmapWidget::getColorForValue(float value) const {
    if(isDataCov) {
        float resultValue = 1 - (value - minValue) / (maxValue - minValue);
        return QColor(255, 255 * resultValue, 255 * resultValue);
    }
    else {
        float mappedValue = (value + 1) / 2.0; // 建立[-1, 1]到[0, 1]的映射
        // 从蓝色渐变为红色
        int redComponent = static_cast<int>(255 * mappedValue);
        int blueComponent = 255 - redComponent;
        return QColor(redComponent, 0, blueComponent);
    }
}
