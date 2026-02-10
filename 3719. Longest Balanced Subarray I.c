#include <stdio.h>

#define MAX_VAL 100000

int longestBalanced(int *nums, int numsSize)
{
    int ans = 0;
    int seenEven[MAX_VAL + 1] = {0};
    int seenOdd[MAX_VAL + 1] = {0};
    int timestamp = 1;

    for (int i = 0; i < numsSize; i++, timestamp++)
    {
        int distinctEven = 0;
        int distinctOdd = 0;

        for (int j = i; j < numsSize; j++)
        {
            int num = nums[j];

            if (num % 2 == 0)
            {
                if (seenEven[num] != timestamp)
                {
                    seenEven[num] = timestamp;
                    distinctEven++;
                }
            }
            else
            {
                if (seenOdd[num] != timestamp)
                {
                    seenOdd[num] = timestamp;
                    distinctOdd++;
                }
            }

            if (distinctEven == distinctOdd)
            {
                int len = j - i + 1;
                if (len > ans)
                    ans = len;
            }
        }
    }

    return ans;
}

int main()
{
    int nums1[] = {2, 5, 4, 3};
    int nums2[] = {3, 2, 2, 5, 4};
    int nums3[] = {1, 2, 3, 2};

    printf("%d\n", longestBalanced(nums1, 4)); // 4
    printf("%d\n", longestBalanced(nums2, 5)); // 5
    printf("%d\n", longestBalanced(nums3, 4)); // 3

    return 0;
}
