/********************************************************************************
** Form generated from reading UI file 'formkategori.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMKATEGORI_H
#define UI_FORMKATEGORI_H

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

class Ui_formkategori
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *id_kategoriLabel;
    QLineEdit *id_kategoriLineEdit;
    QLabel *kategoriLabel;
    QLineEdit *kategoriLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tablekategori;

    void setupUi(QWidget *formkategori)
    {
        if (formkategori->objectName().isEmpty())
            formkategori->setObjectName("formkategori");
        formkategori->resize(589, 289);
        formLayoutWidget = new QWidget(formkategori);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 20, 321, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        id_kategoriLabel = new QLabel(formLayoutWidget);
        id_kategoriLabel->setObjectName("id_kategoriLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, id_kategoriLabel);

        id_kategoriLineEdit = new QLineEdit(formLayoutWidget);
        id_kategoriLineEdit->setObjectName("id_kategoriLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, id_kategoriLineEdit);

        kategoriLabel = new QLabel(formLayoutWidget);
        kategoriLabel->setObjectName("kategoriLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, kategoriLabel);

        kategoriLineEdit = new QLineEdit(formLayoutWidget);
        kategoriLineEdit->setObjectName("kategoriLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, kategoriLineEdit);

        pushButton = new QPushButton(formkategori);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 20, 101, 24));
        pushButton_2 = new QPushButton(formkategori);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 50, 101, 24));
        pushButton_3 = new QPushButton(formkategori);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(460, 20, 101, 24));
        pushButton_4 = new QPushButton(formkategori);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(460, 50, 101, 24));
        tablekategori = new QTableView(formkategori);
        tablekategori->setObjectName("tablekategori");
        tablekategori->setGeometry(QRect(30, 80, 531, 192));

        retranslateUi(formkategori);

        QMetaObject::connectSlotsByName(formkategori);
    } // setupUi

    void retranslateUi(QWidget *formkategori)
    {
        formkategori->setWindowTitle(QCoreApplication::translate("formkategori", "Form", nullptr));
        id_kategoriLabel->setText(QCoreApplication::translate("formkategori", "ID Kategori", nullptr));
        kategoriLabel->setText(QCoreApplication::translate("formkategori", "Kategori", nullptr));
        pushButton->setText(QCoreApplication::translate("formkategori", "Simpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("formkategori", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("formkategori", "Hapus", nullptr));
        pushButton_4->setText(QCoreApplication::translate("formkategori", "Cari", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formkategori: public Ui_formkategori {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMKATEGORI_H
