/********************************************************************************
** Form generated from reading UI file 'formdetail.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDETAIL_H
#define UI_FORMDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formdetail
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_detailLabel;
    QLineEdit *id_detailLineEdit;
    QLabel *id_lokasiLabel;
    QLineEdit *id_lokasiLineEdit;
    QLabel *penginapanLabel;
    QLineEdit *penginapanLineEdit;
    QLabel *nama_lokasiLabel;
    QLineEdit *nama_lokasiLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *formdetail)
    {
        if (formdetail->objectName().isEmpty())
            formdetail->setObjectName("formdetail");
        formdetail->resize(400, 300);
        formLayoutWidget = new QWidget(formdetail);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(60, 20, 271, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_detailLabel = new QLabel(formLayoutWidget);
        id_detailLabel->setObjectName("id_detailLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_detailLabel);

        id_detailLineEdit = new QLineEdit(formLayoutWidget);
        id_detailLineEdit->setObjectName("id_detailLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_detailLineEdit);

        id_lokasiLabel = new QLabel(formLayoutWidget);
        id_lokasiLabel->setObjectName("id_lokasiLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, id_lokasiLabel);

        id_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        id_lokasiLineEdit->setObjectName("id_lokasiLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, id_lokasiLineEdit);

        penginapanLabel = new QLabel(formLayoutWidget);
        penginapanLabel->setObjectName("penginapanLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, penginapanLabel);

        penginapanLineEdit = new QLineEdit(formLayoutWidget);
        penginapanLineEdit->setObjectName("penginapanLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, penginapanLineEdit);

        nama_lokasiLabel = new QLabel(formLayoutWidget);
        nama_lokasiLabel->setObjectName("nama_lokasiLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, nama_lokasiLabel);

        nama_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        nama_lokasiLineEdit->setObjectName("nama_lokasiLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, nama_lokasiLineEdit);

        pushButton = new QPushButton(formdetail);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 150, 121, 24));
        pushButton_2 = new QPushButton(formdetail);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 150, 121, 24));
        pushButton_3 = new QPushButton(formdetail);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(60, 180, 121, 24));
        pushButton_4 = new QPushButton(formdetail);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(210, 180, 121, 24));

        retranslateUi(formdetail);

        QMetaObject::connectSlotsByName(formdetail);
    } // setupUi

    void retranslateUi(QWidget *formdetail)
    {
        formdetail->setWindowTitle(QCoreApplication::translate("formdetail", "Form", nullptr));
        id_detailLabel->setText(QCoreApplication::translate("formdetail", "id_detail", nullptr));
        id_lokasiLabel->setText(QCoreApplication::translate("formdetail", "id_lokasi", nullptr));
        penginapanLabel->setText(QCoreApplication::translate("formdetail", "penginapan", nullptr));
        nama_lokasiLabel->setText(QCoreApplication::translate("formdetail", "nama_lokasi", nullptr));
        pushButton->setText(QCoreApplication::translate("formdetail", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formdetail", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formdetail", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formdetail", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formdetail: public Ui_formdetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDETAIL_H
