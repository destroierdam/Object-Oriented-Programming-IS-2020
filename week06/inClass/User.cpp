#include "User.h"

User::User() {
    username[0] = '\0';
    password[0] = '\0';
    email[0] = '\0';
}

User::User(char * username, char * password, char * email) {
    cout << "Calling constructor of User with username " << username << "\n";
    strcpy(this->username, username);
    strcpy(this->password, password);
    strcpy(this->email, email);
}

void User::setUsername(const char * newUsername) {
    strcpy(this->username, newUsername);
}
const char* User::getUsername() const {
    return this->username;
}

const char* User::getEmail() const {
    return this->email;
}
