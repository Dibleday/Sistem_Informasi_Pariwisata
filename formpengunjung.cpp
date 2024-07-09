#include "formpengunjung.h"
#include "ui_formpengunjung.h"
#include "QMessageBox"

formpengunjung::formpengunjung(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formpengunjung)
{
    ui->setupUi(this);
    loadbtablepengjunjung();
}

void formpengunjung::loadbtablepengjunjung()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM pengunjung ORDER BY id_pengunjung ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Pengunjung"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Lokasi"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Nama Pengunjung"));

    ui->tablepengunjung->setModel(tabelModel);
    ui->tablepengunjung->setColumnWidth(0,160);
    ui->tablepengunjung->setColumnWidth(1,160);
    ui->tablepengunjung->setColumnWidth(2,175);
    ui->tablepengunjung->show();
}

formpengunjung::~formpengunjung()
{
    delete ui;
}

void formpengunjung::on_pushButton_clicked()
{
        if(ui->id_pengunjungLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Id Pengunjung belum diisi");
            ui->id_pengunjungLineEdit->setFocus();
        }else if(ui->id_lokasiLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "ID Lokasi belum diisi");
            ui->id_lokasiLineEdit->setFocus();
        }else if(ui->nama_pengunjungLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Nama Pengunjung belum diisi");
            ui->nama_pengunjungLineEdit->setFocus();
        }else {
            QSqlQuery duplicate;
            duplicate.prepare("SELECT * FROM pengunjung WHERE id_pengunjung = '"+ui->id_pengunjungLineEdit->text()+"'");
            duplicate.exec();
            if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Pengunjung sudah terdaftar");
            ui->id_pengunjungLineEdit->setText(duplicate.value(1).toString());
            ui->id_lokasiLineEdit->setText(duplicate.value(2).toString());
            ui->nama_pengunjungLineEdit->setText(duplicate.value(3).toString());
        }else{
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


void formpengunjung::on_tablepengunjung_activated(const QModelIndex &index)
{
    int baris = ui->tablepengunjung->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_pengunjungLineEdit->setText(ui->tablepengunjung->model()->index(baris,0).data().toString());
    ui->id_lokasiLineEdit->setText(ui->tablepengunjung->model()->index(baris,1).data().toString());
    ui->nama_pengunjungLineEdit->setText(ui->tablepengunjung->model()->index(baris,2).data().toString());
}

