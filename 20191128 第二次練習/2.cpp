#include <cstdlib>
#include <ctime>
#include <cstdio>

void initGame(int num[]) {
    for (int i = 0; i < 4; ++i) {
        num[i] = -1;
    }
    for (int i = 0; i < 4; ++i) {
        int t = rand() % 10;
        bool p = false;
        while (!p) {
            p = true;
            for (int j = 0; j < i; ++j) {
                if (num[j] == t) p = false;
            }
            if (p) {
                num[i] = t;
            } else {
                t = rand() % 10;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        printf("%d", num[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int num[4] = {-1};
    int gameStatus = 1;
    while (gameStatus == 1) {
        initGame(num);
        bool guess = false;
        while (!guess) {
            char g[4];
            scanf(" %s", g);
            int guessNum[4] = {-1};
            for (int i = 0; i < 4; ++i) {
                guessNum[i] = g[i] - '0';
            }
            int a = 0, b = 0;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (num[i] == guessNum[j]) {
                        if (i == j) a++;
                        else b++;
                    }
                }
            }
            if (a == 4) guess = true;
            else {
                printf("%dA%dB\n", a, b);
            }
        }
        printf("Play again?(0/1)");
        scanf("%d", &gameStatus);
    }
}
