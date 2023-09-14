#include "helpdialog.h"
#include "ui_helpdialog.h"
#include <QFile>


QString readHtmlFile(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QString();

    QTextStream in(&file);
    return in.readAll();
}

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    ui->textBrowser->setOpenExternalLinks(true); // 帮助文档中的外部链接可以打开
    QString Content = readHtmlFile(":/data/data/help.html");
    ui->textBrowser->setHtml(Content);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}


