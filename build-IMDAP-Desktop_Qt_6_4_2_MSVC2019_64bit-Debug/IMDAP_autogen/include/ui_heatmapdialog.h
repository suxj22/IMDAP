/********************************************************************************
** Form generated from reading UI file 'heatmapdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEATMAPDIALOG_H
#define UI_HEATMAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include "drawheatmapwidget.h"

QT_BEGIN_NAMESPACE

class Ui_HeatmapDialog
{
public:
    QFormLayout *formLayout;
    QPushButton *exportButton;
    QRadioButton *radioButton_2;
    QPushButton *copyButton;
    DrawHeatmapWidget *widget;
    QRadioButton *radioButton;

    void setupUi(QDialog *HeatmapDialog)
    {
        if (HeatmapDialog->objectName().isEmpty())
            HeatmapDialog->setObjectName("HeatmapDialog");
        HeatmapDialog->resize(1280, 724);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HeatmapDialog->sizePolicy().hasHeightForWidth());
        HeatmapDialog->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(HeatmapDialog);
        formLayout->setObjectName("formLayout");
        exportButton = new QPushButton(HeatmapDialog);
        exportButton->setObjectName("exportButton");

        formLayout->setWidget(1, QFormLayout::FieldRole, exportButton);

        radioButton_2 = new QRadioButton(HeatmapDialog);
        radioButton_2->setObjectName("radioButton_2");

        formLayout->setWidget(3, QFormLayout::LabelRole, radioButton_2);

        copyButton = new QPushButton(HeatmapDialog);
        copyButton->setObjectName("copyButton");

        formLayout->setWidget(3, QFormLayout::FieldRole, copyButton);

        widget = new DrawHeatmapWidget(HeatmapDialog);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(800, 700));

        formLayout->setWidget(6, QFormLayout::LabelRole, widget);

        radioButton = new QRadioButton(HeatmapDialog);
        radioButton->setObjectName("radioButton");

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton);


        retranslateUi(HeatmapDialog);

        QMetaObject::connectSlotsByName(HeatmapDialog);
    } // setupUi

    void retranslateUi(QDialog *HeatmapDialog)
    {
        HeatmapDialog->setWindowTitle(QCoreApplication::translate("HeatmapDialog", "Dialog", nullptr));
        exportButton->setText(QCoreApplication::translate("HeatmapDialog", "\345\257\274\345\207\272", nullptr));
        radioButton_2->setText(QCoreApplication::translate("HeatmapDialog", "\347\233\270\345\205\263\346\200\247\347\237\251\351\230\265", nullptr));
        copyButton->setText(QCoreApplication::translate("HeatmapDialog", "\345\244\215\345\210\266", nullptr));
        radioButton->setText(QCoreApplication::translate("HeatmapDialog", "\345\215\217\346\226\271\345\267\256\347\237\251\351\230\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeatmapDialog: public Ui_HeatmapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEATMAPDIALOG_H
