#include <stdio.h>

int minimumDeletions(char *s)
{
    int bCount = 0;
    int deletions = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'b')
        {
            bCount++;
        }
        else
        { // s[i] == 'a'
            if (bCount > 0)
            {
                deletions++;
                if (deletions > bCount)
                {
                    deletions = bCount;
                }
            }
        }
    }

    return deletions;
}

int main()
{
    char s[] = "aababbab";

    int result = minimumDeletions(s);

    printf("Input: %s\n", s);
    printf("Minimum deletions needed: %d\n", result);

    return 0;
}