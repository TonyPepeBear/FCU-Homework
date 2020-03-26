#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    char s[20];
    scanf("%s", s);
    char *c = strtok(s, "(");
    c = strtok(c, ")");
    int front = 0;
    for (int i = 0; i < 3; ++i) {
        int t = 1;
        for (int j = 0; j < i; ++j) {
            t *= 10;
        }
        front += (c[2 - i] - '0') * t;
    }
    int a = atoi(c);
    printf("%d\n", a);
    c = strtok(NULL, "-");
    long num = 0;
    for (int i = 0; i < 3; ++i) {
        int t = 1;
        for (int j = 0; j < i + 4; ++j) {
            t *= 10;
        }
        num += (c[2 - i] - '0') * t;
    }
    c = strtok(NULL, "");
    for (int i = 0; i < 4; ++i) {
        int t = 1;
        for (int j = 0; j < i; ++j) {
            t *= 10;
        }
        num += (c[3 - i] - '0') * t;
    }

    printf("%ld", num);

    return 0;
}


// "(123)456-7890"