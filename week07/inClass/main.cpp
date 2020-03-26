#include <iostream>
#include "User.h"
// #include "SocialNetwork.h"
using namespace std;

int main() {
    User traicho, kircho;


    User pencho = traicho;
    
    kircho = traicho = pencho; 
}
