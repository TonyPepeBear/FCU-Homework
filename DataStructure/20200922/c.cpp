#include <cstdio>

void bin(long long n) {
    if (n > 0) {
        bin(n / 2);
        printf("%lld", n % 2);
    }
}

int main() {
    long long n = 0;
    scanf("%lld", &n);
    bin(n);
    return 0;
}
