#ifndef FORMEVENT_H
#define FORMEVENT_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>


namespace Ui {
class formevent;
}

class formevent : public QWidget
{
    Q_OBJECT

public:
    explicit formevent(QWidget *parent = nullptr);
    ~formevent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::formevent *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMEVENT_H
