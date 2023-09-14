#include "chartviewdialog.h"
#include "ui_chartviewdialog.h"

ChartViewDialog::ChartViewDialog(QWidget *parent, QChartView *chartview) :
    QDialog(parent),
    ui(new Ui::ChartViewDialog)
{
    chartView = chartview;
    chartView->setMinimumWidth(1248);
    chartView->setMinimumHeight(702);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // 设置策略以填充父级控件
    ui->setupUi(this);
    ui->ScatterCheckBox->blockSignals(true);
    ui->SplineCheckBox->blockSignals(true);
    ui->ScatterCheckBox->setChecked(true);
    ui->SplineCheckBox->setChecked(true);
    ui->ScatterCheckBox->blockSignals(false);
    ui->SplineCheckBox->blockSignals(false);
    ui->gridLayout->addWidget(chartView);
}

ChartViewDialog::~ChartViewDialog()
{
    delete ui;
}

void ChartViewDialog::setViewChart(QChartView *chartview) {
    chartView = chartview;
    chartView->setMinimumWidth(1248);
    chartView->setMinimumHeight(702);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // 设置策略以填充父级控件
    ui->gridLayout->addWidget(chartView);
    for (auto *series : chartView->chart()->series()) {
        if (auto *scatterSeries = dynamic_cast<QScatterSeries*>(series)) {
            connect(scatterSeries, &QScatterSeries::hovered,
                    this, &ChartViewDialog::handlePointHovered);
        }
    }
}


void ChartViewDialog::on_exportImageButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "保存直方图", "", "PNG图像 (*.png);;JPEG图像 (*.jpg)");
    if (!filePath.isEmpty()) {
        QPixmap chartPixmap = chartView->grab();
        chartPixmap.save(filePath);
    }
}


void ChartViewDialog::on_copyToClipboardButton_clicked()
{
    QPixmap chartPixmap = chartView->grab();
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setPixmap(chartPixmap);
}

void ChartViewDialog::showNumOfDuplicatePoints(int num) {
    ui->numOfDuplicatePointsLabel->setText("重复点个数：" + QString::number(num) + "个");

}
void ChartViewDialog::setValueLabel(int num, float p, float r2) {
    ui->numOfDuplicatePointsLabel->setText("重复点个数：" + QString::number(num) + "个");
    ui->pValueLabel->setText("p值：" + QString::number(p));
    ui->r2ValueLabel->setText("r^2值：" + QString::number(r2));
}


void ChartViewDialog::on_ScatterCheckBox_stateChanged(int arg1)
{
    // 获取QChart对象
    QChart *chart = chartView->chart();

    // 获取所有系列
    QList<QAbstractSeries*> allSeries = chart->series();

    // 检查是否至少有两个系列
    if(allSeries.size() >= 2) {
        switch (arg1) {
        case Qt::Unchecked:
            allSeries.at(0)->setVisible(false);
            break;
        case Qt::Checked:
            allSeries.at(0)->setVisible(true);
        default:
            break;
        }
    }
}


void ChartViewDialog::on_SplineCheckBox_stateChanged(int arg1)
{
    // 获取QChart对象
    QChart *chart = chartView->chart();

    // 获取所有系列
    QList<QAbstractSeries*> allSeries = chart->series();

    // 检查是否至少有两个系列
    if(allSeries.size() >= 2) {
        switch (arg1) {
        case Qt::Unchecked:
            allSeries.at(1)->setVisible(false);
            break;
        case Qt::Checked:
            allSeries.at(1)->setVisible(true);
        default:
            break;
        }
    }
}
void ChartViewDialog::handlePointHovered(const QPointF &point, bool state)
{
    if (state) {
        QToolTip::showText(QCursor::pos(), QString("X: %1\nY: %2").arg(point.x()).arg(point.y()));
    } else {
        QToolTip::hideText();
    }
}

