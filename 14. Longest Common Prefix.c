#include <stdio.h>
#include <string.h>

// Function to find longest common prefix
char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
        return "";

    for (int i = 0; strs[0][i] != '\0'; i++)
    {
        char c = strs[0][i];

        for (int j = 1; j < strsSize; j++)
        {
            if (strs[j][i] != c)
            {
                strs[0][i] = '\0'; // cut prefix here
                return strs[0];
            }
        }
    }
    return strs[0];
}

// Example main function
int main()
{
    char *strs1[] = {"flower", "flow", "flight"};
    char *strs2[] = {"dog", "racecar", "car"};

    printf("Output 1: %s\n", longestCommonPrefix(strs1, 3));
    printf("Output 2: %s\n", longestCommonPrefix(strs2, 3));

    return 0;
}