#include <cstdio>

#define N 200

int main() {
    int t = 0;
    scanf("%d", &t);
    int n[N] = {0}, m[N] = {0}, ans[N] = {0};
    bool read = true;
    while (read) {
        int x = 0, y = 0;
        read = scanf("%d%d", &x, &y);
        if (read) { n[y] += x; }
    }
    char c;
    scanf(" %c", &c);

    scanf("%d", &t);
    read = true;
    while (read) {
        int x = 0, y = 0;
        read = scanf("%d%d", &x, &y);
        if (read) { m[y] += x; }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ans[i + j] += n[i] * m[j];
        }
    }

    bool isFirst = true;
    // 17*x^10 + 7*x^8 + 15*x^5 + 11*x^3 + 10*x^2 + 10*x^0
    for (int i = N - 1; i > -1; --i) {
        if (ans[i] > 0) {
            if (!isFirst) { printf(" + "); }
            printf("%d*x^%d", ans[i], i);
            isFirst = false;
        }
    }

    return 0;
}
