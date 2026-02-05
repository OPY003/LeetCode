#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    long long sum;
    int idx;
} HeapNode;

typedef struct
{
    long long val;
    int prev, next;
    bool alive;
} Node;

bool isBetter(HeapNode a, HeapNode b)
{
    if (a.sum != b.sum)
        return a.sum < b.sum;
    return a.idx < b.idx;
}

static HeapNode heap[400005];
static int heapSize;

void heapPush(long long sum, int idx)
{
    heap[++heapSize] = (HeapNode){sum, idx};
    int i = heapSize;
    while (i > 1 && isBetter(heap[i], heap[i / 2]))
    {
        HeapNode t = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = t;
        i /= 2;
    }
}

HeapNode heapPop()
{
    HeapNode ret = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1)
    {
        int s = i;
        int l = i * 2, r = i * 2 + 1;
        if (l <= heapSize && isBetter(heap[l], heap[s]))
            s = l;
        if (r <= heapSize && isBetter(heap[r], heap[s]))
            s = r;
        if (s == i)
            break;
        HeapNode t = heap[i];
        heap[i] = heap[s];
        heap[s] = t;
        i = s;
    }
    return ret;
}

int minimumPairRemoval(int *nums, int n)
{
    if (n <= 1)
        return 0;

    Node *nodes = (Node *)malloc(n * sizeof(Node));
    heapSize = 0;

    int bad = 0;
    for (int i = 0; i < n; i++)
    {
        nodes[i] = (Node){(long long)nums[i], i - 1, i + 1, true};
        if (i > 0)
        {
            heapPush(nodes[i - 1].val + nodes[i].val, i - 1);
            if (nodes[i - 1].val > nodes[i].val)
                bad++;
        }
    }
    nodes[n - 1].next = -1;

    int ops = 0;
    while (bad > 0 && heapSize > 0)
    {
        HeapNode h = heapPop();
        int i = h.idx;

        if (!nodes[i].alive)
            continue;
        int j = nodes[i].next;
        if (j == -1 || !nodes[j].alive || (nodes[i].val + nodes[j].val != h.sum))
            continue;

        int left = nodes[i].prev;
        int right = nodes[j].next;

        // Remove old 'bad' counts
        if (left != -1 && nodes[left].val > nodes[i].val)
            bad--;
        if (nodes[i].val > nodes[j].val)
            bad--;
        if (right != -1 && nodes[j].val > nodes[right].val)
            bad--;

        // Merge operation
        nodes[i].val += nodes[j].val;
        nodes[j].alive = false;
        nodes[i].next = right;
        if (right != -1)
            nodes[right].prev = i;

        if (left != -1 && nodes[left].val > nodes[i].val)
            bad++;
        if (right != -1 && nodes[i].val > nodes[right].val)
            bad++;

        if (left != -1)
            heapPush(nodes[left].val + nodes[i].val, left);
        if (right != -1)
            heapPush(nodes[i].val + nodes[right].val, i);

        ops++;
    }

    free(nodes);
    return ops;
}

int main()
{
    int nums1[] = {5, 2, 3, 1};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d (Expected: 2)\n", minimumPairRemoval(nums1, n1));

    int nums2[] = {1, 2, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d (Expected: 0)\n", minimumPairRemoval(nums2, n2));

    int nums3[] = {3, 4, 1, 1, -3, 2, 4, 3};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d (Expected: 5)\n", minimumPairRemoval(nums3, n3));

    int nums4[] = {10};
    int n4 = 1;
    printf("Output: %d (Expected: 0)\n", minimumPairRemoval(nums4, n4));

    return 0;
}
