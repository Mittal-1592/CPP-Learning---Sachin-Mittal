#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"

class Account {
    int accountNumber;
    double balance;

    Transaction** transactions;
    int txnCount, txnCapacity;

    void resize();
    std::string getCurrentDate();

public:
    Account(int acc);
    ~Account();

    int getAccountNumber();
    double getBalance();

    void deposit(double amt);
    bool withdraw(double amt);

    void miniStatement();
    void fullStatement();
};

#endif