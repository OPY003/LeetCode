#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x % 10 == 0 && x != 0)
        return false;

    int reversed = 0;

    while (x > reversed)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return (x == reversed) || (x == reversed / 10);
}

int main()
{
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (isPalindrome(x))
    {
        printf("True - It is a palindrome\n");
    }
    else
    {
        printf("False - It is not a palindrome\n");
    }

    return 0;
}
