#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;

typedef struct Stack
{
    ElemType* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps)
{
    assert(ps);
    ps->a = (ElemType*)malloc(sizeof(ElemType) * 4);
    if(ps->a == NULL)
    {
        printf("Stack Init Failed\n");
        exit(-1);
    }
    ps->capacity = 4;
    ps->top = 0;
}

void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = 0;
}

void StackPush(ST* ps, ElemType x)
{
    assert(ps);
    if(ps->top == ps->capacity)
    {
        ElemType* tmp = realloc(ps->a, ps->capacity * 2 * sizeof(ElemType));
        if(tmp == NULL)
        {
            printf("relloc failed\n");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity *= 2;
        }
    }
    ps->a[ps->top] = x;
    ps->capacity++;
}

void StackPop(ST* ps, ElemType x);

ElemType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

int main()
{
    ST* st;
    StackInit(&st);


    StackDestory(&st);
    return 0;
}