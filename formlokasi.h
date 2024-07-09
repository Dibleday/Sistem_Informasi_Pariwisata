#ifndef FORMLOKASI_H
#define FORMLOKASI_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class formlokasi;
}

class formlokasi : public QWidget
{
    Q_OBJECT

public:
    explicit formlokasi(QWidget *parent = nullptr);
    void loadtablelokasi();
    ~formlokasi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tablelokasi_activated(const QModelIndex &index);

private:
    Ui::formlokasi *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMLOKASI_H
