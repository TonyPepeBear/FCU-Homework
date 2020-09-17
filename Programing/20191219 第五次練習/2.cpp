#include <cstdio>

int main() {
    double value1 = 20.4568, value2;
    // a
    double *dPtr;
    // b
    dPtr = &value1;
    // c
    printf("%f\n", *dPtr);
    // d
    value2 = *dPtr;
    // e
    printf("%f\n", value2);
    // f
    printf("%p\n", &value1);
    // g
    printf("%p\n", dPtr);

    return 0;
}
