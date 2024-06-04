#ifndef FORMPENGELOLA_H
#define FORMPENGELOLA_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class formpengelola;
}

class formpengelola : public QWidget
{
    Q_OBJECT

public:
    explicit formpengelola(QWidget *parent = nullptr);
    ~formpengelola();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::formpengelola *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMPENGELOLA_H
