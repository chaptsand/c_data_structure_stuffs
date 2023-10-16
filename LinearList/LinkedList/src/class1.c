#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct SListNode
{
    ElemType data;
    struct SListNode* next;
}SLTNode;

bool InitList(SLTNode** pplist)
{
    *pplist = (SLTNode*)malloc(sizeof(SLTNode));
    if((*pplist) == NULL)
        return false;
    (*pplist)->next = NULL;
    return true;
}

SLTNode* BuySListNode(ElemType e)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    newnode->data = e;
    newnode->next = NULL;
    return newnode;
}

bool SListInsert(SLTNode* plist, ElemType i, ElemType e)
{
    if(i < 1)
        return false;
    SLTNode* prev;
    prev = plist;
    int j = 0;
    while (prev != NULL && j < i - 1)
    {
        prev = prev->next;
        j++;
    }
    if(prev == NULL)
        return false;

    SLTNode* tail = (SLTNode*)malloc(sizeof(SLTNode));
    tail->data = e;
    tail->next = prev->next;
    prev->next = tail;
    return true;
}

bool SListPushFront(SLTNode* plist, ElemType e)
{
    SLTNode* newnode = BuySListNode(e);
    newnode->next = plist->next;
    plist->next = newnode;
    return true;
}

bool SListPushBack(SLTNode* plist, ElemType e)
{
    SLTNode* newnode = BuySListNode(e);
    SLTNode* cur = plist;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newnode;
    return true;
}

SLTNode* SListGetElem(SLTNode* plist, int i)
{
    if(i < 1)
    {
        return NULL;
    }

    int j = 1;
    SLTNode* cur = plist->next;
    while (cur != NULL && j < i)
    {
        cur = cur->next;
        j++;
    }
    return cur;
}

int SlistLocElem(SLTNode* plist, ElemType e)
{
    SLTNode* cur = plist->next;
    int count = 1;
    while (cur != NULL && cur->data != e)
    {
        cur = cur->next;
        count++;
    }
    return count;
}

bool SListDelete(SLTNode** pplist, int i)
{
    if(i < 1)
        return false;
    SLTNode* cur = SListGetElem(*pplist, i-1);
    if(cur == NULL)
        return false;
    SLTNode* qur = cur->next;
    cur->next = qur->next;
    free(qur);
    return true;
}

int SListLength(SLTNode* plist)
{
    int count = 0;
    SLTNode* cur = plist;
    while (cur->next != NULL)
    {
        cur = cur->next;
        count++;
    }
    return count;

}

void SListPrint(SLTNode* plist)
{
    SLTNode* cur = plist->next;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    SLTNode* plist;
    InitList(&plist);
    SListInsert(plist, 1, 1);
    SListInsert(plist, 2, 2);
    SListInsert(plist, 3, 3);
    SListInsert(plist, 4, 4);
    SListInsert(plist, 1, 0);
    SListPushFront(plist, 5);
    SListPushBack(plist, 6);
    SListPrint(plist);
    // SListDelete(&plist, 9);
    // SListPrint(plist);
    // SLTNode* ret = SListGetElem(plist, 5);
    // printf("%d\n", *ret);
    // int bet = SlistLocElem(plist, 4);
    // printf("%d\n", bet);
    // printf("%d\n", SListLength(plist));
    // return 0;
}