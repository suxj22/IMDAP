/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *AverageAndMeanAction;
    QAction *HistogramAction;
    QAction *ScatterAction;
    QAction *Matrixaction;
    QAction *PCAAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/wenjian.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action->setMenuRole(QAction::TextHeuristicRole);
        action->setIconVisibleInMenu(false);
        AverageAndMeanAction = new QAction(MainWindow);
        AverageAndMeanAction->setObjectName("AverageAndMeanAction");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/pingjunzhi.png"), QSize(), QIcon::Normal, QIcon::Off);
        AverageAndMeanAction->setIcon(icon1);
        HistogramAction = new QAction(MainWindow);
        HistogramAction->setObjectName("HistogramAction");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/zhifangtu.png"), QSize(), QIcon::Normal, QIcon::Off);
        HistogramAction->setIcon(icon2);
        ScatterAction = new QAction(MainWindow);
        ScatterAction->setObjectName("ScatterAction");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/sandiantu.png"), QSize(), QIcon::Normal, QIcon::Off);
        ScatterAction->setIcon(icon3);
        Matrixaction = new QAction(MainWindow);
        Matrixaction->setObjectName("Matrixaction");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/xiangguanxingjuzhentu.png"), QSize(), QIcon::Normal, QIcon::Off);
        Matrixaction->setIcon(icon4);
        PCAAction = new QAction(MainWindow);
        PCAAction->setObjectName("PCAAction");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/pca.png"), QSize(), QIcon::Normal, QIcon::Off);
        PCAAction->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(900, 400));
        QFont font;
        font.setFamilies({QString::fromUtf8(".AppleSystemUIFont")});
        tableWidget->setFont(font);

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setMinimumSize(QSize(0, 0));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        formLayout = new QFormLayout(dockWidgetContents);
        formLayout->setObjectName("formLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        textBrowser = new QTextBrowser(dockWidgetContents);
        textBrowser->setObjectName("textBrowser");

        verticalLayout_2->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        formLayout->setLayout(2, QFormLayout::LabelRole, verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_4 = new QPushButton(dockWidgetContents);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(dockWidgetContents);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_2);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget);

        toolBar->addAction(action);
        toolBar->addSeparator();
        toolBar->addAction(AverageAndMeanAction);
        toolBar->addAction(HistogramAction);
        toolBar->addAction(ScatterAction);
        toolBar->addAction(Matrixaction);
        toolBar->addAction(PCAAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\226\207\344\273\266", nullptr));
        AverageAndMeanAction->setText(QCoreApplication::translate("MainWindow", "\345\235\207\345\200\274\345\222\214\346\226\271\345\267\256", nullptr));
#if QT_CONFIG(tooltip)
        AverageAndMeanAction->setToolTip(QCoreApplication::translate("MainWindow", "\345\235\207\345\200\274\345\222\214\346\226\271\345\267\256", nullptr));
#endif // QT_CONFIG(tooltip)
        HistogramAction->setText(QCoreApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\345\222\214\346\255\243\346\200\201\345\210\206\345\270\203\346\233\262\347\272\277", nullptr));
#if QT_CONFIG(tooltip)
        HistogramAction->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\345\222\214\346\255\243\346\200\201\345\210\206\345\270\203\346\233\262\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        ScatterAction->setText(QCoreApplication::translate("MainWindow", "\346\225\243\347\202\271\345\233\276\345\222\214\346\233\262\347\272\277\346\213\237\345\220\210", nullptr));
#if QT_CONFIG(tooltip)
        ScatterAction->setToolTip(QCoreApplication::translate("MainWindow", "\346\225\243\347\202\271\345\233\276\345\222\214\346\233\262\347\272\277\346\213\237\345\220\210", nullptr));
#endif // QT_CONFIG(tooltip)
        Matrixaction->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\205\263\346\200\247\345\222\214\345\215\217\346\226\271\345\267\256\347\237\251\351\230\265", nullptr));
#if QT_CONFIG(tooltip)
        Matrixaction->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\270\345\205\263\346\200\247\345\222\214\345\215\217\346\226\271\345\267\256\347\237\251\351\230\265", nullptr));
#endif // QT_CONFIG(tooltip)
        PCAAction->setText(QCoreApplication::translate("MainWindow", "PCA\351\231\215\347\273\264", nullptr));
#if QT_CONFIG(tooltip)
        PCAAction->setToolTip(QCoreApplication::translate("MainWindow", "PCA\351\231\215\347\273\264", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
