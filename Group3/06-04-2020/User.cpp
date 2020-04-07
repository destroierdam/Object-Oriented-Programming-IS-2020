#include "User.h"
#include <cstring>

void User::erase() {
	delete[] this->username;
	delete[] this->password;
	delete[] this->email;
}

void User::copy(const User& other) {
	this->username = new char[strlen(other.username) + 1];
	strcpy_s(this->username, strlen(other.username) + 1, other.username);
	
	this->password = new char[strlen(other.password) + 1];
	strcpy_s(this->password, strlen(other.password) + 1, other.password);

	this->email = new char[strlen(other.email) + 1];
	strcpy_s(this->email, strlen(other.email) + 1, other.email);

	this->age = other.age;
}

User::User() {
	this->username = new char[1];
	// strcpy(this->username, "");
	this->username[0] = '\0';

	this->password = new char[1];
	this->password[0] = '\0';

	this->email = new char[1];
	this->email = '\0';

	this->age = 0;
}

User::User(const char* username, const char* password, const char* email, int age) {
	this->username = new char[strlen(username) + 1];
	strcpy_s(this->username, strlen(username) + 1, username);

	this->password = new char[strlen(password) + 1];
	strcpy_s(this->password, strlen(password) + 1, password);

	this->email = new char[strlen(email) + 1];
	strcpy_s(this->email, strlen(email) + 1, email);

	this->age = age;
}

User::User(const User& other) {
	this->copy(other);
}

User& User::operator=(const User& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

User::~User() {
	this->erase();
}