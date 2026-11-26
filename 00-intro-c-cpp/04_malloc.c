#include <stdlib.h>
#include <stdio.h>

int main(void) {
    size_t n = 10;
    int* arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        arr[i] = i * i;
    }
    for (size_t i = 0; i < n; i++) {
        printf("Case %zu : %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}