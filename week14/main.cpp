#include <iostream>
#include <iomanip>
#include <vector>
#include "Vector.h"

int main()
{

    std::cout << std::setfill('0') << std::setw(10);
    std::cout << 15.1 << std::endl;
    return 0;
    Vector<int> vec;

    vec.pushBack(5);
    vec.pushBack(13);

    for(Vector<int>::Iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    for(Vector<int>::Iterator it = vec.begin(); it != vec.end(); ++it) {
        (*it)++;
    }
    std::cout << std::endl;
    for(Vector<int>::Iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    
}
