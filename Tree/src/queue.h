#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct BinaryTreeNode;

typedef struct BinaryTreeNode* QElemType;

typedef struct QueueNode
{
    QElemType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QElemType x);
void QueuePop(Queue* pq);

QElemType QueueFront(Queue* pq);
QElemType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
