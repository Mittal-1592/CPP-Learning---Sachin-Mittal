#include "AccountHolder.h"

AccountHolder::AccountHolder(std::string u, std::string p, Account* acc)
    : User(u, p), account(acc) {}

Account* AccountHolder::getAccount() {
    return account;
}

std::string AccountHolder::getUserName() {
    return userName;
}