#include "formpromosi.h"
#include "ui_formpromosi.h"
#include "QMessageBox"

formpromosi::formpromosi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formpromosi)
{
    ui->setupUi(this);
    loadtablepromosi();
}

void formpromosi::loadtablepromosi()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM promosi ORDER BY id_promosi ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Promosi"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Lokasi"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Nama Promo"));

    ui->tablepromosi->setModel(tabelModel);
    ui->tablepromosi->setColumnWidth(0,160);
    ui->tablepromosi->setColumnWidth(1,160);
    ui->tablepromosi->setColumnWidth(2,175);
    ui->tablepromosi->show();
}

formpromosi::~formpromosi()
{
    delete ui;
}

void formpromosi::on_pushButton_clicked()
{
        if(ui->id_promosiLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Id Promosi belum diisi");
            ui->id_promosiLineEdit->setFocus();
        }else if(ui->id_lokasiLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "ID Lokasi belum diisi");
            ui->id_lokasiLineEdit->setFocus();
        }else if(ui->nama_promoLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Nama Promo belum diisi");
            ui->nama_promoLineEdit->setFocus();
        }else {
            QSqlQuery duplicate;
            duplicate.prepare("SELECT * FROM promosi WHERE id_promosi = '"+ui->id_promosiLineEdit->text()+"'");
            duplicate.exec();
            if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Promosi sudah terdaftar");
            ui->id_promosiLineEdit->setText(duplicate.value(1).toString());
            ui->id_lokasiLineEdit->setText(duplicate.value(2).toString());
            ui->nama_promoLineEdit->setText(duplicate.value(3).toString());
        }else{
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


void formpromosi::on_tablepromosi_activated(const QModelIndex &index)
{
    int baris = ui->tablepromosi->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_promosiLineEdit->setText(ui->tablepromosi->model()->index(baris,0).data().toString());
    ui->id_lokasiLineEdit->setText(ui->tablepromosi->model()->index(baris,1).data().toString());
    ui->nama_promoLineEdit->setText(ui->tablepromosi->model()->index(baris,2).data().toString());
}

