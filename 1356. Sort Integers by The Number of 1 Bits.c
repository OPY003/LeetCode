#include <stdio.h>
#include <stdlib.h>

/* Count number of 1 bits */
int countBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x - 1); // remove lowest set bit
        count++;
    }
    return count;
}

/* Comparator for qsort */
int cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    int bx = countBits(x);
    int by = countBits(y);

    if (bx == by)
        return x - y; // same bit count → normal ascending
    return bx - by;   // sort by bit count
}

/* LeetCode function */
int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
}

/* ----------- MAIN FOR TESTING ----------- */
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int returnSize;

    int *result = sortByBits(arr, n, &returnSize);

    printf("Sorted array: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    return 0;
}