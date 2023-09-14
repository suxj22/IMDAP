#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool tableWidgetIsEmpty();
    void tableEmptyWarning();
    QStringList GetColumnNames();
    float normalFit(float stddev, float avg, float x);
    void displaySelectedCellInfo(); // 实现简单的信息显示

public slots:
    void loadCSVFileToTableWidget();

private slots:
    void on_AverageAndMeanAction_triggered();

    void on_HistogramAction_triggered();

    void on_ScatterAction_triggered();

    void on_Matrixaction_triggered();

    void on_PCAAction_triggered();

    void on_actionKMeans_triggered();

    void on_ShowColoraction_triggered(bool checked);

    void on_clearButton_clicked();

    void on_copyButton_clicked();

    void on_Helpaction_triggered();

private:
    Ui::MainWindow *ui;
    QString lastImportedFilePath; // 避免重复导入相同文件
    QHash<QString, float> discreteValueMap; // 将B/M映射为可计算的数
    QHash<float, QString> reverseValueMap;
    QList<QString> indexOfText; // 存储文本映射的对应关系
    QChartView *chartView; // 存储汇出的图像
    QList<QColor> colors = {Qt::red, Qt::blue, Qt::green, Qt::yellow, Qt::cyan, Qt::magenta, Qt::gray, Qt::darkBlue, Qt::darkGreen, Qt::darkCyan}; // 存储聚类的颜色
};
#endif // MAINWINDOW_H
