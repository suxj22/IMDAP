#ifndef SELECTTWOCOLUMNSDIALOG_H
#define SELECTTWOCOLUMNSDIALOG_H

#include <QDialog>

namespace Ui {
class SelectTwoColumnsDialog;
}

class SelectTwoColumnsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectTwoColumnsDialog(QWidget *parent = nullptr);
    ~SelectTwoColumnsDialog();
    void setColumnNames(const QStringList &name); // 设置comboBox内容
    int getSelectedColumnX() const; // 返回选择的横轴
    int getSelectedColumnY() const; // 返回选择的纵轴

private:
    Ui::SelectTwoColumnsDialog *ui;
};

#endif // SELECTTWOCOLUMNSDIALOG_H
