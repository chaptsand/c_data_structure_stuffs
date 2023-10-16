#include "List.h"

LNode* BuyListNode(ElemType x)
{
    LNode* newnode = (LNode*)malloc(sizeof(LNode));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;

}

LNode* ListInit()
{
    LNode* phead = BuyListNode(0);
    phead->prev = phead;
    phead->next = phead;
    return phead;
}

void ListPushBack(LNode* phead, ElemType x)
{
    assert(phead);
    LNode* tail = phead->prev;
    LNode* newnode = BuyListNode(x);

    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
}

void ListPrint(LNode* phead)
{
    LNode* cur = phead->next;
    while (cur != phead)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// void ListPushFront(LNode* phead, ElemType x)
// {
//     assert(phead);
//     LNode* first = phead->next;
//     LNode* newnode = BuyListNode(x);

//     //phead newnode first
//     phead->next = newnode;
//     newnode->prev = phead;
//     newnode->next = first;
//     first->prev = newnode;
// }

void ListPushFront(LNode* phead, ElemType x)
{
    assert(phead);

    LNode* newnode = BuyListNode(x);
    newnode->next = phead->next;
    phead->next->prev = newnode;

    phead->next = newnode;
    newnode->prev = phead;
}

void ListPopFront(LNode* phead)
{
    assert(phead);
    assert(phead->next != phead);

    LNode* first = phead->next;
    LNode* second = first->next;

    phead->next = second;
    second->prev = phead;

    free(first);
    first = NULL;
}

void ListPopBack(LNode* phead)
{
    assert(phead);
    assert(phead->next != phead);

    LNode* tail = phead->prev;
    LNode* prev = tail->prev;

    prev->next = phead;
    phead->prev = prev;

    free(tail);
    tail = NULL;
}

LNode* ListFind(LNode* phead, ElemType x)
{
    LNode* cur = phead->next;
    while (cur != phead)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

void ListInsert(LNode* pos, ElemType x)
{
    assert(pos);

    LNode* prev = pos->prev;
    LNode* newnode = BuyListNode(x);

    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = pos;
    pos->prev = newnode;
}

void ListErase(LNode* pos)
{
    assert(pos);

    LNode* prev = pos->prev;
    LNode* next = pos->next;

    prev->next = next;
    next->prev = prev;

    free(pos);
    pos = NULL;
}

bool ListEmpty(LNode* phead)
{
    if(phead->next == phead)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ListSize(LNode* phead)
{
    assert(phead);
    LNode* cur = phead;
    int count = 0;
    while (cur->next != phead)
    {
        cur = cur->next;
        count++;
    }
    return count;
}