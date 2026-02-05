#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int lastSeen[256];

    for (int i = 0; i < 256; i++)
    {
        lastSeen[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int end = 0; s[end] != '\0'; end++)
    {
        unsigned char c = s[end];

        if (lastSeen[c] >= start)
        {
            start = lastSeen[c] + 1;
        }

        lastSeen[c] = end;

        int currentLen = end - start + 1;
        if (currentLen > maxLen)
        {
            maxLen = currentLen;
        }
    }

    return maxLen;
}

// Test function
int main()
{
    // Test cases
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";
    char s3[] = "pwwkew";
    char s4[] = "";
    char s5[] = "dvdf";

    printf("Input: \"%s\" -> Output: %d\n", s1, lengthOfLongestSubstring(s1));
    printf("Input: \"%s\" -> Output: %d\n", s2, lengthOfLongestSubstring(s2));
    printf("Input: \"%s\" -> Output: %d\n", s3, lengthOfLongestSubstring(s3));
    printf("Input: \"%s\" -> Output: %d\n", s4, lengthOfLongestSubstring(s4));
    printf("Input: \"%s\" -> Output: %d\n", s5, lengthOfLongestSubstring(s5));

    return 0;
}