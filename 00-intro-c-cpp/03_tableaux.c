#include <stdio.h>

int main(void) {
    int arr[5] = {1, 5, 13, 19, 27};
    int* p = arr;
    for (int i = 0; i < 5; i++) {
        printf("i = %d, &arr[i] = %p, arr[i] = %d, *(p + i) = %d\n", i, (void *)&arr[i], arr[i], *(p+i));
    }
    return 0;
}