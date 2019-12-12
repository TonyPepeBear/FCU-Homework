#include <cstdio>
#include <cstdlib>
#include <ctime>

void a() {
    printf("a: \n");
    int n[2][2] = {0};
    printf("before: \n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            n[i][j] = (int) random() % 10;
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }
    n[1][1] *= 3;
    printf("after: \n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }
}

void b() {
    printf("\n\nb: \n");
    int n[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            n[i][j] = (int) random() % 10;
        }

    }
    int total = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", n[i][j]);
            total += n[i][j];
        }
        printf("\n");
    }
    printf("total: %d\n", total);
}

void c() {
    printf("\n\nc: \n");
    int n[3][3] = {{3, 3, 3},
                   {3, 3, 3},
                   {3, 3, 3}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }
}

void d() {
    printf("\n\nd: \n");
    int sales[4][5];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            sales[i][j] = (int) random() % 10;
            printf("%d ", sales[i][j]);
        }
        printf("\n");
    }
    int min = 99, max = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (sales[i][j] > max) max = sales[i][j];
            if (sales[i][j] < min) min = sales[i][j];
        }
    }
    printf("max = %d, min = %d\n", max, min);
}

void e() {
    printf("\n\ne: \n");
    int n1[10][10];
    int n2[20][10];
    printf("n1 :\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            n1[i][j] = (int) random() % 10;
            printf("%d ", n1[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i < 10)
                n2[i][j] = 0;
            else
                n2[i][j] = n1[i - 10][j];
        }
    }
    printf("n2 :\n");
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", n2[i][j]);
        }
        printf("\n");
    }
}

void f() {
    printf("\n\nf: \n");
    int d1[10][10], d2[10][10], sum[10][10], difference[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            d1[i][j] = (int) (random() % 10);
            d2[i][j] = (int) (random() % 10);
            sum[i][j] = d1[i][j] + d2[i][j];
            difference[i][j] = d1[i][j] - d2[i][j];
        }
    }
    printf("d1:\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", d1[i][j]);
        }
        printf("\n");
    }
    printf("d2:\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", d2[i][j]);
        }
        printf("\n");
    }
    printf("sum:\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    printf("difference:\n");
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }
}


int main() {
    srand(time(NULL));
    a();
    b();
    c();
    d();
    e();
    f();
}
