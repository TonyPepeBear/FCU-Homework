#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    printf("(a)\n");
    double sales[20] = {0};
    for (int i = 0; i < 20; i++) {
        scanf("%lf", &sales[i]);
    }
    printf("(b)\n");
    double allowance[75] = {0};
    srand(time(NULL));
    for (int i = 0; i < 75; i++) {
        allowance[i] = (double) (rand() % 100 + 1001);
    }
    for (int i = 0; i < 75; i++) {
        printf("%d: %lf\n", i, allowance[i]);
    }
    printf("(c)\n");
    int numbers[50] = {0};
    for (int i = 0; i < 50; i++) {
        printf("%d: %d\n", i, numbers[i]);
    }
    printf("(d)\n");
    int GAP[] = {4.0, 4.2, 3.9, 3.5, 4.5, 3.8, 3.2, 4.9, 3.7, 3.8};
    for (int i = 0; i < 10; i++) {
        printf("%d ", GAP[i]);
    }
    printf("\n");
    return 0;
}

/*----------------------------------------------------------------
1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 1.0 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 1.0 2.3 3.4
*/
