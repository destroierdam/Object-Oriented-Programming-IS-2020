#include "SocialNetwork.h"

void SocialNetwork::copy(const SocialNetwork& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->users = new User[this->capacity];
	
	for(size_t i = 0; i < this->size; i++) {
		this->users[i] = other.users[i];
	}
}

void destroy() {
	delete[] this->users;
}

void resize() {
	this->capacity *= 2;
	User * newBuffer = new User[this->capacity];
	for(size_t i = 0; i < this->size; i++) {
		newBuffer[i] = this->users[i];
	}
	
	delete[] this->users;
	
	this->users = newBuffer;
}

SocialNetwork::SocialNetwork() {
	this->capacity = 42;
	this->users = new User[this->capacity];
	this->size = 0;
}

SocialNetwork::SocialNetwork(const SocialNetwork& other) {
	this->copy(other);
}

SocialNetwork& SocialNetwork::operator=(const SocialNetwork& other) {
	if(this != &other) {
		this->destroy();
		this->copy(other);
	}
	
	return *this;
}

SocialNetwork::~SocialNetwork() {
	this->destroy();
}

SocialNetwork& addUser(const User & newUser) {
	if(this->size == this->capacity) {
		this->resize();
	}
	
	this->users[this->size] = newUser;
	this->size++;
	
	return *this;
}















