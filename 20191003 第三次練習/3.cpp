#include <stdio.h>

int main() {
    int num = 0, count = 0;
    float total = 0;
    scanf("%d%d", &num, &count);
    switch (num) {
        case 1:
            total = (count)*2.98;
            break;
        case 2:
            total = (count)*4.50;
            break;
        case 3:
            total = (count)*9.98;
            break;
        case 4:
            total = (count)*4.49;
            break;
        case 5:
            total = (count)*6.87;
            break;
    }
    printf("%.2f\n", total);
}
