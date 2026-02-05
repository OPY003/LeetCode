#include <stdio.h>
#include <stdbool.h>

bool isStrictlyPalindromic(int n)
{
    return false; // Mathematical fact: always false for n >= 4
}

// Main function for local testing
int main(void)
{
    int testCases[] = {4, 5, 6, 7, 8, 9};
    int size = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < size; i++)
    {
        int n = testCases[i];
        printf("n = %d -> %s\n", n, isStrictlyPalindromic(n) ? "true" : "false");
    }

    return 0;
}
