#include "formdesa.h"
#include "ui_formdesa.h"

formdesa::formdesa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formdesa)
{
    ui->setupUi(this);
    QSqlDatabase koneksi = QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("dsn_pariwisata_");
    koneksi.setUserName("root");
    koneksi.setPassword("");

    if(!koneksi.open()){
        qDebug()<<koneksi.lastError().text();
    }else{
        qDebug()<<"Database Terkoneksi";

    }
}

formdesa::~formdesa()
{
    delete ui;
}

void formdesa::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO desa (id_desa,id_kecamatan,nama_kecamatan)"
                "VALUE (:id_desa,:id_kecamatan,:nama_kecamatan)");
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formdesa::on_pushButton_3_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE desa SET id_kecamatan=:id_kecamatan, nama_kecamatan=:nama_kecamatan "
                "WHERE id_desa=:id_desa");
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formdesa::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM desa WHERE id_desa=:id_desa");
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formdesa::on_pushButton_2_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM desa WHERE id_desa=:id_desa");
    sql.bindValue(":id_desa",ui->id_desaLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}

