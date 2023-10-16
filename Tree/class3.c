#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
}TNode;

TNode* CreatTree(char* a, int* pi)
{
    if(a[*pi] == '#')
    {
        ++(*pi);
        return NULL;
    }

    TNode* root = (TNode*)malloc(sizeof(TNode));
    if(root == NULL)
    {
        printf("malloc failed\n");
        exit(-1);
    }

    root->val = a[(*pi)++];
    root->left = CreatTree(a, pi);
    root->right = CreatTree(a, pi);

    return root;
}

void PrevOrder(TNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    printf("%c ", root->val);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

void InOrder(TNode* root)
{
    if(root == NULL)
    {
        // printf("NULL ");
        return;
    }

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    char str[100] = "abc##de#g##f###";

    int i = 0;
    TNode* root = CreatTree(str, &i);

    InOrder(root);
    printf("\n");
    return 0;
}