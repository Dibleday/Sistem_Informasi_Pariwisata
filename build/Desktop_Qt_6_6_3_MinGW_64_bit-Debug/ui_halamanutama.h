/********************************************************************************
** Form generated from reading UI file 'halamanutama.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HALAMANUTAMA_H
#define UI_HALAMANUTAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_halamanutama
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *halamanutama)
    {
        if (halamanutama->objectName().isEmpty())
            halamanutama->setObjectName("halamanutama");
        halamanutama->resize(324, 181);
        centralwidget = new QWidget(halamanutama);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 20, 75, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 50, 75, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 80, 75, 24));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(130, 20, 75, 24));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(130, 50, 75, 24));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(130, 80, 75, 24));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(220, 20, 75, 24));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(220, 50, 75, 24));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(220, 80, 75, 24));
        halamanutama->setCentralWidget(centralwidget);
        menubar = new QMenuBar(halamanutama);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 324, 22));
        halamanutama->setMenuBar(menubar);
        statusbar = new QStatusBar(halamanutama);
        statusbar->setObjectName("statusbar");
        halamanutama->setStatusBar(statusbar);
        toolBar = new QToolBar(halamanutama);
        toolBar->setObjectName("toolBar");
        halamanutama->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(halamanutama);

        QMetaObject::connectSlotsByName(halamanutama);
    } // setupUi

    void retranslateUi(QMainWindow *halamanutama)
    {
        halamanutama->setWindowTitle(QCoreApplication::translate("halamanutama", "halamanutama", nullptr));
        pushButton->setText(QCoreApplication::translate("halamanutama", "Desa", nullptr));
        pushButton_2->setText(QCoreApplication::translate("halamanutama", "Detail Lokasi", nullptr));
        pushButton_3->setText(QCoreApplication::translate("halamanutama", "Event", nullptr));
        pushButton_4->setText(QCoreApplication::translate("halamanutama", "Kategori", nullptr));
        pushButton_5->setText(QCoreApplication::translate("halamanutama", "Kecamatan", nullptr));
        pushButton_6->setText(QCoreApplication::translate("halamanutama", "Lokasi", nullptr));
        pushButton_7->setText(QCoreApplication::translate("halamanutama", "Pengelola", nullptr));
        pushButton_8->setText(QCoreApplication::translate("halamanutama", "Pengunjung", nullptr));
        pushButton_9->setText(QCoreApplication::translate("halamanutama", "Promosi", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("halamanutama", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class halamanutama: public Ui_halamanutama {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HALAMANUTAMA_H
