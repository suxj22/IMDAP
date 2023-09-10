#include "pcadialog.h"
#include "ui_pcadialog.h"

PCADialog::PCADialog(QWidget *parent, QWidget *contentWidget) :
    QDialog(parent),
    ui(new Ui::PCADialog)
{
    ui->setupUi(this);
    ui->formLayout->addWidget(contentWidget);
}

PCADialog::~PCADialog()
{
    delete ui;
}
