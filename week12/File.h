#pragma once
#include <iostream>
#include <cstring>
class File {
private:
    char * filename;
public:
    File(const char * filename) {
        std::cout << "Constructing File " << filename << std::endl;
        this->filename = new char [strlen(filename)+1];
        strcpy(this->filename, filename);
    }
    const char * getFileName() const {
        return this->filename;
    }
    virtual void printHello() {
        std::cout << "Hello File\n";
    }
    virtual ~File() {
        std::cout << "Destructing File " << filename << std::endl;
        delete[] this->filename;
    }
};