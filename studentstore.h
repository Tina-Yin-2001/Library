#ifndef STUDENTSTORE_H
#define STUDENTSTORE_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "student.h"
using namespace std;
using namespace student;
namespace studentstore {

//构造用户
Student* creatStudent();
Student* creatStudent(string name, string stu_id, string code, string major);
//添加删除（根据主键）用户
bool addStudent(Student* stu);
bool deleteStudent(int ID);
/*查询
因为学生只有一个，所以只能查出一条*/
Student * search(int ID);    //根据ID查询学生信息
Student * search_stuid(string stu_id);//根据学号查找学生信息
vector<Student*> search_multipleReturn(string name);
}
#endif // STUDENTSTORE_H
