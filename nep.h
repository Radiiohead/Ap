#pragma once
#ifndef NEP_H
#define NEP_H

#include <QDialog>
#include <classes.h>
namespace Ui {
class NEP;
}

class NEP : public QDialog
{
    Q_OBJECT

public:
    explicit NEP(QWidget *parent = nullptr);
    int n;
    ~NEP();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NEP *ui;
};

#endif // NEP_H
