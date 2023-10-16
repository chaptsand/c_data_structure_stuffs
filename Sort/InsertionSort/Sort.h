#pragma once

#include <stdio.h>
#include <stdlib.h>

// #define MAXSIZE 20

typedef int ElemType;
typedef ElemType SqList[];

void PrintArray(SqList L, int n);

void InsertSort(SqList L, int n);
void ShellSort(SqList L, int n);

void TestOP();