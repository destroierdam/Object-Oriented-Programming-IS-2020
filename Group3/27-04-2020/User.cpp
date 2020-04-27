#include "User.h"
#include <cstring>

void User::destroy() {
    delete[] this->username;
    delete[] this->password;
    delete[] this->email;
    delete[] this->birthplace;
    delete[] this->address;
}

void User::copy(const User & other) {
    this->username = new char[strlen(other.username)+1];
    strcpy(this->username, other.username);

    this->password = new char[strlen(other.password)+1];
    strcpy(this->password, other.password);

    this->age = other.age;

    this->gender = other.gender;

    this->email = new char[strlen(other.email)+1];
    strcpy(this->email, other.email);
    
    this->birthplace = new char[strlen(other.birthplace)+1];
    strcpy(this->birthplace, other.birthplace);
    
    this->address = new char[strlen(other.address)+1];
    strcpy(this->address, other.address);
}

User::User() {
    username = nullptr;
    password = nullptr;
    email = nullptr;
    birthplace = nullptr;
    address = nullptr; 
}

User::User(const char * username, const char * password, const char * email, int age, bool gender, const char * birthplace, const char * address) {
    this->username = new char[strlen(username)+1];
    strcpy(this->username, username);

    this->password = new char[strlen(password)+1];
    strcpy(this->password, password);

    this->age = age;

    this->gender = gender;

    this->email = new char[strlen(email)+1];
    strcpy(this->email, email);
    
    this->birthplace = new char[strlen(birthplace)+1];
    strcpy(this->birthplace, birthplace);
    
    this->address = new char[strlen(address)+1];
    strcpy(this->address, address);
}

User::User(const User & other) {
    this->copy(other);
}

User& User::operator=(const User & other) {
    if (this != &other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

User::~User() {
    this->destroy();
}

const char * User::getUsername() const {
    return this->username;
}

void User::setUsername(const char * newUsername) {
    delete[] this->username;

    this->username = new char[strlen(newUsername)+1];
    strcpy(this->username, newUsername);
}

int User::getAge() const {
	return this->age;
}

void User::setAge(int newAge) {
	this->age = newAge;
}

bool User::getGender() const {
    return this->gender;
}

bool User::operator<(const User & other) {
	return this->age < other.age;
}

std::ostream& operator<<(std::ostream& out, const User& object) {
	out << object.username << '\n' 
        << object.password << '\n' 
        << object.email << '\n'
        << object.age << '\n'
        << object.gender << '\n'
        << object.birthplace << '\n'
        << object.address << '\n';
	return out;
}




