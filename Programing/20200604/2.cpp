#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]) {
    int ans = 1;
    for (int i = 1; i < argc; ++i) {
        ans *= atoi(argv[i]);
    }
    printf("%d\n", ans);
    return 0;
}
