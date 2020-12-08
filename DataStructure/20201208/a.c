#include <stdio.h>
#include <string.h>

#define N 100000

int main() {
    int p[N];
    for (int i = 0; i < N; ++i) {
        p[i] = 0;
    }
    int n = 0;
    scanf("%d", &n);
    int a, b;
    int count = 0;
    char s[1000];
    while (scanf(" %s%d%d", s, &a, &b) != EOF) {
        if (!strcmp(s, "BeFriend")) {
            if (p[a] || p[b]) {
                if (p[a]) {
                    if (!p[b]) {
                        p[b] = p[a];
                        continue;
                    } else {
                        int t = p[b];
                        for (int i = 0; i < n + 1; ++i) {
                            if (p[i] == t) { p[i] = p[a]; }
                        }
                    }
                } else {
                    if (!p[a]) {
                        p[a] = p[b];
                        continue;
                    } else {
                        int t = p[a];
                        for (int i = 0; i < n + 1; ++i) {
                            if (p[i] == t) { p[i] = p[b]; }
                        }
                    }
                }
            } else {
                count++;
                p[a] = count;
                p[b] = count;
            }
        }
        if (!strcmp(s, "IsFriend")) {
            if (p[a] == p[b] && p[a] != 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
