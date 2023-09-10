#ifndef HEATMAPDIALOG_H
#define HEATMAPDIALOG_H

#include <QDialog>
#include "drawheatmapwidget.h"

namespace Ui {
class HeatmapDialog;
}

class HeatmapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HeatmapDialog(QWidget *parent = nullptr);
    ~HeatmapDialog();
    void setDataCov(const QVector<QVector<float>> &data);
    void setDataPer(const QVector<QVector<float>> &data);
    void setLabels(const QStringList &names);

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_exportButton_clicked();

    void on_copyButton_clicked();

private:
    Ui::HeatmapDialog *ui;
};

#endif // HEATMAPDIALOG_H
