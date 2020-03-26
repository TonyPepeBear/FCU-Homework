#include <cstdio>
#include <cstring>

int main() {
    char str[5][20];
    for (int i = 0; i < 5; ++i) {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < 5; ++i) {
        int len = strlen(str[i]);
        char *c = strstr(str[i], "tion");
        if (c - str[i] == len - 4) {
            printf("%s\n", str[i]);
        }
    }
    return 0;
}

