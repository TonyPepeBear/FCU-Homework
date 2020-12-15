#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int main() {
    int n = 0;
    scanf("%d", &n);

    int trust[N] = {0};
    int beTrust[N] = {0};

    int a = 0, b = 0;
    while (scanf("%d%d", &a, &b) != EOF) {
        trust[a]++;
        beTrust[b]++;
    }
    int ans = 0;
    for (int i = 1; i < n + 1; ++i) {
        if (trust[i] == 0 && beTrust[i] == n - 1) {
            if (ans != 0) {
                ans = 0;
                break;
            }
            ans = i;
        }
    }
    if (ans == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
