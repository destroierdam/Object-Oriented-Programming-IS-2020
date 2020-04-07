#include "SocialNetwork.h"

void SocialNetwork::destroy() {
	delete[] this->users;
}

void SocialNetwork::copy(const SocialNetwork & other) {
	this->size = other.size;
	this->capacity = other.capacity;
	this->users = new User[this->capacity];
	
	for (size_t i = 0; i < this->size; i++) {
		this->users[i] = other.users[i];
	}
}

void SocialNetwork::resize() {
	this->capacity *= 2;
	User* newUsers = new User[this->capacity];
	for (size_t i = 0; i < this->size; i++) {
		newUsers[i] = this->users[i];
	}
	delete[] this->users;
	this->users = newUsers;
}

SocialNetwork::SocialNetwork() {
	this->size = 0;
	this->capacity = 42;
	this->users = new User[this->capacity];
}

SocialNetwork::SocialNetwork(const SocialNetwork& other) {
	this->copy(other);
}

SocialNetwork& SocialNetwork::operator=(const SocialNetwork& other) {
	if (this != &other) {
		this->destroy();
		this->copy(other);
	}
	return *this;
}

SocialNetwork::~SocialNetwork() {
	this->destroy();
}

SocialNetwork& SocialNetwork::addUser(const User& newUser) {
	if (size >= capacity) {
		resize();
	}
	this->users[this->size] = newUser;
	this->size++;

	return *this;
}