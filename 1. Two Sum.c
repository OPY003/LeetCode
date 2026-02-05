#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    *returnSize = 0;
    free(result);
    return NULL;
}

int main()
{
    // Test case 1
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;

    int *result1 = twoSum(nums1, 4, target1, &returnSize1);

    if (result1 != NULL)
    {
        printf("Test 1 - Target: %d\n", target1);
        printf("Indices: [%d, %d]\n", result1[0], result1[1]);
        printf("Values: [%d, %d]\n\n", nums1[result1[0]], nums1[result1[1]]);
        free(result1);
    }

    // Test case 2
    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;

    int *result2 = twoSum(nums2, 3, target2, &returnSize2);

    if (result2 != NULL)
    {
        printf("Test 2 - Target: %d\n", target2);
        printf("Indices: [%d, %d]\n", result2[0], result2[1]);
        printf("Values: [%d, %d]\n\n", nums2[result2[0]], nums2[result2[1]]);
        free(result2);
    }

    // Test case 3
    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;

    int *result3 = twoSum(nums3, 2, target3, &returnSize3);

    if (result3 != NULL)
    {
        printf("Test 3 - Target: %d\n", target3);
        printf("Indices: [%d, %d]\n", result3[0], result3[1]);
        printf("Values: [%d, %d]\n\n", nums3[result3[0]], nums3[result3[1]]);
        free(result3);
    }

    return 0;
}