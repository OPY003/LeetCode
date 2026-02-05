#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>

long long maximumSum(int *nums, int n)
{
    long long *incL = (long long *)malloc(sizeof(long long) * n);
    long long *dec = (long long *)malloc(sizeof(long long) * n);
    long long *incR = (long long *)malloc(sizeof(long long) * n);

    for (int i = 0; i < n; i++)
    {
        incL[i] = nums[i];
        if (i > 0 && nums[i - 1] < nums[i])
        {
            incL[i] += incL[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        dec[i] = nums[i];
        if (i + 1 < n && nums[i] > nums[i + 1])
        {
            dec[i] += dec[i + 1];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        incR[i] = nums[i];
        if (i + 1 < n && nums[i] < nums[i + 1])
        {
            incR[i] += incR[i + 1];
        }
    }

    long long ans = LLONG_MIN;

    for (int q = 1; q < n - 1; q++)
    {
        if (!(nums[q - 1] > nums[q] && nums[q] < nums[q + 1]))
            continue;

        if (q - 1 > 0 && nums[q - 2] < nums[q - 1])
        {
            long long sum =
                incL[q - 1] + dec[q] + incR[q] - nums[q - 1] - nums[q];

            if (sum > ans)
                ans = sum;
        }
    }

    free(incL);
    free(dec);
    free(incR);

    return ans;
}

int main()
{
    int nums1[] = {0, -2, -1, -3, 0, 2, -1};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output 1: %" PRId64 "\n", maximumSum(nums1, n1));

    int nums2[] = {1, 4, 2, 7};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output 2: %" PRId64 "\n", maximumSum(nums2, n2));

    return 0;
}
