#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef char ElemType;
typedef struct BinaryTreeNode
{
    ElemType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;


void PrevOrder(BTNode* root)
{
    if(root == NULL)
    {
        // printf("NULL ");
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
        // printf("NULL ");
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
        // printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);
}

// void TreeSize(BTNode* root, int* psize)
// {
//     if(root == NULL)    
//     {
//         return;
//     }
//     else
//     {
//         ++(*psize);
//     }

//     TreeSize(root->left, psize);
//     TreeSize(root->right, psize);
// }

int TreeSize(BTNode* root)
{
    return (root == NULL) ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

// void TreeLeafSize(BTNode* root, int* psize)
// {
//     if(root == NULL)    
//     {
//         return;
//     }
    
//     if(root->left == NULL && root->right == NULL)
//     {
//         ++(*psize);
//     }

//     TreeLeafSize(root->left, psize);
//     TreeLeafSize(root->right, psize);
// }

int TreeLeafSize(BTNode* root)
{
    if(root == 0)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

void LevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    if(root != NULL)
    {
        QueuePush(&q, root);
    }

    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        printf("%c ", front->data);

        if(front->left)
        {
        QueuePush(&q, front->left);
        }
        if(front->right)
        {
        QueuePush(&q, front->right);
        }
    }

    printf("\n");
    QueueDestory(&q);

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

    PrevOrder(A);
    printf("\n");
    // InOrder(A);
    // printf("\n");
    // PostOrder(A);
    // printf("\n");

    // int Asize = 0;
    // TreeSize(A, &Asize);
    // printf("%d\n", Asize);

    // int Lsize = 0;
    
    printf("%d\n", TreeLeafSize(A));

    printf("%d\n", TreeSize(A));
    printf("%d\n", TreeSize(B));

    LevelOrder(A);
    return 0;
}