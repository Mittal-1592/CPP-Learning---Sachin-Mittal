#include "Bank.h"
#include <iostream>

int Bank::accountNumberGenerator = 1000;

Bank::Bank() : accCount(0), userCount(0), capacity(5) {
    accounts = new Account*[capacity];
    users = new AccountHolder*[capacity];
}

Bank::~Bank() {
    for (int i = 0; i < accCount; i++) delete accounts[i];
    for (int i = 0; i < userCount; i++) delete users[i];

    delete[] accounts;
    delete[] users;
}

void Bank::resize() {
    capacity *= 2;

    Account** tempA = new Account*[capacity];
    AccountHolder** tempU = new AccountHolder*[capacity];

    for (int i = 0; i < accCount; i++) tempA[i] = accounts[i];
    for (int i = 0; i < userCount; i++) tempU[i] = users[i];

    delete[] accounts;
    delete[] users;

    accounts = tempA;
    users = tempU;
}

void Bank::createAccount(std::string userName, std::string password) {
    if (accCount == capacity) resize();

    int accNo = accountNumberGenerator++;

    Account* acc = new Account(accNo);
    accounts[accCount++] = acc;

    users[userCount++] = new AccountHolder(userName, password, acc);

    std::cout << "Account Created | Account Number: " << accNo << std::endl;
}

bool Bank::closeAccount(int accNo) {
    for (int i = 0; i < accCount; i++) {
        if (accounts[i]->getAccountNumber() == accNo) {
            std::cout << accounts[i]->getAccountNumber() << " " << users[i]->getUserName() << std::endl;
            delete accounts[i];
            delete users[i];

            accounts[i] = accounts[accCount - 1];
            users[i] = users[userCount - 1];

            accCount--;
            userCount--;

            std::cout << "Account closed successfully." << std::endl;
            return true;
        }
    }
    std::cout << "Account not found." << std::endl;
    return false;
}

Account* Bank::getAccount(int accNo) {
    for (int i = 0; i < accCount; i++)
        if (accounts[i]->getAccountNumber() == accNo)
            return accounts[i];
    return nullptr;
}

AccountHolder* Bank::loginUser(std::string userName, std::string password) {
    for (int i = 0; i < userCount; i++)
        if (users[i]->login(userName, password)){
            std::cout << "Login successful for user: " << users[i]->getUserName() << std::endl;
            return users[i];
        }
            
    return nullptr;
}

void Bank::showAllAccounts() {
    std::cout << std::endl << "Account Number | User Name | Balance" << std::endl;
    for (int i = 0; i < accCount; i++)
        std::cout << accounts[i]->getAccountNumber()
                  << "           |  " << users[i]->getUserName()
                  << "   |  " << accounts[i]->getBalance() << std::endl;
}

    