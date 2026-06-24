#ifndef BANK_H
#define BANK_H

#include "AccountHolder.h"

class Bank {
    Account** accounts;
    AccountHolder** users;

    int accCount, userCount, capacity;

    void resize();
    static int accountNumberGenerator;  

public:
    Bank();
    ~Bank();

    void createAccount(std::string username, std::string password);
    bool closeAccount(int accNo);

    Account* getAccount(int accNo);
    AccountHolder* loginUser(std::string u, std::string p);

    void showAllAccounts();
};

#endif