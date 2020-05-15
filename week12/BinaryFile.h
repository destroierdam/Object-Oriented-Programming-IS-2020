#pragma once
#include "File.h"

class BinaryFile : public File {
    bool hasCR;
public:
    BinaryFile(const char * filename, bool hasCR):File(filename) {
        std::cout << "Constructing BinaryFile " << filename << std::endl;
        this->hasCR = hasCR;
    }
    void printHello() {
        std::cout << "Hello BinaryFile\n";
    }
    ~BinaryFile() {
        std::cout << "Destructing BinaryFile " << this->getFileName() << std::endl;
    }
};
