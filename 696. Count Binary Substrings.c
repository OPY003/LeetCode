#include <stdio.h>
#include <string.h>

int countBinarySubstrings(char *s)
{
    int ans = 0, pre_c = 0, cur_c = 1;
    int n = strlen(s);

    if (n < 2)
        return 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
        {
            cur_c++;
        }
        else
        {
            pre_c = cur_c;
            cur_c = 1;
        }

        if (pre_c >= cur_c)
            ans++;
    }

    return ans;
}

int main()
{
    char s[100001];

    printf("Enter binary string: ");
    scanf("%100000s", s);

    int result = countBinarySubstrings(s);

    printf("Number of valid substrings: %d\n", result);

    return 0;
}
