#include "string.h"

void StringTest()
{
    String str;
    initString(&str);
    String string;
    _initString(&string);
    strPrint(string);
    strCopy(&str, string);
    strPrint(str);
    printf("%d\n", str.length);
}

int main()
{
    StringTest();
    return 0;
}