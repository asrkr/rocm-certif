#include <iostream>

int main() {
    std::size_t n = 10;
    int* arr = new int[n];
    for (size_t i = 0; i < n; i++) {
        arr[i] = static_cast<int>(i * i);
        std::cout << "Case " << i << " : " << arr[i] << "\n";
    }
    delete[] arr;
    return 0;
}