#pragma once
#include <vector>
class Folder : public File {
private:
    std::vector<File*> files;
public:
    Folder(const char * name):File(name) {
        std::cout << "Folder constructed\n";
    }
    Folder& addFile(File * newFile) {
        this->files.push_back(newFile);
        return *this;
    }
    ~Folder() {
        std::cout << "Folder " << this->getName() << " destructed\n";
        for(size_t i = 0; i < this->files.size(); i++) {
            delete this->files[i];
        }
    }
};