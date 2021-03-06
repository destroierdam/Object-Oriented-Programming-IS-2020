#pragma once
#include <functional>
#include "User.h"
	
class SocialNetwork {
private:
	User* users;
	size_t size, capacity;
	void copy(const SocialNetwork& other);
	void destroy();
	void resize();
public:
	SocialNetwork();
	SocialNetwork(const SocialNetwork& other);
	SocialNetwork& operator=(const SocialNetwork& other);
	~SocialNetwork();
	
	SocialNetwork& addUser(const User & newUser);

	SocialNetwork& alterCertainUsers(std::function<bool(const User &)> filter, std::function<void(User &)> alter);
	SocialNetwork& alterCertainUsers(std::function<void(User &)> alteringFunc);
};
