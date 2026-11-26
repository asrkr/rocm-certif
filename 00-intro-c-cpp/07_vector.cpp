#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr(10);
    for (std::size_t i = 0; i < arr.size(); i++) {
        arr[i] = static_cast<int>(i * i);
    }
    for (int x : arr) {
        std::cout << x << "\n";
    }
    return 0;
}