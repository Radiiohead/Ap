#include "editpage.h"
#include "ui_editpage.h"



EditPage::EditPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPage)
{
    ui->setupUi(this);
}

EditPage::~EditPage()
{
    delete ui;
}

void EditPage::on_pushButton_clicked()
{
    apv[n].use = ui->lineEdit_22->text();
    //apv[n].area = ui->lineEdit_23->text().toInt();
    apv[n].level_num = ui->lineEdit_24->text().toInt();
    apv[n].home_level = ui->lineEdit_25->text().toInt();
    apv[n].total_area = ui->lineEdit_26->text().toInt();
    apv[n].home_room_num = ui->lineEdit_27->text().toInt();
    apv[n].house_per_level = ui->lineEdit_28->text().toInt();
    apv[n].elevator_condition = ui->lineEdit_29->text().toInt();
    apv[n].home_building_area = ui->lineEdit_30->text().toInt();
    apv[n].price();

}
