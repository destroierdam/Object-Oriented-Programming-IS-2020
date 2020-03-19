#pragma once
#include <iostream>
using std::cout;

class User {
private:
    char username[64];
    char password[64];
    char email[64];
public:
    User();
    User(char * username, char * password, char * email);
    void setUsername(const char * newUsername);
    const char* getUsername() const;
    const char* getEmail() const;
};
