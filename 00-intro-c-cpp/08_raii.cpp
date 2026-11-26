#include <cstddef>
#include <iostream>

class IntBuffer {
public:
    IntBuffer(std::size_t n) : n_(n) {
        // TODO : allouer n int avec new[] et ranger l'adresse dans data_
        data_ = new int[n];
    }

    ~IntBuffer() {
        // TODO : libérer la mémoire
        delete[] data_;
    }

    // Interdit la copie d'un IntBuffer
    IntBuffer(const IntBuffer&) = delete;
    IntBuffer& operator=(const IntBuffer&) = delete;

    std::size_t size() const { return n_; }
    int* data() { return data_; }

private:
    int* data_;
    std::size_t n_;
};

int main() {
    // TODO : créer un IntBuffer de 10 éléments
    IntBuffer b(10);
    // TODO : le remplir avec i * i en passant par data() et size()
    // TODO : afficher les valeurs
    for (std::size_t i = 0; i < b.size(); i++) {
        b.data()[i] = static_cast<int>(i * i);
        std::cout << "Case " << i << " : " << b.data()[i] << "\n";
    }
    // Pas de delete[] ici, c'est le rôle du destructeur
    return 0;
}