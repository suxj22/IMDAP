#include "kmeansdialog.h"
#include "QtGui/qclipboard.h"
#include "ui_kmeansdialog.h"
#include <QFileDialog>
#include <QPainter>
#include "Legend3D.h"

KMeansDialog::KMeansDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KMeansDialog)
{
    this->setWindowTitle("KMeans聚类图");
    ui->setupUi(this);
}

KMeansDialog::~KMeansDialog()
{
    delete ui;
}

void KMeansDialog::addChartView(QWidget * view) {
    ui->horizontalLayout_2->addWidget(view);
}

void KMeansDialog::on_export2DButton_clicked()
{
    QLayout *layout = ui->horizontalLayout_2; // 布局对象
    auto widget = layout->itemAt(0)->widget();
    QPixmap pixmap = widget->grab();
    QString defaultFilename = "exported_image.png";
    QString filter = "PNG Files (*.png);;JPEG Files (*.jpg *.jpeg);;All Files (*)";
    QString chosenFilePath = QFileDialog::getSaveFileName(this, "Save Image", defaultFilename, filter);
    if (!chosenFilePath.isEmpty()) {
        pixmap.save(chosenFilePath);
    }
}

void KMeansDialog::on_copy2DButton_clicked()
{
    QLayout *layout = ui->horizontalLayout_2; // 您的布局对象
    auto widget = layout->itemAt(0)->widget();
    QPixmap pixmap = widget->grab();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setPixmap(pixmap);
}

