#pragma once
#ifndef SEP_H
#define SEP_H

#include <QDialog>
#include <classes.h>
namespace Ui {
class SEP;
}

class SEP : public QDialog
{
    Q_OBJECT

public:
    explicit SEP(QWidget *parent = nullptr);
    int n;
    ~SEP();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SEP *ui;
};

#endif // SEP_H
