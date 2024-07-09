#include "formkategori.h"
#include "ui_formkategori.h"
#include "QMessageBox"

formkategori::formkategori(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formkategori)
{
    ui->setupUi(this);
    loadtablekategori();
}

void formkategori::loadtablekategori()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM kategori ORDER BY id_kategori ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Kategori"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Kategori"));

    ui->tablekategori->setModel(tabelModel);
    ui->tablekategori->setColumnWidth(0,257);
    ui->tablekategori->setColumnWidth(1,257);
    ui->tablekategori->show();
}

formkategori::~formkategori()
{
    delete ui;
}

void formkategori::on_pushButton_clicked()
{
        if(ui->id_kategoriLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Id Kategori belum diisi");
            ui->id_kategoriLineEdit->setFocus();
        }else if(ui->kategoriLineEdit->text().isEmpty()){
            QMessageBox::information(this, "warning", "Kategori belum diisi");
            ui->kategoriLineEdit->setFocus();
        }else {
            QSqlQuery duplicate;
            duplicate.prepare("SELECT * FROM kategori WHERE id_kategori = '"+ui->id_kategoriLineEdit->text()+"'");
            duplicate.exec();
            if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Kategori sudah terdaftar");
            ui->id_kategoriLineEdit->setText(duplicate.value(1).toString());
            ui->kategoriLineEdit->setText(duplicate.value(2).toString());
        }else{
            QSqlQuery sql (koneksi);
            sql.prepare("INSERT INTO kategori (id_kategori,kategori)"
                        "VALUE (:id_kategori,:kategori)");
            sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
            sql.bindValue(":kategori",ui->kategoriLineEdit->text());

            if (sql.exec()){
                qDebug()<<"Data Berhasil Di Simpan";
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
    }
}


void formkategori::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE kategori SET kategori=:kategori "
                "WHERE id_kategori=:id_kategori");
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());
    sql.bindValue(":kategori",ui->kategoriLineEdit->text());


    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkategori::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM kategori WHERE id_kategori=:id_kategori");
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formkategori::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM kategori WHERE id_kategori=:id_kategori");
    sql.bindValue(":id_kategori",ui->id_kategoriLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}




void formkategori::on_tablekategori_activated(const QModelIndex &index)
{
    int baris = ui->tablekategori->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_kategoriLineEdit->setText(ui->tablekategori->model()->index(baris,0).data().toString());
    ui->kategoriLineEdit->setText(ui->tablekategori->model()->index(baris,1).data().toString());
}

