#pragma once
#include "File.h"
class TextFile : public File {
    int wordCount;
public: 
    TextFile(const char * fileName):File(fileName) {

    }
};