#include <cstdio>

void reverseBits(unsigned int);

int main() {
    unsigned int n;
    scanf("%d", &n);
    reverseBits(n);
    return 0;
}

void reverseBits(unsigned int num) {
    char ans[32] = {0};
    int mask = 1 << 31;
    for (int c = 1; c < 33; c++, num <<= 1) {
        ans[c - 1] = num & mask ? '1' : '0';
        putchar(ans[c - 1]);
        if (c % 8 == 0) putchar(' ');
    }
    putchar('\n');
    for (int i = 1; i < 33; ++i) {
        putchar(ans[32 - i]);
        if (i % 8 == 0)
            putchar(' ');
    }
    putchar('\n');
}
