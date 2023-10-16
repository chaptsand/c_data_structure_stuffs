#pragma once

#include <stdio.h>
#include <string.h>

#define MAXSIZE 255

typedef struct String
{
    char ch[MAXSIZE];
    int length;
}String;

void initString(String* pstr);
void _initString(String* pstr);
int strLength(String str);
void strPrint(String str);
void strCopy(String* pstr, String string);