#include "login.h"
#include "ui_login.h"
#include "studentstore.h"
#include "utils.h"
#include <QString>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <string.h>
#include <QMessageBox>
using namespace studentstore;
using namespace utils;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login) {
    ui->setupUi(this);
    showinfo = new show_stuinfo(this);
    showinfo->hide();
}

login::~login() {
    delete ui;
}

void login::on_loginButton_clicked() {
//    if(this->on_radioButton_clicked(1)==0)//管理员
//    {
//        QString str=ui->lineEdit->text();
//        string admin=string((const char *)str.toLocal8Bit());
//        QString str2=ui->lineEdit_2->text();
//        string code=string((const char*)str2.toLocal8Bit());
//        if(strcmp(admin.c_str(),admin_id.c_str())==0&&strcmp(code.c_str(),admin_password.c_str())==0)
//        {
//            QMessageBox::information(NULL, "Title", "Content",
//                                     QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//        }
//        else{
//            QMessageBox::warning(NULL, "warning", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

//        }
//    }
//    if(this->on_radioButton_2_clicked(1)==1)
//    {
    QString str = ui->idEdit->text();
    string stu_id = string((const char *)str.toLocal8Bit());
    QString str2 = ui->pwdEdit->text();
    string code = string((const char*)str2.toLocal8Bit());
    Student* stu = search_oneReturn<Student>("stu_id", stu_id, studentDatPath) ;
    if(strcmp(stu->code, code.c_str()) == 0) {
        showinfo->open();
//        showinfo->show(stu);
    }

}

