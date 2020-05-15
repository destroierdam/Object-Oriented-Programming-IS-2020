#pragma once
#include <iostream>

class Base {
private:
    // vptr * vtablePointer;
public:
    virtual void func1() {
        std::cout << "Base::func1()\n";
    }
    virtual void func2() {
        std::cout << "Base::func2()\n";
    }
};

class Derived : public Base {
public:
    void func1() {
        std::cout << "Derived::func1()\n";
    }
};