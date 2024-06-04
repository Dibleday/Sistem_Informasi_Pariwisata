/********************************************************************************
** Form generated from reading UI file 'formlokasi.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMLOKASI_H
#define UI_FORMLOKASI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formlokasi
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_lokasiLabel;
    QLineEdit *id_lokasiLineEdit;
    QLabel *id_desaLabel;
    QLineEdit *id_desaLineEdit;
    QLabel *id_kategoriLabel;
    QLineEdit *id_kategoriLineEdit;
    QLabel *nama_lokasiLabel;
    QLineEdit *nama_lokasiLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *formlokasi)
    {
        if (formlokasi->objectName().isEmpty())
            formlokasi->setObjectName("formlokasi");
        formlokasi->resize(400, 300);
        formLayoutWidget = new QWidget(formlokasi);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 20, 331, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_lokasiLabel = new QLabel(formLayoutWidget);
        id_lokasiLabel->setObjectName("id_lokasiLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_lokasiLabel);

        id_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        id_lokasiLineEdit->setObjectName("id_lokasiLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_lokasiLineEdit);

        id_desaLabel = new QLabel(formLayoutWidget);
        id_desaLabel->setObjectName("id_desaLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, id_desaLabel);

        id_desaLineEdit = new QLineEdit(formLayoutWidget);
        id_desaLineEdit->setObjectName("id_desaLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, id_desaLineEdit);

        id_kategoriLabel = new QLabel(formLayoutWidget);
        id_kategoriLabel->setObjectName("id_kategoriLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, id_kategoriLabel);

        id_kategoriLineEdit = new QLineEdit(formLayoutWidget);
        id_kategoriLineEdit->setObjectName("id_kategoriLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, id_kategoriLineEdit);

        nama_lokasiLabel = new QLabel(formLayoutWidget);
        nama_lokasiLabel->setObjectName("nama_lokasiLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, nama_lokasiLabel);

        nama_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        nama_lokasiLineEdit->setObjectName("nama_lokasiLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, nama_lokasiLineEdit);

        pushButton = new QPushButton(formlokasi);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 140, 121, 24));
        pushButton_2 = new QPushButton(formlokasi);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 140, 121, 24));
        pushButton_3 = new QPushButton(formlokasi);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 170, 121, 24));
        pushButton_4 = new QPushButton(formlokasi);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(240, 170, 121, 24));

        retranslateUi(formlokasi);

        QMetaObject::connectSlotsByName(formlokasi);
    } // setupUi

    void retranslateUi(QWidget *formlokasi)
    {
        formlokasi->setWindowTitle(QCoreApplication::translate("formlokasi", "Form", nullptr));
        id_lokasiLabel->setText(QCoreApplication::translate("formlokasi", "id_lokasi", nullptr));
        id_desaLabel->setText(QCoreApplication::translate("formlokasi", "id_desa", nullptr));
        id_kategoriLabel->setText(QCoreApplication::translate("formlokasi", "id_kategori", nullptr));
        nama_lokasiLabel->setText(QCoreApplication::translate("formlokasi", "nama_lokasi", nullptr));
        pushButton->setText(QCoreApplication::translate("formlokasi", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formlokasi", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formlokasi", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formlokasi", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formlokasi: public Ui_formlokasi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMLOKASI_H
