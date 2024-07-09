#ifndef FORMKECAMATAN_H
#define FORMKECAMATAN_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class formkecamatan;

}

class formkecamatan : public QWidget
{
    Q_OBJECT

public:
    explicit formkecamatan(QWidget *parent = nullptr);
    void loadtablekecamatan();
    ~formkecamatan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tablekecamatan_activated(const QModelIndex &index);

private:
    Ui::formkecamatan *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMKECAMATAN_H
