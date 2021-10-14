#include "bookstore.h"
#include "init.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "book.h"

using namespace bookandrecord;
using namespace utils;

namespace bookstore {
//相当于构造函数（调用创造book）
Menu* createMenu() {
    Menu* menu = new Menu();
    memset(menu, 0, sizeof (Menu));//所有信息先赋值为0
    menu->count = 1;
    menu->remain = menu->count;
    return menu;
}
//count表示书的多少
Menu* createMenu(string name, string writer, string ISBN, string publish, int count = 1) {
    Menu* menu = new Menu();
    memset(menu, 0, sizeof (Menu));//所有信息先赋值为0
    menu->count = 1;
    menu->remain = menu->count;
    strcpy(menu->name, &name[0]);
    strcpy(menu->writer, &writer[0]);
    strcpy(menu->ISBN, &ISBN[0]);
    strcpy(menu->publish, &publish[0]);
    menu->count = count;
    return menu;
}
Book* createBook(string ISBN) {
    Book* book = new Book();
    memset(book, 0, sizeof (Book));//所有信息先赋值为0
    book->ID = -1;
    strcpy(book->ISBN, &ISBN[0]);       //出版号（区分是否是一种书）
    book->exist = 1;        //1代表存在
    book->condition = 1;   //借阅状态：未借出1
    book->book_cond = 0;    //本书状态：正常0
    book->borrow_num = 0;      //被借阅次数
    return book;
}

Book* creatBook() {
    Book* book = new Book();
    memset(book, 0, sizeof (Book));//所有信息先赋值为0
    return book;
}


//添加书籍,为了做成多册入库
bool addBook(Book* book, int count = 1) {
    auto size = sizeof (Book);//学生类的大小
    FILE *file = openfile(bookDatPath, size); //打开文件
    for(int i = 0; i < count; i++) {
        if (book->ID == -1) { //初始化ID为-1，若ID为-1则表示该学生是新用户
            fseek(file, 0, SEEK_END);//fseek将文件指针指到文件末尾
            auto offset = ftell(file);//ftell得到文件从指针到文件头的大小（offset是文件总大小）
            book->ID = offset / size; //确定ID大小
            fwrite(book, size, 1, file);//将book内容写入文件
        } else {
            //已存在ID，表示不是新用户可以进行文件修改
            fseek(file, size * book->ID, SEEK_SET);//将文件指针移到文件第ID个学生后
            fwrite(book, size, 1, file);//将student内容写入文件
        }
    }
    string isbn;

    fclose(file);//关闭文件
    return 1;//返回1表示添加成功
}
//删除书籍（需要修改）
bool deleteBook(int ID) {
    auto size = sizeof (Book);//书籍类的大小
    FILE *file = openfile(bookDatPath, size); //打开文件

    if(ID != -1) { //存在该ID的学生
        fseek(file, size * ID, SEEK_SET);//将文件指针移到文件第ID个书籍后
        Book* book = new Book() ;//设置一个中间变量
        fread(book, size, 1, file);//读取要删除的书籍信息
        book->exist = 0; //将此书的标记位设置成0 表示已经被删除
        fseek(file, size * ID, SEEK_SET);//将指针指回
        fwrite(book, size, 1, file);//将已经修改的内容写回文件
        delete book;//释放中间变量
    } else return 0; //若该书籍编号不存在 则表示删除失败
    fclose(file);//关闭文件
    return 1;//返回1表示删除成功

}

//借书, 1成功借阅， 2 无此用户 , 3 无此书籍, 4 书籍以被借出或者预约
//给出提示
int  borrow(string stu_id, int bookID) {
    auto size = sizeof (Record);//记录类的大小
    FILE *file = openfile(recordDatPath, size); //打开文件

}

//续借书籍（在原来的基础上，所以已知了ID）
void reborrow(int userID, int bookID);
//归还图书,1正常还书,0逾期还书,-1还书失败
int returnbook(string stu_id, int ID);

//通过ID查找书籍信息
//Book * search(int ID) {
//    auto size = sizeof (Book);//书籍的大小
//    FILE *file = openfile(bookDatPath, size); //打开文件
//    Book * book = creatBook();
//    if(ID != -1) {
//        fseek(file, size * ID, SEEK_SET);   //将指针移到该放的地方
//        fread(book, size, 1, file);          //读出需要查询的同学数据
//        fclose(file);//关闭文件
//        return book;
//        // memcpy(t, book, size);
//    } else return NULL;
//}

/*通过ISBN在Menu.dat中查找书籍
Menu* search(string ISBN){
auto size = sizeof (Menu);//Menu类的大小
FILE *file = openfile(menuDatPath,size);//打开文件
Menu* menu = createMenu();
if() {
    fseek(file, size * , SEEK_SET);   //将指针移到该放的地方
    fread(menu, size, 1, file);          //读出需要查询的menu数据
    fclose(file);//关闭文件
    return menu;
    // memcpy(t, menu, size);
}
else return NULL;
}

*/

}
