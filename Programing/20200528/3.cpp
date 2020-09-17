#include <cstdio>

#define MINIMUM2(a, b) (a > b) ? b : a

int main() {
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    printf("The min of x and y is %d\n", MINIMUM2(a, b));
    return 0;
}

