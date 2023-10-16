#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// #define MaxSize 10

typedef int ElemType;

typedef struct Stack
{
    ElemType* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);

void StackPush(ST* ps, ElemType x);
void StackPop(ST* ps, ElemType x);

ElemType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);