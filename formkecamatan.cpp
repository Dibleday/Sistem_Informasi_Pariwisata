#include "formkecamatan.h"
#include "ui_formkecamatan.h"
#include "QMessageBox"

formkecamatan::formkecamatan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formkecamatan)
{
    ui->setupUi(this);
    loadtablekecamatan();
}

void formkecamatan::loadtablekecamatan()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM kecamatan ORDER BY id_kecamatan ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Kecamatan"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Nama Kecamatan"));

    ui->tablekecamatan->setModel(tabelModel);
    ui->tablekecamatan->setColumnWidth(0,257);
    ui->tablekecamatan->setColumnWidth(1,257);
    ui->tablekecamatan->show();
}

formkecamatan::~formkecamatan()
{
    delete ui;
}

void formkecamatan::on_pushButton_clicked()
{
        if(ui->id_kecamatanLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Id Kecamatan belum diisi");
            ui->id_kecamatanLineEdit->setFocus();
        }else if(ui->nama_kecamatanLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Nama Kecamatan belum diisi");
            ui->nama_kecamatanLineEdit->setFocus();
        }else {
            QSqlQuery duplicate;
            duplicate.prepare("SELECT * FROM kecamatan WHERE id_kecamatan = '"+ui->id_kecamatanLineEdit->text()+"'");
            duplicate.exec();
            if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Kecamatan sudah terdaftar");
            ui->id_kecamatanLineEdit->setText(duplicate.value(1).toString());
            ui->nama_kecamatanLineEdit->setText(duplicate.value(2).toString());
        }else{
            QSqlQuery sql (koneksi);
            sql.prepare("INSERT INTO kecamatan (id_kecamatan,nama_kecamatan)"
                        "VALUE (:id_kecamatan,:nama_kecamatan)");
            sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
            sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());

            if (sql.exec()){
                qDebug()<<"Data Berhasil Di Simpan";
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
    }
}


void formkecamatan::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE kecamatan SET nama_kecamatan=:nama_kecamatan "
                "WHERE id_kecamatan=:id_kecamatan");
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkecamatan::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM kecamatan WHERE id_kecamatan=:id_kecamatan");
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkecamatan::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM kecamatan WHERE id_kecamatan=:id_kecamatan");
    sql.bindValue(":id_kecamatan",ui->id_kecamatanLineEdit->text());
    sql.bindValue(":nama_kecamatan",ui->nama_kecamatanLineEdit->text());


    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkecamatan::on_tablekecamatan_activated(const QModelIndex &index)
{
    int baris = ui->tablekecamatan->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_kecamatanLineEdit->setText(ui->tablekecamatan->model()->index(baris,0).data().toString());
    ui->nama_kecamatanLineEdit->setText(ui->tablekecamatan->model()->index(baris,1).data().toString());
}

