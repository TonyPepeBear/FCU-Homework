#include <cstdio>

int move = 0;

void hanoi(int n, char start, char reg, char des) {
    if (n > 0) {
        hanoi(n - 1, start, des, reg);
        move++;
        printf("%d:%d %c %c\n", move, n, start, des);
        hanoi(n - 1, reg, start, des);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int counter = 0;
    hanoi(n, 'a', 'b', 'c');
    return 0;
}
