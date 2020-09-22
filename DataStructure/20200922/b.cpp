#include <cstdio>

unsigned long long chess(unsigned long long n, unsigned long long step) {
    if (n == 0) return 0;
    unsigned long long x = 1, t = step;
    while (t > 0) {
        x *= 2;
        t--;
    }
    if (n > x)
        return chess(n - x, step + 1);
    else
        return step + 1;
}

int main() {
    unsigned long long n = 0;
    scanf("%llu", &n);
    printf("%llu", chess(n, 0));
    return 0;
}
