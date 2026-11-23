#include <stdio.h>

void swap(int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int main(void) {
    int x = 5;
    int y = 7;
    printf("Valeur de x : %d\n", x);
    printf("Valeur de y : %d\n", y);
    swap(&x, &y);
    printf("Swap effectué.\n");
    printf("Valeur de x : %d\n", x);
    printf("Valeur de y : %d\n", y);
    return 0;
}