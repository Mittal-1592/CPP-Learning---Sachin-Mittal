#include "admin.h"
#include <iostream>

Admin::Admin(int id, std::string name)
    : User(id) {}

void Admin::createAccount(Bank& bank, int accNo) {
    if(bank.addAccount(accNo))
        std::cout << std::endl << "Account created successfully." << std::endl;   
}

void Admin::closeAccount(Bank& bank, int accNo) {
    if(bank.removeAccount(accNo)){
        std::cout << "Account closed successfully." << std::endl;
    }
}

void Admin::miniStatement(Bank& bank, int accNo) {
    Account* acc = bank.getAccount(accNo);
    if (acc)
        acc->miniStatement();
    if(!acc)
        std::cout << std::endl << "--------------- Account not Found ---------------" << std::endl;
        
}

void Admin::fullStatement(Bank& bank, int accNo) {
    Account* acc = bank.getAccount(accNo);
    if (acc)
        acc->fullStatement();
    if(!acc)
        std::cout << std::endl << "--------------- Account not Found ---------------" << std::endl;
}