#pragma once
class User
{
private:
	char* username;
	char* password;
	char* email;
	int age;
	void erase();
	void copy(const User& other);
public:
	User();
	User(const char* username, const char* password, const char* email, int age);
	User(const User& other);
	User& operator=(const User& other);
	~User();
};

