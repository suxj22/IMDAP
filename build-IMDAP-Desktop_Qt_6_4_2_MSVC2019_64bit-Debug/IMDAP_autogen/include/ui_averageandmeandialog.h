/********************************************************************************
** Form generated from reading UI file 'averageandmeandialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVERAGEANDMEANDIALOG_H
#define UI_AVERAGEANDMEANDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AverageAndMeanDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QDialog *AverageAndMeanDialog)
    {
        if (AverageAndMeanDialog->objectName().isEmpty())
            AverageAndMeanDialog->setObjectName("AverageAndMeanDialog");
        AverageAndMeanDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AverageAndMeanDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(AverageAndMeanDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 110, 165, 55));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);


        retranslateUi(AverageAndMeanDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AverageAndMeanDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AverageAndMeanDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AverageAndMeanDialog);
    } // setupUi

    void retranslateUi(QDialog *AverageAndMeanDialog)
    {
        AverageAndMeanDialog->setWindowTitle(QCoreApplication::translate("AverageAndMeanDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AverageAndMeanDialog", "\350\257\267\351\200\211\346\213\251\344\270\200\345\210\227\357\274\210\347\254\254\344\270\200\345\210\227\351\231\244\345\244\226\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AverageAndMeanDialog: public Ui_AverageAndMeanDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVERAGEANDMEANDIALOG_H
