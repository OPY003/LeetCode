#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
    {

        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0, high = x;

    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX)
        {

            if ((x + y) % 2 == 0)
            {
                return ((maxX > maxY ? maxX : maxY) + (minX < minY ? minX : minY)) / 2.0;
            }
            else
            {
                return (maxX > maxY ? maxX : maxY);
            }
        }
        else if (maxX > minY)
        {
            high = partitionX - 1;
        }
        else
        {
            low = partitionX + 1;
        }
    }

    return -1.0;
}

int main()
{
    int nums1[] = {1, 3};
    int nums2[] = {2};

    double median = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("Median: %.1f\n", median);

    return 0;
}