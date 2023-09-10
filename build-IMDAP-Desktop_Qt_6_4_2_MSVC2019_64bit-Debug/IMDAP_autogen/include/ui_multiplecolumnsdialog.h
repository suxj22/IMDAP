/********************************************************************************
** Form generated from reading UI file 'multiplecolumnsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLECOLUMNSDIALOG_H
#define UI_MULTIPLECOLUMNSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MultipleColumnsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MultipleColumnsDialog)
    {
        if (MultipleColumnsDialog->objectName().isEmpty())
            MultipleColumnsDialog->setObjectName("MultipleColumnsDialog");
        MultipleColumnsDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(MultipleColumnsDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(MultipleColumnsDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(MultipleColumnsDialog);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(MultipleColumnsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MultipleColumnsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MultipleColumnsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MultipleColumnsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MultipleColumnsDialog);
    } // setupUi

    void retranslateUi(QDialog *MultipleColumnsDialog)
    {
        MultipleColumnsDialog->setWindowTitle(QCoreApplication::translate("MultipleColumnsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MultipleColumnsDialog", "\350\257\267\351\200\211\346\213\251\345\244\232\345\210\227\357\274\214id\345\210\227\344\270\215\345\217\257\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MultipleColumnsDialog: public Ui_MultipleColumnsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLECOLUMNSDIALOG_H
