#include "formpengelola.h"
#include "ui_formpengelola.h"
#include "QMessageBox"

formpengelola::formpengelola(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formpengelola)
{
    ui->setupUi(this);
    loadtablepengelola();
}

void formpengelola::loadtablepengelola()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM pengelola ORDER BY id_pengelola ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Pengelola"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Lokasi"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Nama Pengelola"));

    ui->tablepengelola->setModel(tabelModel);
    ui->tablepengelola->setColumnWidth(0,150);
    ui->tablepengelola->setColumnWidth(1,150);
    ui->tablepengelola->setColumnWidth(2,150);
    ui->tablepengelola->show();
}

formpengelola::~formpengelola()
{
    delete ui;
}

void formpengelola::on_pushButton_clicked()
{
        if(ui->id_pengelolaLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Id Pengelola belum diisi");
            ui->id_pengelolaLineEdit->setFocus();
        }else if(ui->id_lokasiLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "ID Lokasi belum diisi");
            ui->id_lokasiLineEdit->setFocus();
        }else if(ui->nama_pengelolaLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Nama Pengelola belum diisi");
            ui->nama_pengelolaLineEdit->setFocus();
        }else {
            QSqlQuery duplicate;
            duplicate.prepare("SELECT * FROM pengelola WHERE id_pengelola = '"+ui->id_pengelolaLineEdit->text()+"'");
            duplicate.exec();
            if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Pengelola sudah terdaftar");
            ui->id_pengelolaLineEdit->setText(duplicate.value(1).toString());
            ui->id_lokasiLineEdit->setText(duplicate.value(2).toString());
            ui->nama_pengelolaLineEdit->setText(duplicate.value(3).toString());
        }else{
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


void formpengelola::on_tablepengelola_activated(const QModelIndex &index)
{
    int baris = ui->tablepengelola->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_pengelolaLineEdit->setText(ui->tablepengelola->model()->index(baris,0).data().toString());
    ui->id_lokasiLineEdit->setText(ui->tablepengelola->model()->index(baris,1).data().toString());
    ui->nama_pengelolaLineEdit->setText(ui->tablepengelola->model()->index(baris,2).data().toString());
}

