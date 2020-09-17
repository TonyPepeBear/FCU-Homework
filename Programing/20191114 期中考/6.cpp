#include <stdio.h>

bool isPrime(int n, int i = 2) {
    if (i * i > n) {
        return true;
    } else if (n % i == 0) {
        return false;
    }  else {
        return isPrime(n, i + 1);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    if(isPrime(n) ) {
        printf("%d is prime number\n", n);
    } else {
        printf("%d is not prime number\n", n);
    }
}
