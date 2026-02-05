#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
    qsort(arr, arrSize, sizeof(int), cmp);

    int minDiff = INT_MAX;

    // Find minimum difference
    for (int i = 1; i < arrSize; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }

    // Count pairs with minimum difference
    int count = 0;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] - arr[i - 1] == minDiff)
            count++;
    }

    // Allocate result
    int **result = (int **)malloc(count * sizeof(int *));
    *returnColumnSizes = (int *)malloc(count * sizeof(int));

    int idx = 0;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] - arr[i - 1] == minDiff)
        {
            result[idx] = (int *)malloc(2 * sizeof(int));
            result[idx][0] = arr[i - 1];
            result[idx][1] = arr[i];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    *returnSize = count;
    return result;
}

int main()
{
    int arr[] = {4, 2, 1, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int returnSize;
    int *returnColumnSizes;

    int **result = minimumAbsDifference(arr, arrSize, &returnSize, &returnColumnSizes);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[%d,%d]", result[i][0], result[i][1]);
        if (i != returnSize - 1)
            printf(",");
    }
    printf("]\n");

    // Free memory
    for (int i = 0; i < returnSize; i++)
        free(result[i]);
    free(result);
    free(returnColumnSizes);

    return 0;
}
