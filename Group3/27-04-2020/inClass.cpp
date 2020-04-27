#include <iostream>
#include <functional>
#include <vector>
#include "User.h"
#include "SocialNetwork.h"

void printHello() {
    std::cout << "Hello\n";
}

int sum(int a, int b) {
    return a+b;
}

using printHello_Type = void(*)(); 
using sum_Type = int(*)(int, int);

void callFunction(sum_Type functionToCall, int n, int m) {
    std::cout << "Calling funcion\n";
    functionToCall(n, m);
    std::cout << "Function has been called\n";
}

class Traicho {
    int number;
public:
    void operator()() {
        number++;
    }

    Traicho(int number) {
        this->number = number;
    }
};

struct Person {
    int age;
    int height;
    Person(int age, int height) {
        this->age = age;
        this->height = height;
    }
};

int main() {
    int number = 0, n;

    std::function<void()> lambda = [&number]() mutable { number++; };

    lambda();
    lambda();
    lambda();

    std::cout << number << std::endl;

    User traicho("mitaka", "password","ASD@ASD.ASD", 20, true ,"ASDSADASD", "ADDRESS");
    User petka("petka", "password", "ASD@ASD.ASD", 22, false ,"ASDSADASD", "ADDRESS");

    SocialNetwork sn;
    sn.addUser(traicho).addUser(petka);

    std::function<void(User &)> changeUsers = [](User & user){
                                                    if(user.getGender()) {
                                                        user.setAge(user.getAge() + 5);
                                                    }
                                                };

    sn.alterCertainUsers(changeUsers);

    std::function<bool(const User &)> filter = [](const User & user) { return user.getGender(); };
    std::function<void(User &)> alter = [](User & user) { user.setAge(user.getAge() + 5); };

    sn.alterCertainUsers(filter, alter);
    
    
    std::function<int()> interestingLambda = [i = 0, j = 1]() mutable {
                                                int sum = i + j;
                                                i = j;
                                                j = sum;
                                                return i;
                                            };

    std::cout << "First call: " << interestingLambda() << std::endl;
    std::cout << "Second call: " << interestingLambda() << std::endl;
    std::cout << "Third call: " << interestingLambda() << std::endl;
    std::cout << "Fourth call: " << interestingLambda() << std::endl;
    std::cout << "Fifth call: " << interestingLambda() << std::endl;
    std::cout << "Sixth call: " << interestingLambda() << std::endl;
    std::cout << "Seventh call: " << interestingLambda() << std::endl;
}