#include "formdesa.h"
#include "ui_formdesa.h"
#include "QMessageBox"

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
    loadtabledesa();
}

void formdesa::loadtabledesa()
{
        tabelModel = new QSqlQueryModel(this);
        tabelModel->setQuery("SELECT*FROM desa ORDER BY id_desa ASC");
        tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Desa"));
        tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Kecamatan"));
        tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Nama Kecamatan"));

        ui->tabledesa->setModel(tabelModel);
        ui->tabledesa->setColumnWidth(0,150);
        ui->tabledesa->setColumnWidth(1,150);
        ui->tabledesa->setColumnWidth(2,155);
        ui->tabledesa->show();
}

formdesa::~formdesa()
{
    delete ui;
}

void formdesa::on_pushButton_clicked()
{
    if(ui->id_desaLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Id Desa belum diisi");
        ui->id_desaLineEdit->setFocus();
    }else if(ui->id_kecamatanLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Id Kecamatan belum diisi");
        ui->id_kecamatanLineEdit->setFocus();
    }else if(ui->nama_kecamatanLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Nama Kecamatan belum diisi");
        ui->nama_kecamatanLineEdit->setFocus();
    }else {
        QSqlQuery duplicate;
        duplicate.prepare("SELECT * FROM desa WHERE id_desa = '"+ui->id_desaLineEdit->text()+"'");
        duplicate.exec();
        if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Desa sudah terdaftar");
            ui->id_desaLineEdit->setText(duplicate.value(1).toString());
            ui->id_kecamatanLineEdit->setText(duplicate.value(2).toString());
            ui->nama_kecamatanLineEdit->setText(duplicate.value(3).toString());
        }else{
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


void formdesa::on_tabledesa_activated(const QModelIndex &index)
{
    int baris = ui->tabledesa->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_desaLineEdit->setText(ui->tabledesa->model()->index(baris,0).data().toString());
    ui->id_kecamatanLineEdit->setText(ui->tabledesa->model()->index(baris,1).data().toString());
    ui->nama_kecamatanLineEdit->setText(ui->tabledesa->model()->index(baris,2).data().toString());
}

