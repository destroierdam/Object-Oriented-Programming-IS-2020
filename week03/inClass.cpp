#include <iostream>
using std::cin;
using std::cout;
/*
Напишете функция, която по подадено число N заделя масив с N цели числа и връща указател към него.
*/
int* makeIntArr(int size) {
    // int * arr = new int[size];
    // return arr;
    return new int[size];
}
void testMakeIntArr() {
    int sizeOfArray;
    cin >> sizeOfArray;
    int * arr = makeIntArr(sizeOfArray);
    delete[] arr;
}

/*
Напишете функция, която прочита N на брой цели числа и връща указател към масив с числата.
*/
void readArr(int *& arr, int & size) {
    cin >> size;
    arr = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

/*
Направете структура, която да представя този масив.
*/
struct DynamicArray {
    int * data;
    int size;
};

/*
Напишете функция, която прочита динамичен масив
*/
void readArr(DynamicArray& dynArray) {
    cin >> dynArray.size;
    dynArray.data = new int[dynArray.size];
    for(int i = 0; i < dynArray.size; i++) {
        cin >> dynArray.data[i];
    }
}
void testReadArr() {
    DynamicArray dynarray;
    readArr(dynarray);
    delete[] dynarray.data;
}

/*
Напишете функция, която приема масив и връща друг масив, който е копие на подадения.
*/
void dynArrayCopy(DynamicArray& destination, const DynamicArray& source) {
    destination.size = source.size;
    destination.data = new int[destination.size];
    for(int i = 0; i < destination.size; i++) {
        destination.data[i] = source.data[i];
    }
    
    // memcpy(destination.data, source.data, sizeof(int)*source.size
}

int main()
{
    
}

