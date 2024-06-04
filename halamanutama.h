#ifndef HALAMANUTAMA_H
#define HALAMANUTAMA_H

#include <QMainWindow>
#include <formdesa.h>
#include <formdetail.h>
#include <formevent.h>
#include <formkategori.h>
#include <formkecamatan.h>
#include <formlokasi.h>
#include <formpengelola.h>
#include <formpengunjung.h>
#include <formpromosi.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class halamanutama;
}
QT_END_NAMESPACE

class halamanutama : public QMainWindow
{
    Q_OBJECT

public:
    halamanutama(QWidget *parent = nullptr);
    ~halamanutama();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::halamanutama *ui;
    formdesa *desform;
    formdetail *detform;
    formevent *eveform;
    formkategori *katform;
    formkecamatan *kecform;
    formlokasi *lokform;
    formpengelola *pengform;
    formpengunjung *peng2form;
    formpromosi *proform;
};
#endif // HALAMANUTAMA_H
