#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "init.h"

#include "importstudent.h"
#include "ui_importstudent.h"
#include "studentstore.h"


using namespace std;

importStudent::importStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importStudent) {
    ui->setupUi(this);



    ui->tableWidget->setColumnCount(4); //设置列数

}

importStudent::~importStudent() {
    delete ui;
}

void importStudent::on_pushButton_clicked() {

    int csvRow =0;
    vector<vector<string>> user_arr; //二维string数组，string方便合法性检测，string可用c_str()函数转换成char*储存
    ifstream fp(defaultUserDataCsvPath);    //定义声明一个ifstream对象，指定文件路径
    string line;
    getline(fp, line); //跳过列名，第一行不做处理

    while (getline(fp, line)) { //循环读取每行数据，可规避未知csv行数的问题
        vector<string> data_line;    //一行的数据
        string cellData;             //单元格的数据
        istringstream readstr(line); //string数据流化

        for (int j = 0; j < 4; j++) { //该csv文件有4列
            getline(readstr, cellData, ','); //以“，”为间隔读取单元格数据放到cellData中
            data_line.push_back(cellData);   //cellData数据存到dataline中
        }
        user_arr.push_back(data_line); //将一行数据插入到vector中
        csvRow++;
    }

    ui->tableWidget->setRowCount(csvRow);    //设置行数

    //插入数据到表格
    for (int i = 0; i < user_arr.size(); i++) {     //从vector中逐个导入数据
        for (int j = 0; j < user_arr[0].size(); j++) {
            QString tempCell = QString(QString::fromStdString(user_arr[i][j]));
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(tempCell));
        }
    }
}


//!!!默认数据合法 列顺序应为(name, stu_id, pwd, major)
//直接调用QTableWidget里的数据
void importStudent::on_pushButton_2_clicked() {

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {     //从vector中逐个导入数据
        Student* tempStu = new Student ();

        QString str = ui->tableWidget->item(i, 0)->text();
        string name = string((const char *)str.toLocal8Bit());
        QString str_2 = ui->tableWidget->item(i, 1)->text();
        string stu_id = string((const char *)str_2.toLocal8Bit());
        QString str_3 = ui->tableWidget->item(i, 2)->text();
        string pwd = string((const char *)str_3.toLocal8Bit());
        QString str_4 = ui->tableWidget->item(i, 3)->text();
        string major = string((const char *)str_4.toLocal8Bit());

        tempStu = studentstore::creatStudent(name, stu_id, pwd, major);
        studentstore::addStudent(tempStu);
        delete(tempStu);
    }
}
