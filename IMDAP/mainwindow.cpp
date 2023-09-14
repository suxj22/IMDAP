#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Eigen/Dense"
#include "covariance.hpp"
#include "heatmapdialog.h"
#include "helpdialog.h"
#include "histogramdialog.h"
#include "chartviewdialog.h"
#include "kmeans.hpp"
#include "kmeansdialog.h"
#include "leastsquare.hpp"
#include "multiplecolumnsdialog.h"
#include "pca.hpp"
#include "pcadialog.h"
#include "rowfeature.hpp"
#include "averageandmeandialog.h"
#include "selecttwocolumnsdialog.h"
#include <vector>
#include <iostream>
#include <limits>
#include <QtCharts>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <cmath>
#include <QtDataVisualization/Q3DScatter>
#include <QtDataVisualization/QScatter3DSeries>
#include <QtDataVisualization/QScatterDataProxy>
#include <Legend3D.h>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, &QAction::triggered, this, &MainWindow::loadCSVFileToTableWidget);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::displaySelectedCellInfo);
    ui->ShowColoraction->setVisible(false); // 初始时不显示表格显示聚类颜色按钮
}

void MainWindow::loadCSVFileToTableWidget() {
    // 设置默认的资源文件路径
    QString defaultPath = QCoreApplication::applicationDirPath();
    // 使用 QFileDialog 从系统中选择 CSV 文件，并设置默认路径
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open CSV File"),
                                                    defaultPath, tr("CSV Files (*.csv)"));
    // 如果用户没有选择文件，直接返回
    if (filePath.isEmpty()) {
        return;
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        // 清空已经存储的内容
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);
        discreteValueMap.clear();
        reverseValueMap.clear();
        indexOfText.clear();
        // 设置表格显示聚类颜色按钮不可见
        ui->ShowColoraction->setVisible(false);
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
        QString result = QString("列名：" + ui->tableWidget->item(0, column)->text() + "\n");
        result.append(QString("平均值：%1\n方差：%2").arg(avg).arg(mean));
        if(column == 1) {
            for (auto x : indexOfText) {
                result.append("\n" + x); // 添加映射说明
            }
        }
        ui->textBrowser->setText(result);
    }
}

