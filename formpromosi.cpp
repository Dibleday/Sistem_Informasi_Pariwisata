#include "formpromosi.h"
#include "ui_formpromosi.h"

formpromosi::formpromosi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formpromosi)
{
    ui->setupUi(this);
}

formpromosi::~formpromosi()
{
    delete ui;
}

void formpromosi::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO promosi (id_promosi,id_lokasi,nama_promo)"
                "VALUE (:id_promosi,:id_lokasi,:nama_promo)");
    sql.bindValue(":id_promosi",ui->id_promosiLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_promo",ui->nama_promoLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpromosi::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE promosi SET id_lokasi=:nama_promo "
                "WHERE id_promosi=:id_promosi");
    sql.bindValue(":id_promosi",ui->id_promosiLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_promo",ui->nama_promoLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpromosi::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM promosi WHERE id_promosi=:id_lokasi=:nama_promo");
    sql.bindValue(":id_promosi",ui->id_promosiLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_promo",ui->nama_promoLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formpromosi::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM promosi WHERE id_promosi=:id_promosi");
    sql.bindValue(":id_promosi",ui->id_promosiLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_promo",ui->nama_promoLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

