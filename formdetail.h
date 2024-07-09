#ifndef FORMDETAIL_H
#define FORMDETAIL_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class formdetail;
}

class formdetail : public QWidget
{
    Q_OBJECT

public:
    explicit formdetail(QWidget *parent = nullptr);
    void loadtabledetail();
    ~formdetail();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tabledetail_activated(const QModelIndex &index);

private:
    Ui::formdetail *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMDETAIL_H
