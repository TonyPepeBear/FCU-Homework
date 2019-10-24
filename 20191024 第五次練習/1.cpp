#include <stdio.h>

int sum(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}
