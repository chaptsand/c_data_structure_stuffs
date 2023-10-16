#include <stdio.h>
#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
}Sqlist;

void InitList(Sqlist* L)
{
    int i = 0;
    for(i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

void PrintList(Sqlist L)
{
    int i = 0;
    for (i = 0; i < MaxSize; i++)
    {
        printf("%d ", L.data[i]);
    }
    
}

int main()
{
    Sqlist L;
    InitList(&L);
    PrintList(L);
    return 0;
}