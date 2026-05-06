#include "User.h"

User::User(std::string u, std::string p)
    : userName(u), password(p) {}

bool User::login(std::string u, std::string p) {
    return userName == u && password == p;
}