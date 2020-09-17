#include <cstdio>

#define SIZE 10

int main() {
    // a
    int oddNum[SIZE] = {0};
    for (int i = 0; i < 20; ++i) {
        oddNum[i] = 2 * i + 1;
    }
    // b
    int *iPtr;
    // c
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", oddNum[i]);
    }
    printf("\n");
    // d
    iPtr = oddNum;
    iPtr = &oddNum[0];
    // e
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", *(iPtr + i));
    }
    printf("\n");
    // f
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", *(oddNum + i));
    }
    printf("\n");
    // g
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", iPtr[i]);
    }
    printf("\n");
    // h
    printf("%d ", oddNum[3]);
    printf("%d ", *(oddNum + 3));
    printf("%d ", iPtr[3]);
    printf("%d ", *(iPtr + 3));
    printf("\n");
    // i
    printf("iPtr + 5 address: %p, value: %d\n", iPtr + 5, *(iPtr + 5));
    // j
    iPtr = &oddNum[9];
    iPtr -= 9;
    printf("iPtr -= 9 address: %p, value: %d\n", iPtr, *iPtr);
    return 0;
}
