/********************************************************************************
** Form generated from reading UI file 'histogramdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMDIALOG_H
#define UI_HISTOGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HistogramDialog
{
public:
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *exportImageButton;
    QPushButton *copyToClipboardButton;
    QCheckBox *HistogramCheckBox;
    QCheckBox *SplineCheckBox;

    void setupUi(QDialog *HistogramDialog)
    {
        if (HistogramDialog->objectName().isEmpty())
            HistogramDialog->setObjectName("HistogramDialog");
        HistogramDialog->resize(1280, 720);
        formLayout = new QFormLayout(HistogramDialog);
        formLayout->setObjectName("formLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        exportImageButton = new QPushButton(HistogramDialog);
        exportImageButton->setObjectName("exportImageButton");

        horizontalLayout->addWidget(exportImageButton);

        copyToClipboardButton = new QPushButton(HistogramDialog);
        copyToClipboardButton->setObjectName("copyToClipboardButton");

        horizontalLayout->addWidget(copyToClipboardButton);

        HistogramCheckBox = new QCheckBox(HistogramDialog);
        HistogramCheckBox->setObjectName("HistogramCheckBox");

        horizontalLayout->addWidget(HistogramCheckBox);

        SplineCheckBox = new QCheckBox(HistogramDialog);
        SplineCheckBox->setObjectName("SplineCheckBox");

        horizontalLayout->addWidget(SplineCheckBox);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);


        retranslateUi(HistogramDialog);

        QMetaObject::connectSlotsByName(HistogramDialog);
    } // setupUi

    void retranslateUi(QDialog *HistogramDialog)
    {
        HistogramDialog->setWindowTitle(QCoreApplication::translate("HistogramDialog", "Dialog", nullptr));
        exportImageButton->setText(QCoreApplication::translate("HistogramDialog", "\345\257\274\345\207\272", nullptr));
        copyToClipboardButton->setText(QCoreApplication::translate("HistogramDialog", "\345\244\215\345\210\266", nullptr));
        HistogramCheckBox->setText(QCoreApplication::translate("HistogramDialog", "\347\233\264\346\226\271\345\233\276", nullptr));
        SplineCheckBox->setText(QCoreApplication::translate("HistogramDialog", "\346\255\243\346\200\201\345\210\206\345\270\203\346\233\262\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistogramDialog: public Ui_HistogramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMDIALOG_H
