#include "Validations.h"
#include <iostream>

#include <iostream>
#include <string>
#include <sstream>

int Validations::isValidChoice(int minimum, int maximum) {
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

        if (choice < minimum || choice > maximum) {
            std::cout<< "Invalid choice. Please enter a number between "<< minimum<< " and "<< maximum<< ".\n";
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

bool Validations::validatePlaylistName(const std::string& playlistName) {
    if (playlistName.empty()) {
        return false;
    }

    bool onlySpaces = true;
    for (char ch : playlistName) {
        if (ch != ' ') {
            onlySpaces = false;
            break;
        }
    }

    if (onlySpaces) {
        return false;
    }

    for (char ch : playlistName) {
        if (!(isalnum(ch) || ch == ' ' || ch == '_' || ch == '-')) {
            return false;
        }
    }

    return true;
}


std::string Validations::getValidPlaylistName() {
    std::string playlistName;
    while (true) {
        std::getline(std::cin, playlistName);
        if (Validations::validatePlaylistName(playlistName)) {
            return playlistName;
        }
        std::cout << "Invalid playlist name. Try again." << std::endl;
    }
}