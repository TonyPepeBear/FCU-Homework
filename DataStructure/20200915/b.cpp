#include <cstdio>

int f(int x, int n);

int main() {
    int N = 0;
    scanf("%d", &N);
    for (int j = 0; j < N; ++j) {
        int x = 0, n = 0;
        scanf("%d%d", &x, &n);
        printf("%d\n", f(x, n));
    }
    return 0;
}

int f(int x, int n) {
    if (n == 0) return 1;
    return x * f(x, n - 1);
}
