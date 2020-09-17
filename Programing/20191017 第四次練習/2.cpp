#include <stdio.h>

void showStar(int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int x = 0, y = 0;
    while (scanf("%d%d", &x, &y) != EOF) {
        showStar(x, y);
    }
    return 0;
}
