#ifndef BANK_H
#define BANK_H

#include "account.h"

class Bank {
private:
    Account** accounts;
    int count = 0;
    int capacity;

    void resize();

public:
    Bank();
    ~Bank();

    bool addAccount(int accNo);
    bool removeAccount(int accNo);
    Account* getAccount(int accNo);
};

#endif