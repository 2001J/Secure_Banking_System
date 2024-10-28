//BankingService.cpp
#include "BankingService.h"
#include <iostream>

void BankingService::createCustomer(int id, const std::string &fName, const std::string &lName, const std::string &mail,
                                    const std::string &addr, const std::string &ph) {
    customers.emplace(id, Customer(id, fName, lName, mail, addr, ph));
}

void BankingService::createAccount(int accNum, int custID, double bal, const std::string &accType) {
    accounts.emplace(accNum, Account(accNum, custID, bal, accType));
}

void BankingService::performTransaction(int accNum, const std::string &type, double amount, int toAccNum) {
    auto it = accounts.find(accNum);
    if (it != accounts.end()) {
        if (type == "Deposit") {
            it->second.deposit(amount);
        } else if (type == "Withdrawal") {
            it->second.withdraw(amount);
        } else if (type == "Transfer" && toAccNum != -1) {
            auto toIt = accounts.find(toAccNum);
            if (toIt != accounts.end()) {
                it->second.transfer(amount, toIt->second);
            } else {
                std::cout << "Destination account not found" << std::endl;
            }
        } else {
            std::cout << "Invalid transaction type or missing destination account number for transfer" << std::endl;
        }
    } else {
        std::cout << "Account not found" << std::endl;
    }
}

void BankingService::viewAccountDetails(int accNum) const {
    auto it = accounts.find(accNum);
    if (it != accounts.end()) {
        std::cout << it->second.getAccountDetails() << std::endl;
    } else {
        std::cout << "Account not found" << std::endl;
    }
}

void BankingService::viewTransactions(int accNum) const {
    auto it = accounts.find(accNum);
    if (it != accounts.end()) {
        it->second.viewTransactions();
    } else {
        std::cout << "Account not found" << std::endl;
    }
}