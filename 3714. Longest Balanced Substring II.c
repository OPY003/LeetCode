#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET 100000
#define SIZE 262147 // Prime number for better distribution

typedef struct
{
    int x, y;
} Pair;

typedef struct
{
    Pair key;
    int value;
    int used;
} Entry;

static Entry map1[SIZE], map2[SIZE], map3[SIZE], map4[SIZE];

static unsigned hash(int x, int y)
{
    unsigned long long hx = (unsigned)(x + OFFSET);
    unsigned long long hy = (unsigned)(y + OFFSET);
    // Better mixing with prime multipliers
    unsigned long long h = hx * 0x9e3779b97f4a7c15ULL + hy * 0x517cc1b727220a95ULL;
    return (unsigned)(h % SIZE);
}

static int map_get_or_set(Entry *map, int x, int y, int index)
{
    unsigned h = hash(x, y);
    unsigned start = h;

    while (map[h].used)
    {
        if (map[h].key.x == x && map[h].key.y == y)
            return map[h].value;
        h = (h + 1) % SIZE;
        // Safety check (shouldn't happen with proper SIZE)
        if (h == start)
            return index;
    }
    map[h].used = 1;
    map[h].key.x = x;
    map[h].key.y = y;
    map[h].value = index;
    return index;
}

int longestBalanced(char *s)
{
    int a = 0, b = 0, c = 0;
    int best = 1;

    memset(map1, 0, sizeof(map1));
    memset(map2, 0, sizeof(map2));
    memset(map3, 0, sizeof(map3));
    memset(map4, 0, sizeof(map4));

    map_get_or_set(map1, 0, 0, 0);
    map_get_or_set(map2, 0, 0, 0);
    map_get_or_set(map3, 0, 0, 0);
    map_get_or_set(map4, 0, 0, 0);

    int run = 0;
    char prev = 0;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == prev)
            run++;
        else
        {
            run = 1;
            prev = s[i];
        }
        if (run > best)
            best = run;

        if (s[i] == 'a')
            a++;
        else if (s[i] == 'b')
            b++;
        else
            c++;

        int i1 = map_get_or_set(map1, a - b, a - c, i + 1);
        int i2 = map_get_or_set(map2, a - b, c, i + 1);
        int i3 = map_get_or_set(map3, b - c, a, i + 1);
        int i4 = map_get_or_set(map4, a - c, b, i + 1);

        if (i + 1 - i1 > best)
            best = i + 1 - i1;
        if (i + 1 - i2 > best)
            best = i + 1 - i2;
        if (i + 1 - i3 > best)
            best = i + 1 - i3;
        if (i + 1 - i4 > best)
            best = i + 1 - i4;
    }

    return best;
}

int main()
{
    // Test case 1: Simple balanced string
    char test1[] = "aabbcc";
    printf("Test 1: \"%s\"\n", test1);
    printf("Result: %d (expected: 6)\n\n", longestBalanced(test1));

    // Test case 2: All same character
    char test2[] = "aaaa";
    printf("Test 2: \"%s\"\n", test2);
    printf("Result: %d (expected: 4)\n\n", longestBalanced(test2));

    // Test case 3: No balanced substring
    char test3[] = "abc";
    printf("Test 3: \"%s\"\n", test3);
    printf("Result: %d (expected: 1)\n\n", longestBalanced(test3));

    // Test case 4: Mixed balanced
    char test4[] = "aabcbc";
    printf("Test 4: \"%s\"\n", test4);
    printf("Result: %d (expected: 4)\n\n", longestBalanced(test4));

    // Test case 5: Your TLE test case
    char test5[] = "aabaaaccaabbbcbcabbcccacbaacbaabaaaacaccbabaccbcbacabaccbbbaabbaababcacabbbcacccbbcaccaabcaacccabababbabaabccababaccacbbbabcccaaabbcbcaccbccaccacacbaabccccbbbaacabbccbcbaaccaacccacbaacbbcccbacbbbbacccbcccaccaacaccaccbcacbbabcaccbbabbcaacbcbabaabacbbcaaabbbcacaabaabbbaccabbabaccaaccaacbcbaabacacaccaaaaaabbbccaaacabcacccbbbcbaccaaacaaccbaaaccbaabbacaabaacaacaacccbbabcabbbccacabcccacbcaacacaacacccacaccbaccabaccbcccacaccbbaccacbaabaabbbcaabbaabcaacacbcbabcbbcaaaccabcaaccbaacabababbccbbbccccaaabaaaaabcacbcacacacacbcbbcbaaabacbcbabcccaabbccbacaaacbbabbcbccbccbacbaaababbacacccabaabbbbcccbcaabccaabcacabbbcabcbbaaabbacaaccaabcabbaabcccccbbabc";
    printf("Test 5: Long string (%d chars)\n", (int)strlen(test5));
    printf("Result: %d\n\n", longestBalanced(test5));

    // Test case 6: Edge case - single character
    char test6[] = "a";
    printf("Test 6: \"%s\"\n", test6);
    printf("Result: %d (expected: 1)\n\n", longestBalanced(test6));

    // Test case 7: Two characters balanced
    char test7[] = "ab";
    printf("Test 7: \"%s\"\n", test7);
    printf("Result: %d (expected: 1)\n\n", longestBalanced(test7));

    // Test case 8: Longer consecutive run
    char test8[] = "aaaaabbbbbccccc";
    printf("Test 8: \"%s\"\n", test8);
    printf("Result: %d (expected: 15)\n\n", longestBalanced(test8));

    return 0;
}