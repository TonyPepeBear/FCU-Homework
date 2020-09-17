#include <cstdio>
#include <cstring>

#define N 10

void f(char *c, int n, int i);

int main() {
    char c[N];
    scanf("%s", c);
    f(c, strlen(c), 0);
    return 0;
}

void f(char *c, int n, int i) {
    if (i < n) {
        for (int j = i; j < n; ++j) {
            char nC[N];
            strcpy(nC, c);
            // change
            char t = c[j];
            for (int k = j; k > i; --k) {
                nC[k] = nC[k - 1];
            }
            nC[i] = t;
            f(nC, n, i + 1);
        }
    } else {
        printf("%s\n", c);
    }
}
