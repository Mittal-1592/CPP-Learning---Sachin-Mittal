#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"

class Account {
private:
    int accNo;
    double balance;

    Transaction** transactions; 
    int txnCount;
    int txnCapacity;

    void resize(); 

public:
    Account(int acc);
    ~Account();

    int getAccNo();
    double getBalance();

    void deposit(double amt,  std::string date);
    bool withdraw(double amt,  std::string date);

    void miniStatement() ;
    void fullStatement() ;
};

#endif