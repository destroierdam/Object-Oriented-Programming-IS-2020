#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

class User {
private:
    static const size_t USERNAME_SIZE = 128;
    static const size_t EMAIL_SIZE = 128;

    char username[USERNAME_SIZE];
    char email[EMAIL_SIZE];
    int age;
    bool gender;
public:
    User() = default;
    User(const char * username, const char * email, int age, bool gender) {
        std::strcpy(this->username, username);
        std::strcpy(this->email, email);
        this->age = age;
        this->gender = gender;
    }

    void print() {
        std::cout << "Username: '" << this->username << "'\n";
        std::cout << "Email: '" << this->email << "'\n";
        std::cout << "age: " << this->age << "\n";
        std::cout << "Gender: " << this->gender << "\n";
    }

    const char * getUsername() const {
        return this->username;
    }

    friend std::ostream& operator<<(std::ostream& out, const User & object);
    friend std::istream& operator>>(std::istream& in, User & object);
};

std::ostream& operator<<(std::ostream& out, const User & object) {
    out << object.getUsername() << '\n';
    out << object.email << '\n';
    out << object.age << '\n';
    out << object.gender << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, User & object) {
    in.getline(object.username, User::USERNAME_SIZE);
    in.getline(object.email, User::EMAIL_SIZE);
    in >> object.age;
    in >> object.gender;
    return in;
}

int main() {
    User traicho;//  ("mitaka", "mitko@gmail.com", 20, true);

    std::fstream file("output.txt", std::ios::in | std::ios::out | std::ios::app);  


    std::cout << file.tellp() << std::endl;
    file.seekp(10, std::ios::cur);
    std::cout << file.tellp() << std::endl;

    if(file.is_open()) {
        file >> traicho;

        file << traicho;
    } else {
        std::cout << R"(File "output.txt" could not be opened.)"; // raw string literals
    }


    
}