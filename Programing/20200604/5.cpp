#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    bool created[1000] = {false};
    int nums[10][100];
    int len[10] = {0};
    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        int ran = rand() % 1000;
        while (created[ran]) ran = rand() % 1000;
        created[ran] = true;
        nums[ran % 10][len[ran % 10]] = ran;
        len[ran % 10]++;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < len[i]; ++j) {
            for (int k = j + 1; k < len[i]; ++k) {
                if (nums[i][j] > nums[i][k]) {
                    int temp = nums[i][j];
                    nums[i][j] = nums[i][k];
                    nums[i][k] = temp;
                }
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("第%d群組<尾數 %d>：\n", i + 1, i);
        for (int j = 0; j < len[i]; ++j) {
            printf("%4d", nums[i][j]);
        }
        printf("\n");
    }
}
