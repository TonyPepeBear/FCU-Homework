#include <cstdio>

int main() {
    char chars[21];
    scanf(" %s", chars);
    char target = 0;
    scanf(" %c", &target);
    int count = 0;
    for (int i = 0; i < 20; ++i) {
        if (chars[i] == target) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
