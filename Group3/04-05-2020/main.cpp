#include <iostream>
#include <vector>

class Animal {
private:
    bool hasFur;
    bool laysEggs;
    std::string name;
public:
    void setHasFur(bool fur) {
        this->hasFur = fur;
    }
    virtual void eat() = 0;

    virtual void greet() const {
        std::cout << "My name is " << this->name;
    }
    bool getHasFur() {
        return this->hasFur;
    }
};

class Cat : public Animal {
    int lives;
public:
    void setHasFur(bool fur) {
        this->setHasFur(fur);
    }
    void eat() override {
        std::cout << "Cat eating...\n";
    }
    void greet() const override {
        Animal::greet();
        std::cout << "I have " << this->lives << " lives left\n";
    }
};









class Employable {
public:
    virtual void work() = 0;
};

class Person : public Employable {
    int salary;
protected:
    std::string name;
public:
    void setName(std::string newName) {
        this->name = newName;
    }
    void work() override {

    }
};

class Dog : public Employable {
    void work() override {

    }
};

class Company {
    std::vector<Employable*> employees;
public:
    void work() {
        for(size_t i = 0; i < employees.size(); i++) {
            employees[i]->work();
        }
    }
    Company& addEmployee(Employable * newEmployee) {
        this->employees.push_back(newEmployee);
        return *this;
    }
};

int main() {
    while(true) {
        std::string command;
        std::cin >> command;

        if (command == "open") {
            std::string fileName;
            std::cin >> fileName;
            std::cout << "Opening file " << fileName;
        } else if (command == "close") {
            std::cout << "closing file";
        }
    }
    return 0;
}
