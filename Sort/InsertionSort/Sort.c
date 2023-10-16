#include "Sort.h"

void PrintArray(SqList L, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", L[i]);
    }
    printf("\n");
}

// 直接插入排序
void InsertSort(SqList L, int n)
{
    // [0,end] 有序， end+1位置的值插入进去，让[0,end+1]也有序
    for(int i = 0; i < n - 1; i++)
    {
        int end = i;
        int tmp = L[end + 1];
        while (end >= 0)
        {
            if(L[end] > tmp)
            {
                L[end + 1] = L[end];
                --end;
            }
            else
            {
                break;
            }
        }
        L[end + 1] = tmp;
    }
}

// 希尔排序 -- 直接插入排序的基础优化
// 1、先进行预排序，让数组接近有序
// 2、预排序完成后进行直接插入排序
// 时间复杂度：O(N*logN) 或者O(N*log3N)
void ShellSort(SqList L, int n)
{
    int gap = n;

    while (gap > 1)
    {
        // gap = gap / 2;   //时间复杂度logN
        gap = gap / 3 + 1;  //时间复杂度log3N
        // gap > 1 时是预排序
        // gap == 1 时就是直接排序

        // gap很大时，下面预排序的时间复杂度O(N)
        // gap很小时，数组接近有序了，这时时间复杂度差不多也是O(N)
        // 把间隔为gap的多组数据同时排序
        for(int i = 0; i < n - gap; i++)
        {
            int end = i;
            int tmp = L[end + gap];
            while (end >= 0)
            {
                if(L[end] > tmp)
                {
                    L[end + gap] = L[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            L[end + gap] = tmp;
        }
    }
}