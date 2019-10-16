/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *Ishodnie;
    QRadioButton *Rasschetnie;
    QFrame *line;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *ObshieIshodnie;
    QRadioButton *KND;
    QRadioButton *KVD;
    QRadioButton *TVD;
    QRadioButton *TND;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1200, 750);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1200, 750));
        MainWindow->setMaximumSize(QSize(1200, 750));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(260, 10, 931, 731));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setTabletTracking(true);
        tableView->setFocusPolicy(Qt::StrongFocus);
        tableView->setAutoFillBackground(false);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 231, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Ishodnie = new QRadioButton(verticalLayoutWidget);
        Ishodnie->setObjectName(QStringLiteral("Ishodnie"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Ishodnie->sizePolicy().hasHeightForWidth());
        Ishodnie->setSizePolicy(sizePolicy2);
        Ishodnie->setAutoFillBackground(false);
        Ishodnie->setChecked(true);

        verticalLayout->addWidget(Ishodnie);

        Rasschetnie = new QRadioButton(verticalLayoutWidget);
        Rasschetnie->setObjectName(QStringLiteral("Rasschetnie"));
        sizePolicy2.setHeightForWidth(Rasschetnie->sizePolicy().hasHeightForWidth());
        Rasschetnie->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(Rasschetnie);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 100, 231, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 120, 231, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ObshieIshodnie = new QRadioButton(verticalLayoutWidget_2);
        ObshieIshodnie->setObjectName(QStringLiteral("ObshieIshodnie"));
        ObshieIshodnie->setCheckable(true);
        ObshieIshodnie->setChecked(false);

        verticalLayout_2->addWidget(ObshieIshodnie);

        KND = new QRadioButton(verticalLayoutWidget_2);
        KND->setObjectName(QStringLiteral("KND"));

        verticalLayout_2->addWidget(KND);

        KVD = new QRadioButton(verticalLayoutWidget_2);
        KVD->setObjectName(QStringLiteral("KVD"));

        verticalLayout_2->addWidget(KVD);

        TVD = new QRadioButton(verticalLayoutWidget_2);
        TVD->setObjectName(QStringLiteral("TVD"));

        verticalLayout_2->addWidget(TVD);

        TND = new QRadioButton(verticalLayoutWidget_2);
        TND->setObjectName(QStringLiteral("TND"));

        verticalLayout_2->addWidget(TND);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Ishodnie->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        Rasschetnie->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        ObshieIshodnie->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\211\320\270\320\265 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        KND->setText(QApplication::translate("MainWindow", "\320\232\320\235\320\224 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        KVD->setText(QApplication::translate("MainWindow", "\320\232\320\222\320\224 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        TVD->setText(QApplication::translate("MainWindow", "\320\242\320\222\320\224 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        TND->setText(QApplication::translate("MainWindow", "\320\242\320\235\320\224 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
