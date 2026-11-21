
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes)
{

    int **result = malloc(numsSize * numsSize * sizeof(int *));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));

    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2; i++)
    {

        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {

                // Allocate memory for each triplet
                result[*returnSize] = malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                // Skip duplicate elements
                while (left < right && nums[left] == nums[left - 1])
                {
                    left++;
                }

                while (left < right && nums[right] == nums[right + 1])
                {
                    right--;
                }
            }

            else if (sum < 0)
            {
                left++;
            }

            else
            {
                right--;
            }
        }
    }

    return result;
}
