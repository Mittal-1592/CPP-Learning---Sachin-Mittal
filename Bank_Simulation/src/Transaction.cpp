#include "Transaction.h"
#include <iomanip>

Transaction::Transaction(std::string d, std::string t, double a, double b)
    : date(d), type(t), amount(a), balanceAfter(b) {}

void Transaction::display() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << date << " | " << type
              << " | Amount: " << amount
              << " | Balance: " << balanceAfter << "\n";
}