float MainWindow::normalFit(float stddev, float avg, float x) {
    float z = (x - avg) / stddev;
    float result = 0.5 * (1 + std::erf(z / sqrt(2)));
    return result;
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

        // 创建QBarSeries和QSplineSeries实例对象并赋值
        QBarSeries *series = new QBarSeries;
        QSplineSeries *splineSeries = new QSplineSeries;
        splineSeries->setName("正态分布曲线");
        auto avgVar = getAvgVar(x);
        float avg = std::get<0>(avgVar); // 均值
        float stddev = sqrt(std::get<1>(avgVar)); // 标准差

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
        }
        // 每个区间添加多个点来绘制正态分布曲线
        for (int j = 0; j < categories.size(); j++) {
            float Down = min + j * intervalWidth;
            float Up = min + (j + 1) * intervalWidth;
            float y = normalFit(stddev, avg, Up) - normalFit(stddev, avg, Down);
            splineSeries->append(QPointF(j, y * (count - 1)));
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

        int inputDegree = dialog.getInputDegree();
        if (inputDegree == -1) {
            QMessageBox::warning(this, "警告", "未选择拟合次数");
            return;
        }
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
        float minX = *std::min_element(x.begin(), x.end()); // 计算x最小值
        float maxX = *std::max_element(x.begin(), x.end()); // 计算x最大值
        float minY = *std::min_element(y.begin(), y.end()); // 计算y最小值
        float maxY = *std::max_element(y.begin(), y.end()); // 计算y最大值
        QList<QPointF> points;
        auto series = new QScatterSeries;
        series->setName("散点图");
        series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        series->setMarkerSize(10.0);
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

        // 添加曲线拟合
        auto splineSeries = new QSplineSeries;
        splineSeries->setName("曲线拟合");

        int totalPoint = 30; // 设置拟合曲线总点数

        float intervalWidth = (maxX - minX) / totalPoint; // 区间宽度
        auto result = fitLeastSquareAndPR(x, y, inputDegree);
        auto coefficients = std::get<0>(result);

        float xPoint = minX;
        for (int j = 0; j <= totalPoint; j++, xPoint += intervalWidth) {
            float yPoint = 0.0;
            for (int i = 0; i < coefficients.size(); i++) {
                yPoint += coefficients[i] * std::pow(xPoint, i);
            }

            splineSeries->append(xPoint, yPoint);
        }
        auto chart = new QChart;
        chart->addSeries(series);
        chart->setTitle("散点图");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setDropShadowEnabled(false);
        chart->addSeries(splineSeries);
        auto axisX = new QValueAxis;
        auto axisY = new QValueAxis;
        QString TextOfX = ui->tableWidget->item(0, columnX)->text();
        QString TextOfY = ui->tableWidget->item(0, columnY)->text();
        axisX->setTitleText(TextOfX);
        axisY->setTitleText(TextOfY);
        axisX->setRange(minX * 0.8, maxX * 1.1);
        axisY->setRange(minY * 0.8, maxY * 1.1);
        chart->addAxis(axisY, Qt::AlignLeft);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        series->attachAxis(axisY);
        splineSeries->attachAxis(axisX);
        splineSeries->attachAxis(axisY);

        // 显示图像
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing); // 抗锯齿渲染
        ChartViewDialog viewDialog(this, chartView);
        connect(series, &QScatterSeries::hovered, [&viewDialog](const QPointF &point, bool state){
            if (state) { // 如果鼠标悬停在点上
                QToolTip::showText(QCursor::pos(),
                                   QString("X: %1\nY: %2").arg(point.x()).arg(point.y()));
            } else { // 如果鼠标移开点
                QToolTip::hideText();
            }
        });
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
            column += 1;
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
            QMessageBox::warning(&dialog, "警告", "未选择数据！");
            return;
        }
        if (items.size() < 2) {
            QMessageBox::warning(&dialog, "警告", "选择的列数过少！");
            return;
        }
        // 获取总行数
        int count = ui->tableWidget->rowCount();
        std::vector<std::vector<float>> inputVector;
        // 导入数据至inputVector
        for (int j = 0; j < count - 1; j++) {

            std::vector<float> x(items.size());
            for (int k = 0; k < items.size(); k++) {
                int column = items[k] + 1;
                QString text = ui->tableWidget->item(j, column)->text();
                if (column != 1) {
                    x[k] = text.toFloat();
                }
                else {
                    x[k] = discreteValueMap[text];
                }
            }
            inputVector.push_back(x);
        }
        // 创建选择次数的对话框
        QDialog powerDialog;
        QVBoxLayout layout(&powerDialog);

        // 创建标签
        QLabel label("请选择降维次数:");
        layout.addWidget(&label);

        // 创建combobox
        QComboBox comboBox;
        comboBox.addItem("2");
        comboBox.addItem("3");
        layout.addWidget(&comboBox);

        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        layout.addWidget(buttonBox);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, &powerDialog, &QDialog::accept);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, &powerDialog, &QDialog::reject);

        if (powerDialog.exec() == QDialog::Accepted) {
            int power = comboBox.currentText().toInt();
            if (items.size() == 2 && power == 3) {
                QMessageBox::warning(&dialog, "警告", "选择的列数过少！");
                return;
            }
            // 定义一个颜色列表，给不同类别的点赋不同颜色
            QList<QColor> colors = {Qt::red, Qt::blue, Qt::green, Qt::yellow, Qt::cyan, Qt::magenta, Qt::gray};
            switch (power) {
            case 2:{
                QList<QScatterSeries*> seriesList(indexOfText.size());
                for (int i = 0; i < seriesList.size(); i++) {
                    seriesList[i] = new QScatterSeries();
                }
                auto result = pca(inputVector, power);
                float minValueX = result(0, 0);
                float maxValueX = result(0, 0);
                float minValueY = result(0, 0);
                float maxValueY = result(0, 0);
                for (int i = 0; i < count - 1; i++) {
                    QString text = ui->tableWidget->item(i + 1, 1)->text();
                    int kind = discreteValueMap[text];
                    seriesList[kind]->setName(text);

                    float x = result(i, 0);
                    float y = result(i, 1);
                    if (x > maxValueX) {
                       maxValueX = x;
                    }
                    if (x < minValueX) {
                       minValueX = x;
                    }
                    if (y > maxValueY) {
                       maxValueY = y;
                    }
                    if (y < minValueY) {
                       minValueY = y;
                    }
                    auto newPoint = QPointF(x, y);
                    seriesList.at(kind)->append(newPoint);
                }

                for (int i = 0; i < seriesList.size(); i++) {
                    QScatterSeries *series = seriesList.at(i);
                    series->setColor(colors.at(i % colors.size()));// 使用颜色列表的颜色，如果series数量大于颜色列表的长度则会循环使用颜色
                    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
                    series->setMarkerSize(10.0);
                }
                auto chart = new QChart;
                for (auto series : seriesList) {
                    qDebug() << "Series Name:" << series->name();
                    for (int i = 0; i < series->count(); i++) {
                       QPointF point = series->at(i);
                       qDebug() << "Point:" << point.x() << "," << point.y();
                    }
                    chart->addSeries(series);
                }
                chart->setTitle("二维降维图");
                auto axisX = new QValueAxis;
                auto axisY = new QValueAxis;
                float factor = 1.1;
                if (minValueX > 0) {
                    minValueX /= factor;
                }
                else {
                    minValueX *= factor;
                }
                if (maxValueX > 0) {
                    maxValueX *= factor;
                }
                else {
                    maxValueX /= factor;
                }
                if (minValueY > 0) {
                    minValueY /= factor;
                }
                else {
                    minValueY *= factor;
                }
                if (maxValueY > 0) {
                    maxValueY *= factor;
                }
                else {
                    maxValueY /= factor;
                }
                axisX->setRange(minValueX, maxValueX);
                axisY->setRange(minValueY, maxValueY);
                chart->addAxis(axisX, Qt::AlignBottom);
                chart->addAxis(axisY, Qt::AlignLeft);
                chart->setAnimationOptions(QChart::SeriesAnimations);
                chart->setDropShadowEnabled(false);
                auto chartView = new QChartView(chart);
                PCADialog viewDialog(this, chartView);
                for (auto series : seriesList) {
                    series->attachAxis(axisX);
                    series->attachAxis(axisY);
                    connect(series, &QScatterSeries::hovered, [&viewDialog](const QPointF &point, bool state){
                        if (state) { // 如果鼠标悬停在点上
                            QToolTip::showText(QCursor::pos(),
                                               QString("X: %1\nY: %2").arg(point.x()).arg(point.y()));
                        } else { // 如果鼠标移开点
                            QToolTip::hideText();
                        }
                    });
                }
                viewDialog.exec();
                break;
            }
            case 3:{
                auto result = pca(inputVector, power);
                auto scatter3D = new Q3DScatter();
                QList<QScatter3DSeries*> seriesList(indexOfText.size());
                for (int i = 0; i < seriesList.size(); i++) {
                    seriesList[i] = new QScatter3DSeries();
                }
                for (int i = 0; i < count - 1; i++) {
                    QString text = ui->tableWidget->item(i + 1, 1)->text();
                    int kind = discreteValueMap[text];
                    seriesList[kind]->setName(text);
                    float x = result(i, 0);
                    float y = result(i, 1);
                    float z = result(i, 2);
                    auto newPoint = QVector3D(x, y, z);
                    seriesList.at(kind)->dataProxy()->addItem(newPoint);
                }
                for (int i = 0; i < seriesList.size(); i++) {
                    QScatter3DSeries *series = seriesList.at(i);
                    series->setBaseColor(colors[i % colors.size()]);
                    scatter3D->addSeries(series);
                    series->setItemSize(0.1f);
                }
                float min_x = std::numeric_limits<float>::max();
                float max_x = std::numeric_limits<float>::min();
                float min_y = std::numeric_limits<float>::max();
                float max_y = std::numeric_limits<float>::min();
                float min_z = std::numeric_limits<float>::max();
                float max_z = std::numeric_limits<float>::min();

                for (int i = 0; i < result.rows(); ++i) {
                    min_x = std::min(min_x, result(i, 0));
                    max_x = std::max(max_x, result(i, 0));
                    min_y = std::min(min_y, result(i, 1));
                    max_y = std::max(max_y, result(i, 1));
                    min_z = std::min(min_z, result(i, 2));
                    max_z = std::max(max_z, result(i, 2));
                }

                float scaleFactor = 1.3f;
                float offset_x = (max_x - min_x) * (scaleFactor - 1.0);
                float offset_y = (max_y - min_y) * (scaleFactor - 1.0);
                float offset_z = (max_z - min_z) * (scaleFactor - 1.0);

                min_x -= offset_x / 2.0;
                max_x += offset_x / 2.0;
                min_y -= offset_y / 2.0;
                max_y += offset_y / 2.0;
                min_z -= offset_z / 2.0;
                max_z += offset_z / 2.0;
                auto axisX = new QValue3DAxis();
                axisX->setRange(min_x, max_x);
                auto axisY = new QValue3DAxis();
                axisY->setRange(min_y, max_y);
                auto axisZ = new QValue3DAxis();
                axisZ->setRange(min_z, max_z);
                scatter3D->setAxisX(axisX);
                scatter3D->setAxisY(axisY);
                scatter3D->setAxisZ(axisZ);
                scatter3D->setHorizontalAspectRatio(true);
                scatter3D->setAspectRatio(true);
                QList<QScatter3DSeries*> list;
                for (auto series : seriesList) {
                    list.push_back(series);
                }

                QWidget * container = createWindowContainer(scatter3D);
                PCADialog viewDialog(this, container, list);
                viewDialog.exec();
                break;
            }
            default:
                break;
            }
        }
    }
}


