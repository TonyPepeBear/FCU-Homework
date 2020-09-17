#include <cstdio>

void add(double, double);

void sub(double, double);

void mut(double, double);

void div(double, double);

int main() {
    void (*f[])(double, double) = {add, sub, mut, div};
    int select = 0;
    printf("\t1\taddition\n"
           "\t2\tsubtraction\n"
           "\t3\tmultiplication\n"
           "\t4\tdivision\n");
    scanf("%d", &select);
    while (select - 1 > -1 && select - 1 < 5) {
        double a, b;
        scanf("%lf%lf", &a, &b);
        f[select - 1](a, b);
        printf("\t1\taddition\n"
               "\t2\tsubtraction\n"
               "\t3\tmultiplication\n"
               "\t4\tdivision\n");
        scanf("%d", &select);
    }
    return 0;
}

void add(double a, double b) {
    printf("%f + %f = %f\n", a, b, a + b);
}

void sub(double a, double b) {
    printf("%f - %f = %f\n", a, b, a - b);
}

void mut(double a, double b) {
    printf("%f * %f = %f\n", a, b, a * b);
}

void div(double a, double b) {
    printf("%f / %f = %f\n", a, b, a / b);
}

