#include "info.h"
#include "ui_info.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);

}

Info::~Info()
{
    delete ui;
}

void Info::on_pushButton_2_clicked()
{
    this->close();
}

void Info::on_pushButton_clicked()
{
    int flag = 1;
    QString str = "";
    QString add = ui->lineEdit->text();
    for(int i =0;i<apv.size();i++){
        if(add == apv[i].use){
            str = str + apv[i].use + " " + QString::number(apv[i].home_room_num) + " " + QString::number(apv[i].home_building_area) + "\n";
            ui->textEdit->setText(str);
            flag = 0;

        }
    }
    if (flag==1){
        for(int i =0;i<nhv.size();i++){
            if(add == nhv[i].address){
                str = str + nhv[i].address + " " + QString::number(nhv[i].total_area) + " " + QString::number(nhv[i].basic_price) + "\n";
                ui->textEdit->setText(str);
                flag = 0;

            }
        }
    }
    else if(flag==1){
        for(int i =0;i<shv.size();i++){
            if(add == shv[i].address){
                str = str + shv[i].address + " " + QString::number(shv[i].total_area) + " " + QString::number(shv[i].basic_price) + "\n";
                ui->textEdit->setText(str);
                flag = 0;

            }
        }
    }
    if(flag == 1){
        ui->textEdit->setText("There is not any house with this address!");
    }
}
