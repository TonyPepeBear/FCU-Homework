#include <cstdio>
#include <cstdlib>
#include <ctime>

#define FILE_NAME "numbers.txt"

int main() {
    FILE *f = fopen(FILE_NAME, "w+");
    srandom(time(NULL));
    for (int i = 0; i < 10; ++i) {
        fprintf(f, "%d\n", (int) random() % 1000000);
    }
    fclose(f);
    f = fopen(FILE_NAME, "r");
    int sum = 0, max = -1, min = 10000000;
    int s = 0;
    while (!feof(f)) {
        fscanf(f, "%d", &s);
        sum += s;
        if (s > max) max = s;
        if (s < min) min = s;
    }
    printf("sum:%d\nmax: %d\nmin: %d\n", sum, max, min);
    fclose(f);
}
