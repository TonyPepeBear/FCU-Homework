#include <cstdio>

int f(int n, int m);

int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int m = 0, n = 0;
        scanf("%d%d", &m, &n);
        printf("%d\n", f(m, n));
    }
    return 0;
}

int f(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return f(m - 1, 1);
    else if (m > 0 && n > 0)
        return f(m - 1, f(m, n - 1));
}
