#include "ThreadBinTree.h"

BTNode* BuyTreeNode(ElemType x)
{
    BTNode* s = (BTNode*)malloc(sizeof(BTNode));
    assert(s);
    s->data = x;
    s->leftChild = s->rightChild = NULL;
    s->ltag = s->rtag = 0;
    return s;
}

void CreatBinTree(BTNode** root, char* str, int* i)
{
    if(str[*i] == '#')
    {
        *root = NULL;
        ++(*i);
        return;
    }
    else
    {
        *root = BuyTreeNode(str[(*i)++]);
        CreatBinTree(&(*root)->leftChild, str, i);
        CreatBinTree(&(*root)->rightChild, str, i);
    }
}

void PrevOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%c ", root->data);
    PrevOrder(root->leftChild);
    PrevOrder(root->rightChild);
}

void CreatInThread(BTNode* root, BTNode* pre)
{
    if(root == NULL)
    {
        return;
    }
    CreatInThread(root->leftChild, pre);
    if(root->leftChild == NULL)
    {
        root->ltag = 1;
        root->leftChild = pre;
    }
    if(pre != NULL && pre->rightChild == NULL)
    {
        pre->rtag = 1;
        pre->rightChild = root;
    }
    pre = root;

    CreatInThread(root->rightChild, pre);
    
}