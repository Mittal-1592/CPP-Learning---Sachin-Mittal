#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class Transaction {
    std::string date, type;
    double amount, balanceAfter;

public:
    Transaction(std::string d, std::string t, double a, double b);
    void display();
};

#endif