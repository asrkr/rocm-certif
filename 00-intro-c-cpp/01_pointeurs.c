#include <stdio.h>

int main(void) {
    int x = 5;
    int* p = &x;
    printf("Valeur de x : %d\n", x);
    printf("Adresse de x : %p\n", (void *)&x);
    printf("Valeur de p : %p\n", (void *)p);
    printf("Valeur de *p : %d\n", *p);
    printf("Adresse de p : %p\n", (void *)&p);
    // Modification de x en passant par son pointeur
    *p = 8;
    printf("Valeur de x : %d\n", x);
    return 0;
}