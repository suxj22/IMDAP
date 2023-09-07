#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Eigen/Dense"
#include "chartviewdialog.h"
#include "rowfeature.hpp"
#include "averageandmeandialog.h"
#include "selecttwocolumnsdialog.h"
#include "ui_chartviewdialog.h"
#include <vector>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, &QAction::triggered, this, &MainWindow::loadCSVFileToTableWidget);
    ui->textBrowser->setStyleSheet("QTextBrowser {"
                                 "background-color: white;"
                                 "border: 1px solid grey;"
                                 "}");
    /*ui->label->setStyleSheet("QLabel {"
                               "background-color: white;"
                               "border: 1px solid grey;"
                               "}");*/


}

void MainWindow::loadCSVFileToTableWidget() {
    QString filePath = ":/data/data/breast-cancer.csv";
    if (filePath == lastImportedFilePath) {
        QMessageBox::information(this, "提示", "请勿重复导入！");
        return;
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(","); // 逗号作为分隔符

            if (ui->tableWidget->columnCount() < fields.size()) {
                ui->tableWidget->setColumnCount(fields.size());  // 动态设置列数
            }

            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row); // 插入新行
            for (int i = 0; i < fields.size(); ++i) {
                QTableWidgetItem *newItem = new QTableWidgetItem(fields[i]);
                ui->tableWidget->setItem(row, i, newItem);
            }
        }
        float currentValue = 0;
        for (int j = 1; j < ui->tableWidget->rowCount(); j++) {
            QTableWidgetItem* item = ui->tableWidget->item(j, 1); // 假定第二列是种类
            if (item) {
                QString text = item->text();
                if (!discreteValueMap.contains(text)) {
                    discreteValueMap[text] = currentValue; // 存储映射
                    reverseValueMap[currentValue] = text; // 存储反向映射
                    QString pre = "文本中";
                    QString middle = "代表";
                    QString res = pre + text + middle + QString::number(static_cast<int>(currentValue)); // 存储映射关系
                    indexOfText.push_back(res);
                    currentValue++;
                }
            }
        }
        lastImportedFilePath = filePath;
        file.close();
    }
    else {
        QMessageBox::warning(this, "警告", "导入文件失败！");
    }
    return;
}
MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::tableWidgetIsEmpty() {
    if (ui->tableWidget->rowCount() == 0 || ui->tableWidget->columnCount() == 0) {
        return true;
    }
    else {
        return false;
    }
}

void MainWindow::tableEmptyWarning() {
    QMessageBox::warning(this, "警告", "未导入数据！");
    return;
}

QStringList MainWindow::GetColumnNames() {
    QStringList names;
    for (int i = 1; i < ui->tableWidget->columnCount(); i++) {
        QTableWidgetItem *item = ui->tableWidget->item(0, i);
        if(item != nullptr && item->text().isEmpty() == false) {
            names << item->text();
        }
    }
    return names;
}
void MainWindow::on_AverageAndMeanAction_triggered()
{
    if (tableWidgetIsEmpty()) {
        tableEmptyWarning();
        return;
    }
    AverageAndMeanDialog dialog(this);
    QStringList names = GetColumnNames();
    dialog.setColumnNames(names);
    if (dialog.exec() == QDialog::Accepted) {
        int column = dialog.getSelectedColumn() + 1;
        int count = ui->tableWidget->rowCount();
        std::vector<float> x(count -1);
        for (int j = 1; j < count; j++) {
            QString text = ui->tableWidget->item(j, column)->text();
            if (column != 1) {
                x[j - 1] = text.toFloat();
            }
            else {
                x[j - 1] = discreteValueMap[text];
            }
        }
        auto avgVar = getAvgVar(x);
        float avg = std::get<0>(avgVar);
        float mean = std::get<1>(avgVar);
        QString result = QString("平均值：%1\n方差：%2").arg(avg).arg(mean);
        if(column == 1) {
            for (auto x : indexOfText) {
                result.append("\n" + x); // 添加映射说明
            }
        }
        ui->textBrowser->setText(result);
    }
}


