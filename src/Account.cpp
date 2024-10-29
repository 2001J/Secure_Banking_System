// Account.cpp
#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <ctime>

// Function to get current date as a string
std::string getCurrentDate() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    return std::to_string(1900 + ltm->tm_year) + "-" +
           std::to_string(1 + ltm->tm_mon) + "-" +
           std::to_string(ltm->tm_mday);
}

Account::Account(int accNum, int custID, double bal, const std::string &accType)
        : accountNumber(accNum), customerID(custID), balance(bal), accountType(accType) {}

int Account::getAccountNumber() const { return accountNumber; }
int Account::getCustomerID() const { return customerID; }
double Account::getBalance() const { return balance; }
std::string Account::getAccountType() const { return accountType; }

void Account::setAccountType(const std::string &accType) { accountType = accType; }

bool Account::deposit(double amount) {
    Transaction transaction(transactions.size() + 1, accountNumber, "Deposit", amount, getCurrentDate());
    if (transaction.executeTransaction(this)) {
        transactions.push_back(transaction);
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    Transaction transaction(transactions.size() + 1, accountNumber, "Withdrawal", amount, getCurrentDate());
    if (transaction.executeTransaction(this)) {
        transactions.push_back(transaction);
        return true;
    }
    return false;
}

bool Account::transfer(double amount, Account &toAccount) {
    Transaction transaction(transactions.size() + 1, accountNumber, "Transfer", amount, getCurrentDate());
    if (transaction.executeTransaction(this, &toAccount)) {
        transactions.push_back(transaction);
        return true;
    }
    return false;
}

void Account::viewTransactions() const {
    for (const auto &transaction : transactions) {
        std::cout << transaction.getTransactionDetails() << std::endl;
    }
}

std::string Account::getAccountDetails() const {
    return "Account Number: " + std::to_string(accountNumber) + ", Customer ID: " + std::to_string(customerID) +
           ", Balance: " + std::to_string(balance) + ", Account Type: " + accountType;
}