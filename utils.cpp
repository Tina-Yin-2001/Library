#include "utils.h"
#include "init.h"
#include "student.h"
#include <string.h>

using namespace std;
using namespace student;

namespace utils {

FILE* openfile(const char* DatPath, int size) { //参数为文件路径、一个结构体大小
    FILE *file = fopen(DatPath, "rb+");//打开文件
    auto i = MaxBuffer;
    if (file == NULL) {//文件打不开
        return NULL;
    } else //允许程序控制缓冲和stream 的缓冲区大小
        setvbuf(file, NULL, _IOFBF, (size * i));
    return file;
}

QString Qstr2str(string str) {
    return QString(QString::fromLocal8Bit(str.c_str()));
}

string Qstr2str(QString str) {
    return string((const char *)str.toLocal8Bit());
}

//判断string是否为num位数字
bool judgenum(string str, int num) {
    int len = str.length();
    if(len == num) {
        int i = 0;
        for(; i < len;) {
            if(isdigit(str[i]))
                i++;
            else break;
        }
        if (i != num)
            return false;
    } else return false;
    return true;
}

}

