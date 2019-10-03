#include <stdio.h>

int main() {
    for (int i = 2; i < 100; i++) {
        bool flag = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d\n", i);
        }
    }
}