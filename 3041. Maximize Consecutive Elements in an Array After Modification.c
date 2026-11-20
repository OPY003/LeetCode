#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int maxSelectedElements(int *nums, int n) {
    qsort(nums, n, sizeof(int), cmp);

    int maxVal = nums[n - 1];
    int *dp = calloc(maxVal + 3, sizeof(int));
    if (!dp)
    return 0;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int up = dp[x] + 1;
        int stay = dp[x - 1] + 1;

        if (up > dp[x + 1]) dp[x + 1] = up;
        if (stay > dp[x]) dp [x] = stay;

        if (dp[x] > ans) ans = dp[x];
        if (dp[x + 1] > ans) ans = dp[x + 1];
    }
    free(dp);
    return ans;
}

static void runTest(const char *name, int *arr, int n, int expected) {
    int result = maxSelectedElements(arr, n);
    printf("%s: got %d, expected %d -> %s\n", name, result, expected, result == expected ? "PASS" : "FAIL");
}

int main(void) {
    int t1[] = {2, 1, 5, 1, 1};
    int t2[] = {1, 4, 7, 10};
    int t3[] = {1, 1, 2};
    int t4[] = {1000000};

    runTest("Example 1", t1, 5, 3);
    runTest("Example 2", t2, 4, 1);
    runTest("Test [1, 1, 2]", t3, 3, 3);
    runTest("Test [1000000]", t4, 1, 1);

    return 0;
}