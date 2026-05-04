#include "validations.h"
#include <iostream>

bool isNumber(std::string& input) {
    if (input.empty()) return false;

    for (char c : input) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}


int validChoice(int min, int max) {
    std::string input;
    int choice;

    while (true) {
        std::cin >> input;

        if (isNumber(input)) {
            choice = std::stoi(input);
            if (choice >= min && choice <= max)
                return choice;
        }
        std::cout << "Invalid choice. Try again: ";
    }
}

int validAccountNumber() {
    std::string input;

    while (true) {
        std::cin >> input;
        if (isNumber(input)) {
            int accNo = std::stoi(input);
            if (accNo >= 1000 && accNo <= 9999)
                return accNo;
        }

        std::cout << "Enter valid 4-digit account number: ";
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

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

bool isValidDateFormat(const std::string& input) {
    if (input.length() != 10) return false;
    if (input[2] != '-' || input[5] != '-') return false;

    if (!std::isdigit(input[0]) || !std::isdigit(input[1])) return false;
    if (!std::isdigit(input[3]) || !std::isdigit(input[4])) return false;    
    for (int i = 6; i <= 9; i++) {
        if (!std::isdigit(input[i])) return false;
    }

    return true;
}

bool isValidDateValue(int d, int m, int y) {
    if (m < 1 || m > 12) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    if (m == 2 && isLeapYear(y))
        daysInMonth[1] = 29;

    if (d < 1 || d > daysInMonth[m - 1])
        return false;
    if(y < 2026)
        return false;
    return true;
}

std::string validDate() {
    std::string input;

    while (true) {
        std::cin >> input;

        if (isValidDateFormat(input)) {

            int day   = (input[0] - '0') * 10 + (input[1] - '0');
            int month = (input[3] - '0') * 10 + (input[4] - '0');
            int year  = (input[6] - '0') * 1000 +
                        (input[7] - '0') * 100 +
                        (input[8] - '0') * 10 +
                        (input[9] - '0');

            if (isValidDateValue(day, month, year))
                return input;
        }

        std::cout << "Enter valid date (DD-MM-YYYY): ";
    }
}