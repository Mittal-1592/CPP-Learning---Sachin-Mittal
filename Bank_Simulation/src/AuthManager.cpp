#include "AuthManager.h"

AuthManager::AuthManager(Admin* admin) {
    this->admin = admin;
    currentUser = nullptr;
}

bool AuthManager::loginAdmin(std::string username, std::string password) {
    return admin->login(username, password);
}

AccountHolder* AuthManager::loginUser(Bank& bank, std::string username, std::string password) {
    currentUser = bank.loginUser(username, password);
    return currentUser;
}

void AuthManager::logout() {
    currentUser = nullptr;
}

AccountHolder* AuthManager::getCurrentUser() {
    return currentUser;
}