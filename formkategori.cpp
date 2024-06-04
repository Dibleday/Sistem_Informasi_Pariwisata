#include "formkategori.h"
#include "ui_formkategori.h"

formkategori::formkategori(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formkategori)
{
    ui->setupUi(this);
}

formkategori::~formkategori()
{
    delete ui;
}

void formkategori::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO kategori (id_kategori,kategori)"
                "VALUE (:id_kategori,:kategori)");
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
    sql.bindValue(":kategori",ui->kategoriLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkategori::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE kategori SET kategori=:kategori "
                "WHERE id_kategori=:id_kategori");
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
    sql.bindValue(":kategori",ui->kategoriLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkategori::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM kategori WHERE id_kategori=:id_kategori");
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkategori::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM kategori WHERE id_kategori=:id_kategori");
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

