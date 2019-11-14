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
    for (int i = 2; i < 100; i++) {
        if(isPrime(i)) printf("%d\n", i);
    }
    return 0;
}

