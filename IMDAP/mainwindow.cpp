#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Eigen/Dense"
#include "covariance.hpp"
#include "heatmapdialog.h"
#include "histogramdialog.h"
#include "chartviewdialog.h"
#include "leastsquare.hpp"
#include "multiplecolumnsdialog.h"
#include "rowfeature.hpp"
#include "averageandmeandialog.h"
#include "selecttwocolumnsdialog.h"
#include <vector>
#include <iostream>
#include <QtCharts>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <cmath>


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
        QFont axisLabelFont;
        axisLabelFont.setPointSize(9); // 设置横轴数据区间大小，尽量显示完整的数字区间
        axisX->append(categories);
        axisX->setLabelsFont(axisLabelFont);
        QFont axisTitleFont;
        axisTitleFont.setPointSize(12);
        axisX->setTitleFont(axisTitleFont);
        axisX->setTitleText("数据区间");
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        splineSeries->attachAxis(axisX);

        int countMax = intervals[0].count;
        int countMin = intervals[0].count;
        for (auto interval : intervals) {
            if (interval.count > countMax) {
                countMax = interval.count;
            }
            if (interval.count < countMin) {
                countMin = interval.count;
            }
        }

        countMax *= 1.2; // 为了让曲线良好地显示，不超上界
        auto axisY = new QValueAxis;
        axisY->setRange(0, countMax);
        axisY->setTitleText("频数");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
        splineSeries->attachAxis(axisY);

        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); // 抗锯齿渲染

        HistogramDialog viewDialog(this);
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
        for (int i = 0; i < count - 1; i++) {
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
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QString TextOfX = ui->tableWidget->item(0, columnX)->text();
        QString TextOfY = ui->tableWidget->item(0, columnY)->text();
        chart->axisX()->setTitleText(TextOfX);
        chart->axisY()->setTitleText(TextOfY);
        chart->setDropShadowEnabled(false);

        // 添加曲线拟合
        auto splineSeries = new QSplineSeries;
        splineSeries->setName("曲线拟合");
        int inputDegree = dialog.getInputDegree();
        int totalPoint = 30; // 设置拟合曲线总点数
        float min = *std::min_element(x.begin(), x.end()); // 计算最小值
        float max = *std::max_element(x.begin(), x.end()); // 计算最大值
        float intervalWidth = (max - min) / totalPoint; // 区间宽度
        auto result = fitLeastSquareAndPR(x, y, inputDegree);
        auto coefficients = std::get<0>(result);

        float xPoint = min;
        for (int j = 0; j <= totalPoint; j++, xPoint += intervalWidth) {
            float yPoint = 0.0;
            for (int i = 0; i < coefficients.size(); i++) {
                yPoint += coefficients[i] * std::pow(xPoint, i);
            }

            splineSeries->append(xPoint, yPoint);
        }
        chart->addSeries(splineSeries);
        splineSeries->attachAxis(chart->axisX());
        splineSeries->attachAxis(chart->axisY());
        // 显示图像
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); // 抗锯齿渲染
        ChartViewDialog viewDialog(this, chartView);
//        viewDialog.setViewChart(chartView);
        // 显示值
        float pValue = std::get<1>(result);
        float r2Value = std::get<2>(result);
        viewDialog.setValueLabel(numOfDuplicatePoints, pValue, r2Value);
        viewDialog.exec();
    }
}



void MainWindow::on_Matrixaction_triggered()
{
    if (tableWidgetIsEmpty()) {
        tableEmptyWarning();
        return;
    }
    QStringList names;
    for (int i = 1; i < ui->tableWidget->columnCount(); i++) {
        QTableWidgetItem *item = ui->tableWidget->item(0, i);
        if(item != nullptr && item->text().isEmpty() == false) {
            names << item->text();
        }
    } // 有待打包
    MultipleColumnsDialog dialog(this, names);
    if (dialog.exec() == QDialog::Accepted) {
        // 获取选择的列
        auto items = dialog.getItems();
        if (items.empty()) {
            QMessageBox::warning(&dialog,"警告", "未选择数据！");
            return;
        }
        // 获取总行数
        int count = ui->tableWidget->rowCount();
        std::vector<std::vector<float>> inputVector;
        QStringList Selectednames;
        // 导入数据至inputVector
        for (auto column : items) {
            std::vector<float> x(count -1);
            Selectednames.append(ui->tableWidget->item(0, column)->text());
            for (int j = 1; j < count; j++) {
                QString text = ui->tableWidget->item(j, column)->text();
                if (column != 1) {
                    x[j - 1] = text.toFloat();
                }
                else {
                    x[j - 1] = discreteValueMap[text];
                }
            }
            inputVector.push_back(x);
        }
        auto covarianceMatrix = getCovariance(inputVector);
        std::vector<float> vars;
        for (auto vec : inputVector) {
            auto avgVar = getAvgVar(vec);
            vars.push_back(std::get<1>(avgVar));
        }
        auto pearsonCorrMatrix = getPearsonCorr(covarianceMatrix, vars);

        int matrixSize = pearsonCorrMatrix.rows();
        QVector<QVector<float>> dataCov(matrixSize,(QVector<float>(matrixSize,0)));
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                dataCov[i][j] = covarianceMatrix(i,j);
            }
        }
        QVector<QVector<float>> dataPer(matrixSize,(QVector<float>(matrixSize,0)));
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                dataPer[i][j] = pearsonCorrMatrix(i,j);
            }
        }
        HeatmapDialog viewDialog(this);

        viewDialog.setDataCov(dataCov);
        viewDialog.setDataPer(dataPer);
        viewDialog.setLabels(Selectednames);
        viewDialog.exec();
    }
}


void MainWindow::on_PCAAction_triggered()
{
    QDialog dialog;
    QVBoxLayout layout(&dialog);

    // 创建标签
    QLabel label("请选择降维次数:");
    layout.addWidget(&label);

    // 创建combobox
    QComboBox comboBox;
    comboBox.addItem("2");
    comboBox.addItem("3");
    layout.addWidget(&comboBox);
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    layout.addWidget(&buttonBox);

    dialog.exec();
}

