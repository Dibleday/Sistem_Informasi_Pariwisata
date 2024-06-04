#include "formpengelola.h"
#include "ui_formpengelola.h"

formpengelola::formpengelola(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formpengelola)
{
    ui->setupUi(this);
}

formpengelola::~formpengelola()
{
    delete ui;
}

void formpengelola::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO pengelola (id_pengelola,id_lokasi,nama_pengelola)"
                "VALUE (:id_pengelola,:id_lokasi,:nama_pengelola)");
    sql.bindValue(":id_pengelola",ui->id_pengelolaLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengelola",ui->nama_pengelolaLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpengelola::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE pengelola SET id_lokasi=:nama_pengelola "
                "WHERE id_pengelola=:id_pengelola");
    sql.bindValue(":id_pengelola",ui->id_pengelolaLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengelola",ui->nama_pengelolaLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpengelola::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM pengelola WHERE id_pengelola=:id_lokasi=:nama_pengelola");
    sql.bindValue(":id_pengelola",ui->id_pengelolaLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengelola",ui->nama_pengelolaLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpengelola::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM pengelola WHERE id_pengelola=:id_pengelola");
    sql.bindValue(":id_pengelola",ui->id_pengelolaLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_pengelola",ui->nama_pengelolaLineEdit->text());


    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

