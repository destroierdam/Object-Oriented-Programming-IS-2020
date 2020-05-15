#pragma once
#include <vector>
#include "File.h"

class Folder : public File {
    std::vector<File*> files;
public:
    Folder(const char * fileName):File(fileName) {} 

    Folder& addFile(File * newFile) {
        this->files.push_back(newFile);
        return *this;
    }
    ~Folder() {
        for(size_t i = 0; i < this->files.size(); i++) {
            delete this->files[i];
        }
    }
};