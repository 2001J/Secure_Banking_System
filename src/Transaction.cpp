// Transaction.cpp
#include "Transaction.h"
#include "Account.h"
#include <iostream>

Transaction::Transaction(int id, int accNum, const std::string &t, double amt, const std::string &d)
        : transactionID(id), accountNumber(accNum), type(t), amount(amt), date(d) {}

int Transaction::getTransactionID() const { return transactionID; }
int Transaction::getAccountNumber() const { return accountNumber; }
std::string Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getDate() const { return date; }

std::string Transaction::getTransactionDetails() const {
    return "Transaction ID: " + std::to_string(transactionID) + ", Account Number: " + std::to_string(accountNumber) +
           ", Type: " + type + ", Amount: " + std::to_string(amount) + ", Date: " + date;
}

bool Transaction::executeTransaction(Account *fromAccount, Account *toAccount) const {
    std::cout << "Executing transaction: " << getTransactionDetails() << std::endl;

    if (type == "Deposit") {
        fromAccount->deposit(amount);
        std::cout << "Deposit completed successfully." << std::endl;
        return true;
    } else if (type == "Withdrawal") {
        if (fromAccount->getBalance() >= amount) {
            fromAccount->withdraw(amount);
            std::cout << "Withdrawal completed successfully." << std::endl;
            return true;
        } else {
            std::cerr << "Transaction failed: Insufficient funds in source account." << std::endl;
            return false;
        }
    } else if (type == "Transfer") {
        if (fromAccount->getBalance() >= amount) {
            if (toAccount != nullptr) {
                fromAccount->withdraw(amount);
                toAccount->deposit(amount);
                std::cout << "Transfer completed successfully." << std::endl;
                return true;
            } else {
                std::cerr << "Invalid destination account." << std::endl;
                return false;
            }
        } else {
            std::cerr << "Transaction failed: Insufficient funds in source account." << std::endl;
            return false;
        }
    } else {
        std::cerr << "Invalid transaction type." << std::endl;
        return false;
    }
}