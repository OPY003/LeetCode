#include <stdio.h>

int value(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(char *s)
{
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int curr = value(s[i]);
        int next = value(s[i + 1]);

        if (curr < next)
            total -= curr;
        else
            total += curr;
    }

    return total;
}

int main()
{
    char s1[] = "III";
    char s2[] = "LVIII";
    char s3[] = "MCMXCIV";

    printf("%d\n", romanToInt(s1)); // 3
    printf("%d\n", romanToInt(s2)); // 58
    printf("%d\n", romanToInt(s3)); // 1994

    return 0;
}
