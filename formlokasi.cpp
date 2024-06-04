#include "formlokasi.h"
#include "ui_formlokasi.h"

formlokasi::formlokasi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formlokasi)
{
    ui->setupUi(this);
}

formlokasi::~formlokasi()
{
    delete ui;
}

void formlokasi::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO lokasi_wisata (id_lokasi,id_desa,id_kategori,nama_lokasi)"
                "VALUE (:id_lokasi,:id_desa,:id_kategori,:nama_lokasi)");
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
    sql.bindValue(":nama_lokasi",ui->nama_lokasiLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formlokasi::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE lokasi_wisata SET id_desa=:id_kategori=:nama_lokasi "
                "WHERE id_lokasi=:id_lokasi");
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
    sql.bindValue(":nama_lokasi",ui->nama_lokasiLineEdit->text());



    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formlokasi::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM lokasi_wisata WHERE id_lokasi=:id_desa=:id_kategori=:nama_lokasi");
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
    sql.bindValue(":nama_lokasi",ui->nama_lokasiLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formlokasi::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM lokasi_wisata WHERE id_lokasi=:id_lokasi");
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
    sql.bindValue(":nama_lokasi",ui->nama_lokasiLineEdit->text());


    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

