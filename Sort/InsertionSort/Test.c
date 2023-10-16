#include "Sort.h"

void SortTest1()
{
    SqList L ={49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(L) / sizeof(L[0]);

    PrintArray(L, n);
    InsertSort(L, n);
    PrintArray(L, n);
}

void SortTest2()
{
    SqList L ={49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(L) / sizeof(L[0]);

    PrintArray(L, n);
    ShellSort(L, n);
    PrintArray(L, n);
}

int main()
{

    // SortTest1();
    // SortTest2();

    TestOP();
    
    return 0;
}