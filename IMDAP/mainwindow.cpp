#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Eigen/Dense"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, &QAction::triggered, this, &MainWindow::loadCSVFileToTableWidget);
}

void MainWindow::loadCSVFileToTableWidget() {
    QString filePath = ":/data/data/breast-cancer.csv";
    if (filePath == lastImportedFilePath) {
        QMessageBox::information(this, "提示", "请勿重复导入！");
        return;
    }
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(","); // 逗号作为分隔符

            if (ui->tableWidget->columnCount() < fields.size()) {
                ui->tableWidget->setColumnCount(fields.size());  // 动态设置列数
            }

            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row); // 插入新行
            for (int i = 0; i < fields.size(); ++i) {
                QTableWidgetItem *newItem = new QTableWidgetItem(fields[i]);
                ui->tableWidget->setItem(row, i, newItem);
            }
        }
        lastImportedFilePath = filePath;
        file.close();
    }
    else {
        QMessageBox::warning(this, "警告", "导入文件失败！");
    }
    return;
}
MainWindow::~MainWindow()
{
    delete ui;
}

