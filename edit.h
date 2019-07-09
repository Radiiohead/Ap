#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include <editpage.h>
#include <nep.h>
#include <sep.h>
namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Edit *ui;
    NEP* nedit;
    SEP* sedit;
    EditPage* aedit;
};

#endif // EDIT_H
