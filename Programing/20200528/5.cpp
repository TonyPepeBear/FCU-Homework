#include <cstdio>

#define SUMMARY(arr, size) ({ \
    int sum = 0; \
    for(int i = 0; i < size; i++)  \
        sum+= arr[i]; \
    sum; \
})

int main() {
    int integers[] = {1, 2, 3, 4, 5};
    printf("%d\n", SUMMARY(integers, 5));
}

