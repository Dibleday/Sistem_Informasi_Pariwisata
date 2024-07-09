#include "formdetail.h"
#include "ui_formdetail.h"
#include "QMessageBox"

formdetail::formdetail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formdetail)
{
    ui->setupUi(this);
    loadtabledetail();
}

void formdetail::loadtabledetail()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM detail_lokasi ORDER BY id_detail ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Detail Lokasi"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Lokasi"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Penginapan"));
    tabelModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Nama Lokasi"));

    ui->tabledetail->setModel(tabelModel);
    ui->tabledetail->setColumnWidth(0,150);
    ui->tabledetail->setColumnWidth(1,150);
    ui->tabledetail->setColumnWidth(2,150);
    ui->tabledetail->setColumnWidth(3,150);
    ui->tabledetail->show();
}

formdetail::~formdetail()
{
    delete ui;
}

void formdetail::on_pushButton_clicked()
{
    if(ui->id_detailLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Id Detail belum diisi");
        ui->id_detailLineEdit->setFocus();
    }else if(ui->id_lokasiLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Id Lokasi belum diisi");
        ui->id_lokasiLineEdit->setFocus();
    }else if(ui->penginapanLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Penginapan belum diisi");
        ui->penginapanLineEdit->setFocus();
    }else if(ui->nama_lokasiLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Nama Lokasi belum diisi");
        ui->nama_lokasiLineEdit->setFocus();
    }else {
        QSqlQuery duplicate;
        duplicate.prepare("SELECT * FROM detail_lokasi WHERE id_detail = '"+ui->id_detailLineEdit->text()+"'");
        duplicate.exec();
        if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Detail sudah terdaftar");
            ui->id_detailLineEdit->setText(duplicate.value(1).toString());
            ui->id_lokasiLineEdit->setText(duplicate.value(2).toString());
            ui->penginapanLineEdit->setText(duplicate.value(3).toString());
            ui->nama_lokasiLineEdit->setText(duplicate.value(4).toString());
        }else{
            QSqlQuery sql (koneksi);
            sql.prepare("INSERT INTO detail_lokasi (id_detail,id_lokasi,penginapan,nama_lokasi)"
                        "VALUE (:id_detail,:id_lokasi,:penginapan,:nama_lokasi)");
            sql.bindValue(":id_detail",ui->id_detailLineEdit->text());
            sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
            sql.bindValue(":penginapan",ui->penginapanLineEdit->text());
            sql.bindValue(":nama_lokasi",ui->nama_lokasiLineEdit->text());

            if (sql.exec()){
                qDebug()<<"Data Berhasil Di Simpan";
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
    }
}


void formdetail::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE detail_lokasi SET id_lokasi=:id_lokasi, penginapan=:penginapan, nama_lokasi=:nama_lokasi "
                "WHERE id_detail=:id_detail");
    sql.bindValue(":id_detail",ui->id_detailLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":penginapan",ui->penginapanLineEdit->text());
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


void formdetail::on_tabledetail_activated(const QModelIndex &index)
{
    int baris = ui->tabledetail->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_detailLineEdit->setText(ui->tabledetail->model()->index(baris,0).data().toString());
    ui->id_lokasiLineEdit->setText(ui->tabledetail->model()->index(baris,1).data().toString());
    ui->penginapanLineEdit->setText(ui->tabledetail->model()->index(baris,2).data().toString());
    ui->nama_lokasiLineEdit->setText(ui->tabledetail->model()->index(baris,3).data().toString());
}

