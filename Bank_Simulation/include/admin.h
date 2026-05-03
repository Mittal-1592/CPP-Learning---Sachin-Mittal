#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "bank.h"

class Admin : public User {
public:
    Admin(int id, std::string name);
    void createAccount(Bank& bank, int accNo);
    void closeAccount(Bank& bank, int accNo);

    void miniStatement(Bank& bank, int accNo);
    void fullStatement(Bank& bank, int accNo);
};

#endif