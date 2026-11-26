#include <stdio.h>

double myPow(double x, int n)
{
    if (n < 0)
    {
        return 1.0 / myPow(x, -n);
    }

    if (n == 0)
    {
        return 1.0;
    }

    double half = myPow(x, n / 2);

    if (n % 2 == 0)
    {
        return half * half;
    }

    return half * half * x;
}

int main()
{
    double x;
    int n;

    printf("Enter base (x): ");
    scanf("%lf", &x);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    double result = myPow(x, n);

    printf("Result: %.6f\n", result);

    return 0;
}