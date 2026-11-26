#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr(10);
    for (std::size_t i = 0; i < arr.size(); i++) {
        arr[i] = static_cast<int>(i * i);
    }
    std::cout << "Affichage du tableau : [ ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
    // Essai 1 : boucle par VALEUR -> x est une copie de chaque cas
    for (int x : arr) {
        x = 0;
    }
    std::cout << "Après la boucle par valeur : [";
    for (int x : arr) {
        std::cout << " " << x;
    }
    std::cout << " ]\n";
    // Essai 2 : boucle par référence -> x est un autre nom pour la même case
    for (int& x : arr) {
        x = 0;
    }
    std::cout << "Après la boucle par référence : [";
    for (int x : arr) {
        std::cout << " " << x;
    }
    std::cout << " ]\n";
    return 0;
}