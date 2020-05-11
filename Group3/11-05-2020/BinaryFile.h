#pragma once
#include <cstring>
#include "File.h"
class BinaryFile : public File {
    bool hasCR;
    char * creator;
public:
    BinaryFile(const char * name, bool hasCR, const char * creator):File(name) {
        std::cout << "BinaryFile constructed\n";

        this->creator = new char[strlen(creator)+1];
        strcpy(this->creator, creator);

        this->hasCR = hasCR;
    }
    void printHello() override {
        std::cout << "Hello Binary\n";
    }
    ~BinaryFile() {
        std::cout << "BinaryFile destructed\n";
        delete[] creator;
    }
};