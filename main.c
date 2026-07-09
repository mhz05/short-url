#include <stdio.h>

#include "menu.h"
#include "tinyurl.h"

int main(void)
{
    int choice;

    // 初始化数据库
    initDatabase();

    while (1)
    {
        menu();

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createShortURL();
                break;

            case 2:
                parseShortURL();
                break;

            case 3:
                showAll();
                break;

            case 4:
                showStatistics();
                break;

            case 5:
                setMaxVisit();
                break;

            case 6:
                printf("\n感谢使用 Tiny URL 短地址服务！\n");
                return 0;

            default:
                printf("输入错误，请重新输入！\n");
        }
    }

    return 0;
}