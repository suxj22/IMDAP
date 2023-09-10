/********************************************************************************
** Form generated from reading UI file 'chartviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
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
    QCheckBox *ScatterCheckBox;
    QCheckBox *SplineCheckBox;
    QLabel *numOfDuplicatePointsLabel;
    QLabel *pValueLabel;
    QLabel *r2ValueLabel;
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

        ScatterCheckBox = new QCheckBox(ChartViewDialog);
        ScatterCheckBox->setObjectName("ScatterCheckBox");
        ScatterCheckBox->setTristate(false);

        horizontalLayout->addWidget(ScatterCheckBox);

        SplineCheckBox = new QCheckBox(ChartViewDialog);
        SplineCheckBox->setObjectName("SplineCheckBox");

        horizontalLayout->addWidget(SplineCheckBox);

        numOfDuplicatePointsLabel = new QLabel(ChartViewDialog);
        numOfDuplicatePointsLabel->setObjectName("numOfDuplicatePointsLabel");

        horizontalLayout->addWidget(numOfDuplicatePointsLabel);

        pValueLabel = new QLabel(ChartViewDialog);
        pValueLabel->setObjectName("pValueLabel");

        horizontalLayout->addWidget(pValueLabel);

        r2ValueLabel = new QLabel(ChartViewDialog);
        r2ValueLabel->setObjectName("r2ValueLabel");

        horizontalLayout->addWidget(r2ValueLabel);

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
        ScatterCheckBox->setText(QCoreApplication::translate("ChartViewDialog", "\346\225\243\347\202\271\345\233\276", nullptr));
        SplineCheckBox->setText(QCoreApplication::translate("ChartViewDialog", "\346\233\262\347\272\277\346\213\237\345\220\210", nullptr));
        numOfDuplicatePointsLabel->setText(QCoreApplication::translate("ChartViewDialog", "\351\207\215\345\244\215\347\202\271\344\270\252\346\225\260\357\274\2320\344\270\252", nullptr));
        pValueLabel->setText(QCoreApplication::translate("ChartViewDialog", "p\345\200\274\357\274\232", nullptr));
        r2ValueLabel->setText(QCoreApplication::translate("ChartViewDialog", "r^2\345\200\274\357\274\232", nullptr));
        DataLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChartViewDialog: public Ui_ChartViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTVIEWDIALOG_H
