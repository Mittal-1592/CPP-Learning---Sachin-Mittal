#include "Validations.h"
#include <iostream>
#include <cctype>

bool isNumber(std::string& input) {
    if (input.empty()) return false;

    for (char c : input) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int getValidChoice(int min, int max) {
    std::string input;

    while (true) {
        std::cin >> input;

        if (isNumber(input)) {
            int choice = std::stoi(input);
            if (choice >= min && choice <= max)
                return choice;
        }

        std::cout << "Invalid choice. Enter a number between "
                  << min << " and " << max << ": ";
    }
}

double getValidAmount() {
    double amt;

    while (true) {
        if (std::cin >> amt && amt > 0)
            return amt;

        std::cout << "Invalid amount. Enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

std::string getValidUserName() {
    std::string username;

    while (true) {
        std::cout << "Enter Username: ";
        std::cin >> username;

        if (username.length() < 4 || username.length() > 20) {
            std::cout << "Username must be 4–20 characters." << std::endl;
            continue;
        }

        bool valid = true;
        for (char c : username) {
            if (!std::isalnum(c)) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            std::cout << "Only letters and digits allowed." << std::endl;
            continue;
        }

        return username; 
    }
}

std::string getValidPassword() {
    std::string password;

    while (true) {
        std::cout << "Enter Password: ";
        std::cin >> password;

        if (password.length() < 6) {
            std::cout << "Password must be at least 6 characters." << std::endl;
            continue;
        }

        bool hasUpper = false, hasLower = false, hasDigit = false;

        for (char c : password) {
            if (std::isupper(c)) hasUpper = true;
            if (std::islower(c)) hasLower = true;
            if (std::isdigit(c)) hasDigit = true;
        }

        if (!(hasUpper && hasLower && hasDigit)) {
            std::cout << "Password must contain uppercase, lowercase, and digit." << std::endl;
            continue;
        }

        return password; 
    }
}