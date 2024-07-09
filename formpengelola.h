#ifndef FORMPENGELOLA_H
#define FORMPENGELOLA_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class formpengelola;
}

class formpengelola : public QWidget
{
    Q_OBJECT

public:
    explicit formpengelola(QWidget *parent = nullptr);
    void loadtablepengelola();
    ~formpengelola();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tablepengelola_activated(const QModelIndex &index);

private:
    Ui::formpengelola *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMPENGELOLA_H
