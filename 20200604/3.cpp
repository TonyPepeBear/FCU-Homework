#include <cstdio>

extern int ran1to13();

extern int compare(int, int);

int main() {
    int guessCount = 1;
    int ans = ran1to13();
    printf("%d\n", ans);
    int guess = 0;
    scanf("%d", &guess);
    while (compare(ans, guess)) {
        if (compare(ans, guess) > 0) {
            printf("Bigger\n");
        } else {
            printf("Smaller\n");
        }
        scanf("%d", &guess);
        guessCount++;
    }
    printf("Bingo %d\n", guessCount);
    return 0;
}
