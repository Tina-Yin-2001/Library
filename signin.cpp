#include "signin.h"
#include "ui_signin.h"
#include "studentstore.h"
#include <QString>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <string.h>
#include <QMessageBox>
#include "login.h"
#include "importstudent.h"
#include "show_stuinfo.h"
#include "debug.h"

using namespace std;
using namespace student;
using namespace studentstore;
signin::signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin) {
    ui->setupUi(this);
    logino = new login(this);
    logino->hide();
    importStudentUI = new importStudent(this);
    importStudentUI->hide();
    show_stulistUI = new show_stulist(this);
    show_stulistUI->hide();
    deBugUI = new deBug(this);
    deBugUI->hide();
}

signin::~signin() {
    delete ui;
}

void signin::on_pushButton_clicked() {
    QString str = ui->lineEdit->text();
    string stu_id = string((const char *)str.toLocal8Bit());
    QString str2 = ui->lineEdit_2->text();
    string name = string((const char *)str2.toLocal8Bit());
    QString str3 = ui->lineEdit_3->text();
    string pwd = string((const char *)str3.toLocal8Bit());

    QString comb = ui->comboBox->currentText();
    string major = string((const char *)comb.toLocal8Bit());

    Student* stu = new Student ();
    stu = creatStudent(name, stu_id, pwd, major);
    addStudent(stu);
    logino->open();

    delete stu;
    //QMessageBox::information(NULL, "OK", "成功", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void signin::on_pushButton_2_clicked() {
    importStudentUI->open();
}

void signin::on_pushButton_3_clicked() {
    show_stulistUI->open();
}
void signin::on_deBugButton_clicked() {
    deBugUI->open();
}
