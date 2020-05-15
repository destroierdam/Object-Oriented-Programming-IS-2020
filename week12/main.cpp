#include <iostream>
#include <vector>

#include "File.h"
#include "Folder.h"
#include "TextFile.h"
#include "BinaryFile.h"

int main() {
    Folder geometry("geometry");
    TextFile * cheatSheet = new TextFile("traicho");
    geometry.addFile(cheatSheet);

    return 0;
}
