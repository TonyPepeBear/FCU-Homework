#include <cstdio>
#include <cstdarg>

#define N 100

int product(int len, ...);

int main() {
    printf("product = %d\n", product(3, 2, 3, 4));
    printf("product = %d\n", product(5, 2, 3, 4, 5, 6));
    return 0;
}

int product(int len, ...) {
    va_list args;
    va_start(args, len);
    int ans = 1;
    for (int i = 0; i < len; ++i) {
        ans *= va_arg(args, int);
    }
    return ans;
}
