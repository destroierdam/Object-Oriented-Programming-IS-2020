#include <iostream>
#include <cstring>
#include "User.h"
#include "Pair.h"

using std::cin;
using std::cout;

int main() {
    User traicho;

    cout << traicho.getUsername();

    Pair<int, char> keyValuePair(1, 'A'); 

    Pair<int, char> newKeyValuePair = Pair<int, char>::makePair(2, 'B');
    return 0;
}

