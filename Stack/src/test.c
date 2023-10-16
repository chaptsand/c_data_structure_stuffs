#include "stack.h"

void Test1()
{
    ST st;
    StackInit(&st);
    StackPrint(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    StackPrint(&st);
    StackDestory(&st);
}

void Test2()
{
    ST st;
    StackInit(&st);
    StackPrint(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    StackPrint(&st);
    StackPop(&st);
    StackPrint(&st);
    StackPop(&st);
    StackPrint(&st);
    StackPop(&st);
    StackPrint(&st);
    StackPop(&st);
    StackPrint(&st);
    StackDestory(&st);
}

void Test3()
{
    ST st;
    StackInit(&st);
    StackPrint(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);

    printf("%d ", StackTop(&st));
    StackPop(&st);
    
    printf("%d ", StackTop(&st));
    StackPop(&st);
    
    StackPush(&st, 4);
    StackPush(&st, 5);
    // StackPrint(&st);
    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }

    StackDestory(&st);
}

int main()
{
    Test3();
    return 0;
}