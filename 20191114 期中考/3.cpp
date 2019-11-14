#include <stdio.h>

int main() {
    for (int i = 100; i < 1000; i++) {
        int n = i, sum = 0;
        while (n > 0) {
            int x = n % 10;
            sum += x * x * x;
            n /= 10;
        }
        if (i == sum) {
            printf("%d\n", i);
        }
    }
    return 0;
}
