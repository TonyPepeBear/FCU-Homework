#include <cstdio>

#define N 200

int main() {
    int count = 0;
    unsigned long long int num[N] = {0};
    bool read = true;
    while (read) {
        unsigned long long int x = 0;
        read = scanf("%llu", &x);
        if (read) {
            num[count] = x;
            count++;
        }
    }
    int ans = 0;
    for (int i = 0; i < count; ++i) {
        int t = 1;
        for (int j = i; j < count - 1; ++j) {
            if (num[j] < num[j + 1])
                t++;
            else
                break;
        }
        if (t > ans) ans = t;
    }
    if (count == 0) printf("0");
    printf("%d", ans);
    return 0;
}
