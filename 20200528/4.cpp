#include <cstdio>

#define MINIMUM2(a, b) (a > b) ? b : a

#define MINIMUM3(a, b, c) (MINIMUM2(MINIMUM2(a, b), c))

int main() {
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);

    printf("The min is %d", MINIMUM3(a, b, c));
    return 0;
}

