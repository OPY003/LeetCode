#include <stdio.h>
#include <stdlib.h>

int *constructTransformedArray(int *nums, int numsSize, int *returnSize)
{
    int *result = (int *)malloc(numsSize * sizeof(int));
    if (!result)
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int newIndex = (i + nums[i]) % numsSize;
        if (newIndex < 0)
            newIndex += numsSize;
        result[i] = nums[newIndex];
    }

    *returnSize = numsSize;
    return result;
}

int main()
{
    int nums[] = {3, -2, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int *result = constructTransformedArray(nums, numsSize, &returnSize);
    if (!result)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Result: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d", result[i]);
        if (i < returnSize - 1)
            printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
