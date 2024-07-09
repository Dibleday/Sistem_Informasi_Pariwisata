/********************************************************************************
** Form generated from reading UI file 'formdesa.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDESA_H
#define UI_FORMDESA_H

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

class Ui_formdesa
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_desaLabel;
    QLineEdit *id_desaLineEdit;
    QLabel *id_kecamatanLabel;
    QLineEdit *id_kecamatanLineEdit;
    QLabel *nama_kecamatanLabel;
    QLineEdit *nama_kecamatanLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tabledesa;

    void setupUi(QWidget *formdesa)
    {
        if (formdesa->objectName().isEmpty())
            formdesa->setObjectName("formdesa");
        formdesa->resize(530, 322);
        formLayoutWidget = new QWidget(formdesa);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 20, 331, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_desaLabel = new QLabel(formLayoutWidget);
        id_desaLabel->setObjectName("id_desaLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_desaLabel);

        id_desaLineEdit = new QLineEdit(formLayoutWidget);
        id_desaLineEdit->setObjectName("id_desaLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_desaLineEdit);

        id_kecamatanLabel = new QLabel(formLayoutWidget);
        id_kecamatanLabel->setObjectName("id_kecamatanLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, id_kecamatanLabel);

        id_kecamatanLineEdit = new QLineEdit(formLayoutWidget);
        id_kecamatanLineEdit->setObjectName("id_kecamatanLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, id_kecamatanLineEdit);

        nama_kecamatanLabel = new QLabel(formLayoutWidget);
        nama_kecamatanLabel->setObjectName("nama_kecamatanLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, nama_kecamatanLabel);

        nama_kecamatanLineEdit = new QLineEdit(formLayoutWidget);
        nama_kecamatanLineEdit->setObjectName("nama_kecamatanLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, nama_kecamatanLineEdit);

        pushButton = new QPushButton(formdesa);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(370, 20, 131, 21));
        pushButton_2 = new QPushButton(formdesa);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(370, 80, 131, 21));
        pushButton_3 = new QPushButton(formdesa);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(370, 50, 131, 21));
        pushButton_4 = new QPushButton(formdesa);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(370, 110, 131, 21));
        tabledesa = new QTableView(formdesa);
        tabledesa->setObjectName("tabledesa");
        tabledesa->setGeometry(QRect(30, 140, 471, 161));

        retranslateUi(formdesa);

        QMetaObject::connectSlotsByName(formdesa);
    } // setupUi

    void retranslateUi(QWidget *formdesa)
    {
        formdesa->setWindowTitle(QCoreApplication::translate("formdesa", "Form", nullptr));
        id_desaLabel->setText(QCoreApplication::translate("formdesa", "ID Desa", nullptr));
        id_kecamatanLabel->setText(QCoreApplication::translate("formdesa", "ID Kecamatan", nullptr));
        nama_kecamatanLabel->setText(QCoreApplication::translate("formdesa", "Nama Kecamatan", nullptr));
        pushButton->setText(QCoreApplication::translate("formdesa", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formdesa", "Hapus", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formdesa", "Ubah", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formdesa", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formdesa: public Ui_formdesa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDESA_H
