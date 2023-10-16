#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct ListNode{
    ElemType data;
    struct ListNode* prev;
    struct ListNode* next;
}LNode;

LNode* ListInit();
void ListDestory(LNode* phead);
void ListPrint(LNode* phead);
void ListPushBack(LNode* phead, ElemType x);
void ListPushFront(LNode* phead, ElemType x);
void ListPopFront(LNode* phead);
void ListPopBack(LNode* phead);

LNode* ListFind(LNode* phead, ElemType x);

//在pos位置之前插入x
void ListInsert(LNode* pos, ElemType x);

//删除pos位置的值
void ListErase(LNode* pos);

bool ListEmpty(LNode* phead);
int ListSize(LNode* phead);