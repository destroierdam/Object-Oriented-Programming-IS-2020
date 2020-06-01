#include <iostream>
#include "Vector.h"
int main() {

    Vector<int> traicho;
    traicho.pushBack(12);
    traicho.pushBack(420);

    for(size_t i = 0; i < traicho.getSize(); i++) {
        std::cout << traicho[i] << " ";
    }

    std::cout << '\n';

    

    for(VectorIterator<int> traichoIterator = traicho.begin(); traichoIterator != traicho.end(); ++traichoIterator) {
        std::cout << *traichoIterator << " ";
    }
    std::cout << '\n';

    for(int x : traicho) {
        std::cout << x << " ";
    }

    std::cout << '\n';
    return 0;
}
