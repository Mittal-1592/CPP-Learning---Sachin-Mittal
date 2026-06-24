#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "Admin.h"
#include "Bank.h"

class AuthManager {
    Admin* admin;
    AccountHolder* currentUser;

public:
    AuthManager(Admin* a);

    bool loginAdmin(std::string u, std::string p);
    AccountHolder* loginUser(Bank& bank, std::string u, std::string p);

    void logout();
    AccountHolder* getCurrentUser();
};

#endif