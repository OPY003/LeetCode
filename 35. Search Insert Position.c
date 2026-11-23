#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target)
{

    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

int main() {
    int nums [] = {1, 3, 5, 6};
    int target = 2;

    int size = sizeof(nums) / sizeof(nums[0]);

    int result = searchInsert(nums, size, target);

    printf("Output: %d\n", result);

    return 0;
}