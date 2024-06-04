/********************************************************************************
** Form generated from reading UI file 'formpengunjung.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPENGUNJUNG_H
#define UI_FORMPENGUNJUNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formpengunjung
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_pengunjungLabel;
    QLineEdit *id_pengunjungLineEdit;
    QLabel *id_lokasiLabel;
    QLineEdit *id_lokasiLineEdit;
    QLabel *nama_pengunjungLabel;
    QLineEdit *nama_pengunjungLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *formpengunjung)
    {
        if (formpengunjung->objectName().isEmpty())
            formpengunjung->setObjectName("formpengunjung");
        formpengunjung->resize(400, 300);
        formLayoutWidget = new QWidget(formpengunjung);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 20, 361, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_pengunjungLabel = new QLabel(formLayoutWidget);
        id_pengunjungLabel->setObjectName("id_pengunjungLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_pengunjungLabel);

        id_pengunjungLineEdit = new QLineEdit(formLayoutWidget);
        id_pengunjungLineEdit->setObjectName("id_pengunjungLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_pengunjungLineEdit);

        id_lokasiLabel = new QLabel(formLayoutWidget);
        id_lokasiLabel->setObjectName("id_lokasiLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, id_lokasiLabel);

        id_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        id_lokasiLineEdit->setObjectName("id_lokasiLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, id_lokasiLineEdit);

        nama_pengunjungLabel = new QLabel(formLayoutWidget);
        nama_pengunjungLabel->setObjectName("nama_pengunjungLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, nama_pengunjungLabel);

        nama_pengunjungLineEdit = new QLineEdit(formLayoutWidget);
        nama_pengunjungLineEdit->setObjectName("nama_pengunjungLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, nama_pengunjungLineEdit);

        pushButton = new QPushButton(formpengunjung);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 120, 141, 24));
        pushButton_2 = new QPushButton(formpengunjung);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 120, 141, 24));
        pushButton_3 = new QPushButton(formpengunjung);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 150, 141, 24));
        pushButton_4 = new QPushButton(formpengunjung);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(240, 150, 141, 24));

        retranslateUi(formpengunjung);

        QMetaObject::connectSlotsByName(formpengunjung);
    } // setupUi

    void retranslateUi(QWidget *formpengunjung)
    {
        formpengunjung->setWindowTitle(QCoreApplication::translate("formpengunjung", "Form", nullptr));
        id_pengunjungLabel->setText(QCoreApplication::translate("formpengunjung", "id_pengunjung", nullptr));
        id_lokasiLabel->setText(QCoreApplication::translate("formpengunjung", "id_lokasi", nullptr));
        nama_pengunjungLabel->setText(QCoreApplication::translate("formpengunjung", "nama_pengunjung", nullptr));
        pushButton->setText(QCoreApplication::translate("formpengunjung", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formpengunjung", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formpengunjung", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formpengunjung", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formpengunjung: public Ui_formpengunjung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPENGUNJUNG_H