void MainWindow::on_actionKMeans_triggered()
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
        else if (items.size() < 2) {
            QMessageBox::warning(&dialog,"警告", "选择的列数过少！");
            return;
        }
        // 获取总行数
        int count = ui->tableWidget->rowCount();
        std::vector<std::vector<float>> inputVector;
        // 导入数据至inputVector
        for (int j = 0; j < count - 1; j++) {

            std::vector<float> x(items.size());
            for (int k = 0; k < items.size(); k++) {
                int column = items[k] + 1;
                QString text = ui->tableWidget->item(j, column)->text();
                if (column != 1) {
                    x[k] = text.toFloat();
                }
                else {
                    x[k] = discreteValueMap[text];
                }
            }
            inputVector.push_back(x);
        }
        int totalcolor = 10;

        // 绘制二维聚类图
        auto KMeansResult = clusterKMeans(inputVector, totalcolor, 100);
        auto Labels = std::get<1>(KMeansResult);
        int newColumnIndex = ui->tableWidget->columnCount(); // 获取当前的列数
        ui->tableWidget->insertColumn(newColumnIndex); // 在最后插入一个新列

        // 如果重复生成聚类则删除之前的列
        int rowCount = ui->tableWidget->rowCount();
        if (ui->tableWidget->item(rowCount - 1, 0)->text() == "KMeans") {
            ui->tableWidget->removeColumn(rowCount - 1);
        }
        // 设置新列的标题
        QTableWidgetItem *header = new QTableWidgetItem(QString::number(ui->tableWidget->columnCount()));
        ui->tableWidget->setHorizontalHeaderItem(newColumnIndex, header);
        QTableWidgetItem *newItem = new QTableWidgetItem(QString("KMeans"));
        ui->tableWidget->setItem(0, newColumnIndex, newItem);
        // 设置新列的值
        for (int row = 0; row < Labels.size(); row++) {
            QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(Labels[row]));
            ui->tableWidget->setItem(row + 1, newColumnIndex, newItem);
        }
        QList<QScatterSeries*> seriesList(totalcolor);
        for (int i = 0; i < seriesList.size(); i++) {
            seriesList[i] = new QScatterSeries();
        }

        auto result = pca(inputVector, 2);
        float minValueX = result(0, 0);
        float maxValueX = result(0, 0);
        float minValueY = result(0, 0);
        float maxValueY = result(0, 0);
        for (int i = 0; i < count - 1; i++) {
            int kind = Labels[i];
            float x = result(i, 0);
            float y = result(i, 1);
            if (x > maxValueX) {
                maxValueX = x;
            }
            if (x < minValueX) {
                minValueX = x;
            }
            if (y > maxValueY) {
                maxValueY = y;
            }
            if (y < minValueY) {
                minValueY = y;
            }
            auto newPoint = QPointF(x, y);
            seriesList.at(kind)->append(newPoint);
        }
        for (int i = 0; i < seriesList.size(); i++) {
            QScatterSeries *series = seriesList.at(i);
            series->setColor(colors.at(i % colors.size()));// 使用颜色列表的颜色，如果series数量大于颜色列表的长度则会循环使用颜色
            series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
            series->setMarkerSize(10.0);
        }
        auto chart = new QChart;
        for (auto series : seriesList) {
            chart->addSeries(series);
        }
        auto axisX = new QValueAxis;
        auto axisY = new QValueAxis;
        float factor = 1.1;
        if (minValueX > 0) {
            minValueX /= factor;
        }
        else {
            minValueX *= factor;
        }
        if (maxValueX > 0) {
            maxValueX *= factor;
        }
        else {
            maxValueX /= factor;
        }
        if (minValueY > 0) {
            minValueY /= factor;
        }
        else {
            minValueY *= factor;
        }
        if (maxValueY > 0) {
            maxValueY *= factor;
        }
        else {
            maxValueY /= factor;
        }
        axisX->setRange(minValueX, maxValueX);
        axisY->setRange(minValueY, maxValueY);
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);
        for (auto series : seriesList) {
            series->attachAxis(axisX);
            series->attachAxis(axisY);
        }
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setDropShadowEnabled(false);
        chart->legend()->hide();
        auto chartView = new QChartView(chart);
        KMeansDialog viewDialog(this);
        chartView->setMinimumSize(600, 600);
        viewDialog.addChart(chart);
        viewDialog.addChartView(chartView);
        for (auto series : seriesList) {
            series->attachAxis(axisX);
            series->attachAxis(axisY);
            connect(series, &QScatterSeries::hovered, [&viewDialog](const QPointF &point, bool state){
                if (state) { // 如果鼠标悬停在点上
                    QToolTip::showText(QCursor::pos(),
                                       QString("X: %1\nY: %2").arg(point.x()).arg(point.y()));
                } else { // 如果鼠标移开点
                    QToolTip::hideText();
                }
            });
        }

        if (items.size() >= 3) {
            auto result = pca(inputVector, 3);
            auto scatter3D = new Q3DScatter();
            QList<QScatter3DSeries*> seriesList(totalcolor);
            for (int i = 0; i < seriesList.size(); i++) {
                seriesList[i] = new QScatter3DSeries();
            }
            for (int i = 0; i < count - 1; i++) {
                int kind = Labels[i];
                float x = result(i, 0);
                float y = result(i, 1);
                float z = result(i, 2);
                auto newPoint = QVector3D(x, y, z);
                seriesList.at(kind)->dataProxy()->addItem(newPoint);
            }
            for (int i = 0; i < seriesList.size(); i++) {
                QScatter3DSeries *series = seriesList.at(i);
                series->setBaseColor(colors[i % colors.size()]);
                scatter3D->addSeries(series);
                series->setItemSize(0.1f);
            }
            float min_x = std::numeric_limits<float>::max();
            float max_x = std::numeric_limits<float>::min();
            float min_y = std::numeric_limits<float>::max();
            float max_y = std::numeric_limits<float>::min();
            float min_z = std::numeric_limits<float>::max();
            float max_z = std::numeric_limits<float>::min();

            for (int i = 0; i < result.rows(); ++i) {
                min_x = std::min(min_x, result(i, 0));
                max_x = std::max(max_x, result(i, 0));
                min_y = std::min(min_y, result(i, 1));
                max_y = std::max(max_y, result(i, 1));
                min_z = std::min(min_z, result(i, 2));
                max_z = std::max(max_z, result(i, 2));
            }

            float scaleFactor = 1.3f;
            float offset_x = (max_x - min_x) * (scaleFactor - 1.0);
            float offset_y = (max_y - min_y) * (scaleFactor - 1.0);
            float offset_z = (max_z - min_z) * (scaleFactor - 1.0);

            min_x -= offset_x / 2.0;
            max_x += offset_x / 2.0;
            min_y -= offset_y / 2.0;
            max_y += offset_y / 2.0;
            min_z -= offset_z / 2.0;
            max_z += offset_z / 2.0;
            auto axisX = new QValue3DAxis();
            axisX->setRange(min_x, max_x);
            auto axisY = new QValue3DAxis();
            axisY->setRange(min_y, max_y);
            auto axisZ = new QValue3DAxis();
            axisZ->setRange(min_z, max_z);
            scatter3D->setAxisX(axisX);
            scatter3D->setAxisY(axisY);
            scatter3D->setAxisZ(axisZ);
            scatter3D->setHorizontalAspectRatio(true);
            scatter3D->setAspectRatio(true);
            QWidget * container = createWindowContainer(scatter3D);
            container->setMinimumSize(600, 600);
            viewDialog.addChartView(container);
        }
        viewDialog.exec();
        // 显示表格按照聚类结果显示按钮
        ui->ShowColoraction->setVisible(true);

    }
}



