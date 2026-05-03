#include "bank.h"
#include <iostream>

Bank::Bank() : count(0), capacity(5) {
    accounts = new Account*[capacity];
}

Bank::~Bank() {
    for (int i = 0; i < count; i++)
        delete accounts[i];
    delete[] accounts;
}

void Bank::resize() {
    capacity *= 2;
    Account** temp = new Account*[capacity];

    for (int i = 0; i < count; i++)
        temp[i] = accounts[i];

    delete[] accounts;
    accounts = temp;
}

Account* Bank::getAccount(int accNo) {
    for (int i = 0; i < count; i++) {
        if (accounts[i]->getAccNo() == accNo)
            return accounts[i];
    }
    return nullptr;
}

bool Bank::addAccount(int accNo) {
    if (getAccount(accNo)) {
        std::cout << "Account already exists.\n";
        return false;
    }

    if (count == capacity)
        resize();

    accounts[count++] = new Account(accNo);
    return true;
}

bool Bank::removeAccount(int accNo) {
    for (int i = 0; i < count; i++) {
        if (accounts[i]->getAccNo() == accNo) {
            delete accounts[i];
            accounts[i] = accounts[count - 1];
            count--;
            return true;
        }
    }
    std::cout << std::endl << "--------------- Account not Found ---------------" << std::endl;
    return false;
}