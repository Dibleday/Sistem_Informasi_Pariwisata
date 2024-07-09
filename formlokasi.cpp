#include "formlokasi.h"
#include "ui_formlokasi.h"
#include "QMessageBox"

formlokasi::formlokasi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formlokasi)
{
    ui->setupUi(this);
    loadtablelokasi();
}

void formlokasi::loadtablelokasi()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM lokasi_wisata ORDER BY id_lokasi ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Lokasi"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Desa"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("ID Kategori"));
    tabelModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Nama Lokasi"));

    ui->tablelokasi->setModel(tabelModel);
    ui->tablelokasi->setColumnWidth(0,150);
    ui->tablelokasi->setColumnWidth(1,150);
    ui->tablelokasi->setColumnWidth(2,150);
    ui->tablelokasi->setColumnWidth(3,150);
    ui->tablelokasi->show();
}

formlokasi::~formlokasi()
{
    delete ui;
}

void formlokasi::on_pushButton_clicked()
{
        if(ui->id_lokasiLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Id Lokasi belum diisi");
            ui->id_lokasiLineEdit->setFocus();
        }else if(ui->id_desaLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "ID Desa belum diisi");
            ui->id_desaLineEdit->setFocus();
        }else if(ui->id_kategoriLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "ID Kategori belum diisi");
            ui->id_kategoriLineEdit->setFocus();
        }else if(ui->nama_lokasiLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Nama Lokasi belum diisi");
            ui->nama_lokasiLineEdit->setFocus();
        }else {
            QSqlQuery duplicate;
            duplicate.prepare("SELECT * FROM lokasi_wisata WHERE id_lokasi = '"+ui->id_lokasiLineEdit->text()+"'");
            duplicate.exec();
            if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Lokasi sudah terdaftar");
            ui->id_lokasiLineEdit->setText(duplicate.value(1).toString());
            ui->id_desaLineEdit->setText(duplicate.value(2).toString());
            ui->id_kategoriLineEdit->setText(duplicate.value(3).toString());
            ui->nama_lokasiLineEdit->setText(duplicate.value(4).toString());
        }else{
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


void formlokasi::on_tablelokasi_activated(const QModelIndex &index)
{
    int baris = ui->tablelokasi->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_lokasiLineEdit->setText(ui->tablelokasi->model()->index(baris,0).data().toString());
    ui->id_desaLineEdit->setText(ui->tablelokasi->model()->index(baris,1).data().toString());
    ui->id_kategoriLineEdit->setText(ui->tablelokasi->model()->index(baris,2).data().toString());
    ui->nama_lokasiLineEdit->setText(ui->tablelokasi->model()->index(baris,3).data().toString());
}

