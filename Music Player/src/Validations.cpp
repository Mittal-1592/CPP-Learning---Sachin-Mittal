#include "Validations.h"
#include <iostream>

#include <iostream>
#include <string>
#include <sstream>

int Validations::isValidChoice(int min, int max) {
    std::string input;
    int choice;

    while (true) {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (!(ss >> choice)) {
            std::cout<< "Invalid input. Please enter an integer.\n";
            continue;
        }

        char extra;
        if (ss >> extra) {
            std::cout<< "Invalid input. Float or extra characters not allowed.\n";
            continue;
        }

        if (choice < min || choice > max) {
            std::cout<< "Invalid choice. Please enter a number between "<< min<< " and "<< max<< ".\n";
            continue;
        }
        return choice;
    }
}

int Validations::isPositionValid(int size) {
    std::string input;
    int position;
    while (true) {
        std::cout << "Enter position: ";
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (!(ss >> position)) {
            std::cout<< "Invalid input. Please enter an integer.\n";
            continue;
        }

        char extra;
        if (ss >> extra) {
            std::cout<< "Invalid input. Float or extra characters not allowed.\n";
            continue;
        }

        if (position <= 0 || position > size) {
            std::cout<< "Invalid position. Please enter a number between 1 and "<< size<< ".\n";
            continue;
        }
        return position - 1;
    }
}
