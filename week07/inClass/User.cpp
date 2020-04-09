#include "User.h"
#include <cstring>

void User::destroy() {
    delete[] this->username;
    delete[] this->password;
    // delete others
}

void User::copy(const user & other) {
    this->username = new char[strlen(other.username)+1];
    strcpy(this->username, other.username);

    this->password = new char[strlen(other.password)+1];
    strcpy(this->password, other.password);

    // ...
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

    // ...
}

User::User(const User & other) {
    this->copy(other);
}

User& User::operator=(const User & other) {
    if (*this != other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

User::~User() {
    this->destroy();
}

const char * User::getUsername() const;

void User::setUsername(const char * newUsername);

int User::getAge() const {
	return this->age;
}

void User::setAge(int newAge) {
	this->age = newAge;
}

bool User::operator<(const User & other) {
	return this->age < other.age;
}

std::ostream& operator<<(std::ostream& out, const User& object) {
	out << this->username << '\n' << this->password; // ...
	return out;
}




