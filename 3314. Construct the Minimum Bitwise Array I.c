#include <stdio.h>
#include <stdlib.h>

int *minBitwiseArray(int *nums, int numsSize, int *returnSize)
{
    int *ans = malloc(numsSize * sizeof *ans);
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        int p = nums[i];
        if (p == 2)
            ans[i] = -1;
        else
        {
            int pos = 0;
            while ((p >> pos) & 1)
                pos++;

            ans[i] = p ^ (1 << (pos - 1));
        }
    }
    return ans;
}

int main()
{
    int nums[] = {2, 3, 5, 7, 11, 13, 31};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int *result = minBitwiseArray(nums, numsSize, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}