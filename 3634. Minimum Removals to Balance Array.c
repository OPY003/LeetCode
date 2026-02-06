#include <stdio.h>
#include <stdlib.h>

static int cmpInt(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int minRemoval(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmpInt);

    int left = 0;
    int ans = 1;

    for (int right = 0; right < numsSize; right++)
    {
        while (left <= right &&
               (long long)nums[right] > (long long)nums[left] * (long long)k)
        {
            left++;
        }

        int len = right - left + 1;
        if (len > ans)
            ans = len;
    }

    return numsSize - ans;
}

int main()
{
    int nums[] = {1, 6, 2, 9};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = minRemoval(nums, size, k);

    printf("Minimum removals = %d\n", result);

    return 0;
}
