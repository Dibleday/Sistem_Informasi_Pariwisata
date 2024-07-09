#include "formevent.h"
#include "ui_formevent.h"
#include "QMessageBox"

formevent::formevent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formevent)
{
    ui->setupUi(this);
    loadtableevent();
}

void formevent::loadtableevent()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM event ORDER BY id_event ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Event"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("ID Lokasi"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Nama Event"));

    ui->tableevent->setModel(tabelModel);
    ui->tableevent->setColumnWidth(0,150);
    ui->tableevent->setColumnWidth(1,150);
    ui->tableevent->setColumnWidth(2,150);
    ui->tableevent->show();
}

formevent::~formevent()
{
    delete ui;
}

void formevent::on_pushButton_clicked()
{
    if(ui->id_eventLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Id Event belum diisi");
        ui->id_eventLineEdit->setFocus();
    }else if(ui->id_lokasiLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Id Lokasi belum diisi");
        ui->id_lokasiLineEdit->setFocus();
    }else if(ui->nama_eventLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Nama Event belum diisi");
        ui->nama_eventLineEdit->setFocus();
    }else {
        QSqlQuery duplicate;
        duplicate.prepare("SELECT * FROM event WHERE id_event = '"+ui->id_eventLineEdit->text()+"'");
        duplicate.exec();
        if(duplicate.next()){
            QMessageBox::information(this, "warning", "Id Event sudah terdaftar");
            ui->id_eventLineEdit->setText(duplicate.value(1).toString());
            ui->id_lokasiLineEdit->setText(duplicate.value(2).toString());
            ui->nama_eventLineEdit->setText(duplicate.value(3).toString());
        }else{
            QSqlQuery sql (koneksi);
            sql.prepare("INSERT INTO event (id_event,id_lokasi,nama_event)"
                        "VALUE (:id_event,:id_lokasi,:nama_event)");
            sql.bindValue(":id_event",ui->id_eventLineEdit->text());
            sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
            sql.bindValue(":nama_event",ui->nama_eventLineEdit->text());

            if (sql.exec()){
                qDebug()<<"Data Berhasil Di Simpan";
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
    }
}


void formevent::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE event SET id_lokasi=:id_lokasi, nama_event=:nama_event "
                "WHERE id_event=:id_event");
    sql.bindValue(":id_event",ui->id_eventLineEdit->text());
    sql.bindValue(":id_lokasi",ui->id_lokasiLineEdit->text());
    sql.bindValue(":nama_event",ui->nama_eventLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formevent::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM event WHERE id_event=:id_event");
    sql.bindValue(":id_event",ui->id_eventLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}




void formevent::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM detail_event WHERE id_event=:id_event");
    sql.bindValue(":id_event",ui->id_eventLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void formevent::on_tableevent_activated(const QModelIndex &index)
{
    int baris = ui->tableevent->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->id_eventLineEdit->setText(ui->tableevent->model()->index(baris,0).data().toString());
    ui->id_lokasiLineEdit->setText(ui->tableevent->model()->index(baris,1).data().toString());
    ui->nama_eventLineEdit->setText(ui->tableevent->model()->index(baris,2).data().toString());
}

