#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>

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

public slots:
    void loadCSVFileToTableWidget();

private slots:
    void on_AverageAndMeanAction_triggered();

private:
    Ui::MainWindow *ui;
    QString lastImportedFilePath; // 避免重复导入相同文件
    QHash<QString, float> discreteValueMap; // 将B/M映射为可计算的数
    QList<QString> indexOfText; // 存储文本映射的对应关系
};
#endif // MAINWINDOW_H
