#include "queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
    assert(pq);

    QNode* cur = pq->head;

    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, ElemType x)
{
    assert(pq);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if(newnode == NULL)
    {
        printf("malloc failed\n");
        exit(-1);
    }

    newnode->data = x;
    newnode->next = NULL;

    if(pq->tail == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    if(pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
}

ElemType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->head);
    return pq->head->data;
}

ElemType QueueBack(Queue* pq)
{
    assert(pq);
    assert(pq->head);
    return pq->tail->data;
}

int QueueSize(Queue* pq)
{
    assert(pq);
    int size = 0;
    QNode* cur = pq->head;
    while(cur)
    {
        size++;
        cur = cur->next;
    }

    return size;
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL;
}