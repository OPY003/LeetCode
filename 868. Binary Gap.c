#include <stdio.h>

int binaryGap(int n)
{
    int lastPos = -1;
    int maxGap = 0;
    int pos = 0;

    while (n > 0)
    {
        if (n & 1)
        { // check if current bit is 1
            if (lastPos != -1)
            {
                int gap = pos - lastPos;
                if (gap > maxGap)
                    maxGap = gap;
            }
            lastPos = pos;
        }
        n >>= 1; // shift right
        pos++;
    }

    return maxGap;
}

int main()
{
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    int result = binaryGap(n);
    printf("Longest Binary Gap = %d\n", result);

    return 0;
}