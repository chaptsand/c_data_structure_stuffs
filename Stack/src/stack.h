#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define InitSize 10

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
void StackPop(ST* ps);
void StackPrint(ST* ps);
ElemType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);