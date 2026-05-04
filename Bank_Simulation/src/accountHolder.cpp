#include "accountHolder.h"
#include <iostream>

AccountHolder::AccountHolder(int id,
                             int acc)
    : User(id), accNo(acc) {}

void AccountHolder::deposit(Bank& bank,
                            double amt,
                            std::string& date) {
    Account* acc = bank.getAccount(accNo);
    if (acc)
        acc->deposit(amt, date);
}

void AccountHolder::withdraw(Bank& bank,
                             double amt,
                             std::string& date) {
    Account* acc = bank.getAccount(accNo);
    if (acc)
        acc->withdraw(amt, date);
}

void AccountHolder::miniStatement(Bank& bank) {
    Account* acc = bank.getAccount(accNo);
    if (acc)
        acc->miniStatement();
}

void AccountHolder::fullStatement(Bank& bank) {
    Account* acc = bank.getAccount(accNo);
    if (acc)
        acc->fullStatement();
}

void AccountHolder::getBalance(Bank& bank) {
    Account* acc = bank.getAccount(accNo);
    if (acc)
        std::cout << "Current Balance: " << acc->getBalance() << std::endl;
}
