#include "heatmapdialog.h"
#include "QtGui/qclipboard.h"
#include "ui_heatmapdialog.h"
#include <QFileDialog>

HeatmapDialog::HeatmapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeatmapDialog)
{
    ui->setupUi(this);
    ui->radioButton->blockSignals(true);
    ui->radioButton->setChecked(true);
    ui->radioButton->blockSignals(false);
}

HeatmapDialog::~HeatmapDialog()
{
    delete ui;
}

void HeatmapDialog::setDataCov(const QVector<QVector<float>> &data) {
    ui->widget->setDataCov(data);
}

void HeatmapDialog::setDataPer(const QVector<QVector<float>> &data) {
    ui->widget->setDataPer(data);
}

void HeatmapDialog::on_radioButton_clicked()
{
    ui->widget->setMode(true);
    ui->widget->update();
}


void HeatmapDialog::on_radioButton_2_clicked()
{
    ui->widget->setMode(false);
    ui->widget->update();
}

void HeatmapDialog::setLabels(const QStringList &names) {
    ui->widget->setLabels(names);
}

void HeatmapDialog::on_exportButton_clicked()
{
    QPixmap pixmap = ui->widget->grab();
    QString fileName = QFileDialog::getSaveFileName(this, "保存热图", "", "PNG Files (*.png);;JPEG Files (*.jpg);;BMP Files (*.bmp);;All Files (*)");
    if (!fileName.isEmpty()) {
        pixmap.save(fileName);
    }
}



void HeatmapDialog::on_copyButton_clicked()
{
    QPixmap pixmap = ui->widget->grab();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setPixmap(pixmap);
}

