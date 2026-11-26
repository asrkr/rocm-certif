#include <iostream>

void swap(int& ra, int& rb) {
    int tmp = ra;
    ra = rb;
    rb = tmp;
}

int main() {
    int x = 5;
    int y = 7;
    std::cout << "Valeur de x : " << x << "\n";
    std::cout << "Valeur de y : " << y << "\n";
    swap(x, y);
    std::cout << "Swap effectué\n";
    std::cout << "Valeur de x : " << x << "\n";
    std::cout << "Valeur de y : " << y << "\n";
    return 0;
}