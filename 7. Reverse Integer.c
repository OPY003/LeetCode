#include <stdio.h>

int reverse(int x) {
    int r = 0;
    while (x != 0) {
        if (r > 214748364 || (r == 214748364 && x % 10 > 7)) return 0;
        if (r < -214748364 || (r == -214748364 && x % 10 < -8)) return 0;
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    int x = 123;
    int result = reverse(x);
    printf("Reversed integer: %d\n", result);

    x = -123;
    result = reverse(x);
    printf("Reversed integer: %d\n", result);

    x = 120;
    result = reverse(x);
    printf("Reversed integer: %d\n", result);

    x = 0;
    result = reverse(x);
    printf("Reversed integer: %d\n", result);

    return 0;
}