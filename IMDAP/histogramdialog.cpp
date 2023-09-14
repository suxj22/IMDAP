#include "histogramdialog.h"
#include "ui_histogramdialog.h"


HistogramDialog::HistogramDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistogramDialog)
{
    ui->setupUi(this);
    ui->HistogramCheckBox->blockSignals(true);
    ui->SplineCheckBox->blockSignals(true); // 防止chartView未初始化进入槽函数导致错误
    ui->HistogramCheckBox->setChecked(true);
    ui->SplineCheckBox->setChecked(true);
    ui->HistogramCheckBox->blockSignals(false);
    ui->SplineCheckBox->blockSignals(false); // 恢复信号
}

HistogramDialog::~HistogramDialog()
{
    delete ui;
}

void HistogramDialog::setViewChart(QChartView *chartview) {
    chartView = chartview;
    chartView->setMinimumWidth(1248);
    chartView->setMinimumHeight(702);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // 设置策略以填充父级控件
    ui->gridLayout->addWidget(chartView);
}

void HistogramDialog::on_exportImageButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "保存直方图", "", "PNG图像 (*.png);;JPEG图像 (*.jpg)");
    if (!filePath.isEmpty()) {
        QPixmap chartPixmap = chartView->grab();
        chartPixmap.save(filePath);
    }
}


void HistogramDialog::on_copyToClipboardButton_clicked()
{
    QPixmap chartPixmap = chartView->grab();
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setPixmap(chartPixmap);
}

void HistogramDialog::on_HistogramCheckBox_stateChanged(int arg1)
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


void HistogramDialog::on_SplineCheckBox_stateChanged(int arg1)
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

