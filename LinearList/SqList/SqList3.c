#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define InitSize 10

//顺序表的动态分配
typedef struct
{
    int* data;
    int MaxSize;
    int length;
}Sqlist;

void InitList(Sqlist* L)
{
    L->data = (int*)malloc(sizeof(int) * InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
    int i = 0;
    for(i = 0; i < L->MaxSize; i++)
    {
        L->data[i] = 0;
    }
}

void PrintList(Sqlist L)
{
    int i = 0;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

void ListAdd(Sqlist* L, int i, int e)
{
    L->data[i - 1] = e;
    L->length++;
}

bool ListInsert(Sqlist* L, int i, int e)
{
    if(i < 1 || i > L->length + 1)
    {
        return false;
    }
    if(L->length >= L->MaxSize)
    {
        return false;
    }
    int j = L->length;
    for (j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j -1];
    }
    
    L->data[i - 1] = e;
    L->length++;
    return true;
}

void PrintWList(Sqlist L)
{
    int i = 0;
    for (i = 0; i < L.MaxSize; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

void IncreaseSize(Sqlist* L, int len)
{
    int* p = L->data;
    L->data = (int*)malloc(sizeof(int) * (L->MaxSize+ len));
    int i = 0;
    for(i = 0; i <L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize += len;
    free(p);
}

int main()
{
    Sqlist L;
    InitList(&L);
    PrintList(L);
    ListAdd(&L, 1, 1);
    ListAdd(&L, 2, 2);
    ListAdd(&L, 3, 3);
    ListAdd(&L, 4, 4);
    ListAdd(&L, 5, 5);
    ListAdd(&L, 6, 6);
    PrintList(L);
    printf("%d\n", L.length);
    printf("%d\n", L.MaxSize);
    // IncreaseSize(&L, 5);
    int ret = ListInsert(&L, 9, 9);
    if(ret == 0)
    {
        printf("插入失败\n");
    }
    PrintWList(L);
    printf("%d\n", L.length);
    printf("%d\n", L.MaxSize);
    return 0;
}