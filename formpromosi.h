#ifndef FORMPROMOSI_H
#define FORMPROMOSI_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class formpromosi;
}

class formpromosi : public QWidget
{
    Q_OBJECT

public:
    explicit formpromosi(QWidget *parent = nullptr);
    void loadtablepromosi();
    ~formpromosi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tablepromosi_activated(const QModelIndex &index);

private:
    Ui::formpromosi *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMPROMOSI_H
