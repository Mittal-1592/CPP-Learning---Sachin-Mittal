#include "validations.h"
#include <iostream>

int validChoice(int min, int max) {
    int choice;
    while (true) {
        if (std::cin >> choice && choice >= min && choice <= max)
            return choice;

        std::cout << "Invalid choice. Try again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

int validAccountNumber() {
    int accNo;
    while (true) {
        if (std::cin >> accNo && accNo >= 1000 && accNo <= 9999)
            return accNo;

        std::cout << "Enter valid 4-digit account number: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

double validAmount() {
    double amt;
    while (true) {
        if (std::cin >> amt && amt > 0)
            return amt;

        std::cout << "Enter valid amount: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}