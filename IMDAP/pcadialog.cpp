#include "pcadialog.h"
#include "ui_pcadialog.h"
#include <QFileDialog>

PCADialog::PCADialog(QWidget *parent, QWidget *contentwidget, QList <QScatter3DSeries*> list) :
    QDialog(parent),
    ui(new Ui::PCADialog)
{
    ui->setupUi(this);
    contentWidget = contentwidget;
    contentWidget->setMinimumSize(1200, 650);
    contentWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->horizontalLayout_4->addWidget(contentWidget);
    ui->widget->setList(list);
    ui->widget->update();
}

PCADialog::~PCADialog()
{
    delete ui;
}

void PCADialog::setList(QList <QScatter3DSeries*> list) {
    List = list;
}

void PCADialog::on_exportButton_clicked()
{

    QString filePath = QFileDialog::getSaveFileName(this, "保存二维降维图", "", "PNG图像 (*.png);;JPEG图像 (*.jpg)");
    if (!filePath.isEmpty()) {
        QPixmap chartPixmap = ui->horizontalLayout_4->itemAt(1)->widget()->grab();
        chartPixmap.save(filePath);
    }
}



void PCADialog::on_copyButton_clicked()
{
    QPixmap chartPixmap = ui->horizontalLayout_4->itemAt(1)->widget()->grab();
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setPixmap(chartPixmap);
}

