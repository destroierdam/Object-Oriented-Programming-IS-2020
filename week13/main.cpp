#include <iostream>
#include <climits>
#include <cstring>

class Array {
    int * data;
    size_t size;
public:
    Array(size_t size) {
        std::cout << "Constructed size: " << size << "\n";
        this->data = new int[size];
        this->size = size;
    }
    int getData(size_t index) const {
        if(index < size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Out of range");
        }
    }
    ~Array() {
        std::cout << "Destructed size: " << this->size <<  "\n";
        delete[] this->data;
    }
};
int main() {

    try {
        Array arr(3);
        Array arr2(100);
        Array arr3(200);

        arr.getData(-5);
    } catch(std::out_of_range &ex) {
        std::cerr << ex.what() << "\n";
    } catch(...) {
        std::cerr << "Random exception thrown\n";
    }
    std::cout << "Continuing...\n";

    return 0;
}
