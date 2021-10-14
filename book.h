#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "init.h"
using namespace std;

namespace bookandrecord {
/*书籍目录类 按照isbn作为主键，区分每一类书，并且包含总书的数量*/
struct Menu{

    char name[MAX_BOOK_NAME];        //书名
    char writer[MAX_WEITER];      //作者
    char ISBN[MAX_ISBN];        //主键 出版号（区分是否是一种书）
    char publish[MAX_PUBLISH];      //出版社
    int tag[MAX_TAG];           //分类
    int count;             //本类书被借阅次数
    int remain;             //当前可借的本书个数
};
/*记录每一本的信息，信息都是独立的*/
struct Book{
    int ID;         //主键
    char ISBN[MAX_ISBN];        //出版号（区分是否是一种书）
    int exist;          //1代表存在 0代表已删除
    int condition;     //借阅状态：已借出0，未借出1，已预约2
    int book_cond;      //本书状态：正常0， 破旧1，破损（需更换）2
    int borrow_num;        //被借阅次数
};

struct Record{
    int ID;                 //借阅记录编号 主键
    int userId;             //用户id
    int bookId;             //书id
    time_t borrowTime;      //借阅时间
    time_t returnTime;      //返还时间
    int isBorrowed;         //书是否归还 0已经归还 1正在借阅 -1超时未归还
    bool isReborrwed;       //是否续借   0正常归还 1续借
};
}
#endif // BOOK_H
