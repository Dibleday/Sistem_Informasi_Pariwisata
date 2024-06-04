#ifndef FORMPROMOSI_H
#define FORMPROMOSI_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class formpromosi;
}

class formpromosi : public QWidget
{
    Q_OBJECT

public:
    explicit formpromosi(QWidget *parent = nullptr);
    ~formpromosi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::formpromosi *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMPROMOSI_H
