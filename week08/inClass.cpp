#include <iostream>
#include <functional>

void print() {
    std::cout << "Heelo!";
}

using pointerToFunction_t = void(*)();

struct PrintStruct {

    void operator()() {
        std::cout << "Hello, World"; 
    }
};

class LambdaFunction {
    int number;
    public:
    LambdaFunction() {
        
    }

    void operator()() {

    }
};

template<typename T>
void map(T * arr, size_t SIZE, std::function<T(T)> func) {
    for(size_t i = 0; i < SIZE; i++) {
        arr[i] = func(arr[i]);
    }
}

template<typename T>
T* filter(T* arr, const size_t SIZE, std::function<bool(T)> func, size_t & resultSize) {
    T * result = new T[SIZE];
    resultSize = 0;
    for(size_t i = 0; i < SIZE; i++) {
        if(func(arr[i])) {
            result[resultSize] = arr[i];
            resultSize++;
        }
    }

    return result;
}

int main() {
    const size_t SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4};

    map<int>(arr, SIZE, [](int x) -> int { return 2 * x; } );
    size_t resultArraySize;
    int * resultArray = 
    filter<int>(arr, SIZE, [](int number) -> bool {return number % 2 == 0; }, resultArraySize);
    
}