#include "formpengunjung.h"
#include "ui_formpengunjung.h"

formpengunjung::formpengunjung(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formpengunjung)
{
    ui->setupUi(this);
}

formpengunjung::~formpengunjung()
{
    delete ui;
}

void formpengunjung::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO pengunjung (id_pengunjung,id_lokasi,nama_pengunjung)"
                "VALUE (:id_pengunjung,:id_lokasi,:nama_pengunjung)");
    sql.bindValue(":id_pengunjung",ui->id_pengunjungLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengunjung",ui->nama_pengunjungLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpengunjung::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE pengelola SET id_lokasi=:nama_pengunjung "
                "WHERE id_pengunjung=:id_pengunjung");
    sql.bindValue(":id_pengunjung",ui->id_pengunjungLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengunjung",ui->nama_pengunjungLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpengunjung::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM pengunjung WHERE id_pengunjung=:id_lokasi=:nama_pengunjung");
    sql.bindValue(":id_pengunjung",ui->id_pengunjungLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengunjung",ui->nama_pengunjungLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpengunjung::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM pengunjung WHERE id_pengunjung=:id_pengunjung");
    sql.bindValue(":id_pengunjung",ui->id_pengunjungLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengunjung",ui->nama_pengunjungLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

