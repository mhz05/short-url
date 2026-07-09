#include <stdio.h>
#include <string.h>

#include "tinyurl.h"


//=======================
// 全局变量
//=======================

TinyURL database[MAX_RECORD];

int databaseSize = 0;

int nextID = 1;


//=======================
// 初始化数据库
//=======================

void initDatabase()
{
    databaseSize = 0;
    nextID = 1;

    memset(database, 0, sizeof(database));

    printf("TinyURL Database Init Success!\n");
}


//=======================
// 下面的函数后面逐个实现
//=======================

// 创建短地址
void createShortURL()
{

}

// 解析短地址
void parseShortURL()
{

}

// 查看所有
void showAll()
{

}

// 查看统计
void showStatistics()
{

}

// 设置访问次数
void setMaxVisit()
{

}