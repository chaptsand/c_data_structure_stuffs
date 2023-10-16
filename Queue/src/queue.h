#pragma once

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

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, ElemType x);
void QueuePop(Queue* pq);

ElemType QueueFront(Queue* pq);
ElemType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
