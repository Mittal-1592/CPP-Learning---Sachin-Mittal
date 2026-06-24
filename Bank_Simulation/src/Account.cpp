#include "Account.h"
#include <ctime>
#include <iostream>

Account::Account(int acc)
    : accountNumber(acc), balance(0), txnCount(0), txnCapacity(5) {
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

int Account::getAccountNumber() { return accountNumber; }
double Account::getBalance() { return balance; }

void Account::deposit(double amount) {
    if (txnCount == txnCapacity) resize();

    balance += amount;
    transactions[txnCount++] =
        new Transaction(getCurrentDate(), "Deposit", amount, balance);

    std::cout << " Deposit successful. Balance: " << balance << std::endl;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient balance" << std::endl;
        return false;
    }

    if (txnCount == txnCapacity) resize();

    balance -= amount;
    transactions[txnCount++] =
        new Transaction(getCurrentDate(), "Withdraw", amount, balance);

    std::cout << " Withdrawal successful. Balance: " << balance << std::endl;
    return true;
}

void Account::miniStatement() {
    std::cout << std::endl << "--- Last 5 Transactions ---" << std::endl;
    int start = txnCount - 5;
    if (start < 0) start = 0;

    for (int i = start; i < txnCount; i++)
        transactions[i]->display();
}

void Account::fullStatement() {
    std::cout << std::endl << "--- Full Statement ---" << std::endl;
    for (int i = 0; i < txnCount; i++)
        transactions[i]->display();
}

std::string Account::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    std::string date = std::to_string(ltm->tm_mday) + "-" +
                       std::to_string(1 + ltm->tm_mon) + "-" +
                       std::to_string(1900 + ltm->tm_year);
    return date;
}