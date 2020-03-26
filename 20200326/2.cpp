#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    char str[100];
    int count[26] = {0};
    gets(str);
    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        str[i] = tolower(str[i]);
        char c = str[i] - 'a';
        if (c > -1 && c < 26) {
            count[c]++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        printf("%c show %d time(s).\n", i + 'a', count[i]);
    }
    return 0;
}
