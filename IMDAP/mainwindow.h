#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loadCSVFileToTableWidget();

private:
    Ui::MainWindow *ui;
    QString lastImportedFilePath; // 避免重复导入相同文件
};
#endif // MAINWINDOW_H
