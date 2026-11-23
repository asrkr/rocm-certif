#include <stdio.h>

int main(void) {
    int arr[5] = {1, 5, 13, 19, 27};
    size_t n_arr = sizeof(arr) / sizeof(arr[0]);
    int* p = arr;
    printf("Tableau d'entiers :\n");
    for (size_t i = 0; i < n_arr; i++) {
        printf("i = %zu, &arr[i] = %p, arr[i] = %d, *(p + i) = %d\n", i, (void *)&arr[i], arr[i], *(p+i));
    }
    printf("Tableau de double :\n");
    double d[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
    size_t n_d = sizeof(d) / sizeof(d[0]);
    double* pd = d;
    for (size_t i = 0; i < n_d; i++) {
        printf("i = %zu, &d[i] = %p, d[i] = %f, *(pd + i) = %f\n", i, (void *)&d[i], d[i], *(pd + i));
    }
    printf("Taille du type int : %zu\n", sizeof(int));
    printf("Taille du type float : %zu\n", sizeof(float));
    printf("Taille du type double : %zu\n", sizeof(double));
    return 0;
}