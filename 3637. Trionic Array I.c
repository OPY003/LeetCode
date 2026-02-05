#include <stdio.h>
#include <stdbool.h>

bool isTrionic(int *nums, int numsSize)
{
    int i = 0;

    while (i + 1 < numsSize && nums[i + 1] > nums[i])
        i++;
    if (i < 1 || i >= numsSize - 1)
        return false;

    while (i + 1 < numsSize && nums[i + 1] < nums[i])
        i++;
    if (i < 2 || i >= numsSize - 1)
        return false;

    while (i + 1 < numsSize && nums[i + 1] > nums[i])
        i++;

    return i == numsSize - 1;
}

int main(void)
{
    int tests[][6] = {
        {1, 3, 5, 4, 2, 6},
        {2, 1, 3},
        {1, 2, 3, 2, 1},
        {1, 2, 1, 2}};
    int sizes[] = {6, 3, 5, 4};

    for (int i = 0; i < 4; i++)
    {
        printf("Test %d: %s\n",
            i + 1,
            isTrionic(tests[i], sizes[i]) ? "true" : "false");
    }
    return 0;
}
