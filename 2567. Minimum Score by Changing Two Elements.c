#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int minimizeSum(int *nums, int numsSize) {
    if (numsSize <= 3)
    return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int a = nums[numsSize - 1] - nums[2];
    int b = nums[numsSize - 2] - nums[1];
    int c = nums[numsSize - 3] - nums[0];

    int ans = a;
    if (b < ans) ans = b;
    if (c < ans) ans = c;
    return ans;
}

int main(void)
{
    int nums[] = {1, 4, 7, 8, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", minimizeSum(nums, n)); // 3

    int tricky[] = {1, 5, 9, 20};
    printf("%d\n", minimizeSum(tricky, 4)); // 4
    return 0;
}