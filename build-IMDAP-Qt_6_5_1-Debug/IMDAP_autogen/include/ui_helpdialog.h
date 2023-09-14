/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName("HelpDialog");
        HelpDialog->resize(1280, 720);
        gridLayout = new QGridLayout(HelpDialog);
        gridLayout->setObjectName("gridLayout");
        buttonBox = new QDialogButtonBox(HelpDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(HelpDialog);
        textBrowser->setObjectName("textBrowser");

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(HelpDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HelpDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HelpDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QCoreApplication::translate("HelpDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
