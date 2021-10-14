#ifndef INIT_H
#define INIT_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <string.h>
extern int MaxBuffer;

const int MAX_NAME = 40;       //姓名长度
const int  MAX_ID = 20;        //学号长度
const int  MAX_CODE = 20;     //密码长度(规定下)
const int MAX_MAJOR = 40;     //专业长度

const int MAX_BOOK_NAME = 100;   //书名长度
const int MAX_WEITER = 100;    //作者名字长度
const int MAX_ISBN = 20;         //出版号（区分是否是一种书）长度
const int MAX_PUBLISH = 50;    //出版社长度
const int MAX_TAG=6;
const char studentDatPath[] = "..\\Library\\student.dat";   //定义student.dat路径
const char bookDatPath[] = "..\\Library\\book.dat";   //定义book.dat路径
const char menuDatPath[] = "..\\Library\\menu.dat";   //定义menu.dat路径
const char recordDatPath[] = "..\\Library\\record.dat";   //定义record.dat路径
const char defaultUserDataCsvPath[] = "..\\Library\\user_data.csv";   //定义默认user_data.csv路径

extern std::string admin_id;
extern std::string admin_password;

#endif // INIT_H
