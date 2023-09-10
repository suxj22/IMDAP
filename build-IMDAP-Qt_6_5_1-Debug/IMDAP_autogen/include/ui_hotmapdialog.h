/********************************************************************************
** Form generated from reading UI file 'hotmapdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTMAPDIALOG_H
#define UI_HOTMAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QVBoxLayout>
#include "hotmapdialog.h"

QT_BEGIN_NAMESPACE

class Ui_HotMapDialog
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    HeatmapWidget *heatMapWidget;

    void setupUi(QDialog *HotMapDialog)
    {
        if (HotMapDialog->objectName().isEmpty())
            HotMapDialog->setObjectName("HotMapDialog");
        HotMapDialog->resize(1280, 720);
        formLayout = new QFormLayout(HotMapDialog);
        formLayout->setObjectName("formLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        heatMapWidget = new HeatmapWidget(HotMapDialog);
        heatMapWidget->setObjectName("heatMapWidget");

        verticalLayout->addWidget(heatMapWidget);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);


        retranslateUi(HotMapDialog);

        QMetaObject::connectSlotsByName(HotMapDialog);
    } // setupUi

    void retranslateUi(QDialog *HotMapDialog)
    {
        HotMapDialog->setWindowTitle(QCoreApplication::translate("HotMapDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotMapDialog: public Ui_HotMapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTMAPDIALOG_H
