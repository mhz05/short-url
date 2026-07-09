#include <stdio.h>
#include <string.h>

#include "base62.h"

// Base62字符表
static const char table[] =
"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

/*
    十进制 -> Base62

    num : 十进制ID
    str : 输出字符串(长度至少6)
*/
void decimalToBase62(int num, char *str)
{
    int i;

    // 默认填充5个'0'
    for(i = 0; i < 5; i++)
    {
        str[i] = '0';
    }

    str[5] = '\0';

    // 从后往前转换
    i = 4;

    while(num > 0 && i >= 0)
    {
        str[i] = table[num % 62];
        num /= 62;
        i--;
    }
}