#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int heightOrFail(struct TreeNode *root)
{
    if (!root)
        return 0;

    int lh = heightOrFail(root->left);
    if (lh == -1)
        return -1;

    int rh = heightOrFail(root->right);
    if (rh == -1)
        return -1;

    if (lh - rh > 1 || rh - lh > 1)
        return -1;

    return (lh > rh ? lh : rh) + 1;
}

bool isBalanced(struct TreeNode *root)
{
    return heightOrFail(root) != -1;
}

struct TreeNode *node(int v)
{
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

int main()
{
    struct TreeNode *root = node(3);
    root->left = node(9);
    root->right = node(20);
    root->right->left = node(15);
    root->right->right = node(7);

    if (isBalanced(root))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
