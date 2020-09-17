#include <stdio.h>

float max(float a, float b, float c, float d) {
    float max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}

int main() {
    float a = 0, b = 0, c = 0, d = 0;
    while (scanf("%f%f%f%f", &a, &b, &c, &d) != EOF) {
        printf("%f\n", max(a, b, c, d));
    }
}
