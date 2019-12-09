#include <cstdio>

#define SIZE 5

int linearSearch(int arr[], int key, int size, int index) {
    if (index == size) return -1;
    if (arr[index] == key) return index;
    return linearSearch(arr, key, size, index + 1);
}

int main() {
    int arr[SIZE] = {0}, key = 0;
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &key);
    printf("%d", linearSearch(arr, key, SIZE, 0));
    return 0;
}
