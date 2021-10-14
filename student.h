#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "init.h"
using namespace std;
namespace student {
struct Student {
    int ID;             //编号
    int canBorrow;     //逾期未还的书的总数量（超过三次无法借书）
    int all_Borrow;    //借阅过的书的数量（记录条数）
    char name[MAX_NAME];
    char stu_id[MAX_ID];         //学号
    char code[MAX_CODE];       //密码
    char major[MAX_MAJOR];      //专业
    bool exist;     //学生被添加时修改为1表示学生存在，当学生被删除时修改为0，
    //表示学生被删除或不存在
    bool type;      //管理员type为0，用户的type为1
};
}

#endif // STUDENT_H
