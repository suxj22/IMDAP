#ifndef MULTIPLECOLUMNSDIALOG_H
#define MULTIPLECOLUMNSDIALOG_H

#include <QDialog>

namespace Ui {
class MultipleColumnsDialog;
}

class MultipleColumnsDialog : public QDialog
{
    Q_OBJECT

public:
    // 构造函数，存储所有列信息
    explicit MultipleColumnsDialog(QWidget *parent = nullptr, const QStringList &names = {});
    ~MultipleColumnsDialog();
    // 获取选择的所有列
    QList <int> getItems();


private slots:
    void on_buttonBox_accepted();

private:
    Ui::MultipleColumnsDialog *ui;
    QList <int> items;
};

#endif // MULTIPLECOLUMNSDIALOG_H
