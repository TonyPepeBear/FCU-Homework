#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int low, int high);

void merge(int *arr, int low, int mid, int high);

void insertionSort(int *arr, int low, int high);

int main() {
    int n = 0;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    int f = 1;
    for (int i = 0; i < n; ++i) {
        printf("%s%d", f == 1 ? "" : " ", arr[i]);
        f = 0;
    }
    return 0;
}

void mergeSort(int *arr, int low, int high) {
    if (high - low > 10) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    } else {
        insertionSort(arr, low, high);
    }
}

void merge(int *arr, int low, int mid, int high) {
    int xSize = mid - low + 1;
    int ySize = high - (mid + 1) + 1;
    int *x = malloc(sizeof(int) * xSize);
    int *y = malloc(sizeof(int) * ySize);
    for (int i = low, n = 0; i < mid + 1; ++i, n++) {
        x[n] = arr[i];
    }
    for (int i = mid + 1, n = 0; i < high + 1; ++i, n++) {
        y[n] = arr[i];
    }
    int i = 0, j = 0, k = low;
    while (i < xSize && j < ySize) {
        arr[k++] = x[i] <= y[j] ? x[i++] : y[j++];
    }
    while (i < xSize) {
        arr[k++] = x[i++];
    }
    while (j < ySize) {
        arr[k++] = y[j++];
    }
}

void insertionSort(int *arr, int low, int high) {
    for (int i = low + 1; i < high + 1; i++) {
        int t = arr[i];
        int j = i - 1;
        while (t < arr[j] && j >= low) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = t;
    }
}
