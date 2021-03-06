#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <QString>
#include "student.h"
#include <vector>

using namespace std;


namespace utils {
FILE* openfile(const char* filename, int size);
QString Qstr2str(string str);
string Qstr2str(QString str);
int judge(string str);


//!!!大坑，template模板函数必须写在.h里，写在.cpp里会报错

//ID快速查找法：按照ID搜索参数为（ID，文件路径），使用时需要指定<数据类型>
template<typename T>
T* search(int ID, const char* path) {       //根据ID查询信息
    auto size = sizeof (T);                 //结构体的大小
    FILE *file = openfile(path, size);      //打开文件
    T* temp = new T;                        //新建一个临时储存类型
    memset(temp, 0, sizeof (T));            //所有信息先赋值为0
    fseek(file, size * ID, SEEK_SET);       //将指针移到该放的地方
    fread(temp, size, 1, file);             //读出需要查询的同学数据
    fclose(file);                           //关闭文件
    return temp;
}


//准确搜索(只返回一个值)，遍历查找法：按照某一项遍历查找，参数为（string 表中的要搜索的字段，string 搜索关键词，文件路径），使用时需要指定<数据类型>
template<typename T>
T * search_oneReturn(string field, string searchKey, const char* path) {
    auto size = sizeof (T);                 //结构体大小
    FILE *file = openfile(path, size);      //打开文件
    fseek(file, 0, SEEK_END);               //fseek将文件指针指到文件末尾
    auto offset = ftell(file);              //ftell得到文件从指针到文件头的大小（offset是文件总大小）
    int count = offset / size;              //确定文件总数
    T* temp = new T;                        //新建一个临时储存类型
    memset(temp, 0, sizeof (T));            //所有信息先赋值为0
    fseek(file, 0, SEEK_SET);               //将指针指到文件头

    char* matchField = NULL;                //根据field给出的字段对matchField赋值
    if(field == "stu_id")
        matchField = temp->stu_id;
    if(field == "name")
        matchField = temp->name;

    for(int i = 0; i <= count; i++) {       //遍历数据
        fread(temp, size, 1, file);         //依次读出并对比数据
        if(strcmp(matchField, searchKey.c_str()) == 0) {
            return temp;                    //得到对应的数据返回
        }

    }
    fclose(file);                           //关闭文件
    return NULL;
}


//多返回搜索，可调节是否使用模糊搜索,参数为（string 是否使用模糊搜索，string 表中的要搜索的字段，string 搜索关键词，文件路径）
template<typename T>
vector<T*> search_multipleReturn(string fuzzySearchCondition, string field, string searchKey, const char* path) {
    auto size = sizeof (T);                 //学生类的大小
    FILE *file = openfile(path, size);      //打开文件
    fseek(file, 0, SEEK_END);               //fseek将文件指针指到文件末尾
    auto offset = ftell(file);              //ftell得到文件从指针到文件头的大小（offset是文件总大小）
    int count = offset / size;              //确定文件总学生信息
    T* temp = new T;                        //新建一个临时储存类型
    memset(temp, 0, sizeof (T));            //所有信息先赋值为0
    fseek(file, 0, SEEK_SET);               //将指针指到文件头

    vector<T*> matchList;
    matchList.clear();

    char* matchField = NULL;
    if(field == "stu_id")
        matchField = temp->stu_id;
    if(field == "name")
        matchField = temp->name;

    //不使用模糊搜索
    if(fuzzySearchCondition == "notFuzzySearch") {
        for(int i = 0; i < count; i++) {                             //遍历数据
            fread(temp, size, 1, file);                              //依次读出并对比学号

            if(strcmp(matchField, searchKey.c_str()) == 0) {         //！！！大坑，不能直接存temp，temp是指针位置最后会跳到文件尾
                T* temp2 = new T;                                    //每次新建一个空间储存新找到的数据结构体
                memset(temp2, 0, sizeof (T));                        //新建的结构体所有信息先赋值为0
                memcpy(temp2, temp, sizeof(T));                      //把temp内存整体复制到temp2
                matchList.push_back(temp2);
            }

        }
    }
    //使用模糊搜索
    else if(fuzzySearchCondition == "useFuzzySearch") {
        for(int i = 0; i < count; i++) {                            //遍历数据
            fread(temp, size, 1, file);                             //依次读出并对比学号

            string tempStr = matchField;
            if(tempStr.find(searchKey.c_str()) != tempStr.npos) {   //！！！大坑，不能直接存temp，temp是指针位置最后会跳到文件尾
                T* temp2 = new T;                                   //每次新建一个空间储存新找到的数据结构体
                memset(temp2, 0, sizeof (T));                       //新建的结构体所有信息先赋值为0
                memcpy(temp2, temp, sizeof(T));                     //把temp内存整体复制到temp2
                matchList.push_back(temp2);
            }

        }
    }
    fclose(file);
    return matchList;
}

}
#endif // UTILS_H
