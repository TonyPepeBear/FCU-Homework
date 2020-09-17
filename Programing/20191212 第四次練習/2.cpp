#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    int n = 0, m = 0, p = 0;
    scanf("%d%d%d", &n, &m, &p);
    int a[100][100], b[100][100], ans[100][100];
    printf("a:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = (int) random() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("b:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            b[i][j] = (int) random() % 10;
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            ans[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("ans:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
