#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct SListNode
{
    ElemType data;
    struct SListNode* next;
}SLTNode;

bool InitList(SLTNode** phead);
void SListPrint(SLTNode* phead);
bool SListPushBack(SLTNode** phead, ElemType x);
bool SListPushFront(SLTNode** phead, ElemType x);
bool SListPopBack(SLTNode** phead);
bool SListPopFront(SLTNode** phead);