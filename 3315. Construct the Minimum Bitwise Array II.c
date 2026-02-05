#include <stdlib.h>

int *minBitwiseArray(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        int p = nums[i];

        if (p == 2)
        {
            ans[i] = -1;
            continue;
        }

        int pos = 0;
        while ((p & (1 << pos)) != 0)
        {
            pos++;
        }

        ans[i] = p - (1 << (pos - 1));
    }

    return ans;
}

#include <stdio.h>
#include <stdlib.h>

int *minBitwiseArray(int *nums, int numsSize, int *returnSize);

int main(void)
{
    int nums[] = {2, 3, 5, 7, 11, 13, 31};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize = 0;
    int *ans = minBitwiseArray(nums, numsSize, &returnSize);

    printf("Input:  ");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\nOutput: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    free(ans);
    return 0;
}
