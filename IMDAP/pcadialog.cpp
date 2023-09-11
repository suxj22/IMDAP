#include "pcadialog.h"
#include "ui_pcadialog.h"

PCADialog::PCADialog(QWidget *parent, QWidget *contentWidget) :
    QDialog(parent),
    ui(new Ui::PCADialog)
{
    ui->setupUi(this);
    contentWidget->setMinimumSize(1200, 650);
    contentWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->formLayout->addWidget(contentWidget);

}

PCADialog::~PCADialog()
{
    delete ui;
}
