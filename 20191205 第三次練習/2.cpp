#include <cstdio>

#define SIZE 5

void sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min = arr[i], minIndex = -1;
        for (int j = i; j < size; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        if (minIndex != -1) {
            int temp = arr[i];
            arr[i] = min;
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
