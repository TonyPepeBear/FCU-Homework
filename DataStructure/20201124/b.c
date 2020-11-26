#include <stdio.h>

#define N 10000

int first = 1;

int search(const int *arr, int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

void printPostOrder(int *in, int *pre, int n) {
    int i = search(in, pre[0], n);

    if (i != 0) { printPostOrder(in, pre + 1, i); }
    if (i != n - 1) { printPostOrder(in + i + 1, pre + i + 1, n - i - 1); }
    if (!first) { printf(" "); }
    first = 0;
    printf("%d", pre[0]);
}

int main() {
    int nums[N];
    int n = 0, x = 0;
    while (scanf("%d", &x) != EOF) {
        nums[n++] = x;
    }
    printPostOrder(nums, nums + n / 2, n / 2);
    return 0;
}
