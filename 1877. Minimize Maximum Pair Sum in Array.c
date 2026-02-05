#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int minPairSum(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int left = 0;
    int right = numsSize - 1;
    int max_sum = nums[left] + nums[right];

    while (left < right)
    {
        int pair_sum = nums[left] + nums[right];
        if (pair_sum > max_sum)
        {
            max_sum = pair_sum;
        }
        left++;
        right--;
    }
    return max_sum;
}

int main()
{
    int nums[] = {-7, 4, -2, 9, -5, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = minPairSum(nums, numsSize);

    printf("Minimum Maximum Pair Sum = %d\n", result);

    return 0;
}