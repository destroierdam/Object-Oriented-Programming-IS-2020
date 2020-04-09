#pragma once
	
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
	
};
