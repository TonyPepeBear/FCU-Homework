#include <stdio.h>

bool isRightTriangle(int a, int b, int c) {
    return a * a + b * b == c * c || a * a + c * c == b * b ||
           b * b + c * c == a * a;
}

int main() {
    int a = 0, b = 0, c = 0;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        if (isRightTriangle(a, b, c)) {
            printf("is right triangle\n");
        } else {
            printf("is not right triangle\n");
        }
    }
    return 0;
}
