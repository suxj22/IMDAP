#include "averageandmeandialog.h"
#include "ui_averageandmeandialog.h"

AverageAndMeanDialog::AverageAndMeanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AverageAndMeanDialog)
{
    ui->setupUi(this);
}

AverageAndMeanDialog::~AverageAndMeanDialog()
{
    delete ui;
}

void AverageAndMeanDialog::setColumnNames(const QStringList &name) {
    ui->comboBox->addItems(name);
}

int AverageAndMeanDialog::getSelectedColumn() const {
    return selectedColumn;
}
void AverageAndMeanDialog::on_buttonBox_accepted()
{
    selectedColumn = ui->comboBox->currentIndex();
}

