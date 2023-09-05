#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Eigen/Dense"
#include "rowfeature.hpp"
#include "averageandmeandialog.h"
#include <vector>
#include <iostream>
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
    ui->textBrowser->setStyleSheet("QTextBrowser {"
                                 "background-color: white;"
                                 "border: 1px solid grey;"
                                 "}");
    ui->label->setStyleSheet("QLabel {"
                               "background-color: white;"
                               "border: 1px solid grey;"
                               "}");


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
        float currentValue = 0;
        for (int j = 1; j < ui->tableWidget->rowCount(); j++) {
            QTableWidgetItem* item = ui->tableWidget->item(j, 1); // 假定第二列是种类
            if (item) {
                QString text = item->text();
                if (!discreteValueMap.contains(text)) {
                    discreteValueMap[text] = currentValue; // 存储映射
                    QString pre = "文本中";
                    QString middle = "代表";
                    QString res = pre + text + middle + QString::number(static_cast<int>(currentValue)); // 存储映射关系
                    indexOfText.push_back(res);
                    currentValue++;
                }
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
bool MainWindow::tableWidgetIsEmpty() {
    if (ui->tableWidget->rowCount() == 0 || ui->tableWidget->columnCount() == 0) {
        return true;
    }
    else {
        return false;
    }
}
void MainWindow::tableEmptyWarning() {
    QMessageBox::warning(this, "警告", "未导入数据！");
    return;
}
void MainWindow::on_AverageAndMeanAction_triggered()
{
    if (tableWidgetIsEmpty()) {
        tableEmptyWarning();
        return;
    }
    AverageAndMeanDialog dialog(this);
    QStringList names;
    for (int i = 1; i < ui->tableWidget->columnCount(); i++) {
        QTableWidgetItem *item = ui->tableWidget->item(0, i);
        if(item != nullptr && item->text().isEmpty() == false) {
            names << item->text();
        }
    }
    dialog.setColumnNames(names);
    if (dialog.exec() == QDialog::Accepted) {
        int column = dialog.getSelectedColumn() + 1;
        int count = ui->tableWidget->rowCount();
        std::vector<float> x(count -1);
        for (int j = 1; j < count; j++) {
            QString text = ui->tableWidget->item(j, column)->text();
            if (column != 1) {
                x[j - 1] = text.toFloat();
            }
            else {
                x[j - 1] = discreteValueMap[text];
            }
        }
        auto avgVar = getAvgVar(x);
        float avg = std::get<0>(avgVar);
        float mean = std::get<1>(avgVar);
        QString result = QString("平均值：%1\n方差：%2").arg(avg).arg(mean);
        if(column == 1) {
            for (auto x : indexOfText) {
                result.append("\n" + x); // 添加映射说明
            }
        }
        ui->textBrowser->setText(result);
    }
}

