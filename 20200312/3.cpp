#include <cstdio>

#define PI 3.14

void perimeter(double);

void area(double);

void ball(double);

int main() {
    void (*f[])(double) = {perimeter, area, ball};
    printf("\t1\tperimeter\n"
           "\t2\tarea\n"
           "\t3\tball\n");
    int select = 0;
    scanf("%d", &select);
    while (select - 1 > -1 && select - 1 < 4) {
        double a, b;
        scanf("%lf", &a);
        f[select - 1](a);
        printf("\t1\tperimeter\n"
               "\t2\tarea\n"
               "\t3\tball\n");
        scanf("%d", &select);
    }
    return 0;
}

void perimeter(double r) {
    printf("2 * pi * %lf = %lf\n", r, r * PI);
}

void area(double r) {
    printf("pi * %lf * %lf = %lf\n", r, r, r * r * PI);
}

void ball(double r) {
    printf("4 / 3 * pi * %lf * %lf * %lf = %lf\n", r, r, r, (3.0 / 4.0) * PI * r * r * r);
}
