#pragma once

class File {
    char * name;
public:
    File() {
        std::cout << "File constructed\n";
    }
    File(const char * name) {
        std::cout << "File constructed\n";
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    virtual void printHello() {
        std::cout << "Hello File\n";
    }
    const char * getName() const {
        return this->name;
    }
    virtual ~File() {
        std::cout << "File " << this->name << "  destructed\n";
    }
};
