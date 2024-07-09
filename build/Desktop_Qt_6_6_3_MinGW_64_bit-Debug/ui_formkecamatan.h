/********************************************************************************
** Form generated from reading UI file 'formkecamatan.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMKECAMATAN_H
#define UI_FORMKECAMATAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formkecamatan
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_kecamatanLabel;
    QLineEdit *id_kecamatanLineEdit;
    QLabel *nama_kecamatanLabel;
    QLineEdit *nama_kecamatanLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tablekecamatan;

    void setupUi(QWidget *formkecamatan)
    {
        if (formkecamatan->objectName().isEmpty())
            formkecamatan->setObjectName("formkecamatan");
        formkecamatan->resize(490, 278);
        formLayoutWidget = new QWidget(formkecamatan);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 251, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_kecamatanLabel = new QLabel(formLayoutWidget);
        id_kecamatanLabel->setObjectName("id_kecamatanLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_kecamatanLabel);

        id_kecamatanLineEdit = new QLineEdit(formLayoutWidget);
        id_kecamatanLineEdit->setObjectName("id_kecamatanLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_kecamatanLineEdit);

        nama_kecamatanLabel = new QLabel(formLayoutWidget);
        nama_kecamatanLabel->setObjectName("nama_kecamatanLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, nama_kecamatanLabel);

        nama_kecamatanLineEdit = new QLineEdit(formLayoutWidget);
        nama_kecamatanLineEdit->setObjectName("nama_kecamatanLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, nama_kecamatanLineEdit);

        pushButton = new QPushButton(formkecamatan);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 10, 101, 24));
        pushButton_2 = new QPushButton(formkecamatan);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 40, 101, 24));
        pushButton_3 = new QPushButton(formkecamatan);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(380, 10, 101, 24));
        pushButton_4 = new QPushButton(formkecamatan);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(380, 40, 101, 24));
        tablekecamatan = new QTableView(formkecamatan);
        tablekecamatan->setObjectName("tablekecamatan");
        tablekecamatan->setGeometry(QRect(10, 70, 471, 192));

        retranslateUi(formkecamatan);

        QMetaObject::connectSlotsByName(formkecamatan);
    } // setupUi

    void retranslateUi(QWidget *formkecamatan)
    {
        formkecamatan->setWindowTitle(QCoreApplication::translate("formkecamatan", "Form", nullptr));
        id_kecamatanLabel->setText(QCoreApplication::translate("formkecamatan", "ID Kecamatan", nullptr));
        nama_kecamatanLabel->setText(QCoreApplication::translate("formkecamatan", "Nama Kecamatan", nullptr));
        pushButton->setText(QCoreApplication::translate("formkecamatan", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formkecamatan", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formkecamatan", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formkecamatan", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formkecamatan: public Ui_formkecamatan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMKECAMATAN_H
