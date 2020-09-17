#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int count[11] = {0};
    srand(time(NULL));
    for (int i = 0; i < 36000; i++) {
        count[rand() % 6 + rand() % 6]++;
    }
    for (int i = 0; i < 11; i++) {
        printf("%d: %d\n", i + 2, count[i]);
    }
    return 0;
}
