#include <cstdio>

#define N 200

int main() {
    int n[N] = {0};
    int t;
    scanf("%d", &t);
    bool read = true;
    while (read) {
        int x = 0, y = 0;
        read = scanf("%d%d", &x, &y);
        n[y] += x;
    }
    char c;
    scanf(" %c", &c);

    scanf("%d", &t);
    read = true;
    while (read) {
        int x = 0, y = 0;
        read = scanf("%d%d", &x, &y);
        n[y] += x;
    }
    bool isFirst = true;
    // 17*x^10 + 7*x^8 + 15*x^5 + 11*x^3 + 10*x^2 + 10*x^0
    for (int i = N - 1; i > -1; --i) {
        if (n[i] > 0) {
            if (!isFirst) { printf(" + ", n[i], i); }
            printf("%d*x^%d", n[i], i);
            isFirst = false;
        }
    }
    printf("\n");
    return 0;
}
