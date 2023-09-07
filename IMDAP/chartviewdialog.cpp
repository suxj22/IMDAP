#include "chartviewdialog.h"
#include "ui_chartviewdialog.h"

ChartViewDialog::ChartViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartViewDialog)
{
    ui->setupUi(this);
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
    ui->formLayout->addWidget(chartView);
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

