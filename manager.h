#ifndef MANAGER_H
#define MANAGER_H

#include <QDialog>
#include <add.h>
#include <info.h>
#include <manage.h>
#include <edit.h>
#include <classes.h>


class Manager : public QDialog
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private:
    Add * adp;
    Info * infp;
    Manage * mngp;
    Edit * edp;
public slots:
   void on_add_clicked();
   void on_info_clicked();
   void on_mng_clicked();
   void on_edit_clicked();
};

#endif // MANAGER_H
