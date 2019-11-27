#include <stdio.h>

int main() {
    int a[10] = {0};
    int b[10] = {0};
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i] == b[j]) {
                printf("%d\n", a[i]);
            }
        }
    }
    return 0;
}
