#include "User.h"

User::User(std::string userName, std::string password)
    : userName(userName), password(password) {}

bool User::login(std::string userName, std::string password) {
    return this->userName == userName && this->password == password;
}