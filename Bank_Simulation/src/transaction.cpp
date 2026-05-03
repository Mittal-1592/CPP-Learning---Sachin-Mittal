#include "transaction.h"
#include <iostream>

Transaction::Transaction(std::string d,
                         std::string t,
                         double a,
                         double b)
    : date(d), type(t), amount(a), balanceAfter(b) {}



void Transaction::display() {
    std::cout << date << " " << type << " " << amount << " Balance: " << balanceAfter << "\n";
}   