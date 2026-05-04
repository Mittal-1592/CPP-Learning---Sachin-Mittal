#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "user.h"
#include "bank.h"

class AccountHolder : public User {
private:
    int accNo;

public:
    AccountHolder(int id, int acc);

    void deposit(Bank& bank, double amt, std::string& date);
    void withdraw(Bank& bank, double amt, std::string& date);
    void miniStatement(Bank& bank);
    void fullStatement(Bank& bank);

    void getBalance(Bank& bank);
};

#endif