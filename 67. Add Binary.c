#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);

    int maxLen = (lenA > lenB ? lenA : lenB) + 2;
    char *result = (char *)malloc(maxLen);

    int i = lenA - 1, j = lenB - 1, k = 0, carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';

    for (int l = 0, r = k - 1; l < r; l++, r--)
    {
        char t = result[l];
        result[l] = result[r];
        result[r] = t;
    }

    return result;
}

int main()
{
    char a[] = "1010";
    char b[] = "1011";

    char *res = addBinary(a, b);
    printf("%s\n", res);

    free(res);
    return 0;
}
