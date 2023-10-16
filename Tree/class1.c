#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    ElemType data;
}BTNode;

void PrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }

    printf("%c ", root->data);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }

    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

void PostOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}

void DestoryTree(BTNode** proot)
{
    if(*proot == NULL)
        return;
    
    DestoryTree(&(*proot)->left);
    DestoryTree(&(*proot)->right);

    free(*proot);
    *proot = NULL;
}

int main()
{
    BTNode* A = (BTNode*)malloc(sizeof(BTNode));
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;

    BTNode* B = (BTNode*)malloc(sizeof(BTNode));
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;

    BTNode* C = (BTNode*)malloc(sizeof(BTNode));
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;

    BTNode* D = (BTNode*)malloc(sizeof(BTNode));
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;

    BTNode* E = (BTNode*)malloc(sizeof(BTNode));
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    // PrevOrder(A);
    // InOrder(A);
    PostOrder(A);
    printf("\n");
    DestoryTree(&A);
    PostOrder(A);
    printf("\n");
    return 0;
}