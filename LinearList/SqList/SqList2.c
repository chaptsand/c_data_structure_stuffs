#include <stdio.h>
#include <stdlib.h>

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

void ListInsert(Sqlist* L, int i, int e)
{
    int count = 1;
    *(L->data + i - 1) = e;
    L->length += count;
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
    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    PrintList(L);
    printf("%d\n", L.MaxSize);
    IncreaseSize(&L, 5);
    printf("%d\n", L.MaxSize);
    PrintList(L);
    return 0;
}