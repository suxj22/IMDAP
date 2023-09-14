/********************************************************************************
** Form generated from reading UI file 'kmeansdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KMEANSDIALOG_H
#define UI_KMEANSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_KMeansDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *export2DButton;
    QPushButton *copy2DButton;

    void setupUi(QDialog *KMeansDialog)
    {
        if (KMeansDialog->objectName().isEmpty())
            KMeansDialog->setObjectName("KMeansDialog");
        KMeansDialog->resize(1280, 720);
        gridLayout = new QGridLayout(KMeansDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        export2DButton = new QPushButton(KMeansDialog);
        export2DButton->setObjectName("export2DButton");

        horizontalLayout->addWidget(export2DButton);

        copy2DButton = new QPushButton(KMeansDialog);
        copy2DButton->setObjectName("copy2DButton");

        horizontalLayout->addWidget(copy2DButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(KMeansDialog);

        QMetaObject::connectSlotsByName(KMeansDialog);
    } // setupUi

    void retranslateUi(QDialog *KMeansDialog)
    {
        KMeansDialog->setWindowTitle(QCoreApplication::translate("KMeansDialog", "Dialog", nullptr));
        export2DButton->setText(QCoreApplication::translate("KMeansDialog", "\345\257\274\345\207\272\344\272\214\347\273\264\350\201\232\347\261\273\345\233\276", nullptr));
        copy2DButton->setText(QCoreApplication::translate("KMeansDialog", "\345\244\215\345\210\266\344\272\214\347\273\264\350\201\232\347\261\273\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KMeansDialog: public Ui_KMeansDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KMEANSDIALOG_H