void MainWindow::on_HistogramAction_triggered()
{
    if (tableWidgetIsEmpty()) {
        tableEmptyWarning();
        return;
    }
    AverageAndMeanDialog dialog(this);
    QStringList names;
    for (int i = 1; i < ui->tableWidget->columnCount(); i++) {
        QTableWidgetItem *item = ui->tableWidget->item(0, i);
        if(item != nullptr && item->text().isEmpty() == false) {
            names << item->text();
        }
    }
    dialog.setColumnNames(names); // 有待打包
    if (dialog.exec() == QDialog::Accepted) {
        int column = dialog.getSelectedColumn() + 1;
        int count = ui->tableWidget->rowCount();
        QTableWidgetItem *head = ui->tableWidget->item(0, column);
        std::vector<float> x(count -1);

        // 导入数据
        for (int j = 1; j < count; j++) {
            QString text = ui->tableWidget->item(j, column)->text();
            if (column != 1) {
                x[j - 1] = text.toFloat();
            }
            else {
                x[j - 1] = discreteValueMap[text];
            }
        }

            float min = *std::min_element(x.begin(), x.end()); // 计算最小值
            float max = *std::max_element(x.begin(), x.end()); // 计算最大值
            int numIntervals;
            float intervalWidth;
            if (column != 1) {
                numIntervals = 10; // 区间数量
                intervalWidth = (max - min) / numIntervals;
            }
            else {
                numIntervals = max - min + 1;
                intervalWidth = (max - min + 1) / numIntervals;
            }
             // 区间宽度
            // 创建区间
            struct Interval {
                float lower;
                float upper;
                int count; // 记录该区间内数据的数量
            };

        QVector<Interval> intervals;
        for (int i = 0; i < numIntervals; ++i) {
            Interval interval;
            interval.lower = min + i * intervalWidth;
            interval.upper = min + (i + 1) * intervalWidth;
            interval.count = 0; // 初始化计数为0
            intervals.push_back(interval);
        }

        // 将数据放入区间
        for (auto value : x) {
            for (int i = 0; i < intervals.size(); i++) {
                Interval* interval = &intervals[i];
                if (i != intervals.size() - 1 ) {
                    if (value >= interval->lower && value < interval->upper) {
                       interval->count++;
                       break;
                    }
                }
                else {
                    if (value >= interval->lower && value <= interval->upper) {
                       interval->count++;
                       break; // 数据位于最后一个区间
                    }
                }
            }
        }

        // 创建QBarSeries实例对象并赋值
        QBarSeries *series = new QBarSeries;
        QSplineSeries *splineSeries = new QSplineSeries;
        splineSeries->setName("正态分布曲线");
        auto set = new QBarSet(ui->tableWidget->item(0, column)->text());
        QStringList categories;
        int intervalsSize = intervals.size();
        for (int i = 0; i < intervalsSize; i++) {
            auto interval = intervals[i];
            if (column != 1) {
                if (i != intervalsSize - 1) {
                    categories.push_back("[" + QString::number(interval.lower) + "," + QString::number(interval.upper) + ")");
                }
                else {
                    categories.push_back("[" + QString::number(interval.lower) + "," + QString::number(interval.upper) + "]");
                }
            }
            else {
                categories.push_back(reverseValueMap[interval.lower]);
            }
            *set << interval.count;
            series->append(set);
            splineSeries->append(QPoint(i, interval.count));
        }

        // 创建QChart对象并添加series
        auto chart = new QChart;
        chart->addSeries(series);
        chart->addSeries(splineSeries);
        chart->setTitle("总数分布直方图");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // 设置横轴和纵轴
        auto axisX = new QBarCategoryAxis;
        QFont axisFont;
        axisFont.setPointSize(9); // 设置横轴字体大小，尽量显示完整的数字区间
        axisX->append(categories);
        axisX->setLabelsFont(axisFont);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        int countMax = intervals[0].count;
        for (auto interval : intervals) {
            if (interval.count > countMax) {
                countMax = interval.count;
            }
        }

        countMax *= 1.2;
        chart->axes(Qt::Vertical).first()->setRange(0, countMax);

        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); // 抗锯齿渲染

        ChartViewDialog viewDialog(this);
        viewDialog.setViewChart(chartView);
        viewDialog.exec();
    }
}


void MainWindow::on_ScatterAction_triggered()
{
    if (tableWidgetIsEmpty()) {
        tableEmptyWarning();
        return;
    }
    SelectTwoColumnsDialog dialog(this);
    QStringList names = GetColumnNames();
    dialog.setColumnNames(names);
    if (dialog.exec() == QDialog::Accepted) {
        int columnX = dialog.getSelectedColumnX() + 1;

        int columnY = dialog.getSelectedColumnY() + 1;

        int count = ui->tableWidget->rowCount();
        std::vector<float> x(count - 1);
        std::vector<float> y(count - 1);
        for (int j = 1; j < count; j++) {
            QString textX = ui->tableWidget->item(j, columnX)->text();
            if (columnX != 1) {
                x[j - 1] = textX.toFloat();
            }
            else {
                x[j - 1] = discreteValueMap[textX];
            }
            QString textY = ui->tableWidget->item(j, columnY)->text();
            if (columnY != 1) {
                y[j - 1] = textY.toFloat();
            }
            else {
                y[j - 1] = discreteValueMap[textY];
            }
        }
        QList<QPointF> points;
        auto series = new QScatterSeries;
        series->setName("散点图");
        series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        series->setMarkerSize(15.0);
        int numOfDuplicatePoints = 0;
        for (int i = 0; i < count; i++) {
            auto newPoint = QPointF(x[i], y[i]);
            for (auto point : points) {
                if (point == newPoint) {
                    numOfDuplicatePoints++;
                    break;
                }
            }
            points.append(newPoint);
            series->append(newPoint);
        }
        auto chart = new QChart;
        chart->addSeries(series);
        chart->setTitle("散点图");
        chart->createDefaultAxes();
        QString TextOfX = ui->tableWidget->item(0, columnX)->text();
        QString TextOfY = ui->tableWidget->item(0, columnY)->text();
        chart->axisX()->setTitleText(TextOfX);
        chart->axisY()->setTitleText(TextOfY);
        chart->setDropShadowEnabled(false);

        // 显示图像
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); // 抗锯齿渲染

        ChartViewDialog viewDialog(this);
        viewDialog.setViewChart(chartView);
        viewDialog.showNumOfDuplicatePoints(numOfDuplicatePoints);
        viewDialog.exec();
    }
}

