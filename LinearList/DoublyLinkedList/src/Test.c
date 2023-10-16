#include "List.h"

void TestList1()
{
    LNode* phead = ListInit();
    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);
    ListPushFront(phead, 0);
    ListPushFront(phead, -1);
    ListPrint(phead);
    ListPopFront(phead);
    ListPrint(phead);
    ListPopBack(phead);
    ListPrint(phead);
    // ListDestory(plist);
}

void TestList2()
{
    LNode* phead = ListInit();
    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);
    ListPrint(phead);
    LNode* pos = ListFind(phead, 3);
    if(pos)
    {
        printf("找到了\n");
    }
    else
    {
        printf("没找到\n");
    }
    ListInsert(pos, 77);
    ListPrint(phead);
    ListErase(pos);
    ListPrint(phead);

}

void TestList3()
{
    LNode* phead = ListInit();
    if(ListEmpty(phead))
        printf("空表\n");
    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);
    ListPushBack(phead, 5);
    ListPushBack(phead, 6);
    if(ListEmpty(phead))
        printf("空表\n");
    ListPrint(phead);
    int ret = ListSize(phead);
    printf("%d\n", ret);
}

int main()
{
    TestList3();
    return 0;
}