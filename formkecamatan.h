#ifndef FORMKECAMATAN_H
#define FORMKECAMATAN_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class formkecamatan;

}

class formkecamatan : public QWidget
{
    Q_OBJECT

public:
    explicit formkecamatan(QWidget *parent = nullptr);
    ~formkecamatan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::formkecamatan *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMKECAMATAN_H
