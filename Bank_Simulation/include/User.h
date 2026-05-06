#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string userName, password;

public:
    User(std::string u, std::string p);
    bool login(std::string u, std::string p);
};

#endif