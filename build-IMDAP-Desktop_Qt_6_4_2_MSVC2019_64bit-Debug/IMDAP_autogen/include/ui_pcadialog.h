/********************************************************************************
** Form generated from reading UI file 'pcadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCADIALOG_H
#define UI_PCADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PCADialog
{
public:
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *PCADialog)
    {
        if (PCADialog->objectName().isEmpty())
            PCADialog->setObjectName("PCADialog");
        PCADialog->resize(1280, 720);
        formLayout = new QFormLayout(PCADialog);
        formLayout->setObjectName("formLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_2 = new QPushButton(PCADialog);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(PCADialog);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout);


        retranslateUi(PCADialog);

        QMetaObject::connectSlotsByName(PCADialog);
    } // setupUi

    void retranslateUi(QDialog *PCADialog)
    {
        PCADialog->setWindowTitle(QCoreApplication::translate("PCADialog", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PCADialog", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("PCADialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PCADialog: public Ui_PCADialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCADIALOG_H
