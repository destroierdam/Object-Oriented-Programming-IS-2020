#pragma once
#include "User.h"

class SocialNetwork
{
private:
	User* users;
	size_t size, capacity;
	void destroy();
	void copy(const SocialNetwork& other);
	void resize();
public:
	SocialNetwork();
	SocialNetwork(const SocialNetwork& other);
	SocialNetwork& operator=(const SocialNetwork& other);
	~SocialNetwork();

	SocialNetwork& addUser(const User& newUser);
};

