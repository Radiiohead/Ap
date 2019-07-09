#include "sep.h"
#include "ui_sep.h"



SEP::SEP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SEP)
{
    ui->setupUi(this);
}

SEP::~SEP()
{
    delete ui;
}

void SEP::on_pushButton_clicked()
{
    shv[n].address = ui->lineEdit->text();
    shv[n].room_num = ui->lineEdit_2->text().toInt();
    shv[n].total_area = ui->lineEdit_3->text().toInt();
    shv[n].basic_price = ui->lineEdit_4->text().toInt();
    shv[n].yard_area = ui->lineEdit_5->text().toInt();
    shv[n].parking_area = ui->lineEdit_6->text().toInt();
    shv[n].building_area = ui->lineEdit_7->text().toInt();
}
