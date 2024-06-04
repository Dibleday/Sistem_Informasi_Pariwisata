#ifndef FORMKATEGORI_H
#define FORMKATEGORI_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class formkategori;
}

class formkategori : public QWidget
{
    Q_OBJECT

public:
    explicit formkategori(QWidget *parent = nullptr);
    ~formkategori();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::formkategori *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMKATEGORI_H
