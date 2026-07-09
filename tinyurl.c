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
    char shortUrl[SHORT_URL_LEN];
    int i;

    // 判断数据库是否为空
    if (databaseSize == 0)
    {
        printf("当前没有任何短地址记录！\n");
        return;
    }

    printf("请输入短地址：");
    scanf("%5s", shortUrl);

    // 遍历数据库查找
    for (i = 0; i < databaseSize; i++)
    {
        // 找到对应短地址
        if (strcmp(shortUrl, database[i].shortUrl) == 0)
        {
            // 判断是否有效
            if (database[i].valid == 0)
            {
                printf("该短地址已失效！\n");
                return;
            }

            // 判断是否达到最大访问次数
            if (database[i].visitCount >= database[i].maxVisit)
            {
                printf("该短地址访问次数已达到上限，已失效！\n");
                database[i].valid = 0;
                return;
            }

            // 更新访问次数
            database[i].visitCount++;

            printf("\n解析成功！\n");
            printf("-----------------------------\n");
            printf("短地址：%s\n", database[i].shortUrl);
            printf("原始URL：%s\n", database[i].url);
            printf("访问次数：%d\n", database[i].visitCount);
            printf("剩余次数：%d\n",
                   database[i].maxVisit - database[i].visitCount);
            printf("-----------------------------\n");

            return;
        }
    }

    // 没找到
    printf("未找到该短地址！\n");
}
// 查看所有
void showAll()
{
    int i;

    // 判断是否有数据
    if (databaseSize == 0)
    {
        printf("当前没有任何短地址记录！\n");
        return;
    }

    printf("\n");
    printf("============================================================================================\n");
    printf("%-5s %-8s %-8s %-10s %-8s %s\n",
           "ID",
           "Short",
           "Visit",
           "MaxVisit",
           "Valid",
           "URL");
    printf("============================================================================================\n");

    for (i = 0; i < databaseSize; i++)
    {
        printf("%-5d %-8s %-8d %-10d %-8s %s\n",
               database[i].id,
               database[i].shortUrl,
               database[i].visitCount,
               database[i].maxVisit,
               database[i].valid ? "Yes" : "No",
               database[i].url);
    }

    printf("============================================================================================\n");
}

// 查看统计
void showStatistics()
{

}

// 设置访问次数
void setMaxVisit()
{

}