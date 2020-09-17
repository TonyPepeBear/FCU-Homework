#include <stdio.h>

int sum(int n) {
    if (n > 10) {
        return (n % 10) + sum(n / 10);
    }
    return n;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}
