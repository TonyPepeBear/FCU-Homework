#include <stdio.h>

bool isPrime(int n, int i = 2) {
    if (n < 2) {
        return false;
    } else if (n % i == 0) {
        return false;
    } else if (i * i > n) {
        return true;
    } else {
        return isPrime(n, i + 1);
    }
}
int main() {
    int n = 0;
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("is prime number\n");
    } else {
        printf("is not prime number\n");
    }
    return 0;
}
