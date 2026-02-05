#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool is_non_decreasing(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int minimumOperations(int *nums, int numsSize)
{
    int operations = 0;
    int current_size = numsSize;

    // Allocate temporary array for modifications
    int *arr = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        arr[i] = nums[i];
    }

    while (!is_non_decreasing(arr, current_size))
    {
        // Find the minimum sum among all adjacent pairs
        int min_sum = INT_MAX;
        int min_idx = -1;

        for (int i = 0; i < current_size - 1; i++)
        {
            int current_sum = arr[i] + arr[i + 1];
            if (current_sum < min_sum)
            {
                min_sum = current_sum;
                min_idx = i;
            }
        }

        // Replace the pair with their sum and shift remaining elements
        arr[min_idx] = min_sum;

        // Shift elements left to remove arr[min_idx+1]
        for (int i = min_idx + 1; i < current_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        current_size--;
        operations++;
    }

    free(arr);
    return operations;
}

int main()
{
    int nums1[] = {5, 2, 3, 1};
    int nums2[] = {1, 2, 2};

    printf("%d\n", minimumOperations(nums1, 4)); // Output: 2
    printf("%d\n", minimumOperations(nums2, 3)); // Output: 0

    return 0;
}