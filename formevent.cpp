#include "formevent.h"
#include "ui_formevent.h"

formevent::formevent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formevent)
{
    ui->setupUi(this);
}

formevent::~formevent()
{
    delete ui;
}

void formevent::on_pushButton_clicked()
{
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

