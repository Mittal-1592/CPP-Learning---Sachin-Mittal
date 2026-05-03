#include "account.h"
#include <iostream>

Account::Account(int acc)
    : accNo(acc), balance(0.0), txnCount(0), txnCapacity(10)
{
    transactions = new Transaction*[txnCapacity];
}

Account::~Account() {
    for (int i = 0; i < txnCount; i++)
        delete transactions[i];
    delete[] transactions;
}

void Account::resize() {
    txnCapacity *= 2;
    Transaction** temp = new Transaction*[txnCapacity];

    for (int i = 0; i < txnCount; i++)
        temp[i] = transactions[i];

    delete[] transactions;
    transactions = temp;
}

int Account::getAccNo() { return accNo; }
double Account::getBalance() { return balance; }

void Account::deposit(double amt, const std::string date) {
    if (txnCount == txnCapacity) {
        resize();
    }
    balance += amt;
    transactions[txnCount++] = new Transaction(date, "Deposit", amt, balance);
    std::cout << std::endl << "Deposit successful. Balance: " << balance << std::endl;
}

bool Account::withdraw(double amt, const std::string date) {
    if (amt > balance){
        std::cout << "Insufficient funds. Current balance: " << balance << std::endl;
        return false;
    }

    if (txnCount == txnCapacity) {
        resize();
    }

    balance -= amt;
    transactions[txnCount++] = new Transaction(date, "Withdraw", amt, balance);
    std::cout << "Withdrawal successful. Balance: " << balance << std::endl;
    return true;
}

void Account::miniStatement() {
    std::cout << "\n--- Last 5 Transactions ---\n";

    int start = txnCount - 5;
    if (start < 0) start = 0;

    for (int i = start; i < txnCount; i++) {
        transactions[i]->display();
    }
}

void Account::fullStatement() {
    std::cout << "\n--- Full Statement ---\n";

    for (int i = 0; i < txnCount; i++) {
        transactions[i]->display();
    }
}