#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < abs(5 - i); j++) {
            printf(" ");
        }
        for (int j = 10; j > (abs(i - 5) * 2 + 1); j--) {
            printf("%s", "*");
        }
        printf("\n");
    }
}
