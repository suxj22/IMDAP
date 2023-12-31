#ifndef PCADIALOG_H
#define PCADIALOG_H

#include "QtDataVisualization/qscatter3dseries.h"
#include <QDialog>
#include <QtDataVisualization>

namespace Ui {
class PCADialog;
}

class PCADialog : public QDialog
{
    Q_OBJECT

public:
    explicit PCADialog(QWidget *parent = nullptr, QWidget *contentWidget = nullptr, QList<QScatter3DSeries*> list = {});
    ~PCADialog();

    // 设置三维图表信息以绘制标签
    void setList(QList <QScatter3DSeries*> list);

private slots:

    // 导出和复制
    void on_exportButton_clicked();

    void on_copyButton_clicked();

private:
    Ui::PCADialog *ui;
    QWidget *contentWidget;
    QList <QScatter3DSeries*> List;
};

#endif // PCADIALOG_H
