#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct ListNode{
    ElemType data;
    struct ListNode* prev;
    struct ListNode* next;
}LNode;

void ListInit(LNode* plist);
void ListDestory(LNode* plist);
void ListPushBack(LNode* plist, ElemType x);