#include "formkecamatan.h"
#include "ui_formkecamatan.h"

formkecamatan::formkecamatan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formkecamatan)
{
    ui->setupUi(this);
}

formkecamatan::~formkecamatan()
{
    delete ui;
}

void formkecamatan::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO kecamatan (id_kecamatan,nama_kecamatan)"
                "VALUE (:id_kecamatan,:nama_kecamatan)");
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkecamatan::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE kecamatan SET nama_kecamatan=:nama_kecamatan "
                "WHERE id_kecamatan=:id_kecamatan");
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkecamatan::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM kecamatan WHERE id_kecamatan=:id_kecamatan");
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkecamatan::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM kecamatan WHERE id_kecamatan=:id_kecamatan");
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());


    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

