/********************************************************************************
** Form generated from reading UI file 'formpromosi.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPROMOSI_H
#define UI_FORMPROMOSI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formpromosi
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_promosiLabel;
    QLineEdit *id_promosiLineEdit;
    QLabel *id_lokasiLabel;
    QLineEdit *id_lokasiLineEdit;
    QLabel *nama_promoLabel;
    QLineEdit *nama_promoLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *formpromosi)
    {
        if (formpromosi->objectName().isEmpty())
            formpromosi->setObjectName("formpromosi");
        formpromosi->resize(400, 300);
        formLayoutWidget = new QWidget(formpromosi);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 20, 311, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_promosiLabel = new QLabel(formLayoutWidget);
        id_promosiLabel->setObjectName("id_promosiLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_promosiLabel);

        id_promosiLineEdit = new QLineEdit(formLayoutWidget);
        id_promosiLineEdit->setObjectName("id_promosiLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_promosiLineEdit);

        id_lokasiLabel = new QLabel(formLayoutWidget);
        id_lokasiLabel->setObjectName("id_lokasiLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, id_lokasiLabel);

        id_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        id_lokasiLineEdit->setObjectName("id_lokasiLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, id_lokasiLineEdit);

        nama_promoLabel = new QLabel(formLayoutWidget);
        nama_promoLabel->setObjectName("nama_promoLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, nama_promoLabel);

        nama_promoLineEdit = new QLineEdit(formLayoutWidget);
        nama_promoLineEdit->setObjectName("nama_promoLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, nama_promoLineEdit);

        pushButton = new QPushButton(formpromosi);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 110, 141, 24));
        pushButton_2 = new QPushButton(formpromosi);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 110, 141, 24));
        pushButton_3 = new QPushButton(formpromosi);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 140, 141, 24));
        pushButton_4 = new QPushButton(formpromosi);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(210, 140, 141, 24));

        retranslateUi(formpromosi);

        QMetaObject::connectSlotsByName(formpromosi);
    } // setupUi

    void retranslateUi(QWidget *formpromosi)
    {
        formpromosi->setWindowTitle(QCoreApplication::translate("formpromosi", "Form", nullptr));
        id_promosiLabel->setText(QCoreApplication::translate("formpromosi", "id_promosi", nullptr));
        id_lokasiLabel->setText(QCoreApplication::translate("formpromosi", "id_lokasi", nullptr));
        nama_promoLabel->setText(QCoreApplication::translate("formpromosi", "nama_promo", nullptr));
        pushButton->setText(QCoreApplication::translate("formpromosi", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formpromosi", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formpromosi", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formpromosi", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formpromosi: public Ui_formpromosi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPROMOSI_H
