#include <cstdio>
#include <cstring>

#define N 10

void f(char *c, int n, int i);

int main() {
    int x = 0;
    scanf("%d", &x);
    for (int i = 0; i < x; ++i) {
        char c[N];
        scanf("%s", c);
        f(c, strlen(c), 0);
    }
    return 0;
}

void f(char *c, int n, int i) {
    if (i < n) {
        for (int j = i; j < n; ++j) {
            char nC[N];
            strcpy(nC, c);
            // change
            char t = nC[j];
            nC[j] = nC[i];
            nC[i] = t;
            f(nC, n, i + 1);
        }
    } else {
        printf("%s\n", c);
    }
}
