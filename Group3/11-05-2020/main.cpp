#include <iostream>
#include <vector>
#include "File.h"
#include "BinaryFile.h"
#include "TextFile.h"
#include "Folder.h"

/*
class Base {
public:
    Function * VtablePointer
    virtual void func1() {
        std::cout << "Base::func1()\n";
    }
    virtual void func2() {
        std::cout << "Base::func2()\n";
    }
};
class Derived : public Base {
public:
Function * VtablePointer (inherited)
    void func1() override {
        std::cout << "Derived::func1()\n";
    }
};
*/


int main() {
    Folder * geometry = new Folder("GeometryFolder");
    geometry->addFile(new TextFile("Definitions"));
    geometry->addFile(new TextFile("Theorems"));

    Folder * FMI = new Folder("FMIFolder");
    FMI->addFile(geometry);

    delete FMI;
    return 0;
}
