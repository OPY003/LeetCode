#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// DFS helper
int dfs(struct TreeNode *root, int current)
{
    if (root == NULL)
        return 0;

    current = (current << 1) | root->val;

    if (root->left == NULL && root->right == NULL)
        return current;

    return dfs(root->left, current) + dfs(root->right, current);
}

// Main function to compute sum
int sumRootToLeaf(struct TreeNode *root)
{
    return dfs(root, 0);
}

int main()
{
    /*
            1
          /   \
         0     1
        / \   / \
       0  1  0  1

    Paths:
    100 = 4
    101 = 5
    110 = 6
    111 = 7
    Sum = 22
    */

    struct TreeNode *root = newNode(1);
    root->left = newNode(0);
    root->right = newNode(1);
    root->left->left = newNode(0);
    root->left->right = newNode(1);
    root->right->left = newNode(0);
    root->right->right = newNode(1);

    int result = sumRootToLeaf(root);
    printf("Sum of Root-to-Leaf Binary Numbers: %d\n", result);

    return 0;
}