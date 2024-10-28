#include <iostream>
#include "Customer.h"
#include "Transaction.h"
#include "BankingService.h"

void displayMenu() {
    std::cout << "\nWelcome to the Banking System\n";
    std::cout << "1. Create a Customer\n";
    std::cout << "2. Create an Account for Customer\n";
    std::cout << "3. Deposit Funds\n";
    std::cout << "4. Withdraw Funds\n";
    std::cout << "5. Transfer Funds\n";
    std::cout << "6. Display Account Balance\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BankingService bankingService;
    int choice;
    int customerId, accountId, fromAccountId, toAccountId;
    std::string firstName, lastName, email, address, phone, accountType;
    double amount;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Customer ID: ";
                std::cin >> customerId;
                std::cout << "Enter First Name: ";
                std::cin >> firstName;
                std::cout << "Enter Last Name: ";
                std::cin >> lastName;
                std::cout << "Enter Email: ";
                std::cin >> email;
                std::cout << "Enter Address: ";
                std::cin >> address;
                std::cout << "Enter Phone: ";
                std::cin >> phone;
                bankingService.createCustomer(customerId, firstName, lastName, email, address, phone);
                std::cout << "Customer created successfully!\n";
                break;

            case 2:
                std::cout << "Enter Account Number: ";
                std::cin >> accountId;
                std::cout << "Enter Customer ID: ";
                std::cin >> customerId;
                std::cout << "Enter Initial Balance: ";
                std::cin >> amount;
                std::cout << "Enter Account Type: ";
                std::cin >> accountType;
                bankingService.createAccount(accountId, customerId, amount, accountType);
                std::cout << "Account created successfully!\n";
                break;

            case 3:
                std::cout << "Enter Account Number to Deposit: ";
                std::cin >> accountId;
                std::cout << "Enter Amount to Deposit: ";
                std::cin >> amount;
                bankingService.performTransaction(accountId, "Deposit", amount);
                break;

            case 4:
                std::cout << "Enter Account Number to Withdraw From: ";
                std::cin >> accountId;
                std::cout << "Enter Amount to Withdraw: ";
                std::cin >> amount;
                bankingService.performTransaction(accountId, "Withdrawal", amount);
                break;

            case 5:
                std::cout << "Enter Source Account Number: ";
                std::cin >> fromAccountId;
                std::cout << "Enter Destination Account Number: ";
                std::cin >> toAccountId;
                std::cout << "Enter Amount to Transfer: ";
                std::cin >> amount;
                bankingService.performTransaction(fromAccountId, "Transfer", amount, toAccountId);
                break;

            case 6:
                std::cout << "Enter Account Number to Check Balance: ";
                std::cin >> accountId;
                bankingService.viewAccountDetails(accountId);
                break;

            case 0:
                std::cout << "Exiting the Banking System. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}