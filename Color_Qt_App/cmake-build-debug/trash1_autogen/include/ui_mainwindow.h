/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *chooseButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *R;
    QSpinBox *G;
    QSpinBox *B;
    QDoubleSpinBox *C;
    QDoubleSpinBox *M;
    QDoubleSpinBox *Y;
    QDoubleSpinBox *K;
    QDoubleSpinBox *X;
    QDoubleSpinBox *XYZY;
    QDoubleSpinBox *Z;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 20, 540, 161));
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::Box);
        chooseButton = new QPushButton(centralwidget);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(300, 210, 160, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 300, 60, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 400, 60, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 400, 60, 20));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 500, 60, 20));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(650, 300, 60, 20));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(650, 400, 60, 20));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(650, 500, 60, 20));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 300, 60, 20));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 400, 60, 20));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 500, 60, 20));
        label_11->setAlignment(Qt::AlignCenter);
        R = new QSpinBox(centralwidget);
        R->setObjectName(QString::fromUtf8("R"));
        R->setGeometry(QRect(50, 250, 60, 50));
        R->setMaximum(255);
        G = new QSpinBox(centralwidget);
        G->setObjectName(QString::fromUtf8("G"));
        G->setGeometry(QRect(50, 350, 60, 50));
        G->setMaximum(255);
        B = new QSpinBox(centralwidget);
        B->setObjectName(QString::fromUtf8("B"));
        B->setGeometry(QRect(50, 450, 60, 50));
        B->setMaximum(255);
        C = new QDoubleSpinBox(centralwidget);
        C->setObjectName(QString::fromUtf8("C"));
        C->setGeometry(QRect(350, 250, 60, 50));
        C->setDecimals(0);
        C->setMaximum(100.000000000000000);
        M = new QDoubleSpinBox(centralwidget);
        M->setObjectName(QString::fromUtf8("M"));
        M->setGeometry(QRect(300, 350, 60, 50));
        M->setDecimals(0);
        M->setMaximum(100.000000000000000);
        M->setSingleStep(1.000000000000000);
        Y = new QDoubleSpinBox(centralwidget);
        Y->setObjectName(QString::fromUtf8("Y"));
        Y->setGeometry(QRect(400, 350, 60, 50));
        Y->setDecimals(0);
        Y->setMaximum(100.000000000000000);
        K = new QDoubleSpinBox(centralwidget);
        K->setObjectName(QString::fromUtf8("K"));
        K->setGeometry(QRect(350, 450, 60, 50));
        K->setDecimals(0);
        K->setMinimum(0.000000000000000);
        K->setMaximum(100.000000000000000);
        K->setSingleStep(1.000000000000000);
        K->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        K->setValue(1.000000000000000);
        X = new QDoubleSpinBox(centralwidget);
        X->setObjectName(QString::fromUtf8("X"));
        X->setGeometry(QRect(650, 250, 60, 50));
        X->setDecimals(0);
        X->setMaximum(100.000000000000000);
        XYZY = new QDoubleSpinBox(centralwidget);
        XYZY->setObjectName(QString::fromUtf8("XYZY"));
        XYZY->setGeometry(QRect(650, 350, 60, 50));
        XYZY->setDecimals(0);
        XYZY->setMaximum(100.000000000000000);
        Z = new QDoubleSpinBox(centralwidget);
        Z->setObjectName(QString::fromUtf8("Z"));
        Z->setGeometry(QRect(650, 450, 60, 50));
        Z->setDecimals(0);
        Z->setMaximum(100.000000000000000);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        chooseButton->setText(QCoreApplication::translate("MainWindow", "Choose color", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
