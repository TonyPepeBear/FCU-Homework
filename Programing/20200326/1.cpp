#include <cstdio>
#include <cstring>

int main() {
    char str[5][20], find[] = {"tion"};
    for (int i = 0; i < 5; ++i) {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < 5; ++i) {
        int len = strlen(str[i]);
        bool f = true;
        for (int j = 0; j < 4; ++j) {
            if (str[i][len - j - 1] != find[4 - j - 1]) {
                f = false;
            }
        }
        if (f) {
            printf("%s\n", str[i]);
        }
    }
    char *x = strstr(str[0], "tion");
    printf("%ld", x - str[0]);
    return 0;
}
