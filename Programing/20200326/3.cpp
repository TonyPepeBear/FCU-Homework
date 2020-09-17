#include <cstdio>

int main() {
    float c = 0, f = 0;
    for (int i = 0; i < 212; ++i) {
        f = float(i);
        c = 5.0 / 9.0 * (f - 32);
        printf("%.3ff = %.3fc\n", f, c);
    }
    return 0;
}
