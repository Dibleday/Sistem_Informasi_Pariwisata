/********************************************************************************
** Form generated from reading UI file 'formevent.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEVENT_H
#define UI_FORMEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formevent
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_eventLabel;
    QLineEdit *id_eventLineEdit;
    QLabel *id_lokasiLabel;
    QLineEdit *id_lokasiLineEdit;
    QLabel *nama_eventLabel;
    QLineEdit *nama_eventLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *formevent)
    {
        if (formevent->objectName().isEmpty())
            formevent->setObjectName("formevent");
        formevent->resize(400, 300);
        formLayoutWidget = new QWidget(formevent);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 20, 301, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_eventLabel = new QLabel(formLayoutWidget);
        id_eventLabel->setObjectName("id_eventLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_eventLabel);

        id_eventLineEdit = new QLineEdit(formLayoutWidget);
        id_eventLineEdit->setObjectName("id_eventLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_eventLineEdit);

        id_lokasiLabel = new QLabel(formLayoutWidget);
        id_lokasiLabel->setObjectName("id_lokasiLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, id_lokasiLabel);

        id_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        id_lokasiLineEdit->setObjectName("id_lokasiLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, id_lokasiLineEdit);

        nama_eventLabel = new QLabel(formLayoutWidget);
        nama_eventLabel->setObjectName("nama_eventLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, nama_eventLabel);

        nama_eventLineEdit = new QLineEdit(formLayoutWidget);
        nama_eventLineEdit->setObjectName("nama_eventLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, nama_eventLineEdit);

        pushButton = new QPushButton(formevent);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 120, 131, 24));
        pushButton_2 = new QPushButton(formevent);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 120, 131, 24));
        pushButton_3 = new QPushButton(formevent);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(50, 150, 131, 24));
        pushButton_4 = new QPushButton(formevent);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(220, 150, 131, 24));

        retranslateUi(formevent);

        QMetaObject::connectSlotsByName(formevent);
    } // setupUi

    void retranslateUi(QWidget *formevent)
    {
        formevent->setWindowTitle(QCoreApplication::translate("formevent", "Form", nullptr));
        id_eventLabel->setText(QCoreApplication::translate("formevent", "id_event", nullptr));
        id_lokasiLabel->setText(QCoreApplication::translate("formevent", "id_lokasi", nullptr));
        nama_eventLabel->setText(QCoreApplication::translate("formevent", "nama_event", nullptr));
        pushButton->setText(QCoreApplication::translate("formevent", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formevent", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formevent", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formevent", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formevent: public Ui_formevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEVENT_H
