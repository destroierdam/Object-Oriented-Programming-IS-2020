#pragma once
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data;
    size_t size, capacity;
    void resize();
    void copy(const Vector<T>& other);
    void destroy();
public:
    Vector(size_t capacity = 8);
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);
    ~Vector();

    T& getElement(size_t index);
    T& operator[](size_t index);
    T operator[](size_t index) const; 

    size_t getSize() const;
    Vector<T>& pushBack(const T& newElement);
    T popBack();

    // void reserve();

    class Iterator {
        Vector<T>& vector;
        size_t position;
    public:
        Iterator(Vector<T>& vector, size_t position):vector(vector) {
            this->position = position;
        }
        Iterator(const Iterator& other) = default;
        Iterator& operator=(const Iterator& other) = default;

        bool operator!=(const Iterator& other) {
            if(&(this->vector) != &(other.vector)) {
                return false;
            }
            return this->position != other.position;
        };

        Iterator& operator++() {
            this->position++;
            return *this;
        }
        Iterator& operator++(int) {
            this->position++;
            return *this;
        }

        T& operator*();
    };

    Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, this->size);
    }
};

/*
template<typename T>
class Iterator {
    Vector<T>& vector;
    size_t position;
public:
    Iterator(Vector<T>& vector, size_t position) {
        this->vector = vector;
        this->position = position;
    }
    Iterator(const Iterator& other) = default;
    Iterator& operator=(const Iterator& other) = default;
};
*/

template<typename T>
void Vector<T>::resize() {
    this->capacity *= 2;
    T * newData = new T[this->capacity];
    for(size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
}

template<typename T>
void Vector<T>::copy(const Vector<T>& other){
    this->data = new T[other.capacity];
    this->size = other.size;
    this->capacity = other.capacity;

    for(size_t  i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

template<typename T>
void Vector<T>::destroy() {
    delete[] this->data;
}

template<typename T>
Vector<T>::Vector(size_t capacity) {
    this->capacity = capacity;
    this->data = new T[capacity];
    this->size = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
    this->copy(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if(this != &other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    this->destroy();
}

template<typename T>
T& Vector<T>::getElement(size_t index) {
    if (index >= this->size) {
        throw std::out_of_range("Vector index out of bounds");
    }
    return this->data[index]; 
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= this->size) {
        throw std::out_of_range("Vector index out of bounds");
    }
    return this->data[index]; 
}

template<typename T>
T Vector<T>::operator[](size_t index) const {
    // return getElement(index);
    if (index >= this->size) {
        throw std::out_of_range("Vector index out of bounds");
    }
    return this->data[index]; 
}


template<typename T>
size_t Vector<T>::getSize() const {
    return this->size;
}

template<typename T>
Vector<T>& Vector<T>::pushBack(const T& newElement) {
    if(size == capacity) {
        resize();
    }
    this->data[size++] = newElement;
    //this->size++;
    return *this;
}

template<typename T>
T Vector<T>::popBack() {
    if(this->size == 0) {
        throw std::logic_error("Removing element from empty vector");
    }
    // this->size--;
    return this->data[--size];
}

template<typename T>
T& Vector<T>::Iterator::operator*() {
    return vector[position];
}