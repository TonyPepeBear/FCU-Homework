#include <cstdio>

#define SIZE 5

void sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != -1) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[SIZE] = {0};
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
