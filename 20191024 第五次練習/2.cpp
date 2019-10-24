#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandom() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int main() {
    int ans = getRandom();
    printf("%d\n", ans);
    int guess = -1;
    bool play = true;
    while (play) {
        scanf("%d", &guess);
        if (guess > ans) {
            printf("Too high. Try again\n");
        } else if (guess < ans) {
            printf("Too low. Try again\n");
        } else {
            printf(
                "Excellent! You guessed the number!\nWould you like to play "
                "again (y or n)?\n");
            char c;
            scanf(" %c", &c);
            if (c == 'y') {
                guess = -1;
                ans = getRandom();
                printf("%d\n", ans);
            } else {
                play = false;
            }
        }
    }
    return 0;
}
