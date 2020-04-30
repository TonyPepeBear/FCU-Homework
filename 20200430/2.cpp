#include <cstdio>
#include <ctime>
#include <cstdlib>

#define N 10000
#define ODD_FILENAME "odd.txt"
#define EVEN_FILENAME "even.txt"

int main() {
    FILE *odd = fopen(ODD_FILENAME, "w+");
    FILE *even = fopen(EVEN_FILENAME, "w+");
    srandom(time(NULL));
    for (int i = 0; i < N; ++i) {
        int r = (int) random() % 100000;
        if (r % 2 == 0) {
            fprintf(even, "%d\n", r);
        } else {
            fprintf(odd, "%d\n", r);
        }
    }
    fclose(odd);
    fclose(even);
}
