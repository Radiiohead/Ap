#include "edit.h"
#include "ui_edit.h"
#include "classes.h"


Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    QString str;
    if(ui->comboBox->currentText() == "Apartment"){

        for(int i =0;i<apv.size();i++){
            str = str + QString::number(i) +"." +apv[i].use + "\n";
        }
    }
    if(ui->comboBox->currentText() == "North House"){

        for(int i =0;i<nhv.size();i++){
            str = str + QString::number(i) +"." +apv[i].use + "\n";
        }
    }
    if(ui->comboBox->currentText() == "South House"){

        for(int i =0;i<shv.size();i++){
            str = str + QString::number(i) +"." +apv[i].use + "\n";
        }
    }
    ui->textEdit->setText(str);
}

Edit::~Edit()
{
    delete ui;
}
 int a;
 int b;
 int c;
void Edit::on_comboBox_activated(const QString &arg1)
{
    QString str;
    if(ui->comboBox->currentText() == "Apartment"){

        for(int i =0;i<apv.size();i++){
            str = str + QString::number(i) +"." +apv[i].use + "\n";
        }
        a++;
    }
    if(ui->comboBox->currentText() == "North House"){

        for(int i =0;i<nhv.size();i++){
            str = str + QString::number(i) +"." +apv[i].use + "\n";
        }
        b++;
    }
    if(ui->comboBox->currentText() == "South House"){

        for(int i =0;i<shv.size();i++){
            str = str + QString::number(i) +"." +apv[i].use + "\n";
        }
        c++;
    }
    ui->textEdit->setText(str);
}

void Edit::on_pushButton_2_clicked()
{
    int num = ui->lineEdit->text().toInt();
    if(a && num >0 && num<apv.size()){
        apv.erase(apv.begin()+(num-1));
    }
    else if(b && num >0 && num<nhv.size()){
        nhv.erase(nhv.begin()+(num-1));
    }
    else if(c && num >0 && num<shv.size()){
        shv.erase(shv.begin()+(num-1));
    }
    else {
        ui->label_2->setText("Wrong Number!");
    }
}

void Edit::on_pushButton_clicked()
{
    int num = ui->lineEdit->text().toInt();
    if(a && num >0 && num<apv.size()){
        aedit = new EditPage;
        aedit->n = num;
        aedit->show();
    }
    else if(b && num >0 && num<nhv.size()){
        nedit = new NEP;
        nedit->n = num;
        nedit->show();
    }
    else if(c && num >0 && num<shv.size()){
        sedit = new SEP;
        sedit->n = num;
        sedit->show();
    }
    else {
        ui->label_2->setText("Wrong Number!");
    }
}
