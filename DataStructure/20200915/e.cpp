#include <cstdio>

void h(int n, char a, char b, char c, int *counter) {
    if (n > 0) {
        h(n - 1, a, c, b, counter);
        ++*counter;
        printf("%d: 將第 %d 層圓盤由 %c 柱移至 %c 柱\n", *counter, n, a, c);
        h(n - 1, b, a, c, counter);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int counter = 0;
    h(n, 'a', 'b', 'c', &counter);
    return 0;
}
