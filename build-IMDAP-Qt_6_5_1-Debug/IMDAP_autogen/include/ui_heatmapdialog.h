/********************************************************************************
** Form generated from reading UI file 'heatmapdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEATMAPDIALOG_H
#define UI_HEATMAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include "drawheatmapwidget.h"

QT_BEGIN_NAMESPACE

class Ui_HeatmapDialog
{
public:
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QPushButton *exportButton;
    QRadioButton *radioButton_2;
    QPushButton *copyButton;
    DrawHeatmapWidget *widget;

    void setupUi(QDialog *HeatmapDialog)
    {
        if (HeatmapDialog->objectName().isEmpty())
            HeatmapDialog->setObjectName("HeatmapDialog");
        HeatmapDialog->resize(1280, 840);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HeatmapDialog->sizePolicy().hasHeightForWidth());
        HeatmapDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(HeatmapDialog);
        gridLayout->setObjectName("gridLayout");
        radioButton = new QRadioButton(HeatmapDialog);
        radioButton->setObjectName("radioButton");

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        exportButton = new QPushButton(HeatmapDialog);
        exportButton->setObjectName("exportButton");

        gridLayout->addWidget(exportButton, 0, 1, 1, 1);

        radioButton_2 = new QRadioButton(HeatmapDialog);
        radioButton_2->setObjectName("radioButton_2");

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);

        copyButton = new QPushButton(HeatmapDialog);
        copyButton->setObjectName("copyButton");

        gridLayout->addWidget(copyButton, 1, 1, 1, 1);

        widget = new DrawHeatmapWidget(HeatmapDialog);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(800, 700));

        gridLayout->addWidget(widget, 2, 0, 1, 1);


        retranslateUi(HeatmapDialog);

        QMetaObject::connectSlotsByName(HeatmapDialog);
    } // setupUi

    void retranslateUi(QDialog *HeatmapDialog)
    {
        HeatmapDialog->setWindowTitle(QCoreApplication::translate("HeatmapDialog", "Dialog", nullptr));
        radioButton->setText(QCoreApplication::translate("HeatmapDialog", "\345\215\217\346\226\271\345\267\256\347\237\251\351\230\265", nullptr));
        exportButton->setText(QCoreApplication::translate("HeatmapDialog", "\345\257\274\345\207\272", nullptr));
        radioButton_2->setText(QCoreApplication::translate("HeatmapDialog", "\347\233\270\345\205\263\346\200\247\347\237\251\351\230\265", nullptr));
        copyButton->setText(QCoreApplication::translate("HeatmapDialog", "\345\244\215\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeatmapDialog: public Ui_HeatmapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEATMAPDIALOG_H
