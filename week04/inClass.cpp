#include<iostream>
using std::cin;
using std::cout;

template<typename T>
T min(T number1, T number2) {
    if(number1 < number2) {
        return number1;
    }
    return number2;
}

template<class T>
void swap(T & arg1, T & arg2) {
    T temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

template<typename T, size_t SIZE>
void printArray(T (&arr)[SIZE]) {
    for(size_t i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
}















void print(int * arr, size_t SIZE) {
    for(size_t i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
}

int sum(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

using ptrFunction_t = int(*)(int, int);




template<typename T>
using mapFuncArg_t = T (*)(T);

template<typename T>
T * map(T * arr, size_t SIZE, mapFuncArg_t<T> mutatingFunc) {
    T * resultArr = new T[SIZE];

    for(size_t i = 0; i < SIZE; i++) {
        resultArr[i] = mutatingFunc(arr[i]);
    }
    return resultArr;
}

bool isEven(int n) {
    return n % 2 == 0;
}

int * filter(int * arr, size_t SIZE, bool (*filteringFunc)(int), size_t & resultSize) {
    int * result = new int[SIZE];
    resultSize = 0;

    for(size_t i = 0; i < SIZE; i++) {
        if(filteringFunc(arr[i])) {
            result[resultSize] = arr[i];
            resultSize++;
        }
    }
    return result;
}

int multiplyBy3(int number) {
    return number * 3;
}

template<typename T>
T multiplyBy2(T number) {
    return number * 2;
}

double multiplyBy3AndAHalf(int number) {
    return number * 3.5;
}

int multiplyBy10(double number) {
    return number * 10;
}


char fromAsciiCode(int n) {
    return (char)n;
}

template<typename P, typename T>
using PToTFuncPtr_t = T(*)(P);

template<typename T1, typename T2, typename T3>
T3 composition(T1 param, PToTFuncPtr_t<T2, T3> f, PToTFuncPtr_t<T1, T2> g) {
    return f(g(param));
}

int main() {
    
    int arg = 10;
    PToTFuncPtr_t functions[] = {multiplyBy2, multiplyBy3, multiplyBy10};
    PToTFuncPtr_t resultFunc = maximizing(arg, functions, 3);

    cout << '\n';
}
