#include <cstdio>
#include <cstdlib>
#include <ctime>


#define CARDS 52
#define COUNT 5

void printDeck(int deck[52]);

char check(const int cards[5]);

void shuffle(int deck[CARDS]) {
    for (int i = 0; i < CARDS; ++i) {
        bool f;
        int r;
        do {
            f = false;
            r = rand() % CARDS;
            for (int j = 0; j < i; ++j) {
                if (r == deck[j]) {
                    f = true;
                    break;
                }
            }
        } while (f);
        deck[i] = r;
    }
}

int main() {
    srand(time(NULL));
    int deck[CARDS] = {0};
    shuffle(deck);
    int cards[COUNT];
    for (int i = 0; i < COUNT; ++i) {
        cards[i] = deck[i];
    }
    for (int i = 0; i < COUNT; ++i) {
        printf("%d ", cards[i]);
    }
    check(cards);
    printf("%c\n", check(cards));
}

char check(const int cards[COUNT]) {
    // f
    {
        bool t = true;
        int suit = cards[0] / 13;
        for (int i = 0; i < COUNT; ++i) {
            if (cards[i] / 13 != suit) {
                t = false;
                break;
            }
        }
        int before = cards[0];
        for (int i = 1; i < COUNT; ++i) {
            if (before + 1 == cards[i]) {
                before = cards[i];
            } else {
                t = false;
            }
        }
        if (t) return 'f';
    }
    // e
    {
        bool t = true;
        int flower = cards[0] / 13;
        for (int i = 0; i < COUNT; ++i) {
            if (cards[i] / 13 != flower) {
                t = false;
                break;
            }
        }
        if (t) return 'e';
    }
    // d, c
    {
        for (int i = 0; i < COUNT; ++i) {
            int count = 0;
            for (int j = 0; j < COUNT; ++j) {
                if (i != j && cards[i] % 13 == cards[j] % 13)
                    count++;
            }
            if (count == 3) {
                return 'd';
            }
            if (count == 2) {
                return 'c';
            }
        }
    }
    // b, a
    {
        int dou = 0;
        for (int i = 0; i < COUNT; ++i) {
            int count = 0;
            for (int j = 0; j < COUNT; ++j) {
                if (i != j && cards[i] % 13 == cards[j] % 13)
                    count++;
            }
            if (count == 1) {
                dou++;
            }
        }
        if (dou == 2) {
            return 'a';
        } else if (dou == 4) {
            return 'b';
        }
    }
    return '0';
}

void printDeck(int deck[CARDS]) {
    for (int i = 0; i < CARDS; ++i) {
        if (i % 13 == 0 && i != 0)
            printf("\n");
        printf("%d:%d ", i, deck[i]);
    }
}


