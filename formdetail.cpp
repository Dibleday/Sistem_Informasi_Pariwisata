#include "formdetail.h"
#include "ui_formdetail.h"

formdetail::formdetail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formdetail)
{
    ui->setupUi(this);
}

formdetail::~formdetail()
{
    delete ui;
}

void formdetail::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO detail_lokasi (id_detail,id_lokasi,nama_lokasi)"
                "VALUE (:id_detail,:id_lokasi,:nama_lokasi)");
    sql.bindValue(":id_detail",ui->id_detailLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_lokasi",ui->nama_lokasiLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formdetail::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE detail_lokasi SET id_lokasi=:id_lokasi, nama_lokasi=:nama_lokasi "
                "WHERE id_detail=:id_detail");
    sql.bindValue(":id_detail",ui->id_detailLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_lokasi",ui->nama_lokasiLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formdetail::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM detail_lokasi WHERE id_detail=:id_detail");
    sql.bindValue(":id_detail",ui->id_detailLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formdetail::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM detail_lokasi WHERE id_detail=:id_detail");
    sql.bindValue(":id_detail",ui->id_detailLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

