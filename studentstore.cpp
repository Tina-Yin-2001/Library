#include "studentstore.h"
#include "init.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "utils.h"
using namespace student;
using namespace utils;

namespace studentstore {
/*添加和修改用户*/
bool addStudent(Student* stu) {
    auto size = sizeof (Student);//学生类的大小
    FILE *file = openfile(studentDatPath, size); //打开文件

    if (stu->ID == -1) { //初始化ID为-1，若ID为-1则表示该学生是新用户
        fseek(file, 0, SEEK_END);//fseek将文件指针指到文件末尾
        auto offset = ftell(file);//ftell得到文件从指针到文件头的大小（offset是文件总大小）
        stu->ID = offset / size; //确定ID大小
    } else { //已存在ID，表示不是新用户可以进行文件修改
        fseek(file, size * stu->ID, SEEK_SET);//将文件指针移到文件第ID个学生后
    }
    fwrite(stu, size, 1, file);//将student内容写入文件
    fclose(file);//关闭文件
    return 1;//返回1表示添加成功
}
/*删除学生*/
bool deleteStudent(int ID) {
    auto size = sizeof (Student);//学生类的大小
    FILE *file = openfile(studentDatPath, size); //打开文件

    if(ID != -1) { //存在该ID的学生
        fseek(file, size * ID, SEEK_SET);//将文件指针移到文件第ID个学生后
        Student* stu = new Student () ;//设置一个中间变量
        fread(stu, size, 1, file);//读取要删除的学生信息
        stu->exist = 0; //将他的标记位设置成0 表示已经被删除
        fseek(file, size * ID, SEEK_SET);//将指针指回
        fwrite(stu, size, 1, file);//将已经修改的内容写回文件
        delete stu;//释放中间变量
    } else return 0; //若该编号学生不存在 则表示删除失败
    fclose(file);//关闭文件
    return 1;//返回1表示删除成功
}

/*构造用户*/
Student* creatStudent(string name, string stu_id, string code, string major) {
    Student* stu = new Student();
    memset(stu, 0, sizeof (Student));//先为所有信息赋值为0
    stu->ID = -1;           //编号
    stu->canBorrow = 0;   //逾期未还的书的总数量（超过三次无法借书）
    strcpy(stu->name, &name[0]);
    strcpy(stu->code, &code[0]);
    strcpy(stu->major, &major[0]);
    strcpy(stu->stu_id, &stu_id[0]);
    stu->exist = 1;        //学生存在了
    stu->type = 1;      //用户类型
    return stu;
}

Student* creatStudent() {
    Student* stu = new Student;
    memset(stu, 0, sizeof (Student));//所有信息先赋值为0
    stu->ID = -1;          //编号
    stu->exist = 1;        //学生存在了
    stu->canBorrow = 0;
    stu->type = 1;      //用户类型
    return stu;
}

}
