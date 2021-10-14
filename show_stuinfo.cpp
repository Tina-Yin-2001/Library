#include "utils.h"
#include "show_stuinfo.h"
#include "ui_show_stuinfo.h"
#include "studentstore.h"
#include <vector>
#include <iostream>


using namespace studentstore;
using namespace utils;

show_stuinfo::show_stuinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_stuinfo) {
    ui->setupUi(this);

    QStringList header;

    ui->tableWidget->setColumnCount(4);
    header << "ID" << "姓名" << "学工号" << "专业";
    ui->tableWidget->setHorizontalHeaderLabels(header);
}

show_stuinfo::~show_stuinfo() {
    delete ui;
}

void show_stuinfo::show(vector<Student*>stuList) {

    for (int i = 0; i < stuList.size(); i++) {      //展示信息

        ui->tableWidget->setRowCount(stuList.size());   //设置表格行数

        QString tempCell = QString(QString::number(stuList[i]->ID));
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(tempCell));
        tempCell = QString(QString::fromLocal8Bit(stuList[i]->name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(tempCell));
        tempCell = QString(QString::fromLocal8Bit(stuList[i]->stu_id));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(tempCell));
        tempCell = QString(QString::fromLocal8Bit(stuList[i]->major));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tempCell));
    }
}


void show_stuinfo::on_pushButton_clicked() {        //按id搜索
    QString str = ui->lineEdit->text(); //Qstring与int转化
    string s = string((const char *)str.toLocal8Bit());
    int tmp = atoi(s.c_str());
    Student* stu = search<Student>(tmp, studentDatPath);
    vector<Student*> stuList;
    stuList.push_back(stu);
    this->show(stuList);
}

void show_stuinfo::on_pushButton_2_clicked() {      //按学号搜索
    QString str = ui->lineEdit->text(); //Qstring与int转化
    string s = string((const char *)str.toLocal8Bit());
    Student* stu = search_oneReturn<Student>("stu_id", s, studentDatPath) ;
    vector<Student*> stuList;
    stuList.push_back(stu);
    this->show(stuList);
}

void show_stuinfo::on_pushButton_3_clicked() {      //按姓名搜索（准确），但可能重名（多返回）
    QString str = ui->lineEdit->text(); //Qstring与int转化
    string searchKey = string((const char *)str.toLocal8Bit());
    vector<Student*> stuList = search_multipleReturn<Student>("notFuzzySearch", "name", searchKey, studentDatPath) ;
    this->show(stuList);

}

void show_stuinfo::on_pushButton_4_clicked() {      //模糊搜索
    QString str = ui->lineEdit->text(); //Qstring与int转化
    string searchKey = string((const char *)str.toLocal8Bit());
    vector<Student*> stuList = search_multipleReturn<Student>("useFuzzySearch", "name", searchKey, studentDatPath) ;
    this->show(stuList);


}
