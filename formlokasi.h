#ifndef FORMLOKASI_H
#define FORMLOKASI_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class formlokasi;
}

class formlokasi : public QWidget
{
    Q_OBJECT

public:
    explicit formlokasi(QWidget *parent = nullptr);
    ~formlokasi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::formlokasi *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMLOKASI_H
