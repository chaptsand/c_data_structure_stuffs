#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct SListNode
{
    ElemType data;
    struct SListNode* next;
}SLTNode;

bool InitList(SLTNode** phead)
{
    *phead = (SLTNode*)malloc(sizeof(SLTNode));
    if(*phead == NULL)
        return false;
    (*phead)->next = NULL;
    return true;
}

SLTNode* BuySListNode(ElemType x)
{
    SLTNode* s = (SLTNode*)malloc(sizeof(SLTNode));
    s->data = x;
    s->next = NULL;
    return s;
}

bool SListPushBack(SLTNode** phead, ElemType x)
{
    SLTNode* s = BuySListNode(x);

    if(*phead == NULL)
    {
        *phead = s;
    }
    else
    {
        SLTNode* t = *phead;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = s;
    }

    return true;
}

bool SListPushFront(SLTNode** phead, ElemType x)
{
    SLTNode* newnode = BuySListNode(x);
    newnode->next = (*phead)->next;
    (*phead)->next = newnode;
    return true;
}

bool SListPopFront(SLTNode** phead)
{
    (*phead)->next = ((*phead)->next)->next;
    return true;
}

bool SListPopBack(SLTNode** phead)
{
    // if((*phead)->next = NULL)
    // {
    //     return false;
    // }
    SLTNode* prev = NULL;
    SLTNode* tail = *phead;
    while (tail->next != NULL)
    {
        prev = tail;
        tail = tail->next;
    }
    free(tail);
    prev->next=NULL;
    return true;
}

void SListPrint(SLTNode* phead)
{
    SLTNode* cur = phead->next;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    SLTNode* plist = NULL;
    if(InitList(&plist))
        printf("初始化成功\n");
    if(SListPushBack(&plist, 1))
        printf("尾插1成功\n");
    if(SListPushBack(&plist, 2))
        printf("尾插入2成功\n");
    if(SListPushBack(&plist, 3))
        printf("尾插入3成功\n");
    if(SListPushBack(&plist, 4))
        printf("尾插入4成功\n");
    if(SListPushFront(&plist, 0))
        printf("头插入0成功\n");
    if(SListPopFront(&plist))
        printf("头删成功\n");
    if(SListPopBack(&plist))
        printf("尾删成功\n");
    SListPrint(plist);
    return 0;
}