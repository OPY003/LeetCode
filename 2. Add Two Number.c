#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode a = {0, NULL};
    struct ListNode *cur = &a;
    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = carry;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = sum % 10;
        cur->next = NULL;
    }

    return a.next;
}

// Helper function to create a new node
struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to create a linked list from an array
struct ListNode *createList(int arr[], int size)
{
    if (size == 0)
        return NULL;

    struct ListNode *head = createNode(arr[0]);
    struct ListNode *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printList(struct ListNode *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d", head->val);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Helper function to free the linked list
void freeList(struct ListNode *head)
{
    struct ListNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    // Test case 1: 342 + 465 = 807
    // Lists store digits in reverse: [2,4,3] + [5,6,4] = [7,0,8]
    printf("Test Case 1:\n");
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    struct ListNode *l1 = createList(arr1, 3);
    struct ListNode *l2 = createList(arr2, 3);

    printf("L1: ");
    printList(l1);
    printf("L2: ");
    printList(l2);

    struct ListNode *result1 = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result1);
    printf("(Represents: 342 + 465 = 807)\n\n");

    freeList(l1);
    freeList(l2);
    freeList(result1);

    // Test case 2: 0 + 0 = 0
    printf("Test Case 2:\n");
    int arr3[] = {0};
    int arr4[] = {0};
    l1 = createList(arr3, 1);
    l2 = createList(arr4, 1);

    printf("L1: ");
    printList(l1);
    printf("L2: ");
    printList(l2);

    struct ListNode *result2 = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result2);
    printf("(Represents: 0 + 0 = 0)\n\n");

    freeList(l1);
    freeList(l2);
    freeList(result2);

    // Test case 3: 9999999 + 9999 = 10009998
    // [9,9,9,9,9,9,9] + [9,9,9,9] = [8,9,9,9,0,0,0,1]
    printf("Test Case 3:\n");
    int arr5[] = {9, 9, 9, 9, 9, 9, 9};
    int arr6[] = {9, 9, 9, 9};
    l1 = createList(arr5, 7);
    l2 = createList(arr6, 4);

    printf("L1: ");
    printList(l1);
    printf("L2: ");
    printList(l2);

    struct ListNode *result3 = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result3);
    printf("(Represents: 9999999 + 9999 = 10009998)\n");

    freeList(l1);
    freeList(l2);
    freeList(result3);

    return 0;
}