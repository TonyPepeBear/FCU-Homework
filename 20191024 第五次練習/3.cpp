#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool flip(int i) {
    srand(time(NULL) + i);
    return rand() % 2;
}

int main() {
    for (int i = 0; i < 100; i++) {
        printf("%d\n", flip(i));
    }
    return 0;
}
