#include "selecttwocolumnsdialog.h"
#include "QtGui/qstandarditemmodel.h"
#include "QtWidgets/qlistview.h"
#include "ui_selecttwocolumnsdialog.h"
#include <QRegularExpressionValidator>

SelectTwoColumnsDialog::SelectTwoColumnsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectTwoColumnsDialog)
{
    QRegularExpression regExp("^[1-9]\\d*$"); // 拟合次数只能为正整数
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp);
    ui->setupUi(this);
    ui->lineEdit->setValidator(validator);
}

SelectTwoColumnsDialog::~SelectTwoColumnsDialog()
{
    delete ui;
}

void SelectTwoColumnsDialog::setColumnNames(const QStringList &name) {
    ui->comboBox->addItems(name);
    ui->comboBox_2->addItems(name);
}

int SelectTwoColumnsDialog::getSelectedColumnX() const {
    return ui->comboBox->currentIndex();
}

int SelectTwoColumnsDialog::getSelectedColumnY() const {
    return ui->comboBox_2->currentIndex();
}

int SelectTwoColumnsDialog::getInputDegree() const {
    if (ui->lineEdit->text().isEmpty()) {
        return -1;
    }
    return ui->lineEdit->text().toInt();
}
