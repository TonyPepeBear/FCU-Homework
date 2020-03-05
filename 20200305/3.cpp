#include <cstdio>

#define SIZE 5

void printArray(const int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int a[SIZE] = {1, 3, 5, 7, 9};
    printArray(a, SIZE);
    return 0;
}
