#pragma once
class TextFile : public File {
    int length;
    char * owner;
public:
    TextFile(const char * name, int length = 0, const char * owner = ""):File(name) {
        std::cout << "TextFile constructed\n";
        this->owner = new char[strlen(owner)+1];
        strcpy(this->owner, owner);
        this->length = length;
    }
    ~TextFile() {
        std::cout << "TextFile " << this->getName() << " destructed\n";

    }
};
