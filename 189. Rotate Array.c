#include <stdio.h>

void reverse(int *nums, int start, int end)
{
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int *nums, int numsSize, int k)
{
    if (numsSize <= 1)
        return;

    k = k % numsSize;
    if (k == 0)
        return;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;

    rotate(nums, n, 3);

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}