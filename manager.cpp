#include "manager.h"
#include <classes.h>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QSlider>
#include <QStyleOptionButton>

Manager::Manager(QWidget *parent) :
    QDialog(parent)
{
    QWidget *center = new QWidget;
    QGridLayout * gl = new QGridLayout;
    QHBoxLayout * hbup = new QHBoxLayout;
    QVBoxLayout * vbpb = new QVBoxLayout;
QLabel* manage = new QLabel;
manage->setText("Manage");

    center->setStyleSheet(tr("color: #b1b1b1;"
                             "background-color: #323232;"));
   QPushButton * pbadd = new QPushButton("Add");
   pbadd->setStyleSheet(tr( "color: white;"
                            " background-color: #27a9e3;"
                       " border-style: outset;"
                      " border-width: 0px;"
                        "border-radius: 10px;"
                        "font: 14px;"
                        "min-width: 10em;"
                        "padding: 6px;"
                            "pressed {"
                            "background-color: rgb(224, 0, 0);"
                            "border-style: inset;"
                        "}"
                           ) );
   pbadd->setMinimumWidth(68);
   pbadd->setMinimumHeight(60);
    connect(pbadd,SIGNAL(clicked()),this,SLOT(on_add_clicked()));

   QPushButton * pbedit = new QPushButton(tr("&Edit"));
  pbedit->setStyleSheet(tr("color: white;"
                           " background-color: #27a9e3;"
                      " border-style: outset;"
                     " border-width: 0px;"
                       "border-radius: 10px;"
                       "font: 14px;"
                       "min-width: 10em;"
                       "padding: 6px;"
                           "pressed {"
                           "background-color: rgb(224, 0, 0);"
                           "border-style: inset;"
                       "}"
                           ));
  pbedit->setMinimumWidth(68);
  pbedit->setMinimumHeight(60);
  connect(pbedit,SIGNAL(clicked()),this,SLOT(on_edit_clicked()));
   QPushButton * pbmng = new QPushButton(tr("&Manage"));
   pbmng->setStyleSheet(tr("color: white;"
                           " background-color: #27a9e3;"
                      " border-style: outset;"
                     " border-width: 0px;"
                       "border-radius: 10px;"
                       "font: 14px;"
                       "min-width: 10em;"
                       "padding: 6px;"
                           "pressed {"
                           "background-color: rgb(224, 0, 0);"
                           "border-style: inset;"
                       "}"
                           "hover { background-color: #66c011; }"
                           ));
   pbmng->setMinimumWidth(68);
   pbmng->setMinimumHeight(60);
   connect(pbmng,SIGNAL(clicked()),this,SLOT(on_mng_clicked()));
   QPushButton * pbinfo = new QPushButton(tr("&Information"));
   pbinfo->setStyleSheet("color: white;"
                         " background-color: #27a9e3;"
                    " border-style: outset;"
                   " border-width: 0px;"
                     "border-radius: 10px;"
                     "font: 14px;"
                     "min-width: 10em;"
                     "padding: 6px;"
                         "pressed {"
                         "background-color: rgb(224, 0, 0);"
                         "border-style: inset;"
                     "}"
                            );
   pbinfo->setMinimumWidth(68);
   pbinfo->setMinimumHeight(60);
   connect(pbinfo,SIGNAL(clicked()),this,SLOT(on_info_clicked()));




   vbpb->addWidget(pbadd);
   vbpb->addWidget(pbedit);
   vbpb->addWidget(pbmng);
   vbpb->addWidget(pbinfo);
   gl->addLayout(hbup, 0,5);
   gl->addLayout(vbpb,45,0,Qt::AlignLeft);
   setLayout(gl);
}

Manager::~Manager()
{

}

void Manager::on_add_clicked(){
    adp = new Add;
    adp->exec();
}

void Manager::on_edit_clicked(){
    edp = new Edit;
    edp->exec();
}

void Manager::on_mng_clicked(){
    mngp = new Manage;
    mngp->exec();
}

void Manager::on_info_clicked(){
    infp = new Info;
    infp->exec();
}
