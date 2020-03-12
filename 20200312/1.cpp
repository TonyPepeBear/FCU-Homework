#include<cstdio>
#include<cstdlib>
#include<ctime>

#define SUITS 4
#define FACES 13
#define CARDS 5
#define COUNT 5

void shuffle(unsigned int wDeck[][FACES]);

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[], int cards[COUNT][2]);

int check(int cards[5][2]);

int main() {
    srand(time(NULL));
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {
            "Ace", "Deuce", "Three", "Four",
            "Five", "Six", "Seven", "Eight",
            "Nine", "Ten", "Jack", "Queen", "King"
    };
    unsigned int deck[SUITS][FACES] = {0};
    shuffle(deck);
    int cards[COUNT][2];
    int cards2[COUNT][2];

    printf("a's cards: \n");
    deal(deck, face, suit, cards); // deal into cards
    int a = check(cards);
    printf("\n\n");

    printf("b's cards: \n");
    shuffle(deck);
    deal(deck, face, suit, cards2); // deal into cards
    int b = check(cards2);
    printf("\n\n");

    if (a > b) printf("a win\n");
    else if (a < b) printf("b win\n");
    else printf("same\n");
}

int check(int cards[5][2]) {
    int ans = 0;
    // e
    {
        int suit = cards[0][0];
        bool f = true;
        for (int i = 1; i < COUNT; ++i) {
            if (cards[i][0] != suit) {
                f = false;
            }
        }
        if (f) {
            printf("同花\n");
            ans += 10;
        }
    }
    //f
    {
        int s[COUNT] = {0};
        for (int i = 0; i < COUNT; ++i) {
            s[i] = cards[i][1];
        }
        // sort s[]
        for (int i = 0; i < COUNT; ++i) {
            for (int j = 0; j < COUNT; ++j) {
                if (s[j] > s[i]) {
                    int temp = s[j];
                    s[j] = s[i];
                    s[i] = temp;
                }
            }
        }
        // check if s[] is continue
        bool f = true;
        for (int i = 1; i < COUNT; ++i) {
            if (s[0] + i != s[i]) {
                f = false;
            }
        }
        if (f) {
            printf("順子\n");
            ans += 9;
        }
    }
    // a, b, c, d
    {
        int _double = 0;
        for (int i = 0; i < COUNT; ++i) {
            int count = 0;
            for (int j = 0; j < COUNT; ++j) {
                if (cards[i][1] == cards[j][1] && i != j) {
                    count++;
                }
            }
            if (count == 1) {
                _double++;
            } else if (count == 2) {
                printf("三條\n");
                ans += 7;
                return ans;
            } else if (count == 3) {
                printf("鐵支\n");
                ans += 8;
                return ans;
            }
        }
        if (_double == 2) {
            printf("對子\n");
            ans += 5;
            return ans;
        } else if (_double == 4) {
            printf("雙對子\n");
            ans += 6;
            return ans;
        }
    }
    if (ans == 0) printf("nothing\n");
    return ans;
}

void shuffle(unsigned int wDeck[][FACES]) {
    size_t row;
    size_t column;
    size_t card;

    for (int i = 0; i < SUITS; ++i) {
        for (int j = 0; j < FACES; ++j) {
            wDeck[i][j] = 0;
        }
    }

    for (card = 1; card <= CARDS; card++) {
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
}

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[], int cards[COUNT][2]) {
    size_t row;
    size_t column;
    size_t card;
    for (card = 1; card <= CARDS; card++) {
        for (row = 0; row < SUITS; row++) {
            for (column = 0; column < FACES; column++) {
                if (wDeck[row][column] == card) {
                    printf("%s of %s\n", wFace[column], wSuit[row]);
                    // cards[][0] put suit
                    // cards[][1] put face
                    cards[card - 1][0] = row;
                    cards[card - 1][1] = column;
                }
            }
        }
    }
}

