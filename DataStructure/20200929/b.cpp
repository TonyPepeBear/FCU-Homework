#include <cstdio>

#define N 101

int main() {
    int count = 0, countZ = 0;
    int num[N] = {0};
    bool con = true;
    while (con) {
        int x = -1;
        con = scanf("%d", &x);
        if (x == 0)
            countZ++;
        else if (x != -1) {
            num[count] = x;
            count++;
        }
    }

    for (int i = 0; i < count; ++i) {
        printf("%d ", num[i]);
    }
    for (int j = 0; j < countZ; ++j) {
        printf("0 ");
    }
    printf("\n");
    return 0;
}
