#include "admin.h"
#include "accountHolder.h"
#include "runProgram.h"
#include "validations.h"

#include <iostream>

void runProgram() {
    Bank bank;
    Admin admin(1, "Admin");

    int mainChoice;
    static int nextId = 1;

    while (true) {
        std::cout << std::endl << "====== BANK MANAGEMENT SYSTEM ======" << std::endl;
        std::cout << "1. Admin" << std::endl;
        std::cout << "2. Account Holder" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter choice: ";
        mainChoice = validChoice(1, 3);

        if (mainChoice == 1) {
            int adminChoice;
            while (true) {
                std::cout << std::endl << "------ ADMIN MENU ------" << std::endl;
                std::cout << "1. Create Account" << std::endl;
                std::cout << "2. Close Account" << std::endl;
                std::cout << "3. Mini Statement" << std::endl;
                std::cout << "4. Full Statement" << std::endl;
                std::cout << "5. Back to Main Menu" << std::endl;
                std::cout << "Enter choice: ";
                adminChoice = validChoice(1, 5);

                if (adminChoice == 1) {
                    int accNo;
                    std::cout << "Enter new Account Number: ";
                    accNo = validAccountNumber();
                    admin.createAccount(bank, accNo);
                }
                else if (adminChoice == 2) {
                    int accNo;
                    std::cout << "Enter Account Number to close: ";
                    accNo = validAccountNumber();
                    admin.closeAccount(bank, accNo);
                }
                else if (adminChoice == 3) {
                    int accNo;
                    std::cout << "Enter Account Number: ";
                    accNo = validAccountNumber();
                    admin.miniStatement(bank, accNo);
                }
                else if (adminChoice == 4) {
                    int accNo;
                    std::cout << "Enter Account Number: ";
                    accNo = validAccountNumber();
                    admin.fullStatement(bank, accNo);
                }
                else if (adminChoice == 5) {
                    break;
                }
            }
        }

        else if (mainChoice == 2) {
            int accNo;
            std::string name;

            std::cout << "Enter Account Number: ";
            accNo = validAccountNumber();

            Account* acc = bank.getAccount(accNo);
            if (!acc) {
                std::cout << "Account not found. Returning to main menu." << std::endl;
                continue;
            }

            AccountHolder user(nextId++, accNo);


            int userChoice;
            while (true) {
                std::cout << std::endl << "---- ACCOUNT HOLDER MENU ----" << std::endl;
                std::cout << "1. Deposit" << std::endl;
                std::cout << "2. Withdraw" << std::endl;
                std::cout << "3. Mini Statement" << std::endl;
                std::cout << "4. Full Statement" << std::endl;
                std::cout << "5. Back to Main Menu" << std::endl;
                std::cout << "Enter choice: ";
                userChoice = validChoice(1, 5);

                if (userChoice == 1) {
                    double amt;
                    std::string date;

                    std::cout << "Enter amount: ";
                    amt = validAmount();

                    std::cout << "Enter date: ";
                    date = validDate();
                    user.deposit(bank, amt, date);
                }
                else if (userChoice == 2) {
                    double amt;
                    std::string date;

                    std::cout << "Enter amount: ";
                    amt = validAmount();

                    std::cout << "Enter date: ";
                    date = validDate();
                    user.withdraw(bank, amt, date);
                }
                else if (userChoice == 3) {
                    user.miniStatement(bank);
                }
                else if (userChoice == 4) {
                    user.fullStatement(bank);
                }
                else if (userChoice == 5) {
                    break;
                }
            }
        }

        else if (mainChoice == 3) {
            std::cout << "Thank you for using Bank System!" << std::endl;
            break;
        }
    }
}