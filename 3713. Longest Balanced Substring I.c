#include <stdio.h>
#include <string.h>

// NOLINTNEXTLINE(readability-identifier-naming)
int longestBalanced(char *s)
{
    int n = (int)strlen(s);
    int best = 0;

    for (int i = 0; i < n; i++)
    {
        if (n - i <= best)
            break;

        int freq[26] = {0};
        int distinct = 0;
        int max_freq = 0;

        for (int j = i; j < n; j++)
        {
            int c = s[j] - 'a';

            if (freq[c]++ == 0)
                distinct++;

            if (freq[c] > max_freq)
                max_freq = freq[c];

            int len = j - i + 1;
            if (distinct * max_freq == len && len > best)
                best = len;
        }
    }
    return best;
}

int main()
{
    char s[1005];

    printf("Enter string: ");
    if (scanf("%1000s", s) != 1)
    {
        printf("Input error\n");
        return 1;
    }

    int result = longestBalanced(s);
    printf("Longest balanced substring length: %d\n", result);

    return 0;
}
