#ifndef SECURE_BANKING_SYSTEM_TRANSACTION_H
#define SECURE_BANKING_SYSTEM_TRANSACTION_H

#include <string>

class Account; //forward declaration

class Transaction {
private:
    int transactionID;
    int accountNumber;
    std::string type;
    double amount;
    std::string date;

public:
    Transaction(int id, int accNum, const std::string &t, double amt, const std::string &d);

    int getTransactionID() const;
    int getAccountNumber() const;
    std::string getType() const;
    double getAmount() const;
    std::string getDate() const;

    std::string getTransactionDetails() const;
    void executeTransaction(Account *fromAccount, Account *toAccount) const;
};

#endif // SECURE_BANKING_SYSTEM_TRANSACTION_H
