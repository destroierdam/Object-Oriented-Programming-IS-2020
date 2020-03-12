#include<iostream>
#include <cmath>
using std::cin;
using std::cout;
/*
struct Point {
    double x;
    double y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
*/

class Point {
public:
    double x;
    double y;

    double distance(Point other) {
        return sqrt((this->x - other.x) * (this->x - other.x) + 
                    (this->y - other.y) * (this->y - other.y));
    }
};

class Date {
public:
    int day;
    int month;
    int year;

    bool isAfter(Date other) {
        if(this->year > other.year) {
            return true;
        }
        if(this->year < other.year) {
            return false;
        }
        if(this->month > other.month) {
            return true;
        }
        if(this->month < other.month) {
            return false;
        }
        if(this->day > other.day) {
            return true;
        }
        if(this->day < other.day) {
            return false;
        }
        return true;
    }

    long long differenceInDays(Date other) {
        long long int thisInDays = this->year*365 + this->month*30 + this->day;
        long long int otherInDays = other.year*365 + other.month*30 + other.day;
        return abs(thisInDays - otherInDays);
        //if(this->isAfter(other)) {
            // result += this->day - other.day;
            // result += (this->month - other.month)*30; // NUMBER of days in a month
            // result += (this->year - other.month)*365;
        //}
    }
};

class DynArray {
public:
    int * data;
    size_t size, capacity;

    void resize() {
        this->capacity *= 2;
        int * oldData = this->data;
        this->data = new int[this->capacity];
        for(size_t i = 0; i < this->size; i++) {
            this->data[i] = oldData[i];
        }
        delete[] oldData;
    }
    void initialize() {
        this->capacity = 8;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    void addToEnd(int newElement) {
        if(this->size == this->capacity) {
            resize();
        }
        this->data[this->size] = newElement;
        this->size++;
    }

    bool hasElem(int element) {
        for(size_t i = 0; i < this->size; i++) {
            if(this->data[i] == element) {
                return true;
            }
        }
        return false;
    }
x
    bool isEmpty() {
        return this->size == 0;
    }

    void deititialize() {
        delete[] this->data;
    }
};

int main() {
    DynArray array;
    array.initialize();

    array.addToEnd(12);

    for(size_t i = 0; i < array.size; i++) {
        cout << array.data[i] << " ";
    }
    cout << "\n";
    array.addToEnd(15);
    for(size_t i = 0; i < array.size; i++) {
        cout << array.data[i] << " ";
    }

    DynArray array2;
    array2 = array;

    array.deinitialize();
    cout << '\n';
}





