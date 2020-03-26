#pragma once

class User {
private:
    char * username;
    char * password;
    char * email;
    int age;
    bool gender;
    char * birthplace;
    char * address;
    
    void destroy();
    void copy(const User & other);
public:
    User();
    User(const char * username, const char * password, const char * email, int age, bool gender, const char * birthplace, const char * address);
    User(const User & other);
    User& operator=(const User & other);
    ~User();

    const char * getUsername() const;
    void setUsername(const char * newUsername);
    int getAge() const;
    void setAge(int newAge);

    // get, set
    // rule of 3
    // cin, cout
    // print
};
