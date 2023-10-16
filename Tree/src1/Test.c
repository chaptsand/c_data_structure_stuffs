#include "ThreadBinTree.h"

int main()
{
    char str[]= "ABC##DE##F##G#H##";
    BTNode* root;
    int i = 0;
    CreatBinTree(&root, str, &i);
    // PrevOrder(root);
    BTNode* pre = NULL;
    CreatInThread(root, pre);
    return 0;
}