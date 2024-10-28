#ifndef SECURE_BANKING_SYSTEM_ACCOUNT_H
#define SECURE_BANKING_SYSTEM_ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

// Forward declaration of Transaction class to prevent circular dependency
class Transaction;

class Account {
private:
    int accountNumber;
    int customerID;
    double balance;
    std::string accountType;
    std::vector<Transaction> transactions;

public:
    Account(int accNum, int custID, double bal, const std::string &accType);

    int getAccountNumber() const;
    int getCustomerID() const;
    double getBalance() const;
    std::string getAccountType() const;

    void setAccountType(const std::string &accType);
    void deposit(double amount);
    void withdraw(double amount);
    void transfer(double amount, Account &toAccount);
    void viewTransactions() const;
    std::string getAccountDetails() const;
};

#endif //SECURE_BANKING_SYSTEM_ACCOUNT_H
