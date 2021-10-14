#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "book.h"
using namespace std;
using namespace bookandrecord;
namespace bookstore {

//相当于构造函数
Menu* createMenu();
//count表示书的多少
Menu* createMenu(string name, string writer, string ISBN, string publish, int count);
Book* createBook(string ISBN,int count);
//添加书籍,为了做成多册入库
bool addBook(Book* book,int count);
//删除书籍（需要修改）
bool deleteBook(int ID);
//借书, 1成功借阅， 2 无此用户 , 3 无此书籍, 4 书籍以被借出或者预约
//给出提示
int  borrow(string stu_id, int bookID);
//续借书籍（在原来的基础上，所以已知了ID）
void reborrow(int userID, int bookID);
//归还图书,1正常还书,0逾期还书,-1还书失败
int returnbook(string stu_id, int ID);

/*
 * 按照不同的要求搜索
 *因为搜索条件不同可能会产生多个记录，所以可能返回多个记录
 */
//根据主键查询书籍信息（返回唯一）
Book* searchbook_id(int ID);
//根据isbn查找书籍,可能有好几本
Menu* searchbook_isbn(string isbn);
//判断是否为一本书
//根据其他的信息判断（先调用searchbook_isbn，判断是不是同本书
bool is_same(string name, string writer, string ISBN, string publish);
//根据书名查找书籍,可能有好几本
Menu** searchbook_name(string Name);
//书名的模糊查询
//Menu** searchbook_partname(string name);
//根据用户ID查询他的借书记录,可能多条
Record** searchrecord_userID(int userID);
//根据书籍ID查询书籍的被借记录，可能多条
//书籍损坏追溯
Record** searchrecord_bookID(int bookID);
}

#endif // BOOKSTORE_H
