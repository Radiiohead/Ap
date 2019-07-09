#include "mainwindow.h"
#pragma once
//#include "ui_mainwindow.h"
QVector<member>memv;
manager m;
time_t t = time(0);
int managerusername;
int managerpassword;
QFile file1("ap project.txt");
QTextStream in1(&file1);
int memf;
void readfile(){
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QString s;
    qDebug()<<"reading...";
    while(!in1.atEnd()){
        in1>>s;
        if(s=="manager")m.filein();
        if(s=="member")member::fileconstructor();
    }
}
bool search(QString s1,QString s2){
    for(int i=0;i<memv.size();i++)
        if(memv[i].check(s1,s2)==1)
            return 1;
    return 0;
}
int finder(QString s1,QString s2){
    for(int i=0;i<memv.size();i++)
        if(memv[i].check(s1,s2)==1)
            return i;
    return -1;
}
int  mystream(QString s,int&a,int &b){
    QString s1,s2,s3;int i;
    for(i=0;s[i]!='/';i++)
        s1.push_back(s[i]);
    i++;
    for(i;s[i]!='/';i++)
        s2.push_back(s[i]);
    i++;
    for(i;i<s.size();i++)
        s3.push_back(s[i]);
    a=s2.toInt();
    b=s3.toInt();
    return s3.toInt();
    return a;
}
QVector<apartment>apbuylist;
QVector<apartment>aprentlist;
QVector<north_house>nhbuylist;
QVector<north_house>nhrentlist;
QVector<south_house>shbuylist;
QVector<south_house>shrentlist;
//QVector<apartment>apv;
//QVector<north_house>nhv;
//QVector<south_house>shv;
void apartment::fileconstructor(){
        apartment*a1=new apartment();
        QFile file("ap project apartment.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream in(&file);
         while(!in.atEnd()){
        qDebug()<<"K 2";
        in>>a1->total_area>>a1->level_num>>a1->basic_price>>a1->house_per_level;
        QString s,t;in>>s>>t;if((s+" "+t)=="Has elevator"){
            a1->elevator_condition=1;
        }
        else a1->elevator_condition=0;//a1="No elevator"
        in>>a1->use>>a1->home_level>>a1->home_room_num>>a1->home_building_area;
        //photos:
        in>>a1->apartment_photo_str>>a1->home_pic_str;
        a1->apartment_photo=QImage(a1->apartment_photo_str+".jpg");
        a1->home_pic=QImage(a1->home_pic_str+".jpg");
        //qDebug()<<a1->home_room_num;
        apv.push_back(*a1);
        //a1->apartment_photo = QImage(image,"JPG");
         //image="C:/Users/behesht/Deskto/pqt files/project/images"+image+".jpg";
         /*QDir dir(image);
         foreach(QFileInfo,dir.entryInfoList()){
             this->;
         }*/
 }
}
void north_house::fileconstructor(){
    north_house*a1=new north_house();
    QFile file("ap project north-house.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
     while(!in.atEnd()){
    in>>a1->total_area>>a1->building_area>>a1->front_yard_area>>a1->back_yard_area>>a1->room_num>>a1->basic_price>>a1->address;
    //photo
    in>>a1->nhome_photo_str;
    a1->nhome_photo=QImage(a1->nhome_photo_str+".jpg");
        nhv.push_back(*a1);
    }
     /*for(int i=0;i<nhv.size();i++)
         qDebug()<<nhv[i].address;*/
}
void south_house::fileconstructor(){
    south_house*a1=new south_house();
    QFile file("ap project south-house.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
     while(!in.atEnd()){
    in>>a1->total_area>>a1->building_area>>a1->yard_area>>a1->parking_area>>a1->room_num>>a1->basic_price>>a1->address;
    //photo
    in>>a1->shome_photo_str;
    a1->shome_photo=QImage(a1->shome_photo_str+".jpg");
        shv.push_back(*a1);
    }
     /*for(int i=0;i<shv.size();i++)
         qDebug()<<shv[i].address;*/
}
login::login(QWidget *parent):QMainWindow(parent){
    readfile();
    apartment::fileconstructor();
    north_house::fileconstructor();
    south_house::fileconstructor();
    qDebug()<<"size : " <<shv.size();
    QPushButton * reg=new QPushButton("Register");
    QPushButton * close=new QPushButton("Close");
    QPushButton * login=new QPushButton("Login");
    QHBoxLayout* all=new QHBoxLayout();
    all->addWidget(reg);
    all->addWidget(close);
    all->addWidget(login);
    QLabel*hi=new QLabel();
    hi->setText("HELLO!");
    QLabel*Hi=new QLabel();
    Hi->setText("Please choose!");
    QWidget *central=new QWidget();
    QVBoxLayout * alllog=new QVBoxLayout();
    alllog->addWidget(hi);
    alllog->addWidget(Hi);
    alllog->addLayout(all);
    central->setLayout(alllog);
    setCentralWidget(central);
    //Signals
    connect(close,SIGNAL(clicked()),this,SLOT(Close()));
    connect(reg,SIGNAL(clicked()),this,SLOT(Register()));
    connect(login,SIGNAL(clicked()),this,SLOT(Login()));

}
void login::Register(){
    regist*r=new regist();
    connect(this,SIGNAL(sendreg()),r,SLOT(show()));
    emit sendreg();
}
void login::Login(){
    loging*r=new loging();
    connect(this,SIGNAL(sendreg()),r,SLOT(show()));
    emit sendreg();
}
void regist::Ok(){
    qDebug()<<memv.size();
    int x1,x2,x3=mystream(regbirthdate2->text(),x1,x2);
    if(search(regusername2->text(),regpassword2->text())==1){
    this->regnovalid->setText("Your username and password is used before please change them");
    }else{
      memv.push_back(member(regname2->text(),reglastname2->text(),0,1,2,regcondition2->text(),regusername2->text(),regpassword2->text()));
      close();
    }
}
void member::fileconstructor(){
    member*a1=new member();
    in1>>a1->name.first>>a1->name.second>>a1->birthdate.first>>a1->birthdate.second.first>>a1->birthdate.second.second
    >>a1->username>>a1->password;
    QString s;in1>>s;if(s=="Active")a1->condition=1;
    else a1->condition=0; in1>>a1->money;
    qDebug()<<"reading time";
    int siz;in1>>siz;char usl=' ';
    struct tm*t1=localtime(&t);struct tm*t2=localtime(&t);
    for(int i=0;i<siz;i++){
        qDebug()<<"reading time"<<i+1;
        t1=new struct tm;
        t2=new struct tm;
        in1>>t1->tm_year>>usl>>t1->tm_mon>>usl>>t1->tm_mday>>t1->tm_hour>>usl>>t1->tm_min>>usl>>t1->tm_sec;
        in1>>t2->tm_year>>usl>>t2->tm_mon>>usl>>t2->tm_mday>>t2->tm_hour>>usl>>t2->tm_min>>usl>>t2->tm_sec;
        qDebug()<<t1->tm_year<<usl<<t1->tm_mon<<usl<<t1->tm_mday<<t1->tm_hour<<usl<<t1->tm_min<<usl<<t1->tm_sec;
        qDebug()<<t2->tm_year<<usl<<t2->tm_mon<<usl<<t2->tm_mday<<t2->tm_hour<<usl<<t2->tm_min<<usl<<t2->tm_sec;
       a1->memtimes.push_back(QPair<tm*,tm*>(t1,t2));
    }
    for(int i=0;i<siz;i++){
        //qDebug()<<"reading time"<<i+1;
        //struct tm*t1=localtime(&t);struct tm*t2=localtime(&t);
        //qDebug()<<a1->memtimes[i].first->tm_year<<usl<<a1->memtimes[i].first->tm_mon<<usl<<a1->memtimes[i].first->tm_mday<<a1->memtimes[i].first->tm_hour<<usl<<a1->memtimes[i].first->tm_min<<usl<<a1->memtimes[i].first->tm_sec;
        //qDebug()<<a1->memtimes[i].second->tm_year<<usl<<a1->memtimes[i].second->tm_mon<<usl<<a1->memtimes[i].second->tm_mday<<a1->memtimes[i].second->tm_hour<<usl<<a1->memtimes[i].second->tm_min<<usl<<a1->memtimes[i].second->tm_sec;
    }
    qDebug()<<"reading done";
    memv.push_back(*(a1));
}
void loging::Login(){
    if(m.checkusername(this->log_username2->text())&& m.checkpassword(this->log_password2->text())){
        Manager* mm = new Manager;
        mm->exec();
    }else{
    if(search(this->log_username2->text(),this->log_password2->text())==1){
        memf=finder(this->log_username2->text(),this->log_password2->text());
        member_in*r1=new member_in();
        connect(this,SIGNAL(sender()),r1,SLOT(show()));
        emit sender();
        close();
    }
    else{
        if(0){
        //manager condition
        }
        else{
        this->log_novalid->setText("Not found such username and password");
    }
  }
    }
}
void show_nhome::sho_nhome_change(){
    shonhome_allarea->setText("All area : "+(QString::number(nhv[nhomecounter].total_area)));
    shonhome_basicp->setText("Basic price : "+(QString::number(nhv[nhomecounter].basic_price)));
    //shonhome_totalp->setText("Apartment has "+(QString::number(nhv[nhomecounter].)));
    shonhome_roomnum->setText("This house has "+QString::number(nhv[nhomecounter].room_num)+"rooms");
    shonhome_fyard->setText("Front yard area : "+QString::number(nhv[nhomecounter].front_yard_area));
    shonhome_byard->setText("Back yard area : "+QString::number(nhv[nhomecounter].back_yard_area));
    shonhome_address->setText("Address : "+nhv[nhomecounter].address);
    int k=nhv[nhomecounter].basic_price*nhv[nhomecounter].building_area+(double)nhv[nhomecounter].basic_price*(double)nhv[nhomecounter].front_yard_area*0.3;
    k+=(double)nhv[nhomecounter].basic_price*(double)nhv[nhomecounter].back_yard_area*0.15;
    shonhome_totalp->setText("Total Price : "+QString::number(k));
    int k1=(int)(((double)(k)*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20)));
    shonhome_rent->setText("Rent cost per month : "+QString::number(k1));
    if(memv[memf].comparemoney(QString::number(k1)))field->setStyleSheet("color : green");
    else field->setStyleSheet("color : red");
    int k2=(int)(((double)k)*((double)(m.getcommission()+(double)1)));
    shonhomebuy->setText("Buy Price : "+QString::number(k2));
    if(memv[memf].comparemoney(QString::number(k2)))shonhomebuy->setStyleSheet("color : green");
    else shonhomebuy->setStyleSheet("color : red");
    //qDebug()<<"hello 2";
   shonhome_image->setPixmap(QPixmap::fromImage(nhv[nhomecounter].nhome_photo));

}
void show_nhome::sho_nhome_nchanger(){
    if(this->nhomecounter+1<=nhv.size()-1){
        nhomecounter++;
        sho_nhome_change();
}
}
void show_nhome::sho_nhome_pchanger(){
    if(this->nhomecounter>0){
        nhomecounter--;
        sho_nhome_change();
}
}
void show_nhome::sho_nhome_b(){
    int k=nhv[nhomecounter].basic_price*nhv[nhomecounter].building_area+(double)nhv[nhomecounter].basic_price*(double)nhv[nhomecounter].front_yard_area*0.3;
    k+=(double)nhv[nhomecounter].basic_price*(double)nhv[nhomecounter].back_yard_area*0.15;
    if(this->letbuy==1){
    if(!memv[memf].comparemoney(QString::number((int)(((double)k)*((double)(m.getcommission()+(double)1)))))){
    QMessageBox*mass=new QMessageBox();mass->setText("Not enough money");mass->show();
    }else{
        memv[memf].reduce((int)(((double)k)*((double)(m.getcommission()+(double)1))));
        nhbuylist.push_back(nhv[nhomecounter]);
        nhv.erase(nhv.begin()+nhomecounter);
        letbuy=0;
        this->~show_nhome();
    }
   }
}
void show_nhome::sho_nhome_r(){
    int k=nhv[nhomecounter].basic_price*nhv[nhomecounter].building_area+(double)nhv[nhomecounter].basic_price*(double)nhv[nhomecounter].front_yard_area*0.3;
    k+=(double)nhv[nhomecounter].basic_price*(double)nhv[nhomecounter].back_yard_area*0.15;
    if(this->letrent==1){
    if(!memv[memf].comparemoney(QString::number((int)(((double)(k)*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20)))))){
    QMessageBox*mass=new QMessageBox();mass->setText("Not enough money");mass->show();
    }else{
        memv[memf].reduce((int)(((double)(k)*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20))));
        nhrentlist.push_back(nhv[nhomecounter]);
        nhv.erase(nhv.begin()+nhomecounter);
        letrent=0;
        this->~show_nhome();
    }
   }
}
void show_app::sho_app_change(){
    //qDebug()<<"hello 1";
    //qDebug()<<appcounter;
    if(apv[appcounter].elevator_condition==1)shoapp_elevator_condition->setText("Has elevator");
    else shoapp_elevator_condition->setText("does'nt have elevator");
    shoapp_cond->setText(apv[appcounter].use+" use");
    shoapp_allarea->setText("All area : "+(QString::number(apv[appcounter].total_area)));
    shoapp_basicp->setText("Basic price : "+(QString::number(apv[appcounter].basic_price)));
    shoapp_layarnum->setText("Apartment has "+(QString::number(apv[appcounter].level_num)+" levels"));
    shoapp_houseperlevel->setText("Each level has "+QString::number(apv[appcounter].house_per_level)+"houses");
    shoapp_levelnum->setText("Level number : "+QString::number(apv[appcounter].home_level));
    int k=(int)(((double)(apv[appcounter].price()))*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20));
    shoapp_rent->setText("Rent cost per month : "+QString::number(k));
    if(memv[memf].comparemoney(QString::number(k)))field->setStyleSheet("color : green");
    else field->setStyleSheet("color : red");
    int k1=(int)(((double)apv[appcounter].price())*((double)(m.getcommission()+(double)1)));
    shoapp_buy->setText("Buy Price : "+QString::number(k1));
    if(memv[memf].comparemoney(QString::number(k1)))shoapp_buy->setStyleSheet("color : green");
    else shoapp_buy->setStyleSheet("color : red");
    //qDebug()<<"hello 2";
    shoapp_roomnum->setText("Building has "+QString::number(apv[appcounter].home_room_num)+" rooms");
    shoapp_build_area->setText("Building area : "+QString::number(apv[appcounter].home_building_area));
    shoapp_totalp->setText("Total price : "+QString::number(apv[appcounter].price()));
    shoapp_house_image->setPixmap(QPixmap::fromImage(apv[appcounter].home_pic));
    shoapp_image->setPixmap(QPixmap::fromImage(apv[appcounter].apartment_photo));
}
void show_app::sho_app_nchanger(){
    if(this->appcounter+1<=apv.size()-1){
        appcounter++;
        sho_app_change();
}
}
void show_app::sho_app_pchanger(){
    if(this->appcounter>0){
        appcounter--;
        sho_app_change();
    }
}
void show_app::sho_app_b(){
    if(this->letbuy==1){
    if(!memv[memf].comparemoney(QString::number((int)(((double)apv[appcounter].price())*((double)(m.getcommission()+(double)1)))))){
    QMessageBox*mass=new QMessageBox();mass->setText("Not enough money");mass->show();
    }else{
        m.induce((int)(((double)apv[appcounter].price())*((double)(m.getcommission()+(double)1))));
        memv[memf].reduce((int)(((double)apv[appcounter].price())*((double)(m.getcommission()+(double)1))));
        apbuylist.push_back(apv[appcounter]);
        apv.erase(apv.begin()+appcounter);
        letbuy=0;
        this->~show_app();
    }
   }
}
void show_app::sho_app_r(){
    if(this->letrent==1){
    if(!memv[memf].comparemoney(QString::number((int)(((double)(apv[appcounter].price()))*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20))))){
    QMessageBox*mass=new QMessageBox();mass->setText("Not enough money");mass->show();
    }else{
        m.induce(((double)(apv[appcounter].price()))*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20));
        memv[memf].reduce((int)(((double)(apv[appcounter].price()))*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20)));
        aprentlist.push_back(apv[appcounter]);
        apv.erase(apv.begin()+appcounter);
        letrent=0;
        this->~show_app();
    }
   }
}
void manager::filein(){
    in1>>m.name.first>>m.name.second>>m.birthdate.first>>m.birthdate.second.first>>m.birthdate.second.second
    >>m.username>>m.password;
    int siz;in1>>siz;char usl;
    for(int i=0;i<siz;i++){
        struct tm*t1=localtime(&t);struct tm*t2=localtime(&t);
        in1>>t1->tm_year>>usl>>t1->tm_mon>>usl>>t1->tm_mday>>usl>>t1->tm_hour>>usl>>t1->tm_min>>usl>>t1->tm_sec;
        in1>>t2->tm_year>>usl>>t2->tm_mon>>usl>>t2->tm_mday>>usl>>t2->tm_hour>>usl>>t2->tm_min>>usl>>t2->tm_sec;
        m.memtimes.push_back(QPair<tm*,tm*>(t1,t2));
    }
};
void show_times::time_in_app(){
    for(int i=0;memv[memf].in_size(i);i++){
    this->time_box1->addItem(memv[memf].gettime1(i));
    this->time_box2->addItem(memv[memf].gettime2(i));
 }
}
void show_houses::seeap(){
    if(apv.size()==0)return;
    show_app*s2=new show_app();
    connect(this,SIGNAL(sp()),s2,SLOT(show()));
    emit sp();
}
void show_houses::seenhome(){
    if(nhv.size()==0)return;
    show_nhome*s3=new show_nhome();
    connect(this,SIGNAL(snh()),s3,SLOT(show()));
    emit snh();
}
void show_houses::seeshome(){
    if(shv.size()==0)return;
    show_shome*s4=new show_shome();
    connect(this,SIGNAL(ssh()),s4,SLOT(show()));
    emit ssh();
}
void show_shome::sho_shome_change(){
    shoshome_allarea->setText("All area : "+(QString::number(shv[shomecounter].total_area)));
    shoshome_basicp->setText("Basic price : "+(QString::number(shv[shomecounter].basic_price)));
    //shonhome_totalp->setText("Apartment has "+(QString::number(nhv[nhomecounter].)));
    shoshome_roomnum->setText("This house has "+QString::number(shv[shomecounter].room_num)+"rooms");
    shoshome_yard->setText("Yard area : "+QString::number(shv[shomecounter].yard_area));
    shoshome_parking->setText("Parking area : "+QString::number(shv[shomecounter].parking_area));
    shoshome_address->setText("Address : "+shv[shomecounter].address);
    int k=shv[shomecounter].basic_price*shv[shomecounter].building_area+(double)shv[shomecounter].basic_price*(double)shv[shomecounter].yard_area*0.3;
    k+=(double)shv[shomecounter].basic_price*(double)shv[shomecounter].parking_area*0.15;
    shoshome_totalp->setText("Total Price : "+QString::number(k));
    int k1=(int)(((double)(k)*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20)));
    shoshome_rent->setText("Rent cost per month : "+QString::number(k1));
    if(memv[memf].comparemoney(QString::number(k1)))field->setStyleSheet("color : green");
    else field->setStyleSheet("color : red");
    int k2=(int)(((double)k)*((double)(m.getcommission()+(double)1)));
    shoshomebuy->setText("Buy Price : "+QString::number(k2));
    if(memv[memf].comparemoney(QString::number(k2)))shoshomebuy->setStyleSheet("color : green");
    else shoshomebuy->setStyleSheet("color : red");
    //qDebug()<<"hello 2";
   shoshome_image->setPixmap(QPixmap::fromImage(shv[shomecounter].shome_photo));

}
void show_shome::sho_shome_nchanger(){
    if(this->shomecounter+1<=shv.size()-1){
        shomecounter++;
        sho_shome_change();
}
}
void show_shome::sho_shome_pchanger(){
    if(this->shomecounter>0){
        shomecounter--;
        sho_shome_change();
}
}
void show_shome::sho_shome_b(){
    int k=shv[shomecounter].basic_price*shv[shomecounter].building_area+(double)shv[shomecounter].basic_price*(double)shv[shomecounter].yard_area*0.3;
    k+=(double)shv[shomecounter].basic_price*(double)shv[shomecounter].parking_area*0.15;
    if(this->letbuy==1){
    if(!memv[memf].comparemoney(QString::number((int)(((double)k)*((double)(m.getcommission()+(double)1)))))){
    QMessageBox*mass=new QMessageBox();mass->setText("Not enough money");mass->show();
    }else{
        m.induce((int)(((double)k)*((double)(m.getcommission()+(double)1))));
        memv[memf].reduce((int)(((double)k)*((double)(m.getcommission()+(double)1))));
        shbuylist.push_back(shv[shomecounter]);
        shv.erase(shv.begin()+shomecounter);
        letbuy=0;
        this->~show_shome();
    }
   }
}
void show_shome::sho_shome_r(){
    int k=shv[shomecounter].basic_price*shv[shomecounter].building_area+(double)shv[shomecounter].basic_price*(double)shv[shomecounter].yard_area*0.3;
    k+=(double)shv[shomecounter].basic_price*(double)shv[shomecounter].parking_area*0.15;
    if(this->letrent==1){
    if(!memv[memf].comparemoney(QString::number((int)(((double)(k)*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20)))))){
    QMessageBox*mass=new QMessageBox();mass->setText("Not enough money");mass->show();
    }else{
        m.induce((int)(((double)(k)*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20))));
        memv[memf].reduce((int)(((double)(k)*(((double)(field->text().toInt()))/(double)100+(m.getcommission()+(double)1)/(double)20))));
        shrentlist.push_back(shv[shomecounter]);
        shv.erase(shv.begin()+shomecounter);
        letrent=0;
        this->~show_shome();
    }
   }
}
MainWindow::~MainWindow(){}
