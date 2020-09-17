#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int sum[13] = {0};
    for (int i = 0; i < 36000; i++) {
        int a = rand() % 6 + 1;
        int b = rand() % 6 + 1;
        sum[a + b]++;
    }
    for (int i = 2; i < 13; i++) {
        printf("%d: %d\n", i, sum[i]);
    }
}
