/********************************************************************************
** Form generated from reading UI file 'formpengelola.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPENGELOLA_H
#define UI_FORMPENGELOLA_H

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

class Ui_formpengelola
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_pengelolaLabel;
    QLineEdit *id_pengelolaLineEdit;
    QLabel *id_lokasiLabel;
    QLineEdit *id_lokasiLineEdit;
    QLabel *nama_pengelolaLabel;
    QLineEdit *nama_pengelolaLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tablepengelola;

    void setupUi(QWidget *formpengelola)
    {
        if (formpengelola->objectName().isEmpty())
            formpengelola->setObjectName("formpengelola");
        formpengelola->resize(442, 289);
        formLayoutWidget = new QWidget(formpengelola);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 291, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_pengelolaLabel = new QLabel(formLayoutWidget);
        id_pengelolaLabel->setObjectName("id_pengelolaLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_pengelolaLabel);

        id_pengelolaLineEdit = new QLineEdit(formLayoutWidget);
        id_pengelolaLineEdit->setObjectName("id_pengelolaLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_pengelolaLineEdit);

        id_lokasiLabel = new QLabel(formLayoutWidget);
        id_lokasiLabel->setObjectName("id_lokasiLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, id_lokasiLabel);

        id_lokasiLineEdit = new QLineEdit(formLayoutWidget);
        id_lokasiLineEdit->setObjectName("id_lokasiLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, id_lokasiLineEdit);

        nama_pengelolaLabel = new QLabel(formLayoutWidget);
        nama_pengelolaLabel->setObjectName("nama_pengelolaLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, nama_pengelolaLabel);

        nama_pengelolaLineEdit = new QLineEdit(formLayoutWidget);
        nama_pengelolaLineEdit->setObjectName("nama_pengelolaLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, nama_pengelolaLineEdit);

        pushButton = new QPushButton(formpengelola);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 10, 121, 21));
        pushButton_2 = new QPushButton(formpengelola);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 30, 121, 21));
        pushButton_3 = new QPushButton(formpengelola);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(310, 50, 121, 21));
        pushButton_4 = new QPushButton(formpengelola);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(310, 70, 121, 21));
        tablepengelola = new QTableView(formpengelola);
        tablepengelola->setObjectName("tablepengelola");
        tablepengelola->setGeometry(QRect(10, 100, 421, 181));

        retranslateUi(formpengelola);

        QMetaObject::connectSlotsByName(formpengelola);
    } // setupUi

    void retranslateUi(QWidget *formpengelola)
    {
        formpengelola->setWindowTitle(QCoreApplication::translate("formpengelola", "Form", nullptr));
        id_pengelolaLabel->setText(QCoreApplication::translate("formpengelola", "ID Pengelola", nullptr));
        id_lokasiLabel->setText(QCoreApplication::translate("formpengelola", "ID Lokasi", nullptr));
        nama_pengelolaLabel->setText(QCoreApplication::translate("formpengelola", "Nama Pengelola", nullptr));
        pushButton->setText(QCoreApplication::translate("formpengelola", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formpengelola", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formpengelola", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formpengelola", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formpengelola: public Ui_formpengelola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPENGELOLA_H
