#include "add.h"
#include "ui_add.h"
#include "classes.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDir>
QVector<apartment>apv;
QVector<north_house>nhv;
QVector<south_house>shv;
Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);

}

Add::~Add()
{
    delete ui;
}
QString pic1 = "";
QString pic2 = "";
int lp=0;
int ls = 0;
QString nhpic = "";
int n1 =0;
QString shpic = "";
int s1 =0;
void Add::on_pushButton_5_clicked()
{
    int ppp = 1;
    apartment tmp;
    QString check = ui->lineEdit_22->text();
    for (int sas =0;sas<apv.size();sas++){
        if (check == apv[sas].use)
            ppp--;
    }
    if(ui->lineEdit_22->text() != "" ){
        tmp.use = ui->lineEdit_22->text();
    }
    else {
        ui->label_53->setText("Cannot be empty!");
        ppp--;
    }
    /*if(ui->lineEdit_23->text() != "" ){
        tmp. = ui->lineEdit_23->text().toInt();
    }
    else {
        ui->label_56->setText("Cannot be empty!");
        ppp--;
    }*/
    if(ui->lineEdit_24->text() != "" ){
        tmp.level_num = ui->lineEdit_24->text().toInt();
    }
    else {
        ui->label_52->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_25->text() != "" ){
        tmp.home_level = ui->lineEdit_25->text().toInt();
    }
    else {
        ui->label_54->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_26->text() != "" ){
        tmp.total_area = ui->lineEdit_26->text().toInt();
    }
    else {
        ui->label_55->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_27->text() != "" ){
        tmp.home_room_num= ui->lineEdit_27->text().toInt();
    }
    else {
        ui->label_50->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_28->text() != "" ){
        tmp.house_per_level= ui->lineEdit_28->text().toInt();
    }
    else {
        ui->label_51->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_29->text() != "" ){
        tmp.elevator_condition= ui->lineEdit_29->text().toInt();
    }
    else {
        ui->label_57->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_30->text() != "" ){
        tmp.home_building_area= ui->lineEdit_30->text().toInt();
    }
    else {
        ui->label_58->setText("Cannot be empty!");
        ppp--;
    }
    if(lp == 1 && ls==1){
        tmp.home_pic_str = pic1;
        tmp.apartment_photo_str = pic2;
        lp--;
    }
    else {
        ui->label_65->setText("You must choose!");
        ppp--;
    }

    if (ppp > 0){
        apv.push_back(tmp);
        ui->label_59->setText("Apartment Added!");
    }
    else {
        ui->label_59->setText("Try Again!");
    }


}

void Add::on_pushButton_6_clicked()
{
    this->close();
}

void Add::on_pushButton_3_clicked()
{
    int ppp = 1;
    north_house tmp;
    QString check = ui->lineEdit_17->text();
    for (int sas =0;sas<nhv.size();sas++){
        if (check == nhv[sas].address)
            ppp--;
    }
    if(ui->lineEdit_17->text() != "" ){
        tmp.address = ui->lineEdit_17->text();
    }
    else {
        ui->label_45->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_18->text() != "" ){
        tmp.room_num = ui->lineEdit_18->text().toInt();
    }
    else {
        ui->label_47->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_19->text() != "" ){
        tmp.total_area = ui->lineEdit_19->text().toInt();
    }
    else {
        ui->label_48->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_20->text() != "" ){
        tmp.basic_price = ui->lineEdit_20->text().toInt();
    }
    else {
        ui->label_43->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_15->text() != "" ){
        tmp.building_area = ui->lineEdit_15->text().toInt();
    }
    else {
        ui->label_46->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_21->text() != "" ){
        tmp.back_yard_area= ui->lineEdit_21->text().toInt();
    }
    else {
        ui->label_44->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_16->text() != "" ){
        tmp.front_yard_area= ui->lineEdit_16->text().toInt();
    }
    else {
        ui->label_49->setText("Cannot be empty!");
        ppp--;
    }
    if(n1 == 1){
        tmp.nhome_photo_str = nhpic;
        n1--;
    }
    else {
        ui->label_66->setText("You must choose!");
        ppp--;
    }

    if (ppp > 0){
        nhv.push_back(tmp);
        ui->label_60->setText("North House Added!");
    }
    else {
        ui->label_60->setText("Try Again!");
    }


}

void Add::on_pushButton_4_clicked()
{
    this->close();
}

void Add::on_pushButton_clicked()
{
    int ppp = 1;
    south_house tmp;
    QString check = ui->lineEdit->text();
    for (int sas =0;sas<shv.size();sas++){
        if (check == shv[sas].address)
            ppp--;
    }
    if(ui->lineEdit->text() != "" ){
        tmp.address = ui->lineEdit->text();
    }
    else {
        ui->label_36->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_2->text() != "" ){
        tmp.room_num = ui->lineEdit_2->text().toInt();
    }
    else {
        ui->label_37->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_3->text() != "" ){
        tmp.total_area = ui->lineEdit_3->text().toInt();
    }
    else {
        ui->label_38->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_4->text() != "" ){
        tmp.basic_price = ui->lineEdit_4->text().toInt();
    }
    else {
        ui->label_39->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_5->text() != "" ){
        tmp.yard_area = ui->lineEdit_5->text().toInt();
    }
    else {
        ui->label_40->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_6->text() != "" ){
        tmp.parking_area= ui->lineEdit_6->text().toInt();
    }
    else {
        ui->label_41->setText("Cannot be empty!");
        ppp--;
    }
    if(ui->lineEdit_7->text() != "" ){
        tmp.building_area= ui->lineEdit_7->text().toInt();
    }
    else {
        ui->label_42->setText("Cannot be empty!");
        ppp--;
    }
    if(s1 == 1){
        tmp.shome_photo_str = shpic;
        s1--;
    }
    else {
        ui->label_67->setText("You must choose!");
        ppp--;
    }


    if (ppp > 0){
        shv.push_back(tmp);
        ui->label_61->setText("South House Added!");
    }
    else {
        ui->label_61->setText("Try Again!");
    }

}

void Add::on_pushButton_2_clicked()
{
      this->close();
}

void Add::on_pushButton_9_clicked()
{
    pic1 = QFileDialog::getOpenFileName(this,"Open a File", QDir::homePath());
    ui->label_65->setText("Image Opened!");

    lp = 1;
}

void Add::on_pushButton_8_clicked()
{
    nhpic = QFileDialog::getOpenFileName(this,"Open a File", QDir::homePath());
    n1 = 1;
}

void Add::on_pushButton_7_clicked()
{
    shpic = QFileDialog::getOpenFileName(this,"Open a File", QDir::homePath());
    s1 = 1;
}

void Add::on_pushButton_10_clicked()
{
    pic2 = QFileDialog::getOpenFileName(this,"Open a File", QDir::homePath());
    ui->label_68->setText("Image Opened!");
    ls = 1;
}
