#include <cstdio>
#include <cstdlib>

int main() {
    int size = 0;
    scanf("%d", &size);
    int *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = (int *) realloc(arr, size / 2 * sizeof(int));
    for (int i = 0; i < size / 2; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
