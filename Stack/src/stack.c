#include "stack.h"

void StackInit(ST* ps)
{
    assert(ps);
    ps->a = (ElemType*)malloc(sizeof(ElemType) * InitSize);
    if(ps->a == NULL)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    ps->capacity = InitSize;
    ps->top = 0;
}

void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void StackPush(ST* ps, ElemType x)
{
    assert(ps);

    if(ps->top == ps->capacity)
    {
        ElemType* tmp = (ElemType*)realloc(ps->a, ps->capacity * 2 * sizeof(ElemType));
        if(tmp == NULL)
        {
            printf("realloc failed\n");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity *= 2;
        }
    }
    ps->a[ps->top] = x;
    ps->top++;
}

void StackPop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

ElemType StackTop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ElemType top = ps->a[ps->top - 1];
    return top;
}

int StackSize(ST* ps)
{
    assert(ps);
    int sz = ps->top;
    return sz;
}

bool StackEmpty(ST *ps)
{
    assert(ps);

    return ps->top == 0;
}

void StackPrint(ST* ps)
{
    assert(ps);
    if (StackEmpty(ps))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int i = 0;
        for (i = 0; i <= ps->top -1; i++)
        {
            printf("%d ", ps->a[i]);
        }
        printf("\n");
    }
}