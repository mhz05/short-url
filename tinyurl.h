#ifndef __TINYURL_H__
#define __TINYURL_H__

#define MAX_URL_LEN 2048      // URL最大长度
#define SHORT_URL_LEN 6       // 5位短地址 + '\0'
#define MAX_RECORD 100        // 最大保存记录数

// 短地址记录
typedef struct
{
    int id;                             // 自增ID
    char url[MAX_URL_LEN];              // 原始URL
    char shortUrl[SHORT_URL_LEN];       // 短地址
    int visitCount;                     // 已访问次数
    int maxVisit;                       // 最大允许访问次数
    int valid;                          // 是否有效(1有效 0失效)

} TinyURL;


//=======================
// 全局数据库
//=======================

extern TinyURL database[MAX_RECORD];

extern int databaseSize;

extern int nextID;


//=======================
// 初始化
//=======================

void initDatabase();


//=======================
// 功能函数
//=======================

// 创建短地址
void createShortURL();

// 解析短地址
void parseShortURL();

// 查看全部
void showAll();

// 查看统计
void showStatistics();

// 设置最大访问次数
void setMaxVisit();

#endif