#include "multiplecolumnsdialog.h"
#include "ui_multiplecolumnsdialog.h"

MultipleColumnsDialog::MultipleColumnsDialog(QWidget *parent, const QStringList &names) :
    QDialog(parent),
    ui(new Ui::MultipleColumnsDialog)
{
    ui->setupUi(this);
    // 初始化listWidget
    for (const QString &itemText : names) {
        QListWidgetItem *item = new QListWidgetItem(itemText, ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);  // 设置项目为可检查（有复选框）
        item->setCheckState(Qt::Unchecked);  // 默认设置为未勾选状态
        ui->listWidget->addItem(item);
    }
}

MultipleColumnsDialog::~MultipleColumnsDialog()
{
    delete ui;
}

QList <int> MultipleColumnsDialog::getItems() {
    return items;
}

void MultipleColumnsDialog::on_buttonBox_accepted()
{
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (item->checkState() == Qt::Checked) {
            items.append(ui->listWidget->row(item));
        }
    }
}

