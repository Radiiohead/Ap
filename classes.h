#pragma once
#ifndef CLASSES_H
#define CLASSES_H

#include <QDialog>
#include <QMainWindow>
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


class Classes : public QDialog
{
    Q_OBJECT

public:
    explicit Classes(QWidget *parent = nullptr);
    ~Classes();

private:

};



class apartment{
    //friend class s
    public:
    int total_area;
    QImage apartment_photo;
    QString apartment_photo_str;
    bool elevator_condition;
    int level_num;
    int house_per_level;
    QString use;
    int home_level;
    QImage home_pic;
    QString home_pic_str;
    int home_room_num;
    int home_building_area;
    int basic_price;
    int price(){
        float k=0;if(use=="Commercial" || use=="commercial")k=0.5;
        if(use=="Official" || use=="official")k=0.3;
        long double x=(long double)(this->basic_price)*(long double)(this->home_building_area);
        x+=x*0.2*(long double)this->home_level+x*0.08*(long double)this->home_room_num+k*x+(long double)this->elevator_condition*x/50;
        return (int)x;
    }
public: friend class show_app;
    static void fileconstructor();
    apartment(int tarea=0,int levnum=0,int bp=0,bool elevator=0,int homeperlev=0,int homelev=0,QString uses="",int homromnum=0,int barea=0,QString apph="",QString hoph=""){
        this->use=uses;this->total_area=tarea;this->level_num=levnum;this->house_per_level=homeperlev;this->basic_price=bp;
        this->home_level=homelev;this->home_room_num=homromnum;this->home_building_area=barea;this->elevator_condition=elevator;
    }
};
class north_house{
    public:
    int building_area;
    int front_yard_area;
    int back_yard_area;
    int total_area;
    int room_num;
    QImage nhome_photo;
    QString nhome_photo_str;
    int basic_price;
    QString address;
public:static void fileconstructor();
    friend class show_nhome;
    north_house(int tarea=0,int barea=0,int fyarea=0,int byarea=0,int romnum=0,int baseprice=0,QString adres="",QString nim=""){
        this->total_area=tarea;this->building_area=barea;this->front_yard_area=fyarea;this->back_yard_area=byarea;
        this->room_num=romnum;this->basic_price=baseprice;this->address=adres;nhome_photo_str=nim;
    }
};
class south_house{
public:
    int building_area;
    int yard_area;
    int parking_area;
    int total_area;
    int room_num;
    QImage shome_photo;
    int basic_price;
    QString address;
    QString shome_photo_str;
public:friend class show_shome;
    static void fileconstructor();
    south_house(int tarea=0,int barea=0,int yarea=0,int parea=0,int romnum=0,int baseprice=0,QString adres="",QString sim=""){
        this->total_area=tarea;this->building_area=barea;this->yard_area=yarea;this->parking_area=parea;
        this->room_num=romnum;this->basic_price=baseprice;this->address=adres;shome_photo_str=sim;
    }
};





extern QVector<apartment>apv;
extern QVector<north_house>nhv;
extern QVector<south_house>shv;

#endif // CLASSES_H
