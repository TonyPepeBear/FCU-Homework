#include <cstdio>

int f(int i);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int j = 0; j < n; ++j) {
        int i = 0;
        scanf("%d", &i);
        printf("%d\n", f(i - 1));
    }
    return 0;
}

int f(int i) {
    if (i < 2) return 1;
    return f(i - 1) + f(i - 2);
}
