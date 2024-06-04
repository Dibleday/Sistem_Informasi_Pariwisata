#include "halamanutama.h"
#include "ui_halamanutama.h"
#include <qstring.h>

halamanutama::halamanutama(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::halamanutama)
{
    ui->setupUi(this);
    desform = new formdesa;
    detform = new formdetail;
    eveform = new formevent;
    katform = new formkategori;
    kecform = new formkecamatan;
    lokform = new formlokasi;
    pengform = new formpengelola;
    peng2form = new formpengunjung;
    proform = new formpromosi;
}

halamanutama::~halamanutama()
{
    delete ui;
}
void halamanutama::on_pushButton_clicked()
{
    desform->show();
}


void halamanutama::on_pushButton_2_clicked()
{
    detform->show();
}


void halamanutama::on_pushButton_3_clicked()
{
    eveform->show();
}


void halamanutama::on_pushButton_4_clicked()
{
    katform->show();
}


void halamanutama::on_pushButton_5_clicked()
{
    kecform->show();
}


void halamanutama::on_pushButton_6_clicked()
{
    lokform->show();
}


void halamanutama::on_pushButton_7_clicked()
{
    pengform->show();
}


void halamanutama::on_pushButton_8_clicked()
{
    peng2form->show();
}


void halamanutama::on_pushButton_9_clicked()
{
    proform->show();
}

