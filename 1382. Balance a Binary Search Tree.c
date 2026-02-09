#include <stdio.h>
#include <stdlib.h>

/* ===== Tree Definition ===== */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* ===== Functions from solution ===== */

void inorderStore(struct TreeNode *root, int *arr, int *index)
{
    if (!root)
        return;
    inorderStore(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorderStore(root->right, arr, index);
}

struct TreeNode *buildBalanced(int *arr, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = arr[mid];
    node->left = buildBalanced(arr, left, mid - 1);
    node->right = buildBalanced(arr, mid + 1, right);

    return node;
}

int countNodes(struct TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

struct TreeNode *balanceBST(struct TreeNode *root)
{
    int n = countNodes(root);

    int *arr = malloc(sizeof(int) * n);
    int index = 0;

    inorderStore(root, arr, &index);

    struct TreeNode *balanced = buildBalanced(arr, 0, n - 1);
    free(arr);

    return balanced;
}

/* ===== Utility functions ===== */

struct TreeNode *newNode(int val)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderPrint(struct TreeNode *root)
{
    if (!root)
        return;
    inorderPrint(root->left);
    printf("%d ", root->val);
    inorderPrint(root->right);
}

/* ===== MAIN ===== */

int main()
{
    /* Create skewed BST: 1 -> 2 -> 3 -> 4 */
    struct TreeNode *root = newNode(1);
    root->right = newNode(2);
    root->right->right = newNode(3);
    root->right->right->right = newNode(4);

    printf("Original BST (Inorder): ");
    inorderPrint(root);
    printf("\n");

    struct TreeNode *balanced = balanceBST(root);

    printf("Balanced BST (Inorder): ");
    inorderPrint(balanced);
    printf("\n");

    return 0;
}
