/********************************************************************************
** Form generated from reading UI file 'pcadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCADIALOG_H
#define UI_PCADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "Legend3D.h"

QT_BEGIN_NAMESPACE

class Ui_PCADialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *exportButton;
    QPushButton *copyButton;
    QHBoxLayout *horizontalLayout_4;
    Legend3D *widget;

    void setupUi(QDialog *PCADialog)
    {
        if (PCADialog->objectName().isEmpty())
            PCADialog->setObjectName("PCADialog");
        PCADialog->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PCADialog->sizePolicy().hasHeightForWidth());
        PCADialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(PCADialog);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        exportButton = new QPushButton(PCADialog);
        exportButton->setObjectName("exportButton");

        horizontalLayout->addWidget(exportButton);

        copyButton = new QPushButton(PCADialog);
        copyButton->setObjectName("copyButton");

        horizontalLayout->addWidget(copyButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        widget = new Legend3D(PCADialog);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(50, 600));

        horizontalLayout_4->addWidget(widget);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);


        retranslateUi(PCADialog);

        QMetaObject::connectSlotsByName(PCADialog);
    } // setupUi

    void retranslateUi(QDialog *PCADialog)
    {
        PCADialog->setWindowTitle(QCoreApplication::translate("PCADialog", "Dialog", nullptr));
        exportButton->setText(QCoreApplication::translate("PCADialog", "\345\257\274\345\207\272\351\231\215\347\273\264\345\233\276\357\274\210\344\273\205\345\257\271\344\272\214\347\273\264\345\233\276\346\234\211\346\225\210\357\274\211", nullptr));
        copyButton->setText(QCoreApplication::translate("PCADialog", "\345\244\215\345\210\266\351\231\215\347\273\264\345\233\276\357\274\210\344\273\205\345\257\271\344\272\214\347\273\264\345\233\276\346\234\211\346\225\210\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PCADialog: public Ui_PCADialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCADIALOG_H
