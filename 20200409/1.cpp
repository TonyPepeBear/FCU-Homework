#include <cstdio>

void displayBits(unsigned int);

int main() {
    unsigned int ans = 0;
    char s[4];
    scanf("%s", s);
    for (int i = 0; i < 4; ++i) {
        ans <<= 8;
        ans |= s[i];
    }
    displayBits(ans);
    return 0;
}

void displayBits(unsigned int num) {
    unsigned int mask = 1 << 31;
    for (int c = 1; c < 33; c++, num <<= 1) {
        putchar(num & mask ? '1' : '0');
        if (c % 4 == 0) putchar(' ');
    }
    putchar('\n');
}
