#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s)
{
    if (s == NULL || *s == '\0')
    {
        char *e = (char *)malloc(1);
        e[0] = '\0';
        return e;
    }

    int n = strlen(s);
    if (n == 1)
    {
        char *result = (char *)malloc(2);
        result[0] = s[0];
        result[1] = '\0';
        return result;
    }

    // Transform string
    int len = 2 * n + 3;
    char *t = (char *)malloc(len);
    t[0] = '^';
    for (int i = 0; i < n; i++)
    {
        t[2 * i + 1] = '#';
        t[2 * i + 2] = s[i];
    }
    t[len - 2] = '#';
    t[len - 1] = '$';

    int *p = (int *)calloc(len, sizeof(int));
    int center = 0, right = 0;
    int maxLen = 0, centerIndex = 0;

    for (int i = 1; i < len - 1; i++)
    {
        int mirror = 2 * center - i;

        if (i < right)
        {
            p[i] = (p[mirror] < (right - i)) ? p[mirror] : (right - i);
        }

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
        {
            p[i]++;
        }

        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }

        if (p[i] > maxLen)
        {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    char *result = (char *)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    free(t);
    free(p);

    return result;
}

int main()
{
    struct
    {
        char *input;
        char *expected;
    } tests[] = {
        {"babad", "bab"},
        {"cbbd", "bb"},
        {"racecar", "racecar"},
        {"a", "a"},
        {"ac", "a"},
        {"abcdcba", "abcdcba"},
        {"bananas", "anana"},
        {"", ""},
        {"aaaaa", "aaaaa"},
        {"abcdefg", "a"}};

    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++)
    {
        char *result = longestPalindrome(tests[i].input);
        printf("Input: \"%s\"\n", tests[i].input);
        printf("Output: \"%s\"\n", result);
        printf("Expected: \"%s\"\n\n", tests[i].expected);
        free(result);
    }

    return 0;
}
