/********************************************************************************
** Form generated from reading UI file 'selecttwocolumnsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTTWOCOLUMNSDIALOG_H
#define UI_SELECTTWOCOLUMNSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectTwoColumnsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QLineEdit *lineEdit;

    void setupUi(QDialog *SelectTwoColumnsDialog)
    {
        if (SelectTwoColumnsDialog->objectName().isEmpty())
            SelectTwoColumnsDialog->setObjectName("SelectTwoColumnsDialog");
        SelectTwoColumnsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(SelectTwoColumnsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(SelectTwoColumnsDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(110, 50, 160, 167));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName("comboBox_2");

        verticalLayout->addWidget(comboBox_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);


        retranslateUi(SelectTwoColumnsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SelectTwoColumnsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SelectTwoColumnsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SelectTwoColumnsDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectTwoColumnsDialog)
    {
        SelectTwoColumnsDialog->setWindowTitle(QCoreApplication::translate("SelectTwoColumnsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SelectTwoColumnsDialog", "\351\200\211\346\213\251\346\250\252\350\275\264\357\274\210id\345\210\227\344\270\215\345\217\257\351\200\211\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("SelectTwoColumnsDialog", "\351\200\211\346\213\251\347\272\265\350\275\264\357\274\210id\345\210\227\344\270\215\345\217\257\351\200\211\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("SelectTwoColumnsDialog", "\351\200\211\346\213\251\346\233\262\347\272\277\346\213\237\345\220\210\347\232\204\346\254\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectTwoColumnsDialog: public Ui_SelectTwoColumnsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTTWOCOLUMNSDIALOG_H
