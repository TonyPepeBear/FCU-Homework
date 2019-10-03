#include <stdio.h>

int main() {
    // C
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 10 - i; j++) {
            printf("%s", "*");
        }
        printf("\n");
    }
    // D
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) {
            printf("%s", "*");
        }
        printf("\n");
    }
}
