#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "User.h"
#include "Account.h"

class AccountHolder : public User {
    Account* account;

public:
    AccountHolder(std::string u, std::string p, Account* acc);

    Account* getAccount();
    std::string getUserName();
};

#endif