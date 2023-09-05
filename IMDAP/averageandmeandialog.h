#ifndef AVERAGEANDMEANDIALOG_H
#define AVERAGEANDMEANDIALOG_H

#include <QDialog>

namespace Ui {
class AverageAndMeanDialog;
}

class AverageAndMeanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AverageAndMeanDialog(QWidget *parent = nullptr);
    ~AverageAndMeanDialog();
    void setColumnNames(const QStringList &name);
    int getSelectedColumn() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AverageAndMeanDialog *ui;
    int selectedColumn;

};

#endif // AVERAGEANDMEANDIALOG_H
