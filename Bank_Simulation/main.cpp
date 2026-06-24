#include "Bank.h"
#include "AuthManager.h"
#include "Admin.h"
#include "runSimulation.h"

int main() {
    Bank bank;
    Admin admin("admin", "Admin123");
    AuthManager authManager(&admin);

    runSimulation(bank, authManager);
}