#ifndef FORMDESA_H
#define FORMDESA_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class formdesa;
}

class formdesa : public QWidget
{
    Q_OBJECT

public:
    explicit formdesa(QWidget *parent = nullptr);
    void loadtabledesa();
    ~formdesa();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_tabledesa_activated(const QModelIndex &index);

private:
    Ui::formdesa *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMDESA_H
