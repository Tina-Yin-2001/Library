#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "show_stuinfo.h"

class show_stuinfo;
namespace Ui {
class login;
}

class login : public QDialog {
    Q_OBJECT

  public:
    explicit login(QWidget *parent = nullptr);
    ~login();

  private slots:
    void on_loginButton_clicked();



  private:
    Ui::login *ui;
    show_stuinfo *showinfo;

};

#endif // LOGIN_H
