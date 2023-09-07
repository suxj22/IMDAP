/********************************************************************************
** Form generated from reading UI file 'chartviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTVIEWDIALOG_H
#define UI_CHARTVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChartViewDialog
{
public:
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *exportImageButton;
    QPushButton *copyToClipboardButton;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QLabel *numOfDuplicatePointsLabel;
    QLabel *DataLabel;

    void setupUi(QDialog *ChartViewDialog)
    {
        if (ChartViewDialog->objectName().isEmpty())
            ChartViewDialog->setObjectName("ChartViewDialog");
        ChartViewDialog->resize(1280, 720);
        formLayout = new QFormLayout(ChartViewDialog);
        formLayout->setObjectName("formLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        exportImageButton = new QPushButton(ChartViewDialog);
        exportImageButton->setObjectName("exportImageButton");

        horizontalLayout->addWidget(exportImageButton);

        copyToClipboardButton = new QPushButton(ChartViewDialog);
        copyToClipboardButton->setObjectName("copyToClipboardButton");

        horizontalLayout->addWidget(copyToClipboardButton);

        checkBox_2 = new QCheckBox(ChartViewDialog);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout->addWidget(checkBox_2);

        checkBox = new QCheckBox(ChartViewDialog);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);

        numOfDuplicatePointsLabel = new QLabel(ChartViewDialog);
        numOfDuplicatePointsLabel->setObjectName("numOfDuplicatePointsLabel");

        horizontalLayout->addWidget(numOfDuplicatePointsLabel);

        DataLabel = new QLabel(ChartViewDialog);
        DataLabel->setObjectName("DataLabel");

        horizontalLayout->addWidget(DataLabel);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(ChartViewDialog);

        QMetaObject::connectSlotsByName(ChartViewDialog);
    } // setupUi

    void retranslateUi(QDialog *ChartViewDialog)
    {
        ChartViewDialog->setWindowTitle(QCoreApplication::translate("ChartViewDialog", "Dialog", nullptr));
        exportImageButton->setText(QCoreApplication::translate("ChartViewDialog", "\345\257\274\345\207\272", nullptr));
        copyToClipboardButton->setText(QCoreApplication::translate("ChartViewDialog", "\345\244\215\345\210\266", nullptr));
        checkBox_2->setText(QCoreApplication::translate("ChartViewDialog", "\346\225\243\347\202\271\345\233\276", nullptr));
        checkBox->setText(QCoreApplication::translate("ChartViewDialog", "\346\233\262\347\272\277\346\213\237\345\220\210", nullptr));
        numOfDuplicatePointsLabel->setText(QCoreApplication::translate("ChartViewDialog", "\351\207\215\345\244\215\347\202\271\344\270\252\346\225\260\357\274\232123\344\270\252", nullptr));
        DataLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChartViewDialog: public Ui_ChartViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTVIEWDIALOG_H
