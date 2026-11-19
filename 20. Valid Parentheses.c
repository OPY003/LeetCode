#include <stdbool.h>

bool isValid(char *s) {
    int t = 0;

    for (int i = 0; s[i]; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            s[t++] = c;
        } else {
            if (t == 0) return false;

            char open = s[--t];
            int diff = c - open;
            if (diff != 1 && diff != 2) return false;
        }
    }
    return t == 0;
}