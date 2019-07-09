/*void closeEvent(QCloseEvent *event){
        this->~regist();
    }*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
//#include <QtGui/QApplication>
#include<QMessageBox>
#include<QListWidget>
#include<iostream>
#include<fstream>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include<QMap>
#include<QtWidgets>
#include <QListWidget>
#include<QVector>
#include <qglobal.h>
#include<QPair>
#include<time.h>
#include<QString>
#include <QCloseEvent>
#include <QtGui>
#include<QDir>
#include <manager.h>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
//void regist::closeEvent (QCloseEvent *event){~regist();}
class login:public QMainWindow{
    Q_OBJECT

public:explicit login(QWidget *parent = nullptr);
    public slots:
    void Close(){
        close();
    }
    void Login();
    void Register();
     signals:
    void sendreg();
};
class loging:public QMainWindow{
    Q_OBJECT;
    QLabel*log_username1;
    QLineEdit*log_username2;
    QLabel*log_password1;
    QLineEdit*log_password2;
    QLabel*log_novalid;
    QHBoxLayout*log_username;
    QHBoxLayout*log_password;
    QVBoxLayout*log_layout;
    QWidget*central;
    QPushButton*log_btn;
public:explicit loging(QWidget *parent = nullptr){
        log_username1=new QLabel;log_username1->setText("Username : ");
        log_username2=new QLineEdit;
        log_password1=new QLabel;log_password1->setText("Password : ");
        log_password2=new QLineEdit;
        log_novalid=new QLabel;log_novalid->setStyleSheet("color : red");
        log_btn=new QPushButton;log_btn->setText("Log");
        log_username=new QHBoxLayout;log_username->addWidget(log_username1);log_username->addWidget(log_username2);
        log_password=new QHBoxLayout;log_password->addWidget(log_password1);log_password->addWidget(log_password2);
        log_layout=new QVBoxLayout;log_layout->addWidget(log_novalid);log_layout->addLayout(log_username);
        log_layout->addLayout(log_password);log_layout->addWidget(log_btn);
        central=new QWidget;central->setLayout(log_layout);
        connect(log_btn,SIGNAL(clicked()),this,SLOT(Login()));
        setCentralWidget(central);
    }
    ~loging(){
        delete central;
    }
    void closeEvent(QCloseEvent *event){
        this->~loging();
    }
public slots:
void Login();
signals:
void sender();
};



class show_app :public QMainWindow{
    Q_OBJECT
    int appcounter=0;
    bool letbuy=1;
    bool letrent =1;
    QWidget*shoapp_wid;
    QVBoxLayout*shoapp_all;
    QVBoxLayout*shoapp_l1;
    QVBoxLayout*shoapp_l2;
    QVBoxLayout*rentfield;
    QVBoxLayout*buyfield;
    QLineEdit*field;
    QHBoxLayout*shoapp_l1l2;
    QHBoxLayout*app_images;
    QHBoxLayout*btns;
    QLabel*shoapp_rent;
    QLabel*shoapp_buy;
    QLabel*shoapp_cond;
    QLabel*shoapp_allarea;
    QLabel*shoapp_basicp;
    QLabel*shoapp_totalp;
    QLabel*shoapp_elevator_condition;
    QLabel*shoapp_layarnum;
    QLabel*shoapp_houseperlevel;
    QLabel*shoapp_levelnum;
    QLabel*shoapp_roomnum;
    QLabel*shoapp_build_area;
    QLabel*shoapp_image;
    QLabel*shoapp_house_image;
    QPushButton*nextap;
    QPushButton*rentap;
    QPushButton*privousap;
    QPushButton*buyap;
public:friend apartment;
    void sho_app_change();
    explicit show_app(QWidget *parent = nullptr){
        shoapp_wid=new QWidget();shoapp_totalp=new QLabel();shoapp_cond=new QLabel();
        shoapp_all=new QVBoxLayout();shoapp_l1=new QVBoxLayout();
        shoapp_l2=new QVBoxLayout();app_images=new QHBoxLayout();
        shoapp_l1l2=new QHBoxLayout();shoapp_allarea=new QLabel();
        shoapp_basicp=new QLabel();btns=new QHBoxLayout();
        shoapp_elevator_condition=new QLabel();field=new QLineEdit();field->setText("Rent time");
        shoapp_layarnum=new QLabel();rentfield=new QVBoxLayout();
        shoapp_houseperlevel=new QLabel();shoapp_rent=new QLabel();
        shoapp_levelnum=new QLabel();shoapp_buy=new QLabel();
        shoapp_roomnum=new QLabel();buyfield=new QVBoxLayout();
        shoapp_build_area=new QLabel();
        shoapp_image=new QLabel();
        shoapp_house_image=new QLabel();
        nextap=new QPushButton("Next");
        rentap=new QPushButton("Rent");
        privousap=new QPushButton("Privous");
        buyap=new QPushButton("Buy");
        buyfield->addWidget(shoapp_buy);
        buyfield->addWidget(buyap);
        rentfield->addWidget(shoapp_rent);
        rentfield->addWidget(rentap);
        rentfield->addWidget(field);
        shoapp_l1->addWidget(shoapp_allarea);
        shoapp_l1->addWidget(shoapp_build_area);
        shoapp_l1->addWidget(shoapp_layarnum);
        shoapp_l1->addWidget(shoapp_levelnum);
        shoapp_l1->addWidget(shoapp_cond);
        shoapp_l2->addWidget(shoapp_elevator_condition);
        shoapp_l2->addWidget(shoapp_roomnum);
        shoapp_l2->addWidget(shoapp_houseperlevel);
        shoapp_l2->addWidget(shoapp_totalp);
        shoapp_l1l2->addLayout(shoapp_l1);
        shoapp_l1l2->addLayout(shoapp_l2);
        app_images->addWidget(shoapp_image);
        app_images->addWidget(shoapp_house_image);
        shoapp_all->addLayout(shoapp_l1l2);
        shoapp_all->addLayout(app_images);
        btns->addWidget(privousap);
        btns->addLayout(rentfield);
        btns->addLayout(buyfield);
        btns->addWidget(nextap);
        shoapp_all->addLayout(btns);
        shoapp_wid->setLayout(shoapp_all);
        setCentralWidget(shoapp_wid);
        this->sho_app_change();
        qDebug()<<"connections";
        connect(nextap,SIGNAL(clicked()),this,SLOT(sho_app_nchanger()));
        connect(privousap,SIGNAL(clicked()),this,SLOT(sho_app_pchanger()));
        connect(buyap,SIGNAL(clicked()),this,SLOT(sho_app_b()));
        connect(rentap,SIGNAL(clicked()),this,SLOT(sho_app_r()));
}
    ~show_app(){
        qDebug()<<"Exited";
        delete shoapp_wid;
    }
    void closeEvent(QCloseEvent *event){
        this->~show_app();
    }
public slots:
    void sho_app_nchanger();
    void sho_app_pchanger();
    void sho_app_b();
    void sho_app_r();
};
class show_nhome:public QMainWindow{
    Q_OBJECT
    int nhomecounter=0;
    bool letbuy=1;
    bool letrent =1;
    QWidget*shonhome_wid;
    QVBoxLayout*shonhome_all;
    QVBoxLayout*shonhome_l1;
    QVBoxLayout*shonhome_l2;
    QVBoxLayout*rentfield;
    QVBoxLayout*buyfield;
    QLineEdit*field;
    QHBoxLayout*shonhome_l1l2;
    QHBoxLayout*nhome_images;
    QHBoxLayout*btns;
    QLabel*shonhome_rent;
    QLabel*shonhomebuy;
    QLabel*shonhome_address;
    QLabel*shonhome_allarea;
    QLabel*shonhome_basicp;
    QLabel*shonhome_totalp;
    QLabel*shonhome_fyard;
    QLabel*shonhome_byard;
    QLabel*shonhome_roomnum;
    QLabel*shonhome_build_area;
    QLabel*shonhome_image;
    QPushButton*nextnhome;
    QPushButton*rentnhome;
    QPushButton*privousnhome;
    QPushButton*buynhome;
public:friend north_house;
    void sho_nhome_change();
    explicit show_nhome(QWidget *parent = nullptr){
        shonhome_wid=new QWidget();shonhome_totalp=new QLabel();shonhome_address=new QLabel();
        shonhome_all=new QVBoxLayout();shonhome_l1=new QVBoxLayout();
        shonhome_l2=new QVBoxLayout();nhome_images=new QHBoxLayout();
        shonhome_l1l2=new QHBoxLayout();shonhome_allarea=new QLabel();
        shonhome_basicp=new QLabel();btns=new QHBoxLayout();
        qDebug()<<"What";
        field=new QLineEdit();field->setText("Rent time");
        shonhome_fyard=new QLabel();rentfield=new QVBoxLayout();
        shonhome_byard=new QLabel();shonhome_rent=new QLabel();
        shonhome_roomnum=new QLabel();buyfield=new QVBoxLayout();
        shonhome_build_area=new QLabel();shonhomebuy=new QLabel();
        shonhome_image=new QLabel();
        nextnhome=new QPushButton("Next");
        rentnhome=new QPushButton("Rent");
        privousnhome=new QPushButton("Privous");
        buynhome=new QPushButton("Buy");
        buyfield->addWidget(shonhomebuy);//bug
        buyfield->addWidget(buynhome);
        rentfield->addWidget(shonhome_rent);
        rentfield->addWidget(rentnhome);
        rentfield->addWidget(field);
        shonhome_l1->addWidget(shonhome_allarea);
        shonhome_l1->addWidget(shonhome_build_area);
        shonhome_l1->addWidget(shonhome_fyard);
        shonhome_l1->addWidget(shonhome_byard);
        shonhome_l2->addWidget(shonhome_address);
        //qDebug()<<"What///////////////////////////////////";
        shonhome_l2->addWidget(shonhome_roomnum);
        shonhome_l2->addWidget(shonhome_basicp);
        shonhome_l2->addWidget(shonhome_totalp);
        shonhome_l1l2->addLayout(shonhome_l1);
        shonhome_l1l2->addLayout(shonhome_l2);
        shonhome_all->addLayout(shonhome_l1l2);
        //qDebug()<<"What";
        shonhome_all->addWidget(shonhome_image);
        btns->addWidget(privousnhome);
        btns->addLayout(rentfield);
        btns->addLayout(buyfield);
        btns->addWidget(nextnhome);
        shonhome_all->addLayout(btns);
        shonhome_wid->setLayout(shonhome_all);
        setCentralWidget(shonhome_wid);
        qDebug()<<"changes";
        this->sho_nhome_change();
        //qDebug()<<"connections";
        connect(nextnhome,SIGNAL(clicked()),this,SLOT(sho_nhome_nchanger()));
        connect(privousnhome,SIGNAL(clicked()),this,SLOT(sho_nhome_pchanger()));
        connect(buynhome,SIGNAL(clicked()),this,SLOT(sho_nhome_b()));
        connect(rentnhome,SIGNAL(clicked()),this,SLOT(sho_nhome_r()));
}
    ~show_nhome(){
        qDebug()<<"Exited";
        delete shonhome_wid;
    }
    void closeEvent(QCloseEvent *event){
        this->~show_nhome();
    }
public slots:
    void sho_nhome_nchanger();
    void sho_nhome_pchanger();
    void sho_nhome_b();
    void sho_nhome_r();
};
class show_shome:public QMainWindow{
    Q_OBJECT
    int shomecounter=0;
    bool letbuy=1;
    bool letrent =1;
    QWidget*shoshome_wid;
    QVBoxLayout*shoshome_all;
    QVBoxLayout*shoshome_l1;
    QVBoxLayout*shoshome_l2;
    QVBoxLayout*rentfield;
    QVBoxLayout*buyfield;
    QLineEdit*field;
    QHBoxLayout*shoshome_l1l2;
    QHBoxLayout*shome_images;
    QHBoxLayout*btns;
    QLabel*shoshome_rent;
    QLabel*shoshomebuy;
    QLabel*shoshome_address;
    QLabel*shoshome_allarea;
    QLabel*shoshome_basicp;
    QLabel*shoshome_totalp;
    QLabel*shoshome_yard;
    QLabel*shoshome_parking;
    QLabel*shoshome_roomnum;
    QLabel*shoshome_build_area;
    QLabel*shoshome_image;
    QPushButton*nextshome;
    QPushButton*rentshome;
    QPushButton*privousshome;
    QPushButton*buyshome;
public:friend south_house;
    void sho_shome_change();
    explicit show_shome(QWidget *parent = nullptr){
        shoshome_wid=new QWidget();shoshome_totalp=new QLabel();shoshome_address=new QLabel();
        shoshome_all=new QVBoxLayout();shoshome_l1=new QVBoxLayout();
        shoshome_l2=new QVBoxLayout();shome_images=new QHBoxLayout();
        shoshome_l1l2=new QHBoxLayout();shoshome_allarea=new QLabel();
        shoshome_basicp=new QLabel();btns=new QHBoxLayout();
        qDebug()<<"What";
        field=new QLineEdit();field->setText("Rent time");
        shoshome_yard=new QLabel();rentfield=new QVBoxLayout();
        shoshome_parking=new QLabel();shoshome_rent=new QLabel();
        shoshome_roomnum=new QLabel();buyfield=new QVBoxLayout();
        shoshome_build_area=new QLabel();shoshomebuy=new QLabel();
        shoshome_image=new QLabel();
        nextshome=new QPushButton("Next");
        rentshome=new QPushButton("Rent");
        privousshome=new QPushButton("Privous");
        buyshome=new QPushButton("Buy");
        buyfield->addWidget(shoshomebuy);//bug
        buyfield->addWidget(buyshome);
        rentfield->addWidget(shoshome_rent);
        rentfield->addWidget(rentshome);
        rentfield->addWidget(field);
        shoshome_l1->addWidget(shoshome_allarea);
        shoshome_l1->addWidget(shoshome_build_area);
        shoshome_l1->addWidget(shoshome_yard);
        shoshome_l1->addWidget(shoshome_parking);
        shoshome_l2->addWidget(shoshome_address);
        //qDebug()<<"What///////////////////////////////////";
        shoshome_l2->addWidget(shoshome_roomnum);
        shoshome_l2->addWidget(shoshome_basicp);
        shoshome_l2->addWidget(shoshome_totalp);
        shoshome_l1l2->addLayout(shoshome_l1);
        shoshome_l1l2->addLayout(shoshome_l2);
        shoshome_all->addLayout(shoshome_l1l2);
        //qDebug()<<"What";
        shoshome_all->addWidget(shoshome_image);
        btns->addWidget(privousshome);
        btns->addLayout(rentfield);
        btns->addLayout(buyfield);
        btns->addWidget(nextshome);
        shoshome_all->addLayout(btns);
        shoshome_wid->setLayout(shoshome_all);
        setCentralWidget(shoshome_wid);
        qDebug()<<"changes";
        this->sho_shome_change();
        //qDebug()<<"connections";
        connect(nextshome,SIGNAL(clicked()),this,SLOT(sho_shome_nchanger()));
        connect(privousshome,SIGNAL(clicked()),this,SLOT(sho_shome_pchanger()));
        connect(buyshome,SIGNAL(clicked()),this,SLOT(sho_shome_b()));
        connect(rentshome,SIGNAL(clicked()),this,SLOT(sho_shome_r()));
}
    ~show_shome(){
        qDebug()<<"Exited";
        delete shoshome_wid;
    }
    void closeEvent(QCloseEvent *event){
        this->~show_shome();
    }
public slots:
    void sho_shome_nchanger();
    void sho_shome_pchanger();
    void sho_shome_b();
    void sho_shome_r();
};
class show_houses:public QMainWindow{
    Q_OBJECT
    QWidget*minwid=new QWidget();
    QVBoxLayout*minlay=new QVBoxLayout();
    QPushButton*minb1=new QPushButton();
    QPushButton*minb2=new QPushButton();
    QPushButton*minb3=new QPushButton();
public:explicit show_houses(QWidget *parent = nullptr){
        minb1->setText("Observe apartments");
        minb2->setText("Observe north houses");
        minb3->setText("Observe south houses");
        minlay->addWidget(minb1);
        minlay->addWidget(minb2);
        minlay->addWidget(minb3);
        minwid->setLayout(minlay);
        connect(minb1,SIGNAL(clicked()),this,SLOT(seeap()));
        connect(minb2,SIGNAL(clicked()),this,SLOT(seenhome()));
        connect(minb3,SIGNAL(clicked()),this,SLOT(seeshome()));
        setCentralWidget(minwid);
    }
    ~show_houses(){
        qDebug()<<"Exited";
        delete minwid;
    }
    void closeEvent(QCloseEvent *event){
        this->~show_houses();
    }  
signals:
    void sp();
    void snh();
    void ssh();
public slots:
    void seeap();
    void seenhome();
    void seeshome();
};
class show_times:public QMainWindow{
    Q_OBJECT
    QWidget*time_wid;
    QListWidget*time_box1;
    QListWidget*time_box2;
    QLabel*time_in;
    QLabel*time_out;
    QHBoxLayout*time_lab;
    QHBoxLayout*time_lists;
    QVBoxLayout*time_all;
public:void time_in_app();
    show_times(){
        time_wid=new QWidget();
        time_box1=new QListWidget();
        time_box2=new QListWidget();
        time_in=new QLabel();time_in->setText("Enter times : ");
        time_out=new QLabel();time_in->setText("Exit times : ");
        time_lab=new QHBoxLayout();
        time_lists=new QHBoxLayout();
        time_all=new QVBoxLayout();
        time_lab->addWidget(time_in);
        time_lab->addWidget(time_out);
        time_lists->addWidget(time_box1);
        time_lists->addWidget(time_box2);
        time_all->addLayout(time_lab);
        time_all->addLayout(time_lists);
        time_wid->setLayout(time_all);
        setCentralWidget(time_wid);
        time_in_app();
    }
    ~show_times(){
        qDebug()<<"Exited";
        delete time_wid;
    }
    void closeEvent(QCloseEvent *event){
        this->~show_times();
    }
};

class member_in:public QMainWindow{
    Q_OBJECT
    QWidget*minwid=new QWidget();
    QVBoxLayout*minlay=new QVBoxLayout();
    QPushButton*minb1=new QPushButton();
    QPushButton*minb2=new QPushButton();
    QPushButton*minb3=new QPushButton();
public:explicit member_in(QWidget *parent = nullptr){
        minb1->setText("Search house");
        minb2->setText("Observe houses");
        minb3->setText("See in-out times");
        minlay->addWidget(minb1);
        minlay->addWidget(minb2);
        minlay->addWidget(minb3);
        minwid->setLayout(minlay);
        connect(minb1,SIGNAL(clicked()),this,SLOT(searching()));
        connect(minb2,SIGNAL(clicked()),this,SLOT(ckecking()));
        connect(minb3,SIGNAL(clicked()),this,SLOT(timing()));
        setCentralWidget(minwid);
    }
    ~member_in(){
        qDebug()<<"Exited";
        delete minwid;
    }
    void closeEvent(QCloseEvent *event){
        this->~member_in();
    }
    public slots:
    void searching(){}
    void ckecking(){
        show_houses*s1=new show_houses();
        connect(this,SIGNAL(show_s()),s1,SLOT(show()));
        emit show_s();
    }
    void timing(){
        show_times*s1=new show_times();
        connect(this,SIGNAL(timer()),s1,SLOT(show()));
        emit timer();
    }
signals:
    void show_s();
    void timer();
};
class member{
    QPair<QString,QString>name;
    QPair<int,QPair<int,int>>birthdate;
    bool condition;
    QString username;
    QString password;
    QVector<QPair<tm*,tm*>>memtimes;
    int money;
public:member(QString nam="",QString lastnam="",int birth1=0,int birth2=0,int birth3=0,QString con="",QString user=0,QString pass=0){
        birthdate.first=birth1;birthdate.second.first=birth2;birthdate.second.second=birth3;
        if(con=="Active" ||con=="active")condition=1;
        else this->condition=0;this->username=user;password=pass;
        name.first=nam;this->name.second=lastnam;
        time_t t=time(0);
        tm*now=localtime(&t);
        memtimes.push_back(QPair<tm*,tm*>(now,now));money=0;
    }
    QString gettime1(int x){
        QString s;
        s=QString::number(this->memtimes[x].first->tm_year);s+="/";
        s+=QString::number(this->memtimes[x].first->tm_mon);s+="/";
        s+=QString::number(this->memtimes[x].first->tm_mday);s+="  ";
        s+=QString::number(this->memtimes[x].first->tm_hour);s+=" : ";
        s+=QString::number(this->memtimes[x].first->tm_min);s+=" : ";
        s+=QString::number(this->memtimes[x].first->tm_sec);
        return s;
    }
    QString gettime2(int x){
        QString s;
        s=QString::number(memtimes[x].second->tm_year);s+="/";
        s+=QString::number(memtimes[x].second->tm_mon);s+="/";
        s+=QString::number(memtimes[x].second->tm_mday);s+="  ";
        s+=QString::number(memtimes[x].second->tm_hour);s+=" : ";
        s+=QString::number(memtimes[x].second->tm_min);s+=" : ";
        s+=QString::number(memtimes[x].second->tm_sec);
        return s;
    }
    bool in_size(int x){
        if(x<memtimes.size())
            return 1;
        return 0;
    }
    void reduce(int a){
        this->money-=a;
    }
    bool comparemoney(QString str){
        if(str.toInt()>this->money){
            return 0;
        }
        return 1;
    }
    static void fileconstructor();
    bool check(QString s1,QString s2){
        if(username==s1 && password==s2)
            return 1;
        else return 0;
    }
};
class regist:public QMainWindow{
    Q_OBJECT;
    QWidget *reg;
    QVBoxLayout*vertivcalreg1;
    QVBoxLayout*vertivcalreg2;
    QLabel *regname1;
    QLabel*regnovalid;
    QLabel *reglastname1;
    QLabel *regbirthdate1;
    QLabel *regusername1;
    QLabel *regpassword1;
    QLabel *regcondition1;
    QPushButton*ok;
    QLineEdit*regname2;
    QLineEdit*reglastname2;
    QLineEdit*regbirthdate2;
    QLineEdit*regusername2;
    QLineEdit*regpassword2;
    QLineEdit*regcondition2;
    QHBoxLayout* regv;
    QVBoxLayout*regall;
public:explicit regist(QWidget *parent=nullptr){
        reg=new QWidget();
        //reg->closeEvent(nullptr);
        vertivcalreg1=new QVBoxLayout();
        vertivcalreg2=new QVBoxLayout();
        regnovalid=new QLabel();regnovalid->setStyleSheet("color : red");
        regname1=new QLabel();regname1->setText("Name : ");
        reglastname1=new QLabel();reglastname1->setText("Lastname : ");
        regbirthdate1=new QLabel();regbirthdate1->setText("Birthday(1397/04/17) : ");
        regusername1=new QLabel();regusername1->setText("User name :");
        regpassword1=new QLabel();regpassword1->setText("Password : ");
        regcondition1=new QLabel();regcondition1->setText("Condition (Fired/Active) : ");
        ok=new QPushButton("Ok");
        regname2=new QLineEdit();regname2->setText("Name");regname2->setStyleSheet("color: gray");
        reglastname2=new QLineEdit();reglastname2->setText("Lastname");reglastname2->setStyleSheet("color: gray");
        regbirthdate2=new QLineEdit();regbirthdate2->setText("1397/04/17");regbirthdate2->setStyleSheet("color: red");
        regusername2=new QLineEdit();regusername2->setText("User name");regusername2->setStyleSheet("color: gray");
        regpassword2=new QLineEdit();regpassword2->setText("1234567890");regpassword2->setEchoMode(QLineEdit::Password);
        regcondition2=new QLineEdit();regcondition2->setText("Condition");regcondition2->setStyleSheet("color:blue");
        regv=new QHBoxLayout();regall=new QVBoxLayout();
        vertivcalreg1->addWidget(regname1);vertivcalreg1->addWidget(reglastname1);
        vertivcalreg1->addWidget(regbirthdate1);vertivcalreg1->addWidget(regusername1);
        vertivcalreg1->addWidget(regpassword1);vertivcalreg1->addWidget(regcondition1);
        vertivcalreg2->addWidget(regname2);vertivcalreg2->addWidget(reglastname2);
        vertivcalreg2->addWidget(regbirthdate2);vertivcalreg2->addWidget(regusername2);
        vertivcalreg2->addWidget(regpassword2);vertivcalreg2->addWidget(regcondition2);
        regv->addLayout(vertivcalreg1);regv->addLayout(vertivcalreg2);
        regall->addWidget(regnovalid);regall->addLayout(regv);regall->addWidget(ok);
        reg->setLayout(regall);
        connect(ok,SIGNAL(clicked()),this,SLOT(Ok()));
        setCentralWidget(reg);
    }
    void closeEvent(QCloseEvent *event){
        this->~regist();
    }
    ~regist(){
        qDebug()<<"Exited";
        delete reg;
    }
    public slots:
    void Ok();
};
class manager{
    QPair<QString,QString>name;
    QPair<int,QPair<int,int>>birthdate;
    QString username;
    QString password;
    double commission;
    QVector<QPair<tm*,tm*>>memtimes;
    int money;
public:void filein();
       manager(QString nam="",QString lastname="",int b1=0,int b2=0,int b3=0,QString user="",QString pass="",int comm=0){
        name=QPair<QString,QString>(nam,lastname);birthdate=QPair<int,QPair<int,int>>(b1,QPair<int,int>(b2,b3));
        username=user;password=pass;commission=comm;
       }
       void induce(int x){
           money+=x;
       }
       bool checkpassword(QString s){
           if(password==s)
               return 1;
           return 0;
       }
       bool checkusername(QString s){
           if(username==s)
               return 1;
           return 0;
       }
       double getcommission(){return commission;}
};

#endif // MAINWINDOW_H
