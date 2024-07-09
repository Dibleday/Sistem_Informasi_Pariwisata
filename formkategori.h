#ifndef FORMKATEGORI_H
#define FORMKATEGORI_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class formkategori;
}

class formkategori : public QWidget
{
    Q_OBJECT

public:
    explicit formkategori(QWidget *parent = nullptr);
    void loadtablekategori();
    ~formkategori();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tablekategori_activated(const QModelIndex &index);

private:
    Ui::formkategori *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMKATEGORI_H
