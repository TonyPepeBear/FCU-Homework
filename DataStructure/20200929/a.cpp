#include <cstdio>

long long int pas(int i, int j) {
    long long int p = 1;
    for (long long int k = 1; k <= j; k++) {
        p = p * (i - k + 1) / k;
    }
    return p;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%lld", pas(i, j));
            if (j != i) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
