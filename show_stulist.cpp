#include "show_stulist.h"
#include "init.h"
#include "student.h"
#include "ui_show_stulist.h"
#include "studentstore.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "utils.h"
using namespace utils;
show_stulist::show_stulist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_stulist) {
    ui->setupUi(this);

    loadStuList();
}

show_stulist::~show_stulist() {
    delete ui;
}

void show_stulist::on_pushButton_clicked() {
    loadStuList();
}

void show_stulist::loadStuList() {
    auto size = sizeof (Student);//学生类的大小
    FILE *file = openfile(studentDatPath, size); //打开文件

    fseek(file, 0, SEEK_END);//fseek将文件指针指到文件末尾
    auto offset = ftell(file);//ftell得到文件从指针到文件头的大小（offset是文件总大小）

    int row = offset / size; //采取和增加用户时算ID大小一样的方法算数据行数
    ui->tableWidget->setColumnCount(3); //设置列数
    QStringList header;
    header << "学工号" << "姓名" << "专业";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(row);    //设置行数



    for(int i = 0; i < row; i++) {
        Student* tempStu = studentstore::creatStudent();

        fseek(file, size * i, SEEK_SET);   //将指针移到该放的地方
        fread(tempStu, size, 1, file);          //读出需要查询的同学数据

        QString id = QString(QString::fromLocal8Bit(tempStu->stu_id, MAX_ID));
        QString name = QString(QString::fromLocal8Bit(tempStu->name, MAX_NAME));
        QString major = QString(QString::fromLocal8Bit(tempStu->major, MAX_MAJOR));
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(major));

        delete(tempStu);
    }
    fclose(file);//关闭文件
}


//导出成csv
void show_stulist::on_pushButton_2_clicked() {
    ofstream outFile;
    outFile.open("C:\\Users\\dell\\Documents\\2021_news\\soft\\Library1.4\\stuList_output.csv", ios::out); //打开模式可省略

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        QString str = ui->tableWidget->item(i, 0)->text();
        string name = string((const char *)str.toLocal8Bit());
        QString str_2 = ui->tableWidget->item(i, 1)->text();
        string stu_id = string((const char *)str_2.toLocal8Bit());
        QString str_3 = ui->tableWidget->item(i, 2)->text();
        string major = string((const char *)str_3.toLocal8Bit());
        outFile << name << "," << stu_id << "," << major << endl;
    }
    outFile.close();
}
