#include <cstdio>

#define BALL(a) (4.0 / 3.0) * 3.14159 * a * a * a

int main() {
    for (int i = 1; i < 11; ++i) {
        printf("r = %d: %lf\n", i, BALL(i));
    }
    return 0;
}

