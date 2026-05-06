#include <iostream>
#include "runSimulation.h"
#include "Validations.h"

void runSimulation(Bank& bank, AuthManager& auth) {
    while (true) {
        std::cout << std::endl << "====================================" << std::endl;
        std::cout << "         BANK MANAGEMENT SYSTEM      " << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << "1. Admin Login" << std::endl;
        std::cout << "2. Account Holder Login" << std::endl;
        std::cout << "3. Close Application" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        choice = getValidChoice(1, 3);

        if (choice == 1) {
            std::string userName, password;

            std::cout << std::endl << "Admin Login" << std::endl;
            userName = getValidUserName();
            password = getValidPassword();

            if (auth.loginAdmin(userName, password)) {
                std::cout << std::endl << "Login successful. Welcome Admin." << std::endl;

                while (true) {
                    std::cout << std::endl << "=========== ADMIN DASHBOARD ===========" << std::endl;
                    std::cout << "1. Create New Account" << std::endl;
                    std::cout << "2. Close Account" << std::endl;
                    std::cout << "3. View All Accounts" << std::endl;
                    std::cout << "4. View Account Statement" << std::endl;
                    std::cout << "5. Logout" << std::endl;
                    std::cout << "--------------------------------------" << std::endl;
                    std::cout << "Enter your choice: ";

                    int choiceAdmin;
                    choiceAdmin = getValidChoice(1,5);

                    if (choiceAdmin == 1) {
                        std::string userName, password;
                        userName = getValidUserName();
                        password = getValidPassword();

                        bank.createAccount(userName, password);
                    }
                    else if (choiceAdmin == 2) {
                        int accountNumber;
                        std::cout << std::endl << "Enter Account Number to close: ";
                        std::cin >> accountNumber;

                        bank.closeAccount(accountNumber);
                    }
                    else if (choiceAdmin == 3) {
                        std::cout << std::endl << "Displaying All Accounts:" << std::endl;
                        bank.showAllAccounts();
                    }
                    else if (choiceAdmin == 4) {
                        int accountNumber;
                        std::cout << std::endl << "Enter Account Number: ";
                        std::cin >> accountNumber;

                        Account* account = bank.getAccount(accountNumber);
                        if (account)
                            account->fullStatement();
                        else
                            std::cout << "Account not found." << std::endl;
                    }
                    else if (choiceAdmin == 5) {
                        std::cout << std::endl << "Logging out..." << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                    }
                }
            } else {
                std::cout << "Invalid admin credentials." << std::endl;
            }
        }

        else if (choice == 2) {
            std::string userName, password;

            std::cout << std::endl << "Account Holder Login" << std::endl;
            userName = getValidUserName();
            password = getValidPassword();

            AccountHolder* user = auth.loginUser(bank, userName, password);

            if (!user) {
                std::cout << "Login failed. Please check your credentials." << std::endl;
                continue;
            }

            std::cout << std::endl << "Login successful." << std::endl;

            Account* account = user->getAccount();

            while (true) {
                std::cout << std::endl << "=========== USER DASHBOARD ===========" << std::endl;
                std::cout << "1. Deposit Money" << std::endl;
                std::cout << "2. Withdraw Money" << std::endl;
                std::cout << "3. Mini Statement" << std::endl;
                std::cout << "4. Full Statement" << std::endl;
                std::cout << "5. Check Balance" << std::endl;
                std::cout << "6. Logout" << std::endl;
                std::cout << "-------------------------------------" << std::endl;
                std::cout << "Enter your choice: ";

                int choiceUser;
                choiceUser = getValidChoice(1, 6);

                if (choiceUser == 1) {
                    double amt;
                    std::cout << "Enter amount to deposit: ";
                    amt = getValidAmount();
                    account->deposit(amt);
                }
                else if (choiceUser == 2) {
                    double amt;
                    std::cout << "Enter amount to withdraw: ";
                    amt = getValidAmount();
                    account->withdraw(amt);
                }
                else if (choiceUser == 3) {
                    account->miniStatement();
                }
                else if (choiceUser == 4) {
                    account->fullStatement();
                }
                else if (choiceUser == 5) {
                    std::cout << "Current Balance: " << account->getBalance() << std::endl;
                }
                else if (choiceUser == 6) {
                    std::cout << std::endl << "Logging out..." << std::endl;
                    auth.logout();
                    break;
                }
                else {
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            }
        }

        else if (choice == 3) {
            std::cout << std::endl << "Thank you for using the Bank Management System." << std::endl;
            break;
        }

        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}