void MainWindow::on_ShowColoraction_triggered(bool checked)
{
    if (checked) {
        for (int row = 1; row < ui->tableWidget->rowCount(); row++) {
            QTableWidgetItem *item = ui->tableWidget->item(row, ui->tableWidget->columnCount() - 1); // 获取最后一列的项
            if (item) {
                int index = item->text().toInt(); // 转换为整数索引
                if (index >= 0 && index < colors.size()) {
                    QColor color = colors[index]; // 获取对应的颜色
                    for (int column = 0; column < ui->tableWidget->columnCount(); column++) {
                       ui->tableWidget->item(row, column)->setBackground(color); // 设置该行的背景颜色
                    }
                }
            }
        }
    }
    else {
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                QTableWidgetItem *item = ui->tableWidget->item(row, col);
                if (item) {
                    item->setBackground(Qt::transparent); // 设置透明背景
                }
            }
        }
    }
}

void MainWindow::displaySelectedCellInfo() {
    // 获取所有选中的范围
    QList<QTableWidgetSelectionRange> ranges = ui->tableWidget->selectedRanges();

    int count = 0;  // 所有选中的单元格总数
    float sum = 0;  // 可计算单元格的总和
    int validFloatCount = 0;  // 可计算的单元格数量
    std::vector<float> validFloats; // 可计算的浮点数集合

    for (const QTableWidgetSelectionRange &range : ranges) {
        for (int row = range.topRow(); row <= range.bottomRow(); ++row) {
            for (int col = range.leftColumn(); col <= range.rightColumn(); ++col) {
                QTableWidgetItem *item = ui->tableWidget->item(row, col);
                if (item) {
                    count ++;
                    bool ok;
                    float value = item->text().toFloat(&ok);
                    if (ok) {  // 如果这个值是一个有效的浮点数
                       sum += value;
                       validFloats.push_back(value);
                       validFloatCount++;
                    }
                }
            }
        }
    }
    if (validFloats.empty()) {
        QString info = QString("选择的单元格总数：%1").arg(count);
        ui->textBrowser->setText(info);
    }
    else {
        auto result = getAvgVar(validFloats);
        // 计算平均数和方差
        float avg = std::get<0>(result);
        float variance = std::get<1>(result);
        // 计算中位数
        std::sort(validFloats.begin(), validFloats.end());
        float median = 0;
        if (validFloatCount % 2 == 1) {
            median = validFloats[validFloatCount / 2];
        } else {
            median = (validFloats[(validFloatCount - 1) / 2] + validFloats[validFloatCount / 2]) / 2.0;
        }
        // 计算众数
        QMap<float, int> frequencyMap;
        for (float value : validFloats) {
            frequencyMap[value]++;
        }
        float mode = validFloats[0];
        int maxCount = 0;

        for (auto item = frequencyMap.constBegin(); item != frequencyMap.constEnd(); ++item) {
            if (item.value() > maxCount) {
                maxCount = item.value();
                mode = item.key();
            }
        }
        QString info = QString("选择的单元格总数：%1\n总和：%2\n平均值：%3\n方差：%4\n中位数：%5\n众数：%6")
                           .arg(count).arg(sum).arg(avg).arg(variance).arg(median).arg(mode);
        ui->textBrowser->setText(info);
    }
}



void MainWindow::on_clearButton_clicked()
{
    ui->textBrowser->clear();
}


void MainWindow::on_copyButton_clicked()
{
    QString content = ui->textBrowser->toPlainText(); // 获取QTextBrowser的文本
    QClipboard *clipboard = QApplication::clipboard(); // 获取应用程序的剪贴板
    clipboard->setText(content); // 将文本设置到剪贴板
}


void MainWindow::on_Helpaction_triggered()
{
    auto dialog = new HelpDialog;
    dialog->exec();
}

