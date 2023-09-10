#ifndef MULTIPLECOLUMNSDIALOG_H
#define MULTIPLECOLUMNSDIALOG_H

#include "QtWidgets/qlistwidget.h"
#include <QDialog>

namespace Ui {
class MultipleColumnsDialog;
}

class MultipleColumnsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MultipleColumnsDialog(QWidget *parent = nullptr, const QStringList &names = {});
    ~MultipleColumnsDialog();
    QList <int> getItems();


private slots:
    void on_buttonBox_accepted();

private:
    Ui::MultipleColumnsDialog *ui;
    QList <int> items;
};

#endif // MULTIPLECOLUMNSDIALOG_H
