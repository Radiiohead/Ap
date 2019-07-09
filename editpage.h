#pragma once
#ifndef EDITPAGE_H
#define EDITPAGE_H

#include <QDialog>
#include <classes.h>
namespace Ui {
class EditPage;
}

class EditPage : public QDialog
{
    Q_OBJECT

public:
    explicit EditPage(QWidget *parent = nullptr);
    int n;
    ~EditPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EditPage *ui;
};

#endif // EDITPAGE_H
