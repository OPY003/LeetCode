#include <stdio.h>

double myPow(double x, int n)
{
    long long p = n;

    if (p < 0)
    {
        x = 1.0 / x;
        p = -p;
    }

    double result = 1.0;

    while (p > 0)
    {
        if (p % 2 == 1)
        {
            result *= x;
        }

        x *= x;
        p /= 2;
    }

    return result;
}

int main()
{
    double x;
    int n;

    printf("Enter base: ");
    scanf("%lf", &x);

    printf("Enter exponent: ");
    scanf("%d", &n);

    printf("Result: %.6f\n", myPow(x, n));

    return 0;
}