#ifndef FORMPENGUNJUNG_H
#define FORMPENGUNJUNG_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class formpengunjung;
}

class formpengunjung : public QWidget
{
    Q_OBJECT

public:
    explicit formpengunjung(QWidget *parent = nullptr);
    ~formpengunjung();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::formpengunjung *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMPENGUNJUNG_H
