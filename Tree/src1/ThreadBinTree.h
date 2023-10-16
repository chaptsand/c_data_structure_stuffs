#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char ElemType;

typedef struct BinTreeNode
{
    ElemType data;
    struct BinTreeNode* leftChild;
    struct BinTreeNode* rightChild;
    int ltag, rtag;
}BTNode;

BTNode* BuyTreeNode(ElemType x);
void CreatBinTree(BTNode** root, char* str, int* i);
void PrevOrder(BTNode* root);
void CreatInThread(BTNode* root, BTNode* pre);