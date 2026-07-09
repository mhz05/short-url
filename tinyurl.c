#include <stdio.h>
#include <string.h>

#include "tinyurl.h"
#include "base62.h"

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
    // 判断数据库是否已满
    if (databaseSize >= MAX_RECORD)
    {
        printf("数据库已满，无法继续创建！\n");
        return;
    }

    TinyURL *record = &database[databaseSize];

    printf("请输入原始URL：\n");

    // 清除输入缓冲区残留的换行
    getchar();

    fgets(record->url, MAX_URL_LEN, stdin);

    // 去掉fgets读入的换行符
    record->url[strcspn(record->url, "\n")] = '\0';

    // 分配ID
    record->id = nextID++;

    // 生成短地址
    decimalToBase62(record->id, record->shortUrl);

    // 初始化统计信息
    record->visitCount = 0;
    record->maxVisit = 100;      // 默认最多访问100次
    record->valid = 1;

    // 数据库记录数+1
    databaseSize++;

    printf("\n");
    printf("生成成功！\n");
    printf("------------------------------\n");
    printf("ID        : %d\n", record->id);
    printf("Short URL : %s\n", record->shortUrl);
    printf("URL       : %s\n", record->url);
    printf("------------------------------\n");
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