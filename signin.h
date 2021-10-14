#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include "login.h"
#include "importstudent.h"
#include "show_stulist.h"
#include "debug.h"

class login;
namespace Ui {
class signin;
}

class signin : public QDialog {
    Q_OBJECT

  public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

  private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_deBugButton_clicked();

  private:
    Ui::signin *ui;
    login* logino;
    importStudent* importStudentUI;
    show_stulist* show_stulistUI;
    deBug* deBugUI;
};

#endif // SIGNIN_H
