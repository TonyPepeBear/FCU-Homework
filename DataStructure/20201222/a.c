#include <stdio.h>
#include <stdlib.h>

int DFS(int *adj, int n, int i, int f, int level) {
    if (i == f || level > n) return 1;
    if (f == -1) f = i;
    for (int j = 0; j < n; j++) {
        if (adj[i * n + j]) {
            if (DFS(adj, n, j, f, level + 1)) { return 1; }
        }
    }
    return 0;
}

int main() {
    int n = 0, x = 0, y = 0;
    scanf("%d", &n);

    int *num = malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; ++i) {
        num[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        num[x * n + y] = 1;
    }

    int f = 0;

    for (int i = 0; i < n; ++i) {
        if (DFS(num, n, i, -1, 0)) {
            f = 1;
            break;
        }
    }

    printf("%s\n", f ? "Cycle" : "No Cycle");
    return 0;
}
