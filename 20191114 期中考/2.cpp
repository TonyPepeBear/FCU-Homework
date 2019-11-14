#include <stdio.h>

int main() {
    int max = 0, now = 0;
    scanf("%d%d", &max, &now);
    if (now > max) {
        max = now;
        printf("目前是最高降雨量\n");
    }
    printf("最高降雨量：%d 目前降雨量：%d\n", max, now);
    return 0;
}
