#include "nep.h"
#include "ui_nep.h"




NEP::NEP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NEP)
{
    ui->setupUi(this);
}

NEP::~NEP()
{
    delete ui;
}

void NEP::on_pushButton_clicked()
{
    nhv[n].address = ui->lineEdit->text();
    nhv[n].room_num = ui->lineEdit_2->text().toInt();
    nhv[n].total_area = ui->lineEdit_3->text().toInt();
    nhv[n].basic_price = ui->lineEdit_4->text().toInt();
    nhv[n].building_area = ui->lineEdit_5->text().toInt();
    nhv[n].back_yard_area = ui->lineEdit_6->text().toInt();
    nhv[n].front_yard_area = ui->lineEdit_7->text().toInt();
}
