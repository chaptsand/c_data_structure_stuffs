#include "string.h"

void initString(String* pstr)
{
    int i = 0;
    for(i = 0; i < MAXSIZE; i++)
    {
        (*pstr).ch[i] = '\0';
    }
    (*pstr).length = 0;
}

void _initString(String* pstr)
{
    char tmp[5] = "abcde";
    int i = 0;
    int j = 0;
    for(i = 0; i < 5; i++)
    {
        (*pstr).ch[i] = tmp[j];
        j++;
    }
    (*pstr).length = 5;
}

int strLength(String str)
{
    return str.length;
}

void strCopy(String* pstr, String string)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < strLength(string); i++)
    {
        (*pstr).ch[i] = string.ch[i];
        (*pstr).length++;
    }
    // for(j = i; i < strLength((*pstr).length); j++)
    // {
    //     (*pstr).ch[j] = '\0';
    // }
}

void strPrint(String str)
{
    int i = 0;
    for(i = 0; i < str.length; i++)
    {
        printf("%c", str.ch[i]);
    }
    printf("\n");
}