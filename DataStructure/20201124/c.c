#include <stdio.h>

#define N 10000

void print(int *arr, int size) {
    int f = 1;
    for (int i = 0; i < size; ++i) {
        if (!f) { printf(" "); }
        f = 0;
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[N];
    int n = 0, x = 0;
    while (scanf("%d", &x) != EOF) {
        arr[n++] = x;
    }

    int heap[N];
    heap[0] = arr[0];

    for (int i = 1; i < n; ++i) {
        heap[i] = arr[i];

        int y = i;
        while (heap[y] > heap[(y - 1) / 2]) {
            int t = heap[y];
            heap[y] = heap[(y - 1) / 2];
            heap[(y - 1) / 2] = t;
            if (y == 0) break;
            y = (y - 1) / 2;
        }
    }

    print(heap, n);

    int m = n, f = 1;
    while (m > 0) {
        if (!f) { printf(" "); }
        f = 0;
        printf("%d", heap[0]);
        heap[0] = heap[m - 1];
        int i = 0;
        while (2 * i + 2 < m && (heap[i] < heap[2 * i + 1] || heap[i] < heap[2 * i + 2])) {
            if (heap[2 * i + 2] < heap[2 * i + 1]) {
                int t = heap[i];
                heap[i] = heap[2 * i + 1];
                heap[2 * i + 1] = t;
                i = 2 * i + 1;
            } else {
                int t = heap[i];
                heap[i] = heap[2 * i + 2];
                heap[2 * i + 2] = t;
                i = 2 * i + 2;
            }
        }
        m--;
    }

    return 0;
}
