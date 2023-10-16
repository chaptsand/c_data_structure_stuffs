#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;
typedef struct QueueNode
{
    ElemType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
}Queue;

//初始化一个带头结点的队列
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = (QNode*)malloc(sizeof(QNode));
    if(pq->tail == NULL)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    pq->head->next = NULL;
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

    pq->tail->next = newnode;
    pq->tail = newnode;
}

bool QueueEmpty(Queue* pq)
{
    if(pq->head == pq->tail)
    {
        printf("Queue is empty\n");
        return true;
    }
    else
    {
        printf("Queue isn't empty\n");
        return false;
    }
}

ElemType QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head->next);

    QNode* tmp = pq->head->next;
    ElemType x = tmp->data;
    pq->head->next = tmp->next;

    if(pq->tail == tmp)
    {
        pq->tail = pq->head;
    }

    free(tmp);
    return x;
}

void TestQueue()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    QueueEmpty(&q);
    printf("%d\n", QueuePop(&q));
    printf("%d\n", QueuePop(&q));
    // printf("%d\n", QueuePop(&q));
    QueueEmpty(&q);
}

void TestQueue1()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    QueueEmpty(&q);
    printf("%d\n", QueuePop(&q));
    printf("%d\n", QueuePop(&q));
    printf("%d\n", QueuePop(&q));
    printf("%d\n", QueuePop(&q));
    QueueEmpty(&q);
}

int main()
{
    TestQueue1();
    return 0;
}